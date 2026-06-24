#include <bits/stdc++.h>
using namespace std;

void    rd(int n){
    if (n){
        cout << n % 10;
        rd(n/10);
    }
}

int main(){
    int n;
    cin >> n;
    rd(n);
    cout << endl;
    return 0;
}
