#include <bits/stdc++.h>
using namespace std;
void    add(int& a, int& b){
    a += b;
    return;
}

int     main(){
    int a, b;
    cin >> a >> b;
    cout << a << " " << b << endl;
    add(a, b);
    cout << a << " " << b << endl;

    return 0;
}