#include <iostream>
using namespace std;

struct drzewoBST {
    drzewoBST* up;
    drzewoBST* left;
    drzewoBST* right;
    int start;
    int end;
};
/*
void AddBstNode(drzewoBST*& root, int x, drzewoBST* root2=NULL)
{
    if (root == NULL)
    {
        drzewoBST* w = new drzewoBST();
        w->up = root2;
        w->left = NULL;
        w->right = NULL;
        w->val = x;
        root = w;


    }
    else
    {
        if (x >= root->val)
        {;
            AddBstNode(root->right, x,root);
            
        }
        else 
        { 
            AddBstNode(root->left, x,root);
        }
    }
}
drzewoBST* szukaj(drzewoBST*& root, int x)
{
    if (root != NULL)
    {
        if (root->val == x)
        {
            return root;
        }

        if (root->val != x)
        {
            if (root->val < x)
            {
                return szukaj(root->right, x);
            }
            else
            {
                return szukaj(root->left, x);
            }

        }

    }
}

void usun(drzewoBST*& root)
{
    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else
        {
            if (root->left != NULL)
            {
                usun(root->left);
            }
            if (root->right != NULL)
            {
                usun(root->right);
            }
        }
    }
}
void inorder(drzewoBST*& root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
   
}
drzewoBST* max(drzewoBST* root)
{
    while (root->right!=NULL) 
    {
        root = root->right;
    }
    cout << "\nMaksymalna wartosc w drzewie to: " << root->val << endl;
    return root;
}
drzewoBST* min(drzewoBST* root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    cout << "\nMinimalna wartosc w drzewie to: " << root->val << endl;
    return root;
}

drzewoBST* znajdzpoprzednik(drzewoBST* root, int x)//poprzednik bez up
{
    drzewoBST* poprzednik = NULL;
    while (root!=NULL) 
    {
        if (x > root->val) 
        {
            poprzednik = root;
            root = root->right;
        }
        else 
        {
            root = root->left;
        }
    }

    if (poprzednik != NULL) {
        cout << "Poprzednikiem dla " << x << " jest: " << poprzednik->val << endl;
    }
    else
    {
        cout << "Nie ma poprzednika dla:  " << x << endl;
    }
    return poprzednik;
}

drzewoBST* znajdznastepnik(drzewoBST* root, int x)//nastepnik bez up
{
    drzewoBST* nastepnik = NULL;
    while (root != NULL)
    {
        if (x < root->val)
        {
            nastepnik = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    if (nastepnik != NULL) {
        cout << "Nastepnikiem dla " << x << " jest: " << nastepnik->val << endl;
    }
    else
    {
        cout << "Nie ma nastepnika dla:  " << x << endl;
    }
    return nastepnik;



}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void usuwanieizamiana(drzewoBST*& root)//???
{
    if (root != NULL)
    {
        drzewoBST* parent = NULL;
        drzewoBST* son = NULL;
        cout << root->left->val << endl;
        son = root->left;
        cout << son->val << endl;
        if (root->left == NULL)
        {
            parent = root;
            son = root->right;
            swap(&(parent->val), &(son->val));
            delete son;
            son = NULL;
            cout<< parent->val << endl;
        }
        else if (root->right == NULL)
        {
            parent = root;
            son = root->left;
            swap(&(parent->val), &(son->val));
            delete son;
            son = NULL;
            cout << parent->val << endl;
        }
    }   
}
void rotacjaL(drzewoBST*& root)
{
    if (root != NULL)
    {
        drzewoBST* p = root->right;
        root->right = p->left;
        p->left = root;
        root = p;
        
    }
}

void rotacjaP(drzewoBST*& root)
{
    if (root != NULL)
    {
        drzewoBST* p = root->left;
        root->left = p->right;
        p->right = root;
        root = p;
    }
}
*/

void AddBstNodeStart(drzewoBST*& root, int x,int y, drzewoBST* root2 = NULL)
{
    if (root == NULL)
    {
        drzewoBST* w = new drzewoBST();
        w->up = root2;
        w->left = NULL;
        w->right = NULL;
        w->start = x;
        w->end = y;
        root = w;


    }
    else
    {
        if (x >= root->start)
        {
            
            AddBstNodeStart(root->right, x,y, root);

        }
        else
        {
            AddBstNodeStart(root->left, x,y, root);
        }
    }
}

void AddBstNodeStart(drzewoBST*& root, int x, int y, drzewoBST* root2 = NULL)
{
    if (root == NULL)
    {
        drzewoBST* w = new drzewoBST();
        w->up = root2;
        w->left = NULL;
        w->right = NULL;
        w->start = x;
        w->end = y;
        root = w;


    }
    else
    {
        if (y >= root->end)
        {

            AddBstNodeStart(root->right, x, y, root);

        }
        else
        {
            AddBstNodeStart(root->left, x, y, root);
        }
    }
}

int main()
{
    drzewoBST* drzewo_start = NULL;
    drzewoBST* drzewo_end = NULL;







   
    
    
}


