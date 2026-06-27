#include <bits/stdc++.h>
using namespace std;

int k;
long long que[1000010];
int f, r;

void    push(long long x){
    que[r++] = x;
}

long long pop(){
    if (f == r) return -1;
    return que[f++];
}

long long front(){
    if (f == r) return -1;
    return que[f];
}

int size(){
    return r - f;
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
        }else if (op == "Front"){
            cout << front() << endl;;
        }else if (op == "Size")
            cout << size() << endl;

    }
    return 0;
}