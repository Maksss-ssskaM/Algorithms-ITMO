#include <iostream>
#include <vector>
#include <set>
using namespace std;


int main() {
    freopen("pathbgep.in", "r", stdin);
    freopen("pathbgep.out", "w", stdout);

    const long long inf = 1e11;

    int n_nodes, n_edges;
    cin >> n_nodes >> n_edges;

    int a, b, w;
    vector<vector<pair<int, int>>> graph(n_nodes);

    for (int i = 0; i < n_edges; i++) {
        cin >> a >> b >> w;
        graph[a - 1].emplace_back(pair<int, int>(b - 1, w));
        graph[b - 1].emplace_back(pair<int, int>(a - 1, w));
    }

    vector<long long> dist(n_nodes, inf);
    dist[0] = 0;

    set<pair<long long, int>> q;
    q.insert(make_pair(0, 0));

    while (!q.empty()) {
        pair<long long, int> v = *q.begin();
        q.erase(q.begin());

        for (auto edge : graph[v.second]) {
            if (dist[edge.first] > v.first + edge.second) {
                q.erase(make_pair(dist[edge.first], edge.first));
                dist[edge.first] = v.first + edge.second;
                q.insert(make_pair(dist[edge.first], edge.first));
            }
        }
    }

    for (auto i : dist)
        cout << i << " ";

    return 0;
}