#include <iostream>
#include <string>

using namespace std;

struct q *head = nullptr;
struct q *tail = nullptr;
int a[26];

struct q {
    int v;
    struct q *n;
};



struct q* put(int x) {
    if (head == nullptr) {
        head = new struct q;
        head->v = x;
        head->n = nullptr;
        tail = head;
        return head;
    }
    struct q *b = new struct q;
    tail->n = b;
    b->v = x;
    b->n = nullptr;
    tail = b;
    return b;
}



int get()
{
    auto x = *head;
    delete head;
    head = x.n;
    return x.v;
}

bool is_digit(string str) {
    int x = str.size();
    for (int i = 0; i < x; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}


int main() {

    freopen("quack.in", "r", stdin);
    freopen("quack.out", "w", stdout);
    int n = 0;
    int x;
    int y;
    string input[100100];
    string l[100100] = {" "};

    while (cin >> input[n]) {
        n++;
    }
    for (int i = 0; i < n; i++) {
        if (input[i][0] == ':') {
            string b = input[i];
            b.erase(b.begin());
            l[i] = b;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (is_digit(input[i]))
        {
            put(stoll(input[i]) & 65535);
        }
        else if (input[i][0] == '+')
        {
            x = get();
            y = get();
            put((x + y) & 65535);
        } else if (input[i][0] == '-')
        {
            x = get();
            y = get();
            put((x - y) & 65535);
        } else if (input[i][0] == '*')
        {
            x = get();
            y = get();
            put((x * y) & 65535);
        }
        else if (input[i][0] == '/')
        {
            x = get();
            y = get();
            if (y == 0)
                put(0);
            else
                put((x / y) & 65535);
        } else if (input[i][0] == '%') {
            x = get();
            y = get();
            if (y == 0)
                put(0);
            else
                put((x % y) & 65535);
        }
        else if (input[i][0] == '>')
        {
            a[int(input[i][1] - 'a')] = get();
        }
        else if (input[i][0] == '<')
        {
            put(a[int(input[i][1] - 'a')]);
        }
        else if (input[i] == "P")
        {
            cout << get() << "\n";
        }
        else if (input[i][0] == 'P')
        {
            cout << a[int(input[i][1] - 'a')] << "\n";
        }
        else if (input[i] == "C")
        {

            printf("%c",get() & 255);
        }
        else if (input[i][0] == 'C')
        {

            printf("%c", a[int(input[i][1] - 'a')] & 255);
        }
        else if (input[i][0] == 'Q')
        {
            return 0;
        }
        else if (input[i][0] == 'J')
        {
            string b = input[i];
            b.erase(b.begin());
            for (int j = 0; j < n; j++)
            {
                if (l[j] == b)
                {
                    i = j;
                }
            }
        }
        else if (input[i][0] == 'Z')
        {
            if (a[int(input[i][1] - 'a')] == 0)
            {
                string b = input[i];
                b.erase(b.begin());
                b.erase(b.begin());
                for (int j = 0; j < n; j++)
                {
                    if (l[j] == b)
                    {
                        i = j;
                    }
                }
            }
        } else if (input[i][0] == 'E')
        {
            if (a[int(input[i][1] - 'a')] == a[int(input[i][2] - 'a')])
            {
                string b = input[i];
                b.erase(b.begin());
                b.erase(b.begin());
                b.erase(b.begin());
                for (int j = 0; j < n; j++) {
                    if (l[j] == b) {
                        i = j;
                    }
                }
            }
        }
        else if (input[i][0] == 'G')
        {
            if (a[int(input[i][1] - 'a')] > a[int(input[i][2] - 'a')]) {
                string b = input[i];
                b.erase(b.begin());
                b.erase(b.begin());
                b.erase(b.begin());
                for (int j = 0; j < n; j++) {
                    if (l[j] == b) {
                        i = j;
                    }
                }
            }
        }
    }

    return 0;
}
