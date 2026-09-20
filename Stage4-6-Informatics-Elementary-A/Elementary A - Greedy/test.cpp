#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;

    cin >> n;
    while(n){
        cout << bool(!(n & n-1)) << endl;
        cin >> n;
    }
    return 0;
}
