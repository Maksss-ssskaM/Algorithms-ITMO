#include <iostream>
#include <string>
using namespace std;

int tail = 0;

void push(char *a, char x)
{
    a[tail] = x;
    tail++;
}

char remove(char* a)
{
    char buf = a[tail - 1];
    tail--;
    return buf;
}
bool isCorrect(string str)
{
    char stack[100010];

    //if((str[0] == ']') || (str[0] == ')'))
      //  return false;

    for(int i = 0; i < str.size(); i++)
    {
        if((str[i] == '(') || (str[i] == '['))
            push(stack, str[i]);
        else
        {   if(tail == 0)
                return false;
            else
            {
            char buf = remove(stack);
            if(buf == '(')
            {
                if(str[i] == ']')
                {
                    tail = 0;
                    return false;
                }
            }
            else
            {
                if(str[i] == ')')
                {
                    tail = 0;
                    return false;
                }
            }
            }
        }
    }


    if(tail == 0)
        return true;
    else
    {
        tail = 0;
        return false;
    }
}


int main() {
   ios_base::sync_with_stdio(false); cin.tie(NULL);
   freopen("brackets.in", "r", stdin);
   freopen("brackets.out", "w", stdout);
    string buf;

   while(cin >> buf)
   {
        if(isCorrect(buf))
            cout << "YES\n";
        else
            cout << "NO\n";
        tail = 0;
    }

    return 0;
}