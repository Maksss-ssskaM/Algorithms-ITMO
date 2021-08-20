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

void fixheight(node* p)
{
    int a = 0, b = 0;
    if(p->left != nullptr)
        a = p->left->height;
    if(p->right != nullptr)
        b = p->right->height;

    p->height = max(a, b) + 1;
}

node* smallrotateright(node *p)
{
    node* q = p->left;

    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

node* smallrotateleft(node *p)
{

    node* q = p->right;

    p->right = q->left;
    q->left = p;
    fixheight(p);
    fixheight(q);
    return q;
}



int getheight(node* p)
{
    return p? p->height : 0;
}

node* balance(node* p) // балансировка узла p
{
    fixheight(p);
    if(getheight(p->left) - getheight(p->right) == 2) // право
    {
        if (getheight(p->left->left) - getheight(p->left->right) > 0)//малый поворот
        {
            p = smallrotateright(p);

        }
        else //большой поворот
        {
            p->left = smallrotateleft(p->left);
            p = smallrotateright(p);

        }
    }
    else if(getheight(p->left) - getheight(p->right) == -2)// лево
    {

        if (getheight(p->right->left) - getheight(p->right->right) < 0)//малый поворот
        {
            p = smallrotateleft(p);
        }
        else //большой поворот
        {
            p->right = smallrotateright(p->right);
            p = smallrotateleft(p);
        }

    }
    return p;
}

node* insert(node* p, int x, int n)
{
    if(p == nullptr)
    {
        array[n].value = x;

        return &array[n];
    }
    if(x < p->value)
        p->left = insert(p->left,x, n);

    else if(x > p->value)
        p->right = insert(p->right,x, n);


    return balance(p);
}

int main()
{
    freopen("addition.in", "r", stdin);
    freopen("addition.out", "w", stdout);
    int n;

    cin >> n;
    if(n == 0)
    {
        cin >> n;
        cout << 1 << endl << n << " " << 0 << " " << 0;
        return 0;
    }
    array = new node[n + 1];
    out = new node[n + 1];
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
    root = insert(root, x, n);

    preorder_walk(root);
    show();

    return 0;
}
