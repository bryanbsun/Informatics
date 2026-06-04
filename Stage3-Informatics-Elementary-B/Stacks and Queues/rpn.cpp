#include <bits/stdc++.h>
using namespace std;

char s[110];
double sta[110];
int t;

void    push(double p){
    sta[t++] = p;
}

double pop(){
    if (!t) return -1;
    return sta[--t];
}

double top(){
    if (!t) return -1;
    return sta[t-1];
}

int main(){
    cin >> s;
    while (s){
        if (s == "+")
            push(pop() + pop());
        else if (s == "*")
            push(pop() * pop());
        else if (s == "-"){
            double a2 = pop();
            double a1 = pop();
            push(a1 - a2);
        }else if (s == "/"){
            double a2 = pop();
            double a1 = pop();
            push(a1 / a2);
        }else
            push(atof(s));
        cin >> s;
    }

    cout << top() << endl;

    return 0;
}