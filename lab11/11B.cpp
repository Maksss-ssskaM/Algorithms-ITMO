#include <iostream>
#include<vector>

using namespace std;

int main() {

    freopen("pathsg.in", "r", stdin);
    freopen("pathsg.out", "w", stdout);

    unsigned n_nodes, n_edges;
    cin >> n_nodes >> n_edges;

    int a, b, c;

    vector<vector<long long>> graph(n_nodes, vector<long long>(n_edges, 1e8));
    for (int i = 0; i < n_edges; i++) {
        cin >> a >> b >> c;
        graph[a - 1][b - 1] = c;
    }

    for (int i = 0; i < n_nodes; i++)
        graph[i][i] = 0;

    for (int k = 0; k < n_nodes; k++)
        for (int i = 0; i < n_nodes; i++)
            for (int j = 0; j < n_nodes; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    for (int i = 0; i < n_nodes; i++) {
        for (int j = 0; j < n_nodes; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }


    return 0;
}
