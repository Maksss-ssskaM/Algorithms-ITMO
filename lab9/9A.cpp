#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct inch
{
    short color;
    vector<int>edges;

    inch()
    {
        color = 0;
    }

};

stack<int> sort;
vector<inch> graph;

bool dfs(int k)
{
        if(graph[k].color == 2)
            return true;
        graph[k].color = 1;
        for(unsigned i = 0; i < graph[k].edges.size(); i++)
        {
            if(graph[graph[k].edges[i]].color == 0)
               {
                   if(!dfs(graph[k].edges[i]))
                   return false;

               }
            else if(graph[graph[k].edges[i]].color == 1)
                return false;
        }
        sort.push(k);
        graph[k].color = 2;
        return true;
}

int main()
{
    freopen("topsort.in", "r", stdin);
    freopen("topsort.out", "w", stdout);

    unsigned n_nodes, n_edges;
    unsigned a, b;
    cin >> n_nodes >> n_edges;

    inch buf;
    for(unsigned i = 0; i < n_nodes; i++)
        graph.push_back(buf);
    for(int i = 0; i < n_edges; i++)
    {
        cin >> a >> b;
        graph[a - 1].edges.push_back(b - 1);
    }
    
    for(unsigned i = 0; i < graph.size(); i++)
    {
        if(!dfs(i))
        {
            cout << -1;
            return 0;
        }

    }
    while(!sort.empty())
    {
        cout << sort.top() + 1 << " ";
        sort.pop();
    }
    return 0;
}