#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    freopen("knapsack.in", "r", stdin);
    freopen("knapsack.out", "w", stdout);
    int n, s;

    cin >> s >> n;

    vector<int> w(n);

    for (int i = 0; i < n; i++)
        cin >> w[i];

    vector<vector<int>> d(n + 1, vector<int>(s + 1, 0));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= s; j++)
        {
            if(j >= w[i - 1])
                d[i][j] = max(d[i - 1][j], d[i - 1][j - w[i - 1]] + w[i - 1]);
            else
                d[i][j] = d[i - 1][j];
        }


    cout << d[n][s];
    return 0;
}
