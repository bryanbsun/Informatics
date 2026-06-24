#include <bits/stdc++.h>
using namespace std;

int f(int n, int a){
    if (n == 1)
        return 1;
    if (a == 1)
        return 0;
    if (n%a == 0)
        return f(n/a, a) + f(n, a-1);
    else 
        return f(n, a-1);
}

int main(){
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i ++){
        cin >> a;
        cout << f(a, a) << endl;
    }

    return 0;
}

