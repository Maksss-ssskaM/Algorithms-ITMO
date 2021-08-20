#include<iostream>
using namespace std;


void heapify(int* a, int i, int n)
{
	int l;
	int r;
	l = 2 * i + 1;
	r = 2 * i + 2;

	int max = i;

	if (l <= n && a[l] > a[i])
	{
		max = l;		
	}


	if (r <= n && a[r] > a[max])
	{
		max = r;		
	}

	if (max != i)
	{
		swap(a[i], a[max]);
		heapify(a, max, n);
	}
}

void heap(int* a, int n)
{
	for (int i = n / 2; i > -1; i--)
		heapify(a, i, n);
}

void heapsort(int* a, int n)
{
	heap(a, n);
	int size = n;

	for (int i = n; i > -1; i--)
	{
		swap(a[i], a[0]);
		size--;
		heapify(a, 0, size);
	}
}

int main()
{
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);


	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	heapsort(a, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}