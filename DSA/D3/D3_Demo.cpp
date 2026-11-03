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

void PrintList(NODE* pHead) {
    if (pHead == nullptr) {
        cout << "Empty List.\n";
        return;
    }

    for (NODE* p = pHead; p != nullptr; p = p->pNext) {
        cout << p->info;
        if (p->pNext != nullptr) {
            cout << ' ';
        }
    }
    cout << '\n';
}

int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    PrintList(L.pHead);

    return 0;
}