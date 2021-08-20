#include <iostream>
#include <vector>

using namespace std;

bool is = true;
struct inch
{
    short color;
    vector<int> edges;
    inch()
    {
        color = 0;
    }
};
 
vector<inch> graph;
 
void dfs(unsigned k, short prev)
{
    int inv;
    if(prev == 1)
        graph[k].color = 2;
    else
        graph[k].color = 1;
 
    for (unsigned i = 0; i < graph[k].edges.size(); i++)
    {   
        if(graph[graph[k].edges[i]].color == 0)
            dfs(graph[k].edges[i], graph[k].color);
        else if(graph[graph[k].edges[i]].color == graph[k].color)
            is = false;
    }
}
 
int main()
{
    freopen("bipartite.in", "r", stdin);
    freopen("bipartite.out", "w", stdout);
 
    unsigned n_nodes, n_edges;
    unsigned a, b;
    cin >> n_nodes >> n_edges;
 
    inch buf;
    for (unsigned i = 0; i < n_nodes; i++)
        graph.push_back(buf);
    for (int i = 0; i < n_edges; i++)
    {
        cin >> a >> b;
        graph[a - 1].edges.push_back(b - 1);
        graph[b - 1].edges.push_back(a - 1);
    }
    for(int i = 0; i < graph.size(); i++)
    {
        if(graph[i].color == 0)
        {
            dfs(i, 2);
        }
    }
  

    if(is)
        cout << "YES";
    else
        cout  << "NO";
    return 0;
}