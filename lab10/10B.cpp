#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct inch
{
    bool is_used;
    int x, y;
    double dist;
    vector<double> edges;
    inch()
    {
        is_used = false;
        dist = 1e6;
    }
};

double dist(int x0, int y0, int x1, int y1)
{
    return sqrt(pow((x0 - x1), 2) + pow((y0 - y1), 2));
}

int main()
{
    freopen("spantree.in", "r", stdin);
    freopen("spantree.out", "w", stdout);
    unsigned n_nodes;
    double min_weight = 0;
    cin >> n_nodes;
    vector<inch>graph(n_nodes);

    for(int i = 0; i < n_nodes; i++)
        cin >> graph[i].x >> graph[i].y;

    for(int i = 0; i < n_nodes; i++)
        for(int j = 0; j < n_nodes; j++)
            if(i == j)
                graph[i].edges.push_back(1e6);
            else
                graph[i].edges.push_back(dist(graph[i].x, graph[i].y, graph[j].x, graph[j].y));

    graph[0].dist = 0;

    for(int i = 0; i < n_nodes; i++)
    {
        int current = 0;
         double buff_dist = 1e6;
        for(int j = 0; j < n_nodes; j++)
            if(!graph[j].is_used && (graph[j].dist < buff_dist))
                {
                    buff_dist = graph[j].dist;
                    current = j;
                }

        min_weight += buff_dist;
        graph[current].is_used = true;

        for(int k = 0; k < n_nodes; k++)
            graph[k].dist = min(graph[k].dist, graph[current].edges[k]);
    }

    cout << setprecision(10) << min_weight;

    return 0;
}
