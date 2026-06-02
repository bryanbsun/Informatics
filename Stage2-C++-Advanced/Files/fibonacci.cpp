#include <bits/stdc++.h>
using namespace std;

int f(int n){
    cout << "trying to find f(" << n << ")..."<<endl;
    if (n==1) return 1;
    if (n==2) return 1;
    return f(n-1)+f(n-2);
}

int main(){
    int n;
    cout << "input a number: ";
    cin >> n;
    cout << "f("<<n<<")=" << f(n) << endl;
    return 0;
}
