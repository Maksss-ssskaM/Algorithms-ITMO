#include <iostream>
#include <string>

using namespace std;

int k = 10000;

int h(int x)
{
    return abs(x) % k;
}

struct e
{
    int v;
    struct e *n = nullptr;
};

struct e *head = new struct e[k];
int search(int);
void insert_list(int phead, int x)
{
    if(search(x) == 1)
        return;
    struct e* p = &head[phead];

    while(p->n != nullptr)
    {

        p = p->n;

    }
    struct e *b = new struct e;
    b->v = x;
    p->n = b;
}
void delete_list(int phead, int x)
{
    auto p = &head[phead];

    while(p->n != nullptr)
    {
        if(p->n->v == x)
        {

            if (p->n->n == nullptr)
            {
                delete p->n;
                p->n = nullptr;
            } else {
                auto h = p->n->n;
                delete p->n;
                p->n = h;
            }
            return;
        }
        p = p->n;
    }
}

int search_list(int phead, int x)
{
    auto p = &head[phead];

    while(p != nullptr)
    {
        if(p->v == x)
            return 1;
        p = p->n;
    }
    return 0;
}

void insert(int x)
{
    insert_list(h(x), x);
}

void delete_hash(int x)
{
    delete_list(h(x), x);
}

int search(int x) {
    return search_list(h(x), x);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("set.in","r", stdin);
    freopen("set.out","w", stdout);

    string buf;

    int x;

    while(cin >> buf)
    {
        if(buf[0] == 'i')
        {

            cin >> x;
            insert(x);
        }
        else if(buf[0] == 'd')
        {
            cin >> x;
            delete_hash(x);
        }
        else if(buf[0] == 'e')
        {
            cin >> x;
            if(search(x) == 1)
                cout << "true\n";
            else
                cout << "false\n";
        }
    }

    return 0;
}
