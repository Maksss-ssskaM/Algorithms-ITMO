#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct inch
{
    vector<int> edges;
};

vector<inch> graph;

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

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
        cout << graph[i].edges.size() << " ";

    return 0;
}
