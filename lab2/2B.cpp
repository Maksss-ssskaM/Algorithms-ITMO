#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include<string>
using namespace std;

struct par
{
    string country;
    string name;
};


void msort(par* arr, int b, int q, int n)
{
    int n1 = q - b + 1;
    int n2 = n - q;

    string* A = new string[n1];
    

    string* A1 = new string [n1];
    

    string* B1 = new string[n2];
   

    string* B = new string[n2];
   

    for (int i = 0; i < n1; i++)
       A[i]=arr[i+b].country;
      

    for (int i = 0; i < n1; i++)
        A1[i] = arr[i + b].name;

    for (int i = 0; i < n2; i++)
        B1[i] = arr[i + q + 1].name;

    for (int i = 0; i < n2; i++)
        B[i] = arr[i + q + 1].country;

    int i = 0;
    int j = 0;
    int k = b;
    while (k <= n && i < n1 && j < n2)
    {

        if (A[i]<= B[j])
        {
            arr[k].country= A[i];
            arr[k].name = A1[i];
            i++;
        }
        else
        {
            arr[k].country= B[j];
            arr[k].name = B1[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k].country = A[i];
        arr[k].name = A1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k].country = B[j];
        arr[k].name = B1[j];
        j++;
        k++;
    }

}

void merge(par* arr, int b, int n)

{
    if (b < n)
    {
        merge(arr, b, (b + n) / 2);
        merge(arr,(b + n) / 2 + 1, n);
        msort(arr, b, (b + n) / 2, n);
    }
}

int main()
{
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    int n;
    cin >> n;
    par* arr = new par[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i].country >> arr[i].name;

    merge(arr,0, n - 1);

    cout << "=== " << arr[0].country << " ===\n";
    cout << arr[0].name << "\n";
    for (int i = 1; i < n; i++)
    {
        if (arr[i].country == arr[i-1].country)
            cout << arr[i].name << "\n";
        else
            cout << "=== " << arr[i].country << " ===\n" << arr[i].name << "\n";
    }

    return 0;
}