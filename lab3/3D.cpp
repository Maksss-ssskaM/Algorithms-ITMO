#include<iostream>
#include<string>
#include<fstream>
#include<vector>
int a[1000000];
int in[1000000];

int n = 0;

using namespace std;

void heapify(int i, int n)
{
    int l;
    int r;
    l = 2 * i + 1;
    r = 2 * i + 2;

    int max = i;

    if (l <= n && a[l] < a[i])
    {
        max = l;
    }


    if (r <= n && a[r] < a[max])
    {
        max = r;
    }

    if (max != i)
    {
        swap(a[i], a[max]);
        swap(in[i], in[max]);
        heapify(max, n);
    }
}

void heap(int n)
{
    for (int i = n / 2; i > -1; i--)
        heapify(i, n);
}



void push(int x, int i)
{
    n++;
 
    a[n - 1] = x;
    in[n - 1] = i;
}

int extract_min()
{ 
   
    int buf = a[0];
    int b = 0;
    int bufi = in[0];

    for(int i = 0; i < n; i++)
        if (buf > a[i])
        {
            buf = a[i];
            b = i;
        }
    for (int i = 0; i < n; i++)
        if (a[i] == buf)
        {
            if (in[i] > in[b])
                b = i;
        }

    swap(a[b], a[n - 1]);
    swap(in[b], in[n - 1]);
    n--;
    return buf;
}

void decrease(int x, int y)
{
   
    for (int i = 0; i < n; i++)
    {
        if (in[i] == x)
        {
            a[i] = y;
           
        }
   }

    
}

int main()
{
     freopen("priorityqueue.in", "r", stdin);
     freopen("priorityqueue.out", "w", stdout);

    string buf;
    int j = 1;

    while (cin >> buf)
    {
        
        if (buf == "push")
        {
            int buffer;
            cin >> buffer;
            push(buffer, j);

          
        }
        else if (buf == "extract-min")
        {

            if (n == 0)
                cout << '*' << "\n";
            else
                cout << extract_min() << "\n";
        }
        else if (buf == "decrease-key")
        {
            int cur;
            int value;

            cin >> cur >> value;
          
            decrease(cur, value);

        }
        j++;
    }
    

    return 0;
}