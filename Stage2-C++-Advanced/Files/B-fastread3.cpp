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
    long long total{0};
    long long a;
    
    freopen("read.in","r",stdin);
    freopen("read.out","w",stdout);
 
    for (long long i = 0; i < 10000000; i ++){
        read(a);
        total += a;
    }

    cout << total << endl;

    return 0;
}

