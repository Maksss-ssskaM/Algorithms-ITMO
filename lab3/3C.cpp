#include<iostream>
#include<string>

using namespace std;

void digitsort(string* a,string *c, int n, int m, int g)
{
	int b[26] = { 0 };

	for (int i = 0; i < n; i++)
	{
		b[int(a[i][g]) - int('a')]++;
	}

	for (int i = 1; i < 26; i++)
		b[i] = b[i] + b[i - 1];
	

	
	for (int i = n-1; i > -1; i--)
	{
		c[b[int(a[i][g]) - int('a')]-1] = a[i];
		b[int(a[i][g]) - int('a')]--;
	}

}

int main()
{
	int n;
	int k;
	int m;

	freopen("radixsort.in", "r", stdin);
	freopen("radixsort.out", "w", stdout);

	cin >> n >> m >> k;

	string* a = new string[n];
	string* b = new string[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < k; i++)
	{
		digitsort(a, b, n, m, m - i - 1);
		for (int i = 0; i < n; i++)
			a[i] = b[i];
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << "\n";

	
	return 0;
}