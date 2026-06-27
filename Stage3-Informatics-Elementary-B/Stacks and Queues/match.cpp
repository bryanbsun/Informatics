#include <bits/stdc++.h>
using namespace std;

char s[110];
int sta[110];
int top;

void    push(int p){
    sta[top++] = p;
}

int pop(){
    if (!top) return -1;
    return sta[--top];
}

int main(){
    cin >> s;

    for (int i = 0; i < strlen(s); i ++){
        if (s[i] == '(')
            push(i);
        else if (s[i] == ')')
            cout << pop() << " " << i << endl;
    }
    return 0;
}