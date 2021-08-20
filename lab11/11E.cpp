#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
 
const long long inf = 1e11 + 9;
 
int relax(int l, int k, long long w, vector<long long> &dist, vector<int> &p) {
    if (dist[k] > dist[l] + w) {
        dist[k] = max(-inf, dist[l] + w);
        p[k] = l;
        return k;
    }
    return -1;
}
 
stack<int> find_cycle(vector<pair<long long, pair<int, int>>> &graph, int n) {
    vector<long long> dist(n, inf);
    vector<int> p(n, -1);
    stack<int> path;
    int last_node = -1;
    for (int i = 0; i < n; i++) {
        last_node = -1;
        for (auto edge : graph) {
                last_node = max(last_node, relax(edge.second.first, edge.second.second, edge.first, dist, p));
        }
    }
    if (last_node != -1) {
        int v = last_node;
        for (int i = 0; i < n; i++)
            v = p[v];
 
        for (int u = v; ; u = p[u]) {
            path.push(u);
            if (u == v && path.size() > 1)
                break;
        }
    }
    return path;
}
 
int main() {
    freopen("negcycle.in", "r", stdin);
    freopen("negcycle.out", "w", stdout);
 

    int n_nodes;
    cin >> n_nodes;
 
    long long w;
    vector<pair<long long, pair<int, int>>> graph;
    for (int i = 0; i < n_nodes; i++) {
        for (int j = 0; j < n_nodes; j++) {
            cin >> w;
            if (w != 1e9)
                graph.push_back(make_pair(w, make_pair(i, j)));
        }
    }
    stack<int> path = find_cycle(graph, n_nodes);
   
   size_t size = path.size();
    if (size) {
        cout << "YES" << endl << size << endl;
        for (int i = 0; i < size; i++) {
            cout << path.top() + 1 << " ";
            path.pop();
        }
    }
    else
        cout << "NO";
    return 0;
}