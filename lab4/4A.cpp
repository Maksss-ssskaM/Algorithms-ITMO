#include <iostream>
using namespace std;

int i = 0;
void push(int *a, int x)
{
    a[i] = x;
    i++;
}

int remove(int* a)
{
    int buf = a[i-1];
    i--;
    return buf;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("stack.in", "r", stdin);
    freopen("stack.out", "w", stdout);
    int n;
    cin >> n;
    int a[1000000];
    char buf;

    for(int j = 0; j < n; j++)
    {
        cin >> buf;
        if(buf == '+')
        {
            int x;
            cin >> x;
            push(a,x);
        }
        else if(buf == '-')
            cout << remove(a) << "\n";
    }
    return 0;
}
