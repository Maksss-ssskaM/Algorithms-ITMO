#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("knight2.in", "r", stdin);
    freopen("knight2.out", "w", stdout);

    int n, m, i, j;
    cin >> n >> m;

    vector<vector<int>> desk(n + 3, vector<int>(m + 3, 0));

    desk[2][2] = 1;
    int k = 2, l = 2;

    while (k < n + 1 || l < m + 1)
    {
        l == m + 1 ? k++ : l++;

        i = k, j = l;

        while (i < n + 2 && j > 1)
        {
            desk[i][j] = desk[i + 1][j - 2] + desk[i - 1][j - 2] + desk[i - 2][j - 1] + desk[i - 2][j + 1];
            i++;
            j--;
        }
    }

    cout << desk[n + 1][m + 1];

    return 0;
}