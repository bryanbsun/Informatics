#include <bits/stdc++.h>
using namespace std;
struct node{
    int v;
    int lc, rs;
}t[110];
int n, r, k;

void    pre(int n){
    if (!n)
        return;
    cout << n << " ";
    for (int p = t[n].lc; p; p = t[p].rs)
        pre(p);
}

int     main(){
    cin >> n >> r;
    for (int i = 1; i <= n; i ++)
        cin >> t[i].v >> t[i].lc >> t[i].rs;
    
    cin >> k;
    int q;
    for (int i = 0; i < k; i ++){
        cin >> q;
        pre(q);
        cout << endl;
    }


    return 0;

}