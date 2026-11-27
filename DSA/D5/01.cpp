#include <iostream>
using namespace std;
#define MAXN 100

struct NODE{
    char info;
    NODE *pNext;
};

NODE *CreateNode(char x){
    NODE *p=new NODE;
    p->info=x;
    p->pNext=NULL;
    return p;
}

struct Stack{
    NODE *top;
};

bool empty(const Stack &s){
    return (s.top==NULL);
}

void CreateEmptyStack(Stack &s){
    s.top=NULL;
}

void push(Stack &s, char x){
    NODE *p=CreateNode(x);
    p->pNext=s.top;
    s.top=p;
}

void pop (Stack &s) {
    if(s.top==NULL) return;
    NODE *p= s.top;
    s.top=s.top->pNext;
    delete p;
}

char stackTop(const Stack &s) {
    return s.top->info;
}

void Input_infix(char infix[], int &ni){
    ni = 0;
    char ch;
    while(ni < MAXN && cin >> ch && ch != '#'){ // khong doc qua kich thuoc mang
        infix[ni++] = ch;
    }
}

int Precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infix_to_postfix(char infix[], int ni, char postfix[], int &np){
    Stack s;
    CreateEmptyStack(s);
    np = 0;

    for(int i = 0; i < ni; i++){
        char ch = infix[i];
        if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            postfix[np++] = ch; // toan hang: chu so hoac chu cai
        else if (ch == '(')
            push(s, ch);
        else if (ch == ')'){
            while(!empty(s) && stackTop(s) != '('){
                postfix[np++] = stackTop(s);
                pop(s);
            }
            if(!empty(s) && stackTop(s) == '(') pop(s);
        }
        else { // toan tu
            while(!empty(s) && stackTop(s) != '(' && Precedence(stackTop(s)) >= Precedence(ch)){
                postfix[np++] = stackTop(s);
                pop(s);
            }
            push(s, ch);
        }
    }

    while(!empty(s)){
        if(stackTop(s) != '(') {
            postfix[np++] = stackTop(s);
        }
        pop(s);
    }
}

void Output(char postfix[], int np){
    if (np == 0) {
        cout << "Empty List.";
        return;
    }
    for(int i = 0; i < np; i++){
        cout << postfix[i] << " ";
    }
}


int main() {
    char infix[MAXN], postfix[MAXN];
    int ni, np;

    Input_infix(infix, ni);

    infix_to_postfix(infix, ni, postfix, np);

    Output(postfix, np);

    return 0;
}