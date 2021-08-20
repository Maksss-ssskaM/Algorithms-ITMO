#include <iostream>
#include<queue>
#include<vector>
using namespace std;
int g = 1;

struct node
{
	bool used;
	vector<int>edges;
	int comp;
};

int main()
{
	freopen("components.in", "r", stdin);
	freopen("components.out", "w", stdout);
	int buf;
	int num_of_edges;
	int num_of_points;

	cin >> num_of_points >> num_of_edges;
	vector<node>graph(num_of_points);

	int a, b;
	for (int i = 0; i < num_of_edges; i++)
	{
		cin >> a >> b;
		if (a != b)
		{
			graph[a - 1].edges.push_back(b - 1);
			graph[b - 1].edges.push_back(a - 1);
		}
	}

	for (int i = 0; i < num_of_points; i++)
	{
		if (graph[i].used == false)
		{
			queue<int>q;
			q.push(i);
			graph[i].comp = g;

			while (!q.empty())
			{
				int v = q.front();
				q.pop();
				for (int j = 0; j < graph[v].edges.size(); j++)
				{
					int next = graph[v].edges[j];

					if (!graph[next].used)
					{
						graph[next].used = true;
						graph[next].comp = g;
						q.push(next);
					}
				}
			}
			g++;
		}
	}
	cout << g - 1<< "\n";
	for (int i = 0; i < num_of_points; i++)
	{
		cout << graph[i].comp << " ";
	}

	return 0;
}
