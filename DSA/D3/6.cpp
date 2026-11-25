
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
    NODE* p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}

void CreateEmptyList(LIST &L) {
    L.pHead = L.pTail = NULL;
}

void AddTail(LIST &L, NODE* p) {
    if (L.pHead == NULL) {
        L.pHead = L.pTail = p;
    } else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void CreateList(LIST &L) {
    int x;
    while (cin >> x && x != -1)
        AddTail(L, CreateNode(x));
}

void PrintList(LIST L) {
    if (L.pHead == NULL) {
        cout << "Empty List.";
    } else {
        for (NODE* p = L.pHead; p; p = p->pNext)
            cout << p->info << " ";
    }
    cout << endl;
}

void Join(LIST &L, LIST &L1, NODE* pivot, LIST &L2) {
    pivot->pNext = NULL;

    // Phần đầu: L1 (nếu có), sau đó là pivot
    if (L1.pHead != NULL) {
        L.pHead = L1.pHead;
        L1.pTail->pNext = pivot;
    } else {
        L.pHead = pivot;
    }
    L.pTail = pivot;

    // Phần sau: L2 (nếu có)
    if (L2.pHead != NULL) {
        pivot->pNext = L2.pHead;
        L.pTail = L2.pTail;
    }

    // L1 và L2 rỗng sau khi nối
    L1.pHead = L1.pTail = NULL;
    L2.pHead = L2.pTail = NULL;
}

int main() {
    LIST L, L1, L2;

    int x;
    NODE *pivot;

    CreateEmptyList(L);
    CreateEmptyList(L1);
    CreateEmptyList(L2);

    CreateList(L1);
    cin >> x;
    pivot=CreateNode(x);
    CreateList(L2);


    Join(L, L1, pivot, L2);
    PrintList(L);

    return 0;
}
