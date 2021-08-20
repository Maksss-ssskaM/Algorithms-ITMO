#include<vector>
#include <iostream>
using namespace std;

struct map {
    struct map* p;
    struct map* n;
    string key, val;
    map(string a, string b, map* last = nullptr) {
        key = a;
        val = b;
        p = last;
        n = nullptr;
    }
};

struct set
{
    vector<struct map*> arr_of_maps[101];
    struct map* last = nullptr;
    string key;
    int n;

    explicit set(string value) {
        n = 0;
        key = value;
    }

    int h(string str) {
        int res = 0;
        for (int i = 0; i < str.size(); ++i) {
            res *= 29;
            res += str[i] - 'a' + 1;
            res %= 9369319;
        }
        res = res % 101 + 101;
        return res % 101;
    }

    void connect(map* v1, map* v2) {
        if (v1)
            v1->n = v2;
        if (v2)
            v2->p = v1;
    }

    bool exists(string value) {
        for (auto &p : arr_of_maps[h(value)])
            if (p->key == value)
                return true;
        return false;
    }

    map* get(string value) {
        for (auto &p : arr_of_maps[h(value)])
            if (p->key == value)
                return p;
        return nullptr;
    }

    void put(string value, string x) {
        if (!exists(value)) {
            map* v2 = new map(value, x);
            connect(last, v2);
            last = v2;
            arr_of_maps[h(value)].push_back(last);
            n++;
        }
        else
        {
            for (auto &p : arr_of_maps[h(value)])
            if (p->key == value)
                p->val = x;
        }
    }

    void delete_from_set(string value)
    {
        auto &p = arr_of_maps[h(value)];
        for (int i = 0; i < (int)p.size(); ++i)
            if (p[i]->key == value) {
                if (p[i] == last)
                    last = p[i]->p;
                connect(p[i]->p, p[i]->n);
                delete p[i];
                p.erase(p.begin() + i);
                n--;
                return;
            }
    }
};


int h(string s) {
    int h = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        h *= 29;
        h += s[i] - 'a' + 1;
        h %= 9369319;
    }
    h = h % 1007 + 1007;
    return h % 1007;
}

vector<set*> a[1007];

bool exists(string key) {
    for (auto &p : a[h(key)])
        if (p->key == key)
            return true;
    return false;
}

set* get(string key) {
    for (auto &p : a[h(key)])
        if (p->key == key)
            return p;
    return nullptr;
}

void put(string key, string value) {
    if (!exists(key))
        a[h(key)].push_back(new set(key));
    get(key)->put(value, "");
}

void delete_all(string key)
{
    auto &p = a[h(key)];
    for (int i = 0; i < (int)p.size(); ++i)
        if (p[i]->key == key)
        {
            delete p[i];
            p.erase(p.begin() + i);
            return;
        }
}

void delete_key(string v, string s) {
    set* p = get(v);

    if (!p)
        return;

    p->delete_from_set(s);
}

void show(set* v)
{
    struct map* p = v->last;

    cout << v->n << " ";

    while (p)
    {
        cout << p->key << " ";
        p = p->p;
    }

    cout << "\n";
}

int main() {

    freopen("multimap.in", "r", stdin),
    freopen("multimap.out", "w", stdout);

    ios_base::sync_with_stdio(0),
    cin.tie(0),
    cout.tie(0);
    
    string buf, value;
    while (cin >> buf)
    {
        if (buf == "put")
        {
            cin >> buf;
            cin >> value;
            put(buf, value);
        }
        else if (buf == "delete")
        {
            cin >> buf;
            cin >> value;
            delete_key(buf, value);
        } else if (buf[0] == 'g')
        {
            cin >> value;
            if (get(value))
                show(get(value));
            else
                cout << "0\n";
        } else if (buf == "deleteall")
        {
            cin >> buf;
            delete_all(buf);
        }
    }

    return 0;
}