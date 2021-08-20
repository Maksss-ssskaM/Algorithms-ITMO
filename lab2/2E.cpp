#include<iostream>
#include<ctime>

using namespace std;

int findk(int* arr, int n, int k)
{
   int p = 0;
   int r = n;


    while (true)
    {
        int mid = (p + r) / 2;
        int i = p + 1;
        int j = r;
        if (r - p <= 1)
        {
            if (r == p + 1 && arr[r] < arr[p])
                swap(arr[p], arr[r]);

            return arr[k];
        }

        swap(arr[mid], arr[p + 1]);

        if (arr[p] > arr[r])
            swap(arr[p], arr[r]);

        if (arr[p + 1] > arr[r])
            swap(arr[p + 1], arr[r]);

        if (arr[p] > arr[p + 1])
            swap(arr[p], arr[p + 1]);

        int buf = arr[p + 1];

        while (true)
        {
            while (arr[++i] < buf);
            while (arr[--j] > buf);

            if (i > j)
                break;

            swap(arr[i], arr[j]);
        }

        arr[p + 1] = arr[j];
        arr[j] = buf;

        if (j >= k)
            r = j - 1;
        if (j <= k)
            p = i;
    }
}
int main()
{
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);

    int n;
    cin >> n;
    int* arr = new int[n];
    int k;
    cin >> k;

    int a, b, c;
    cin >> a >> b >> c;

    int x1, x2;
    cin >> x1 >> x2;
    arr[0] = x1;
    arr[1] = x2;

    for (int i = 2; i < n; i++)
        arr[i] = a * arr[i - 2] + b * arr[i - 1] + c;

    cout << findk(arr, n-1, k-1);

    return 0;
}
