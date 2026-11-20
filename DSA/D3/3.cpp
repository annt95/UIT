#include <iostream>
using namespace std;

struct NODE {
    int info;
    NODE* pNext;
};

struct LIST {
    NODE* pHead = nullptr;
    NODE* pTail = nullptr;
};

void CreateEmptyList(LIST& L) {
    L.pHead = L.pTail = nullptr;
}

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    p->info = x;
    p->pNext = nullptr;
    return p;
}

void CreateList(LIST& L) {
    int value;
    while (cin >> value && value != -1) {
        NODE* p = CreateNode(value);
        if (L.pHead == nullptr) {
            L.pHead = L.pTail = p;
        } else {
            L.pTail->pNext = p;
            L.pTail = p;
        }
    }
}

void RemoveTail(LIST& L) {
    if (L.pHead == nullptr) {
        return;
    }
    if (L.pHead == L.pTail) {
        delete L.pHead;
        L.pHead = L.pTail = nullptr;
        return;
    }
    NODE* p = L.pHead;
    while (p->pNext != L.pTail) {
        p = p->pNext;
    }
    delete L.pTail;
    L.pTail = p;
    L.pTail->pNext = nullptr;
}

void PrintList(LIST& L) {
    if (L.pHead == nullptr) {
        cout << "Empty List.\n";
        return;
    }
    for (NODE* p = L.pHead; p != nullptr; p = p->pNext) {
        cout << p->info;
        if (p->pNext != nullptr) {
            cout << ' ';
        }
    }
}


int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
	RemoveTail(L);
    PrintList(L);

    return 0;
}
