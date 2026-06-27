#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x, y, z, w;

    cin >> n;

    x = 1;
    y = 2;
    z = 3;

    for (int i = 1; i < n; i ++){
        cin >> w;
        if (w != x && w != y){
            cout << "No" << endl;
            return 0;
        }else 
            if (w == x)
                swap (y, z);
            else 
                swap (x, z);
    }
    cout << "Yes" << endl;

    return 0;
}

