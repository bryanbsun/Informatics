#include <bits/stdc++.h>
using namespace std;

int n;

void    f(){
    int n = 3;
    cout << "local n = " << n << endl;
}

int main(){
    n = 2;
    cout << "global n = " << n << endl;
    f();
    return 0;
}
