#include <iostream>
#include <vector>
using namespace std;

const long long inf = 9e18;

struct inch
{
    bool is_used;
    vector<int> edges;
    int parent;
    long long dist;
    inch()
    {
        is_used = false;
        dist = inf;
        parent = -1;
    }
};

int relax(int l, int k, long long w, vector<inch>&graph)
{
    if (graph[k].dist > graph[l].dist + w)
    {
        graph[k].dist = max(-inf, graph[l].dist + w);
        graph[k].parent = l;
        return k;
    }
    return -1;
}

void dfs(int k, vector<inch> &graph)
{
    graph[k].dist = -inf;
    graph[k].is_used = true;
    for(int i = 0; i < graph[k].edges.size(); i++)
        if (!graph[graph[k].edges[i]].is_used)
            dfs(graph[k].edges[i], graph);
}

void find_min(unsigned start, vector<pair<long long, pair<int, int>>> &edges, unsigned n_nodes, vector<inch> &graph)
{
    graph[start].dist = 0;
    int check_for_relax = 0;

    for (int i = 0; i < n_nodes - 1; i++)
    {
        for (auto edge : edges)
        {
            if(graph[edge.second.first].dist < inf)
                relax(edge.second.first, edge.second.second, edge.first, graph);
        }
    }


    check_for_relax = -1;
    for (auto edge : edges)
    {
        if(graph[edge.second.first].dist < inf)
            check_for_relax = max(check_for_relax , relax(edge.second.first, edge.second.second, edge.first, graph));
    }
    int tmp = check_for_relax;

    if(tmp == -1)
        return;

    for (int i = 0; i < n_nodes; i++)
        tmp = graph[tmp].parent;

    dfs(tmp, graph);

    for(auto &i : graph)
        i.is_used = false;

    while (check_for_relax != -1)
    {
        check_for_relax = -1;
        for (auto edge : edges)
        {
            if(graph[edge.second.first].dist < inf && graph[edge.second.first].dist > -inf)
                check_for_relax = max(check_for_relax , relax(edge.second.first, edge.second.second, edge.first, graph));
        }
        int tmp = check_for_relax;

        if(tmp == -1)
            return;

        for (int i = 0; i < n_nodes; i++)
            tmp = graph[tmp].parent;

        dfs(tmp, graph);

        for(auto &i : graph)
            i.is_used = false;
    }
}

int main() {

    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);
    unsigned n_nodes, n_edges, start;
    cin >> n_nodes >> n_edges >> start;
    start--;
    unsigned a, b;
    long long w;
    vector<pair<long long, pair<int, int>>> edges;
    vector<inch> graph(n_nodes);
    for (int i = 0; i < n_edges; i++)
    {
        cin >> a >> b >> w;
        graph[a - 1].edges.push_back(b - 1);
        edges.emplace_back(w, make_pair(a - 1, b - 1));
    }

    find_min(start, edges, n_nodes, graph);

    for (const auto& i : graph)
        if(i.dist == -inf) cout << "-\n";
        else if(i.dist == inf) cout << "*\n";
        else cout << i.dist << "\n";

    return 0;
}
