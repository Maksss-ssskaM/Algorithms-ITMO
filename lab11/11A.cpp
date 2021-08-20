#include <iostream>
#include <set>
#include <vector>

using namespace std;

const long long inf = 1e12 + 7;

struct edge
{
    int to;
    long weight;
    edge(int a, long b)
    {
        to = a;
        weight = b;
    }
};

vector<vector<edge>> edges;


long long find_path(int start, int end, vector<vector<edge>>&graph)
{
    int n = graph.size();
    vector<long long> distances(n, inf);
    set<pair<long long, int>> queue;

    distances[start] = 0;
    queue.insert({0, start });

    while (!queue.empty())
    {
        pair<long long, int> buf = *queue.begin();
        queue.erase(queue.begin());

        for (auto edge : graph[buf.second])
            if (distances[edge.to] > buf.first + edge.weight)
            {
                queue.erase({distances[edge.to], edge.to });
                queue.insert({buf.first + edge.weight, edge.to });
                distances[edge.to] = buf.first + edge.weight;
            }
    }
    return distances[end] == inf ? -1 : distances[end];
}

int main()
{
    freopen("pathmgep.in", "r", stdin);
    freopen("pathmgep.out", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n_nodes, start, end;
    cin >> n_nodes >> start >> end;

    start--, end--;

    edges.resize(n_nodes);
    long long buf;

    for (int i = 0; i < n_nodes; i++)
        for (int j = 0; j < n_nodes; j++)
        {
            cin >> buf;
            if (buf != -1 && j != i)
                edges[i].emplace_back(j, buf);
        }


    cout << find_path(start, end, edges) << "\n";


    return 0;
}