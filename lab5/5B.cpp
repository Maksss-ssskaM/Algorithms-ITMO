#include <iostream>
using namespace std;
int j = 0;

void push(int* a, int x)
{
    a[j] = x;
    j++;
}

void inorder_tree_walk(int* v, int* l, int* r, int* res, int i)
{
    if (l[i] != 0)
        inorder_tree_walk(v, l, r, res, l[i] - 1);

    push(res, v[i]);

    if (r[i] != 0)
        inorder_tree_walk(v, l, r, res, r[i] - 1);
}


int main() {
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);

    int n;
    cin >> n;
    if (n == 0)
    {
        cout << "YES";
        return 0;
    }
    int* value = new int[n];
    int* left = new int[n];
    int* right = new int[n];
    int* res = new int[n];

    bool is_correct = true;

    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
        cin >> left[i];
        cin >> right[i];
    }
    inorder_tree_walk(value, left, right, res, 0);

    for (int i = 0; i < n - 1; i++)
        if (res[i] >= res[i + 1])
            is_correct = false;

    cout << (is_correct ? "YES" : "NO");

    return 0;
}
