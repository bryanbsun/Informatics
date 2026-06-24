#include <bits/stdc++.h>
using namespace std;

int n;

int adj(int n){
    if (n == 1)
        return 7;
    else return n;
}

int     score(int a, int b, int c){
    int t = 0, d = 0, s = 0;
    if (a == b && a == c){
        t = adj(a);
    }else if (a == b){
        d = adj(a);
        s = adj(c);
    }else if (a == c){
        d = adj(a);
        s = adj(b);
    }else if (b == c){
        d = adj(b);
        s = adj(a);
    }else{
        s = a + b + c;
    }
//    cout << "("<<a<<","<<b<<","<<c<<"):("<<t<<","<<d<<","<<s<<")"<<endl;
    return t * 1000 + d * 100 + s;
}

int     main(){
    int a, b, c, d, e, f;
    int p1, p2;

    cin >> n;
    for (int i = 0; i < n; i ++){
        cin >> a >> b >> c;
        p1 = score(a,b,c);
        cin >> d >> e >> f;
        p2 = score(d,e,f);
    
        if (p1 > p2)
            cout << "XiaoMing" << endl;
        else if (p2 > p1)
            cout << "XiaoWang" << endl;
        else
            cout << "Draw" << endl;
    }
        
    return 0;
}

