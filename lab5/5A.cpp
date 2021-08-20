#include <iostream>
using namespace std;
int main() {
    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);
    int n;
    cin >> n;
    int max;
    int *left = new int [n];
    int *right = new int [n];
    int *arr1 = new int [n];
    int *arr2 = new int [n];
    for(int i = 0; i < n; i++)
    {
        arr1[i] = 0;
        arr2[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
      cin >> max;
      cin >> left[i];
      cin >> right[i];
    }
    arr1[0] = 1; arr2[0] = 1;

    for(int i = 0; i < n; i++)
    {
        if(left[i] != 0)
        {
            arr1[left[i]-1] = arr1[i] + 1;
            arr2[left[i]-1] = arr2[i] + 1;
        }
        if(right[i] != 0)
        {
            arr1[right[i]-1] = arr1[i] + 1;
            arr2[right[i]-1] = arr2[i] + 1;
        }
    }

    max = 0;
    for(int i = 0; i < n; i++)
        if(max < arr1[i])
            max = arr1[i];

    for(int i = 0; i < n; i++)
        if(max < arr2[i])
            max = arr2[i];

        cout << max;

    return 0;
}
