#include <iostream>
using namespace std;

struct node
{
    int value;
    node* left;
    node* right;
    int height;
    int index_for_out;
    int index_of_right;
    int index_of_left;

    node()
    {
        left = nullptr;
        right = nullptr;
        height = 1;
        index_of_left = 0;
        index_of_right = 0;
    }
};

node *root = nullptr;
node *array = nullptr;
node *out = nullptr;

int k = 0;
void preorder_walk(node* p)
{
    if(p == nullptr)
        return;
    out[k] = *p;
    k++;
    p->index_for_out = k;

    if(p->left != nullptr)
        preorder_walk(p->left);
    if(p->right != nullptr)
        preorder_walk(p->right);
}



void show()
{
    cout << k << "\n";

    for (int i = 0; i < k; i++)
    {
        cout << out[i].value << " ";
        if(out[i].left != nullptr)
            cout << out[i].left->index_for_out << " ";
        else
            cout << 0 << " ";

        if(out[i].right != nullptr)
            cout << out[i].right->index_for_out << "\n";
        else
            cout << 0 << "\n";
    }
}

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
    return getheight(p->right) - getheight(p->left);
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
    else {
        node* l = p->left;
        node* r = p->right;
        if (!l) {
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
int main()
{
    freopen("deletion.in", "r", stdin);
    freopen("deletion.out", "w", stdout);
    int n;

    cin >> n;

    array = new node[n];
    out = new node[n];
    root = &array[0];
    for(int i = 0; i < n; i++)
    {
        cin >> array[i].value >> array[i].index_of_left >> array[i].index_of_right;
    }

    for(int i = 0; i < n; i++) //связывание узлов указателями
    {
        if(array[i].index_of_left != 0)
        {
            array[i].left = &array[array[i].index_of_left - 1];
        }
        else
            array[i].left = nullptr;
        if(array[i].index_of_right != 0)
        {
            array[i].right = &array[array[i].index_of_right - 1];
        }
        else
            array[i].right = nullptr;
    }

    int x;
    cin >> x;

    setheight(root);
    root = remove(root, x);

    preorder_walk(root);

    show();

    return 0;
}