#include <bits/stdc++.h>
using namespace std;

int k;
long long sta[1000010];
int t;

void    push(long long x){
    sta[t++] = x;
}

long long pop(){
    if (!t) return -1;
    return sta[--t];
}

long long top(){
    if (!t) return -1;
    return sta[t-1];
}

int size(){
    return t;
}

int main() {
    string op;
    int n;
    long long a;

    cin >> k;
    for (int i = 0; i < k; i ++){
        cin >> op;
        if (op == "Push"){
            cin >> n;
            for (int j = 0; j < n; j ++){
                cin >> a;
                push(a);
            }
        }else if (op == "Pop"){
            cin >> n;
            for (int j = 0; j < n; j ++)
                cout << pop() << " ";
            cout << endl;
        }else if (op == "Top"){
            cout << top() << endl;;
        }else if (op == "Size")
            cout << size() << endl;

    }
    return 0;
}