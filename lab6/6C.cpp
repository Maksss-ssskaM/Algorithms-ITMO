#include <iostream>
#include <string>

using namespace std;

int h(string str)
{
    long long int res = 0;
    for (int i = 0; i < str.length(); i++) {
        res = res * 123;
        res = res + str[i] - '0';
        res = res % 9040023;
    }
    res = res % 3333;

    return res;
}
struct map* last = nullptr;

struct map {
    string key = " ";
    string value = " ";
    struct map *p = nullptr;
    struct map *n = nullptr;
};

struct map arr[3333][1000];

struct map* search(string);
void delete_key(string);

void put(string key, string value)
{
    int i = h(key);
    auto p = search(key);

    if(p != nullptr)
    {
       p->value = value;
        return;
    }

    for(int j = 0; j < 1000; j++)
    {
        if (arr[i][j].key == " ")
        {
            arr[i][j].key = key;
            arr[i][j].value = value;

            if(last != nullptr) //если уже есть последний
            {
                last->n = &arr[i][j];
                arr[i][j].p = last;
                last = &arr[i][j];
            }
            else
                last = &arr[i][j];

            return;
        }

    }
}
void delete_key(string key)
{
    int i = h(key);

    for(int j = 0; j < 1000; j++)
    {

        if(arr[i][j].key == key)
        {
            arr[i][j].key = " ";
            arr[i][j].value = " ";


            if(last == &arr[i][j]) //удаляем последний элемент => след нету перемещаем ласт на пред если он есть
            {
                if(arr[i][j].p != nullptr)
                {
                    last = arr[i][j].p;
                }
                else
                    last = nullptr;
            }

            if(arr[i][j].p != nullptr)
            {
                if(arr[i][j].n != nullptr) //есть справа и слева, связываем их
                {
                    arr[i][j].p->n = arr[i][j].n;
                    arr[i][j].n->p = arr[i][j].p;
                }
                else//след нету, тогда пред даем нуль
                {
                    arr[i][j].p->n = nullptr;
                }

            }
            else if(arr[i][j].n != nullptr) //есть след но нету пред => зануляем пред у след
            {
                    arr[i][j].n->p = nullptr;
            }
            arr[i][j].n = nullptr;
            arr[i][j].p = nullptr;
        }
    }
}

struct map* search(string key)
{
    int i = h(key);
    for(int j = 0; j < 1000; j++)
    {
        if(arr[i][j].key == key)
        {
            return &arr[i][j];
        }
    }

    return nullptr;
}

string prev(string key)
{
        auto p = search(key);
        if(p != nullptr)
        {
            if(p->p != nullptr)
                return p->p->value;
        }

        return "none";
}
string next(string key)
{
    auto p = search(key);
    if(p != nullptr)
    {
        if(p->n != nullptr)
            return p->n->value;
    }

    return "none";
}

void show()
{
    auto p = last;
    while( p != nullptr)
    {
        cout << p->key << " " << p->value<< "|";
        p = p->p;
    }

}

int main() {


    freopen("linkedmap.in","r", stdin);
    freopen("linkedmap.out","w", stdout);


    string buf;
    string value;
    while(cin >> buf)
    {
        if(buf == "put")
        {
            cin >> buf;
            cin >> value;
            put(buf, value);
        }
        else if(buf[0] == 'd')
        {
            cin >> buf;
            delete_key(buf);
        }
        else if(buf[0] == 'g')
        {
            cin >> buf;
            auto u = search(buf);

            if(u == nullptr)
                cout << "none\n";
            else
                cout <<  u->value << "\n";
        }
        else if(buf == "prev")
        {
            cin >> buf;
            cout << prev(buf) << "\n";
        }
        else if(buf[0] == 'n')
        {
            cin >> buf;
            cout << next(buf) << "\n";
        }
    }

    return 0;
}
