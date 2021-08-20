#include <iostream>
#include <string>

using namespace std;

int j = 0;
int root = 0;
int g = 0;
int v[110];
int l[110] = {0};
int r[110] = {0};
int p[110] = {0};

int search(int x) {
    if(j == 0)
        return -1;

    for (int i = root;;)
    {
        if (v[i] < x)
        {
            if (r[i] == 0)
                return -1;
            i = r[i] - 1;
        }
        else if (x < v[i])
        {
            if (l[i] == 0)
                return -1;
            i = l[i] - 1;
        }
        else
            return i;
    }
}

void insert(int x) {
    if (j == 0) {
        j++;
        g++;
        v[root] = x;
        return;
    }

    for (int i = root;;) {
        if (v[i] < x) {
            if (r[i] == 0) {
                v[g] = x;
                r[i] = g + 1;
                p[g] = i + 1;
                j++;
                g++;
            } else {
                i = r[i] - 1;
            }

        } else if (x < v[i]) {
            if (l[i] == 0) {
                v[g] = x;
                l[i] = g + 1;
                p[g] = i + 1;
                j++;
                g++;
            } else {
                i = l[i] - 1;
            }
        } else
            return;
    }

}

int next(int x) {
    if(j == 0)
        return -1;
    int s = -1;
    for (int i = root;;) {
        if (v[i] > x) {
            s = i;
            if (l[i] == 0)
                return s;
            i = l[i] - 1;
        } else {
            if (r[i] == 0)
                return s;
            i = r[i] - 1;
        }
    }
}

int prev(int x) {
    if(j == 0)
        return -1;
    int s = -1;
    for (int i = root;;) {
        if (v[i] < x) {
            s = i;
            if (r[i] == 0)
                return s;
            i = r[i] - 1;
        } else {
            if (l[i] == 0)
                return s;
            i = l[i] - 1;
        }
    }
}

void delete_member(int x) {
    int k = search(x);
    if (k == -1)
        return;
    j--;
    if (l[k] == 0 && r[k] == 0) {
        if (l[p[k] - 1] - 1 == k) {
            l[p[k] - 1] = 0;
        } else
            r[p[k] - 1] = 0;
    } else if (l[k] == 0 || r[k] == 0) {
        if (l[p[k] - 1] - 1 == k) //слева от родителя
        {
            if (l[k] == 0) //правый ребенок
            {
                if (k == root)
                    root = r[k] - 1;
                l[p[k] - 1] = r[k];
                p[r[k] - 1] = p[k];
            } else //левый ребенок
            {
                if (k == root)
                    root = l[k] - 1;
                l[p[k] - 1] = l[k];
                p[l[k] - 1] = p[k];
            }
        } else //справа от родителя
        {
            if (l[k] == 0) //правый ребенок
            {
                if (k == root)
                    root = r[k] - 1;
                r[p[k] - 1] = r[k];
                p[r[k] - 1] = p[k];
            } else // левый ребенок
            {
                if (k == root)
                    root = l[k] - 1;
                r[p[k] - 1] = l[k];
                p[l[k] - 1] = p[k];
            }
        }
    } else //два ребенка
    {

        int n = next(x);
        int b = v[n];
        delete_member(v[n]);
        j++;
        v[k] = b;
    }
}

int main() {
    string buf;
    freopen("bstsimple.in", "r", stdin);
	freopen("bstsimple.out", "w", stdout);
    int x;
    while (cin >> buf) {
        if (buf[0] == 'i') {
            cin >> x;
            insert(x);
        } else if (buf[0] == 'd') {
            cin >> x;
            delete_member(x);
        } else if (buf[0] == 'e') {
            cin >> x;
            int b = search(x);
            if (b == -1)
                cout << "false" << "\n";
            else
                cout << "true" << "\n";

        } else if (buf[0] == 'n') {
            cin >> x;
            auto b = next(x);

            if (b != -1)
                cout << v[b] << "\n";
            else
                cout << "none" << "\n";

        } else if (buf[0] == 'p') {
            cin >> x;
            auto b = prev(x);

            if (b != -1)
                cout << v[b] << "\n";
            else
                cout << "none" << "\n";
        }

    }
    return 0;

}
