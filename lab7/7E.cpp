#include <iostream>
#include <string>
using namespace std;

struct node
{
    int value;
    node* left;
    node* right;
    int height;

    node(int x)
    {
        left = nullptr;
        right = nullptr;
        height = 1;
        value = x;
    }
};

node *root = nullptr;

int setheight(node* p)
{
    int a = 1, b = 1;
    if (p->left != nullptr)
        a = setheight(p->left) + 1;
    if (p->right != nullptr)
        b = setheight(p->right) + 1;

    p->height = max(a, b);

    return p->height;
}


int getheight(node* p)
{
    return p ? p->height : 0;
}

int diff(node* p)
{
    return p ?getheight(p->right) - getheight(p->left): 0;
}

void fixheight(node* p)
{
    int l = getheight(p->left);
    int r = getheight(p->right);
    p->height = (l > r ? l : r) + 1;
}

node* rotateright(node* p) {
    node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

node* rotateleft(node* q) {
    node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

node* balance(node* p) {
    fixheight(p);
    if (diff(p) == 2)
    {
        if (diff(p->right) < 0)
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if (diff(p) == -2)
    {
        if (diff(p->left) > 0)
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p;
}

node* insert(node* p, int x)
{
    if(p == nullptr)
    {
        return new node(x);
    }
    if(x < p->value)
        p->left = insert(p->left,x);

    else if(x > p->value)
        p->right = insert(p->right,x);
    else
        return p;


    return balance(p);
}
node* removeMin(node* p) {
    if (!p)
        return nullptr;
    if (!p->right)
        return p->left;
    p->right = removeMin(p->right);
    return balance(p);
}

node* remove(node* p, int x) {
    if (!p)
        return nullptr;
    if (p->value > x) {
        p->left = remove(p->left, x);
    }
    else if (p->value < x) {
        p->right = remove(p->right, x);
    }
    else
        {
        node* l = p->left;
        node* r = p->right;
        if (!l)
        {
            return r;
        }
        node* a = l;
        while (a->right) a = a->right;
        a->left = removeMin(l);
        a->right = r;
        return balance(a);
        }
    return balance(p);
}

node* search(int x)
{
    auto p = root;

    while(p != nullptr)
    {
        if(x > p->value)
            p = p->right;
        else if(x < p->value)
            p = p->left;
        else
            return p;
    }
    return nullptr;
}


int main()
{
    freopen("avlset.in", "r", stdin);
    freopen("avlset.out", "w", stdout);
    int n;
    string buf;
    cin >> n;


    while(cin >> buf)
    {
        if(buf == "A") //вставка
        {
            cin >> n;
            root = insert(root, n);
            cout << diff(root) << "\n";
        }
        else if(buf == "C")//поиск
        {
            cin >> n;
            auto p = search(n);
            if(p)
                cout << "Y\n";
            else
                cout << "N\n";
        }
        else if(buf == "D")//удаление
        {
            cin >> n;
            root = remove(root, n);
            cout << diff(root) << "\n";
        }

    }




    return 0;
}