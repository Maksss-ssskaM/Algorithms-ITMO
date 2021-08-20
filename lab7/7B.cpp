#include<iostream>

using namespace std;
int v[200000];
int l[200000];
int r[200000];
int out[200000];
int outr[200000];
int outl[200000];
pair <int, int> h[200000];
int root = 0;

int balance(int i)
{
	if (l[i] != 0)
		h[i].first = balance(l[i] - 1) + 1;
	if (r[i] != 0)
		h[i].second = balance(r[i] - 1) + 1;

	return h[i].first > h[i].second ? h[i].first : h[i].second;
}

void smallrotateleft(int i)
{
	int buf = r[i];
	r[i] = l[r[i] - 1];
	l[buf - 1] = i + 1;
}

void smallrotateright(int i)
{
	int buf = l[i];
	l[i] = r[l[i] - 1];
	r[buf - 1] = i + 1;

}

void megarotateleft(int i)
{
	int buf = l[r[i] - 1];
	smallrotateright(r[i] - 1);
	r[i] = buf;
	smallrotateleft(i);
}
int j = 0;
void preorder_tree_walk(int i)
{
	out[j] = v[i];
	outr[j] = r[i];
	outl[j] = l[i];
	j++;

	if (l[i] != 0)
		preorder_tree_walk(l[i] - 1);

	if (r[i] != 0)
		preorder_tree_walk(r[i] - 1);
}

int find(int x, int n, int k)
{
	for (int i = k; i < n; i++)
	{
		if (out[i] == x)
			return i + 1;
	}
}

void show(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << out[i] << " ";
		if (outl[i] == 0)
			cout << 0 << " ";
		else
			cout << find(v[outl[i] - 1], n, i) << " ";
		if (outr[i] == 0)
			cout << 0 << "\n";
		else
			cout << find(v[outr[i] - 1], n, i) << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("rotation.in", "r", stdin);
	freopen("rotation.out", "w", stdout);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i] >> l[i] >> r[i];
	}

	balance(0);

	if ((h[r[0] - 1].second - h[r[0] - 1].first == 1) || (h[r[0] - 1].second - h[r[0] - 1].first == 0)) //малый левый поворот
	{
		root = r[0] - 1;
		smallrotateleft(0);
	}
	else if(h[r[0] - 1].second - h[r[0] - 1].first == -1)// большой левый мегаповорит
	{
		root = l[r[0] - 1] - 1;
		megarotateleft(0);
	}

	preorder_tree_walk(root);
	cout << n << "\n";
	show(n);

	return 0;
}
