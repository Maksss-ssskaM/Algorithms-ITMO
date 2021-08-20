#include <iostream>
#include<queue>
#include<vector>
#include <string>

using namespace std;

struct node {
    bool isUsed;
    bool isExit;
    bool isCoridor;
    vector<int> edges;
    int dist;
    string path;

    node() {
        dist = 0;
        isUsed = false;
        isExit = false;
        isCoridor = false;
    }
};

char find_way(int a, int b, int columns) {
    if (a - b == columns)
        return 'U';
    if (b - a == columns)
        return 'D';
    if (a - b == 1)
        return 'L';
    if (b - a == 1)
        return 'R';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int num_of_lines;
    int num_of_columns;

    cin >> num_of_lines >> num_of_columns;
    vector<node> graph(num_of_lines * num_of_columns);

    char buf;
    int start;
    for (int i = 0; i < num_of_lines * num_of_columns; i++) //ввод
    {
        cin >> buf;
        if (buf == 'T') {
            graph[i].isCoridor = true;
            graph[i].isExit = true;
        }
        else if (buf == 'S') {
            start = i;
            graph[i].isCoridor = true;
        }
        else if (buf == '.') {
            graph[i].isCoridor = true;
        }
    }

    //связь
    for (int i = 0; i < num_of_columns * num_of_lines; i++) {
        if (graph[i].isCoridor)
        {
            if (i + 1 < num_of_columns * num_of_lines && (i + 1) % num_of_columns != 0)
                if (graph[i + 1].isCoridor) {
                    graph[i].edges.push_back(i + 1);
                }
            if (i >= 0 && (i) % num_of_columns != 0)
                if (graph[i - 1].isCoridor) {
                    graph[i].edges.push_back(i - 1);
                }
            if (i + num_of_columns < num_of_columns * num_of_lines)
                if (graph[i + num_of_columns].isCoridor) {
                    graph[i].edges.push_back(i + num_of_columns);
                }
            if (i - num_of_columns >= 0) {
                if (graph[i - num_of_columns].isCoridor) {
                    graph[i].edges.push_back(i - num_of_columns);
                }
            }
        }
    }
    queue<int> q;
    q.push(start);
    graph[start].isUsed = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int j = 0; j < graph[v].edges.size(); j++) {
            int next = graph[v].edges[j];
            if (!graph[next].isUsed) {
                graph[next].isUsed = true;
                graph[next].dist = graph[v].dist + 1;
                graph[next].path = graph[v].path + find_way(v, next, num_of_columns);
                q.push(next);
            }
        }
    }

    for (int i = 0; i < num_of_columns * num_of_lines; i++) {
        if (graph[i].isExit) {
            if (graph[i].dist == 0)
                cout << -1 << "\n";
            else {
                cout << graph[i].dist << "\n";
                cout << graph[i].path;
            }

        }
    }

    return 0;
}
