#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, c[1010], a[1010];
    int r;

    cin >> n;

    while (n){
        for (int i = 0; i < n; i ++)
            cin >> c[i];

        r = 0;
        while (1){
            memcpy(a, c, sizeof(c));
            int i;
            for (i = 0; i < n; i ++){
                c[i] = a[i] / 2 + a[(i+n-1)%n] / 2;
                if (c[i] % 2)
                    c[i] --;
            }
            r ++;

            for (i = 0; i < n; i ++)
                if (c[i] != c[0])
                    break;

            if (i == n){
                cout << r << " " << c[0] * n << endl;
                break;
            }
        }
    
        cin >> n;
    }

    return 0;
}
