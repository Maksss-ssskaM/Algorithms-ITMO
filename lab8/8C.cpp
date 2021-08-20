#include <iostream>
#include<vector>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int buf;
	int num_of_edges;
	int num_of_points;
	bool is = true;
	cin >> num_of_points >> num_of_edges;
	int** matrix = new int* [num_of_points];
	for (int i = 0; i < num_of_points; i++)
		matrix[i] = new int[num_of_points];
	for (int i = 0; i < num_of_points; i++)
		for (int j = 0; j < num_of_points; j++)
			matrix[i][j] = 0;

	int a, b;
	for (int i = 0; i < num_of_edges; i++)
	{
		cin >> a >> b;
		if (matrix[a - 1][b - 1] == 1 && a != b)
		{
			is = false;
			break;
		}
		matrix[a - 1][b - 1] = 1;
		if (matrix[b - 1][a - 1] == 1 && a != b)
		{
			is = false;
			break;
		}
	}

	if (is == false)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
