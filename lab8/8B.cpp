#include <iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	bool isCorrect = true;
	int n;
	cin >> n;

	int** arr = new int* [n];

	for (int i = 0; i < n; i++)
		arr[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if (arr[i][j] != arr[j][i] && i != j)
			{
				isCorrect = false;
				break;
			}
	for (int i = 0; i < n; i++)
		if (arr[i][i] == 1)
		{
			isCorrect = false;
			break;
		}
	if (isCorrect == true)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}