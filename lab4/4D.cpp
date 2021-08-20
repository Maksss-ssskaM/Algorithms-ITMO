#include <iostream>
#include<string>
using namespace std;
int i = 0;
void push(long long int *a,long long int x)
{
    a[i] = x;
    i++;
}
long long int pop(long long int *a)
{
    int buf = a[i-1];
    i--;
    return buf;
}


int main()
{
    freopen("postfix.in", "r", stdin);
    freopen("postfix.out", "w", stdout);
    
    string str;
    long long int stack[100];
    getline(cin, str);

    for(int j = 0; j < str.size(); j++)
    {
        if(str[j] - '0' <= 9 && str[j] - '0' >= 0)
            push(stack, str[j] - '0');

        else if(str[j] == '*' || str[j] == '+' || str[j] == '-')
        {
           long long int first = pop(stack);
           long long int second = pop(stack);

            if(str[j] == '+')
                push(stack, first + second);
            else if(str[j] == '-')
                push(stack, - first + second);
            else if(str[j] == '*')
                push(stack, first * second);
        }
    }

    cout << pop(stack);


    return 0;
}
