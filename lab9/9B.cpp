#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
unsigned start_ = -1;
unsigned end_ = -1;

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
vector<int> cycle;

short dfs(unsigned k)
{
    graph[k].color = 1;

    for (unsigned i = 0; i < graph[k].edges.size(); i++)
    {
        if (graph[graph[k].edges[i]].color == 0) //идем
        {
            if (dfs(graph[k].edges[i]) == 2)
            {
                cycle.push_back(k);
                return 2;
            }
        }
        else if (graph[graph[k].edges[i]].color == 1)
        {
            start_ = graph[k].edges[i];
            end_ = k;
            cycle.push_back(k);
            return 2;
        }
    }

    graph[k].color = 2;
    return 0;
}

int main()
{
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);

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
    }

    for (unsigned i = 0; i < graph.size(); i++)
    {
        if (dfs(i) == 2)
        {
            cout << "YES\n";
            reverse(cycle.begin(), cycle.end());
            for (int i = 0; i < cycle.size(); i++)
            {
                if(cycle[i] == start_)
                    for(int j = i; j < cycle.size(); j++)
                        {
                            cout << cycle[j] + 1 << " ";
                            if(cycle[j] == end_)
                                return 0;
                        }
            }
            return 0;
        }
    }
    cout << "NO";
    return 0;
}