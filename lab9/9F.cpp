#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct inch
{
    vector<int> edges;
    int local_result;

    inch()
    {
        local_result = -1;
    }
};
vector<inch> graph;

void dfs(int k, int player)
{
    for (unsigned i = 0; i < graph[k].edges.size(); i++)
        if (graph[graph[k].edges[i]].local_result == -1)
            dfs(graph[k].edges[i], (player == 0 ? 1 : 0));

    for (int i = 0; i < graph[k].edges.size(); i++)
        graph[k].local_result = max(graph[k].local_result, (graph[graph[k].edges[i]].local_result + 1) % 2);
    if (graph[k].local_result == -1)
        graph[k].local_result = 0;

}

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    unsigned n_nodes, n_edges, start;
    unsigned a, b;

    cin >> n_nodes >> n_edges >> start;

    start--;

    inch buf;
    for (unsigned i = 0; i < n_nodes; i++)
        graph.push_back(buf);

    for (int i = 0; i < n_edges; i++)
    {
        cin >> a >> b;
        graph[a - 1].edges.push_back(b - 1);
    }

    dfs(start, 0);
    
    cout << (graph[start].local_result == 1? "First player wins" : "Second player wins");

    return 0;
}