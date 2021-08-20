#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct inch
{
    short color;
    vector<int> edges;

    inch()
    {
        color = 0;
    }
};

vector<int> sort;
vector<inch> graph;
vector<inch> t_graph;
vector<int> comp;
int n_comp = 1;

void topsort(int k)
{

    graph[k].color = 1;
    for (unsigned i = 0; i < graph[k].edges.size(); i++)
    {
        if (graph[graph[k].edges[i]].color == 0)
        {
            topsort(graph[k].edges[i]);
        }
    }
    sort.push_back(k);
    graph[k].color = 2;
}

void dfs(int k)
{
    if (t_graph[k].color == 2)
        return;
    t_graph[k].color = 1;
    comp[k] = n_comp;
    for (unsigned i = 0; i < t_graph[k].edges.size(); i++)
    {
        if (t_graph[t_graph[k].edges[i]].color == 0)
            dfs(t_graph[k].edges[i]);
    }
    graph[k].color = 2;
}

int main()
{

    freopen("cond.in", "r", stdin);
    freopen("cond.out", "w", stdout);

    unsigned n_nodes, n_edges;
    unsigned a, b;
    cin >> n_nodes >> n_edges;

    inch buf;
    for (unsigned i = 0; i < n_nodes; i++)
    {
        graph.push_back(buf);
        t_graph.push_back(buf);
        comp.push_back(0);
    }
    for (int i = 0; i < n_edges; i++) //ввели штуку
    {
        cin >> a >> b;
        graph[a - 1].edges.push_back(b - 1);
        t_graph[b - 1].edges.push_back(a - 1);
    }

    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[i].color == 0)
            topsort(i);
    }
    for (int i = 0; i < graph.size(); i++)
    {
        graph[i].color = 0;
    }

    for (int i = 0; i < graph.size(); i++)
    {
        int current = sort[sort.size() - 1 - i];
        if (graph[current].color == 0)
        {
            dfs(current);
            n_comp++;
        }
    }
    cout << n_comp - 1<< endl;
    for (int i = 0; i < graph.size(); i++)
    {
        cout << comp[i] << " ";
    }

    return 0;
}