#include <iostream>
using namespace std;

int binary_search(int *a, int key, int n)
{
    bool isFind = false;
    int l = 0;
    int r = n;
    int mid;

    while ((l <= r) && (isFind != true))
    {
        mid = (l + r) / 2;

        if (a[mid] == key)
            isFind = true;
        if (a[mid] > key)
            r = mid - 1;
        else
            l = mid + 1;
    }

    if (isFind)
        return mid;
    else
        return -1;
}

void search(int *a, int key, int* first, int *second, int n)
{
    int k = binary_search(a, key, n);
    if(k == -1)
    {
        *first = -2;
        *second = -2;
    }
    else
    {
        *first = 0;
        *second = n;

        for(int i = k; i < n; i++)
            if(a[i] != key)
            {
                *second = i - 1;
                break;
            }
        for(int i = k; i > -1; i--)
            if(a[i] != key)
            {
                *first = i + 1;
                break;
            }
    }
}
int main()
{
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);
   int n;
   int k;
   int first;
   int second;
   int *pfirst = &first;
   int *psecond = &second;
   cin >> n;
   int *a = new int[n];
   for(int  i = 0; i < n; i++)
       cin >> a[i];

   cin >> k;

   int *asks = new int[k];
   for(int i = 0; i < k; i++)
       cin >> asks[i];

   for(int i = 0; i < k; i++)
   {
       search(a, asks[i], pfirst, psecond, n - 1);
       cout << first + 1 << " " << second + 1 <<"\n";
   }
    return 0;
}
