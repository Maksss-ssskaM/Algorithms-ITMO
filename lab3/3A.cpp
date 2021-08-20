#include<iostream>
using namespace std;
bool istrue = true;

void heapify(int* a, int i, int n)
{
	int l;
	int r;
	
		l = 2 * i + 1;
		r = 2 * i + 2;
	
	int max = i;

	if (l <= n && a[l] < a[i])
	{
		max = l;
		istrue = false;
	}
	

	if (r <= n && a[r] < a[max])
	{
		max = r;
		istrue = false;
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

int main()
{
	freopen("isheap.in", "r", stdin);
	freopen("isheap.out", "w", stdout);


	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	heap(a, n - 1);

	if (istrue == false)
		cout << "NO";
	else
		cout << "YES";

	return 0;
}