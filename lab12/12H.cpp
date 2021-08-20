#include <iostream>
#include <vector>


using namespace std;

const int m = 1000000000;

signed main() {
    int n;
    cin >> n;
    if( n == 1)
    {
        cout << 0;
        return 0;
    }

    vector<int> colors(n);

    for (int i = 0; i < n; i++)
        cin >> colors[i];

    vector<vector<int>> d(n, vector<int>(n, 0)); //количество подпалиндромов на отрезке от i до j

    for (int i = 0; i < n; i++)
        d[i][i] = 1;


    for (int len = 1; len < n; len++)
        for (int i = 0; i + len < n; i++)
        {
            int j = i + len;

                if (colors[i] == colors[j])
                    d[i][j] = (d[i + 1][j] % m + d[i][j - 1] % m + 1) % m;
                else
                    d[i][j] = (d[i + 1][j] % m + d[i][j - 1] % m - d[i + 1][j - 1] % m) % m;


        }


    cout << (d[0][n - 1] + m) % m;

    return 0;
}
