#include <bits/stdc++.h>
using namespace std;
struct win{
    int l, t, r, b;
}win1, win2;

int main(){
    cin >> win1.l>> win1.r>> win1.t>> win1.b;
    cin >> win2.l>> win2.r>> win2.t>> win2.b;

    win win3;
    win3.l = max(win1.l, win2.l);
    win3.t = max(win1.t, win2.t);
    win3.r = min(win1.r, win2.r);
    win3.b = min(win1.b, win2.b);

    if (win3.l > win3.r || win3.t > win3.b)
        cout << 0 << endl;
    else 
        cout << (win3.r - win3.l) * (win3.b - win3.t) << endl;

    return 0;
}
