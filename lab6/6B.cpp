#include <iostream>
#include <string>
#include<vector>
using namespace std;

int h(string str)
{
    int res = 0;
    for (int i = 0; i < str.length(); i++) {
        res = res * 123;
        res = res + str[i] - '0';
        res = res % 9040023;
    }
    res = res % 33333;

    return res;
}

struct map {
    string key = " ";
    string value = " ";
};
struct map arr[33333][100];

struct map* search(string);

void put(string key, string value)
{
       int i = h(key);
       auto p = search(key);

       if(p != nullptr)
       {
           p->value = value;
       }

    for(int j = 0; j < 100; j++)
    {
        if (arr[i][j].key == " ")
        {
            arr[i][j].key = key;
            arr[i][j].value = value;
            return;
        }
    }

}
void delete_key(string key)
{
    int i = h(key);
    for(int j = 0; j < 100; j++)
    {
       if(arr[i][j].key == key)
       {
           arr[i][j].key = " ";
       }
    }
}

struct map* search(string key)
{
    int i = h(key);
    for(int j = 0; j < 100; j++)
    {
        if(arr[i][j].key == key)
        {

            return &arr[i][j];
        }
    }

    return nullptr;
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("map.in","r", stdin);
    freopen("map.out","w", stdout);

    string buf;
    string value;
    while(cin >> buf)
    {
        if(buf[0] == 'p')
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
    }

    return 0;
}