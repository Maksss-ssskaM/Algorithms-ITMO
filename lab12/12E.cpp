#include <iostream>
#include <vector>

using namespace std;

struct inch {
    vector<int> edges;
   };

void dfs(int k, vector<inch>& graph, vector<vector<int>>&d)
{
    d[k][0] = 0;
    d[k][1] = 1;

    for(int i = 0; i < graph[k].edges.size(); i++)
        dfs(graph[k].edges[i], graph, d);

    for(int i = 0; i < graph[k].edges.size(); i++)
    {
        d[k][1] += d[graph[k].edges[i]][0];
        d[k][0] += max(d[graph[k].edges[i]][0], d[graph[k].edges[i]][1]);
    }

}



signed main() {

    int n_nodes;
    cin >> n_nodes;
    int num = 0;
    vector<int>result;
    vector<inch>graph(n_nodes);
    int root = 0;
    vector<vector<int>> d(n_nodes, vector<int>(2));
    int a;
    for(int i = 0; i < n_nodes; i++)
    {
        cin >> a;
        if(a != 0)
            graph[a - 1].edges.push_back(i);
        else
            root = i;

    }

    dfs(root, graph, d);

    cout << max(d[root][0], d[root][1]);






    return 0;
}