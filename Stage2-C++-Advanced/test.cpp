#include <bits/stdc++.h>
using namespace std;

void f(int &a){
    a *= 10;
    cout << "a in f() = " << a << endl;

}

int main(){
    int a = 10;
    f(a);
    cout << "a in main() = " << a << endl;
    return 0;
}
