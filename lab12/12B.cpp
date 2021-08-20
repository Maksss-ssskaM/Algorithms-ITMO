#include <iostream>
#include <vector>
#include <algorithm>

const long INF = 2e9;

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> d(n + 1, INF);
    vector<long long> pos(n + 1);
    vector<long long> prev(n);
    long long length = 0;
    d[0] = -INF;
    pos[0] = -1;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for (long long i = 0; i < n; i++)
    {
        int j = int(upper_bound(d.begin(), d.end(), a[i]) - d.begin());
        if ((d[j - 1] < a[i]) && (a[i] < d[j])) {
            d[j] = a[i];
            pos[j] = i;
            prev[i] = pos[j - 1];
            length = (length > j ? length : j);
        }
    }

    auto p = pos[length];


    vector<long long>result;

    while (p != -1)
    {
        result.push_back(a[p]);
        p = prev[p];
    }



    cout << length << endl;
   for(int i = length - 1; i > -1; i--)
       cout << result[i] << " ";

    return 0;


}
