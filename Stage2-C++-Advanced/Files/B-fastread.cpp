#include <bits/stdc++.h>

using namespace std;

template <typename T> void read(T &a){
    a=0; int flag=1; char ch = getchar();
    while (ch <'0' || ch>'9') {
        if (ch == '-') flag = -1;
        ch = getchar();
    }
    do{
        a = a *10 + ch - '0';
        ch = getchar();
    } while('0' <= ch && ch <= '9');
    a *= flag;
}

int main(){
    int a;
    long long b;
    double c;
    
    freopen("numbers.in","r",stdin);
 
    for (int i = 0; i < 1000000; i ++)
        read(a);
/*    read(a);
    read(b);
    read(c);

    cout << a << " " << b << " " << c << endl;
*/
    return 0;
}
