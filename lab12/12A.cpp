#include <iostream>
#include <vector>

using namespace  std;

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    vector<int> d(n, 1);
    vector<int>prev(n, -1);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i] && d[j] + 1 > d[i])
            {
                d[i] = d[j] + 1;
                prev[i] = j;
            }

    }
    int pos = 0;
    int length = d[0];

    for(int i = 0; i < n; i++)
        if(d[i] > length)
        {
            pos = i;
            length = d[i];
        }

    vector<int>result;
    while (pos != -1)
    {
        result.push_back(arr[pos]);
        pos = prev[pos];
    }

    cout << length << endl;
    for(int i = result.size() - 1; i > -1; i--)
        cout << result[i] << " ";

    return 0;


}