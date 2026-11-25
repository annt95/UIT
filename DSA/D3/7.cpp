
#include <iostream>
using namespace std;

// Cấu trúc của một node
struct NODE {
    int info;
    NODE* pNext;
};
// Cấu trúc của một DSLK
struct LIST {
    NODE* pHead;
    NODE* pTail;
};

NODE* CreateNode(int x) {
    NODE* p;
    p = new NODE;
    //if (p == NULL)
    //		exit(1);

    p->info = x;
    p->pNext = NULL;
    return p;
}
void AddTail(LIST &L, NODE* p) {
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else {
        L.pTail->pNext = p;
        L.pTail=p;
    }
}

void CreateEmptyList(LIST &L) {
    L.pHead = NULL;
    L.pTail = NULL;
}
void CreateList(LIST &L) {
    NODE* p;
    int x, n;
    cin >> n; // Số lượng phần tử của danh sách
    while (n-->0) {
        cin >> x;
        p = CreateNode(x);
        AddTail(L, p);
    }
}




int length(NODE *p){
    int i=0;
    while (p) {
        i++;
        p = p->pNext;
    }
    return i;
}

void PrintList(NODE* p) {
    if (p == NULL)
        cout << "Empty List.";
    else {
        // cout << boolalpha << is_ascending(p) << endl;
        cout << length(p) << endl;
        while (p) {
            cout << p->info << " ";
            p = p->pNext;
        }
    }
}

void quicksort_ascending(LIST &L)
{
    if (L.pHead == NULL || L.pHead == L.pTail)
        return;

    NODE* slow = L.pHead;
    NODE* fast = L.pHead->pNext;
    while (fast && fast->pNext) {
        slow = slow->pNext;
        fast = fast->pNext->pNext;
    }
    int pivot = slow->info;

    LIST L1, Leq, L2;
    CreateEmptyList(L1);
    CreateEmptyList(Leq);
    CreateEmptyList(L2);

    NODE* p = L.pHead;
    while (p) {
        NODE* next = p->pNext;
        p->pNext = NULL;
        if (p->info < pivot)       AddTail(L1, p);
        else if (p->info > pivot)  AddTail(L2, p);
        else                       AddTail(Leq, p);
        p = next;
    }

    quicksort_ascending(L1);
    quicksort_ascending(L2);

    if (L1.pHead) {
        L.pHead = L1.pHead;
        L1.pTail->pNext = Leq.pHead;
    } else {
        L.pHead = Leq.pHead;
    }

    Leq.pTail->pNext = L2.pHead;
    L.pTail = L2.pHead ? L2.pTail : Leq.pTail;
}


int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    quicksort_ascending(L);
    PrintList(L.pHead);

    return 0;
}
