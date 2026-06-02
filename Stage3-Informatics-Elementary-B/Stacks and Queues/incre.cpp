#include <bits/stdc++.h>
using namespace std;

int main(){
    int x = 3;
    int a;
    a = x ++;
    cout << "a = x ++; " << a << " " << x << endl;
    x = 3;
    a = ++ x;
    cout << "a = ++ x; " << a << " " << x << endl;

    return 0;
}
