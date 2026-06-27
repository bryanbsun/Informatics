#include <bits/stdc++.h>
using namespace std;

int conv(int p, int b){
    int bb = 1, pp = 0;

    while(p){
        int d = p%10;
        p/=10;

        pp += d * bb;
        bb *= b;
    }

    return pp;
}

int main(){
    int n, b;

    cin >> n >> b;
    cout<<conv(n,b)<<endl;
    return 0;
}
