#include <bits/stdc++.h>
using namespace std;

string s;
double sta[1000010];
int t;

void    push(double p){
//    cout << "push " << p << endl;
    sta[t++] = p;
}

double pop(){
    if (!t) return -1;
//    cout << "pop " << sta[t-1] << endl;
    return sta[--t];
}

double top(){
    if (!t) return -1;
//    cout << "top " << sta[t-1] << endl;
    return sta[t-1];
}

int main(){
 //   string line;
 //   getline(cin, line);
 //   istringstream sin(line);

    while (cin >> s){
//        cout << " :" << s << endl;
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
            push(stof(s));
    }

    cout << fixed << setprecision(6) << top() << endl;

    return 0;
}
