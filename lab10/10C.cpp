#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n_nodes;

int is_safe(int v, vector<int> &p)
{
    return (v == p[v]) ? v : (p[v] = is_safe(p[v], p));
}

void unite(int a, int b, vector<int> &p)
{
    a = is_safe(a, p);
    b = is_safe(b, p);
    if (rand() & 1)
        swap(a, b);
    if (a != b)
        p[a] = b;
}

int main()
{
    freopen("spantree3.in", "r", stdin);
    freopen("spantree3.out", "w", stdout);

    vector<pair<int, pair<int, int>>> edges;
    unsigned n_nodes, n_edges;
    long long min_weight = 0;
    cin >> n_nodes >> n_edges;
    vector<int> tree_id(n_nodes);
    int a, b;
    pair<double, pair<int, int>>buf;
    
    for (int i = 0; i < n_edges; i++)
    {
        cin >> a >> b >> buf.first;
        buf.second.first = a - 1;
        buf.second.second = b - 1;
        edges.push_back(buf);
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i < n_nodes; ++i)
        tree_id[i] = i;
    int d;
    for (int i = 0; i < n_edges; ++i)
    {
        a = edges[i].second.first;
        b = edges[i].second.second;
        d = edges[i].first;
        
        if (is_safe(a, tree_id) != is_safe(b, tree_id))
        {
            min_weight += d;
            unite(a, b, tree_id);
        }
    }

    cout << min_weight;
    return 0;
}