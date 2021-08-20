#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct inch
{
    bool is_visited;
    vector<int> edges;
 
    inch()
    {
        is_visited = false;
    }
};
 
vector<int> topsort_;
vector<inch> graph;
 
void topsort(int k)
{
     graph[k].is_visited = true;
    for (unsigned i = 0; i < graph[k].edges.size(); i++)
        if (!graph[graph[k].edges[i]].is_visited)
            topsort(graph[k].edges[i]);
    topsort_.push_back(k);
   
}

bool is_connected(int next, int current)
{
    for(int i = 0; i < graph[current].edges.size(); i++)
        if(next == graph[current].edges[i])
            return true;       
    return false;
}

int main()
{
    freopen("hamiltonian.in", "r", stdin);
    freopen("hamiltonian.out", "w", stdout);
 
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

    for(int i = 0; i < graph.size(); i++)
    {
        if(!graph[i].is_visited)
        {
            topsort(i);
        }
    }


    int next, current;
    bool is_hamiltonian = true;
    reverse(topsort_.begin(), topsort_.end());
    for(int i = 0; i < graph.size() - 1; i++)
    {
        current = topsort_[i];
        next = topsort_[i + 1];
        if(!is_connected(next, current))
            is_hamiltonian = false;

    }
    cout << (is_hamiltonian ? "YES" : "NO");
    
    return 0;
}
