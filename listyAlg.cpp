#include <iostream>
using namespace std;

struct node
{
    int val;
    node* next;
};

void AddToList(node*& H, int x)
{
    node* p = new node;
    p->val = x;
    p->next = H;
    H = p;
}

void Del(node*& H)
{
    if (H != NULL)
    {
        node* p = H;
        H = H->next;
        delete p;
    }
}



void Show(node* H)
{
    cout << "H->";
    node* p = H;
    while (p != NULL)
    {
        cout << p->val << "->";
        p = p->next;
    }
    cout << "NULL" << endl;
}

void Copy(node*& H)
{
    node* p = H;
    while (p != NULL)
    {
        AddToList(p->next, p->val);
        p = p->next->next;
    }
}

void SwapH(node*& H)
{
    if (H && H->next)
    {
        node* p = H;
        H = H->next; // H=p->next
        p->next = p->next->next;
        H->next = p;
    }
}

void Swap2(node*& H)
{
    if (H && H->next)
    {
        node* p = H;
        node* r = H;
        p->next = H->next; // H=p->next
        H->next = p->next;
        H = p->next;
    }
}

void SwapX(node*& H, int x)
{
    if (H && H->next)
    {
        if (H->val == x)
            SwapH(H);
        else
        {
            node* p = H;
            while (p->next != NULL && p->next->val != x)
                p = p->next;
            if (p->next && p->next->next)
                SwapH(p->next);
        }
    }
}

void SwapFirstWithLast(node*& H)
{
    if (H && H->next)
    {
        node* p = H;
        node* q = H;
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        q = p->next;
        p->next = H;
        q->next = H->next;
        H->next = NULL;
        H = q;

    }
}

void SwapXWith(node* H, int x)
{
    if (H && H->next)
    {
        node* p = H;
        if (H->next->val == x)
        {
            H = H->next;
            p->next = p->next->next;
            H->next = p;
        }

        else
        {
            node* p = H;
            while (p->next != NULL && p->next->val != x)
                p = p->next;
            if (p->next && p->next->next)
                SwapH(p->next);
        }
    }
}

void DelX(node*& H, int x)
{
    if (H)
    {
        if (H->val == x)
            Del(H);
        else
        {
            node* p = H;
            while (p->next != NULL && p->next->val != x)
                p = p->next;
            if (p->next != NULL)
                Del(p->next);
        }
    }
}

node* removePos(node*& head, int pos)
{
    if (!head)
    {
        cout << "Lista jest pusta" << endl;
        return NULL;
    }

    if (!head->next || pos == 0)
    {
        node* pom = head;
        head = head->next;
        return pom;
    }

    node* pom = head;
    int i = 0;

    while (pom->next->next && i < pos - 1)
    {
        pom = pom->next;
        i++;
    }

    node* pom2 = pom->next;
    pom->next = pom2->next;
    return pom2;
}

node* DelDow(node*& H, int licz)
{
    if (H != NULL) {
        if (licz == 0)
        {
            return H;
        }
        node* pom = H;
        int i = 0;
        while (pom->next->next && i < licz - 1)
        {
            pom = pom->next;
            i++;
        }
        node* pom2 = pom->next;
        pom->next = pom2->next;
        return pom2;
    }
    else {
        cout << "Lista jest pusta" << endl;
    }
}


void DelSec(node*& H)
{
    if (H != NULL)
    {
        node* p = H;
        while (p->next != NULL)
        {
            Del(p->next);
            p = p->next;
        }
    }
}

void CopyEvery(node*& H)
{
    if (H != NULL)
    {
        node* p = H;
        while (p != NULL)
        {
            AddToList(p->next, p->val);
            p = p->next->next;
        }
    }
}

void CopyMEvery(node*& H)
{
    if (H != NULL)
    {
        int x;
        node* p = H;
        while (p != NULL)
        {
            x = p->val;
            cout << x << endl;
            for (int i = 0; i < x - 1; i++)
            {
                AddToList(p->next, p->val);
                p = p->next;
            }
            p = p->next;
        }
    }
}

void SwapEvery(node*& H)
{
    if (H && H->next)
    {
        SwapH(H);
        node* p = H->next;
        while (p->next && p->next->next)
        {
            SwapH(p->next);
            p = p->next->next;

        }
    }
}

void DelDiv2(node*& H)
{
    if (H)
    {
        while (H != NULL && H->val % 2 == 0)
        {
            Del(H);
        }
        if (H != NULL)
        {
            node* p = H;
            while (p->next != NULL)
            {
                if (p->next->val % 2 == 0)
                {
                    Del(p->next);
                }
                else
                {
                    p = p->next;
                }
            }
        }
    }
}

void AddtoEnd(node*& H, node*& T, int x)
{
    node* p = new node;
    p->val = x;
    p->next = NULL;
    if (H == NULL)
    {
        H = p;
        T = p;
    }
    else
    {
        T->next = new node;
        T = T->next;
        T->next = NULL;
        T->val = x;
    }
}

void AddtoEnd(node*& H, node* p)
{
    p->next = NULL;
    node* T = H;
    while (T != NULL && T->next != NULL)
    {
        T = T->next;
    }
    if (H == NULL)
    {
        H = p;
        T = p;
    }
    else
    {
        T->next = p;
        T = p;
    }
}

void SwapAll(node*& H)
{
    if (H && H->next)
    {
        node* p;
        node* H1 = NULL;
        while (H != NULL)
        {
            p = H;
            H = p->next;
            p->next = H1;
            H1 = p;
        }
        H = H1;
    }
}

void AddcpSwapped(node*& H)
{
    if (H)
    {
        node* p = H;
        node* H2 = NULL;
        while (p->next != NULL)
        {
            AddToList(H2, p->val);
            p = p->next;
        }
        AddToList(H2, p->val);
        p = H2;
    }
}
/*
void Split(node*& H, node*& H1, node*& H2)
{
    if (H != NULL)
    {
        int a = 0;
        node* p = H;
        while (p != NULL)
        {
            p = p->next;
            a++;
        }
        node* q = H;
        for (int i = 0; i < a / 2; i++)
        {
            q = q->next;
        }
        H2 = q->next;
        q->next = NULL;
        H1 = H;
        H = NULL;
    }
}
*/
void Merge(node*& H, node*& H1, node*& H2)
{
    if (H1 && H2)
    {
        node* p = new node;
        while (H1 && H2)
        {

            if (H1->val < H2->val)
            {
                p = H1;
                H1 = H1->next;
                AddtoEnd(H, p);
            }
            else
            {
                p = H2;
                H2 = H2->next;
                AddtoEnd(H, p);
            }
        }
        if (H1 == NULL)
        {
            while (H2)
            {
                p = H2;
                H2 = H2->next;
                AddtoEnd(H, p);
            }
        }
        if (H2 == NULL)
        {
            while (H1)
            {
                p = H1;
                H1 = H1->next;
                AddtoEnd(H, p);
            }
        }
    }
}

/*
void mergeSort(node*& H) {
    if (H != NULL) {

        if (H->next == NULL) {
            return;
        }
        node* H1 = NULL;
        node* H2 = NULL;

        Split(H, H1, H2);
        mergeSort(H1);
        mergeSort(H2);
        Merge(H, H1, H2);
        cout << "Lista jest posegregowana" << endl;
    }
    else {
        cout << "Lista jest pusta" << endl;
        return;
    }
}
*/



void buble(node*& H)
{
    if (H != NULL)
    {
        node* p = H;
        node* T = NULL;
        int stan = 1;
        while (stan == 1)
        {
            stan = 0;
            while (p->next != T)
            {
                if (p->val > p->next->val)
                {
                    SwapX(H, p->val);
                    stan = 1;
                }
                else
                {
                    p = p->next;
                }
            }
            T = p;
            p = H;
        }
    }
}

void findmax(node*& H, node*& H1)
{
    node* p = H;
    node* maximum = H;
    int poz = 0;
    int licz = 0;
    while (p != NULL)
    {
        if (p->val > maximum->val)
        {
            maximum = p;
            poz = licz;
        }
        p = p->next;
        licz++;
    }
    node* q = removePos(H, poz);
    AddToList(H1, q->val);
    delete q;

}

void findmin(node*& H, node*& H1)
{
    node* p = H;
    node* minimum = H;
    int licz = 0;
    int poz = 0;
    while (p != NULL)
    {
        if (p->val < minimum->val)
        {
            minimum = p;
            poz = licz;
        }
        p = p->next;
        licz++;
    }
    node* q = removePos(H, poz);
    AddToList(H1, q->val);
    delete q;

}



int main()
{
    node* H1 = NULL;
    node* H2 = NULL;
    node* H11 = NULL;
    node* H12 = NULL;
    node* H21 = NULL;
    node* H22 = NULL;
    node* H = NULL;
    AddToList(H, 50);
    AddToList(H, 10);
    AddToList(H, 6);
    AddToList(H, 4);
    AddToList(H, 30);
    AddToList(H, 2);
    AddToList(H, 7);
    AddToList(H, 5);
    AddToList(H, 1);
    AddToList(H, 40);

    node* p = H;

    while (H != NULL && H->next != NULL)
    {
        findmax(H, H2);
        findmin(H, H1);
    }
    cout << "Podzielenie list: \n";
    Show(H1);
    Show(H2);
    Show(H);
    while (H1 != NULL && H1->next != NULL)
    {
        findmax(H1, H12);
        findmin(H1, H11);
    }
    while (H1 != NULL)
    {
        findmax(H1, H12);
        if (H1 == NULL) {
            break;
        }
        findmin(H1, H11);
        if (H1 == NULL) {
            break;
        }
    }

    while (H2 != NULL && H2->next != NULL)
    {
        findmax(H2, H22);
        findmin(H2, H21);
    }

    while (H2 != NULL)
    {
        findmax(H2, H12);
        if (H2 == NULL) {
            break;
        }
        findmin(H2, H11);
        if (H2 == NULL) {
            break;
        }
    }


    cout << "Podzielenie list na mniejsze listy: \n";
    Show(H11);
    Show(H12);
    Show(H22);
    Show(H21);
    cout << "Sortowanie (bubblesort): \n";
    buble(H11);
    buble(H12);
    buble(H21);
    buble(H22);
    cout << "Posortowane male listy: \n";
    Show(H11);
    Show(H12);
    Show(H22);
    Show(H21);

    cout << "Laczenie list: " << endl;
    Merge(H1, H11, H12);
    Merge(H2, H21, H22);
    Merge(H, H1, H2);
    cout << "Ostateczna wersja: " << endl;
    Show(H);




}