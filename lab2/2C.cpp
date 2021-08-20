#include<iostream>
using namespace std;
long long int c = 0;
void msort(int* arr, int b, int q, int n)
{
    int n1 = q - b + 1;
    int n2 = n - q;

    int* A = new int[n1];
    int* B = new int[n2];

    for (int i = 0; i < n1; i++)
        A[i] = arr[i + b];

    for (int i = 0; i < n2; i++)
        B[i] = arr[i + q + 1];
    int i = 0;
    int j = 0;
    int k = b;
    while (k <= n && i < n1 && j < n2)
    {

        if (A[i] <= B[j])
        {
            arr[k] = A[i];
            i++;
           
        }
        else
        {
            arr[k] = B[j];
            j++;
            c = c+ n1 - i;
        }
        k++;
    }

    while (i < n1)
    {
       
        arr[k] = A[i];
        i++;
        k++;
    }

    while (j < n2)
    {

        arr[k] = B[j];
        j++;
        k++;
    }

}

void merge(int* arr, int b, int n)

{
    if (b < n)
    {
        merge(arr, b, (b + n) / 2);
        merge(arr, (b + n) / 2 + 1, n);
        msort(arr, b, (b + n) / 2, n);
    }
}

int main()
{
    freopen("inversions.in", "r", stdin);
    freopen("inversions.out", "w", stdout);

    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];
 
    merge(arr, 0, n - 1);
    cout << c;
   
    return 0;
}