#include <iostream>
using namespace std;

struct node
{
    int value;
    struct node* left = nullptr;
    struct node* right = nullptr;
    struct node* parent = nullptr;
    int height_of_left = 0;
    int height_of_right = 0;

    int index_for_out;

    int index_of_right = 0;
    int index_of_left = 0;
};

node *root = nullptr;
node *array = nullptr;
node *out = nullptr;

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int height(node* p)
{
        if (p->left != nullptr)
            p->height_of_left = height(p->left) + 1;
        if (p->right != nullptr)
            p->height_of_right= height(p->right) + 1;

        return max(p->height_of_left, p->height_of_right);
}

void insert(int x, int n)
{
    auto p = root;

    while(p != nullptr)
    {
        if(x > p->value)
        {
            if(p->right == nullptr)
            {
                array[n].value = x;
                array[n].parent = p;
                p->right = &array[n];
            }
            else
            {
                p = p->right;
            }
        }
        else if(x < p->value)
        {
            if(p->left == nullptr)
            {
                array[n].value = x;
                array[n].parent = p;
                p->left = &array[n];
            }
            else
            {
                p = p->left;
            }
        }
        else
            return;
    }

}
int k = 0;
void preorder_walk(node* p)
{
    out[k] = *p;
    k++;
    p->index_for_out = k;

    if(p->left != nullptr)
        preorder_walk(p->left);
    if(p->right != nullptr)
        preorder_walk(p->right);
}

void smallrotateright(node *p)
{
    node* q = p->left;
    if(p->parent == nullptr)
    {
        root = q;
        q->parent = nullptr;
    }
    else
    {
        if(p->parent->left == p)
        {
            p->parent->left = q;
            q->parent = p->parent;
        }
        else
        {
            p->parent->right = q;
            q->parent = p->parent;
        }
    }
    p->left = q->right;
    q->right = p;
    p->parent = q;
}

void smallrotateleft(node *p)
{
    node* q = p->right;
    if(p->parent == nullptr)
    {
        root = q;
        q->parent = nullptr;
    }
    else
    {
        if(p->parent->left == p)
        {
            p->parent->left = q;
            q->parent = p->parent;
        }
        else
        {
            p->parent->right = q;
            q->parent = p->parent;
        }
    }
    p->right = q->left;
    q->left = p;
    p->parent = q;
}

void bigrotateright(node *p)
{
    smallrotateleft(p->left);
    smallrotateright(p);
}

void bigrotateleft(node *p)
{
    smallrotateright(p->right);
    smallrotateleft(p);
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


int main()
{
   freopen("balance.in", "r", stdin);
   freopen("balance.out", "w", stdout);

   int n;
   cin >> n;
   array = new node[n + 1];
   out = new node[n + 1];
   root = array;
   if(n != 0)
       cin >> root->value >> root->index_of_left >> root->index_of_right;
   else
   {
       cin >> n;
       cout << 1 << "\n" << n << " " << 0 << " " << 0;
       return 0;
   }

    for(int i = 1; i < n; i++)
    {
        cin >> array[i].value >> array[i].index_of_left >> array[i].index_of_right;
    }

    for(int i = 0; i < n; i++) //связывание узлов указателями
    {
        if(array[i].index_of_left != 0)
        {
            array[i].left = &array[array[i].index_of_left - 1];
            array[array[i].index_of_left - 1].parent = &array[i];
        }
        if(array[i].index_of_right != 0)
        {
            array[i].right = &array[array[i].index_of_right - 1];
            array[array[i].index_of_right - 1].parent = &array[i];
        }
    }

    height(root);

    for(int i = 0; i < n; i++)
    {
        cout << array[i].height_of_right - array[i].height_of_left << "\n";
    }

    return 0;
}
