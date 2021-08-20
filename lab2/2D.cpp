#include<iostream>

using namespace std;

void antiquicksort(int* arr, int n)
{
    for (int i = 0; i < n; i++)
        swap(arr[i], arr[i / 2]);

}

int main()
{
    freopen("antiqs.in", "r", stdin);
    freopen("antiqs.out", "w", stdout);

	int n;
	cin >> n;
	int* arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = i +1;
    antiquicksort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;

}
