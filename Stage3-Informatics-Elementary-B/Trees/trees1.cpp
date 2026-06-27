#include <bits/stdc++.h>
using namespace std;

int n, k;
struct Node{
    int v;
    int f;
}t[110];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> t[i].v >> t[i].f;
    
    cin >> k;
    for (int i = 1; i <= k; i ++){
        int x, y;
        cin >> x >> y;
        int f1=x;
        while (f1 = t[f1].f)
            if (f1 == y){
                cout << y << endl;
                break;
            }
        int f2 = y;
        while (f2 = t[f2].f)
            if (f2 == x){
                cout << x << endl;
                break;
            }

        if (!f1 && !f2)
            cout << -1 << endl;
    }

    return 0;
}