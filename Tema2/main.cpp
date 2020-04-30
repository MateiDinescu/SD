#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class PairNode
{
    public:
        int element;
        PairNode *leftChild;
        PairNode *nextSibling;
        PairNode *prev;
        PairNode(int element)
        {
            this->element = element;
            leftChild = NULL;
            nextSibling = NULL;
            prev = NULL;
        }
};

class PairingHeap
{
    private:
        PairNode *root;
        void reclaimMemory(PairNode *t);
        void compareAndLink(PairNode * &first, PairNode *second);
        PairNode *combineSiblings(PairNode *firstSibling);
        PairNode *clone(PairNode *t);
    public:
        PairingHeap();
        PairingHeap(PairingHeap &rhs);
        ~PairingHeap();
        bool isEmpty();
        bool isFull();
        int &findMin();
        PairNode *Insert(int &x);
        void deleteMin();
        void deleteMin(int &minItem);
        void makeEmpty();
        PairingHeap &operator=(PairingHeap &rhs);
};

PairingHeap::PairingHeap()
{
    root = NULL;
}

PairingHeap::PairingHeap(PairingHeap & rhs)
{
    root = NULL;
    *this = rhs;
}

PairingHeap::~PairingHeap()
{
    makeEmpty();
}


PairNode *PairingHeap::Insert(int &x)
{
    PairNode *newNode = new PairNode(x);
    if (root == NULL)
        root = newNode;
    else
        compareAndLink(root, newNode);
    return newNode;
}


int &PairingHeap::findMin()
{
    return root->element;
}


void PairingHeap::deleteMin()
{
    PairNode *oldRoot = root;
    if (root->leftChild == NULL)
        root = NULL;
    else
        root = combineSiblings(root->leftChild);
    delete oldRoot;
}

void PairingHeap::deleteMin(int &minItem)
{
    if (isEmpty())
    {
        cout<<endl<<"Heap-ul este gol!"<<endl<<endl;
        return;
    }
    minItem = findMin();
    deleteMin();
    cout<<endl<<"Elementul minim : "<<minItem<<" a fost sters"<<endl<<endl;
}

bool PairingHeap::isEmpty()
{
    return root == NULL;
}

bool PairingHeap::isFull()
{
    return false;
}

void PairingHeap::makeEmpty()
{
    reclaimMemory(root);
    root = NULL;
}

PairingHeap &PairingHeap::operator=(PairingHeap & rhs)
{
    if (this != &rhs)
    {
        makeEmpty( );
        root = clone(rhs.root);
    }
    return *this;
}

void PairingHeap::reclaimMemory(PairNode * t)
{
    if (t != NULL)
    {
        reclaimMemory(t->leftChild);
        reclaimMemory(t->nextSibling);
        delete t;
    }
}

void PairingHeap::compareAndLink(PairNode * &first, PairNode *second)
{
    if (second == NULL)
        return;
    if (second->element < first->element)
    {
        second->prev = first->prev;
        first->prev = second;
        first->nextSibling = second->leftChild;
        if (first->nextSibling != NULL)
            first->nextSibling->prev = first;
        second->leftChild = first;
        first = second;
    }
    else
    {
        second->prev = first;
        first->nextSibling = second->nextSibling;
        if (first->nextSibling != NULL)
            first->nextSibling->prev = first;
        second->nextSibling = first->leftChild;
        if (second->nextSibling != NULL)
            second->nextSibling->prev = second;
        first->leftChild = second;
    }
}

PairNode *PairingHeap::combineSiblings(PairNode *firstSibling)
{
    if (firstSibling->nextSibling == NULL)
        return firstSibling;
    static vector<PairNode *> treeArray(5);
    int numSiblings = 0;
    for (; firstSibling != NULL; numSiblings++)
    {
        if (numSiblings == treeArray.size())
            treeArray.resize(numSiblings * 2);
        treeArray[numSiblings] = firstSibling;
        firstSibling->prev->nextSibling = NULL;
        firstSibling = firstSibling->nextSibling;
    }
    if (numSiblings == treeArray.size())
        treeArray.resize(numSiblings + 1);
    treeArray[numSiblings] = NULL;
    int i = 0;
    for (; i + 1 < numSiblings; i += 2)
        compareAndLink(treeArray[i], treeArray[i + 1]);
    int j = i - 2;
    if (j == numSiblings - 3)
        compareAndLink (treeArray[j], treeArray[j + 2]);
    for (; j >= 2; j -= 2)
        compareAndLink(treeArray[j - 2], treeArray[j] );
    return treeArray[0];
}

PairNode *PairingHeap::clone(PairNode * t)
{
    if (t == NULL)
        return NULL;
    else
    {
        PairNode *p = new PairNode(t->element);
        if ((p->leftChild = clone( t->leftChild)) != NULL)
            p->leftChild->prev = p;
        if ((p->nextSibling = clone( t->nextSibling)) != NULL)
            p->nextSibling->prev = p;
        return p;
    }
}

int main()
{
    int choice, num, pos,n;
    char ch;
    PairingHeap h;
    PairNode * pn;
    while (1)
    {
        cout<<"------------------------"<<endl;
        cout<<"Operatii cu Pairing Heap"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"1.Insereaza n Elemente In Heap "<<endl;
        cout<<"2.Insereaza Un Element "<<endl;
        cout<<"3.Sterge Elementul Minim "<<endl;
        cout<<"4.Sterge Tot Heapul "<<endl;
        cout<<"5.Iesire"<<endl;
        cout<<"Introdu Alegerea Ta : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Introdu cate numere vrei sa adaugi in heap : ";
            cin>>n;
            for(int i = 1;i <= n;i++)
                {pn = h.Insert(i); cout<<"Nodul "<<i<<" a fost inserat!"<<endl<<endl;}
            break;

        case 2:
            cout<<"Introdu numarul pe care vrei sa il adaugi : ";
            cin>>num;
            pn = h.Insert(num);
            break;
        case 3:
            h.deleteMin(num);
            break;
        case 4:
            for(int i = 1; i <= n;i++)
                h.deleteMin(i);
            break;
        case 5:
            exit(1);
        default:
            cout<<endl<<"Alegere gresita!"<<endl<<endl;
        }
    }


    return 0;
}
