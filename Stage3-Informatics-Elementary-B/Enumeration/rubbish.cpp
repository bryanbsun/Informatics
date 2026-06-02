#include <bits/stdc++.h>
using namespace std;

int b[1010][1010]{0};
int x[1010], y[1010], i[1010];
int mx = 0;
int nm = 0;

int main(){
    int s,d,n;

    cin >> s >> d >> n;
    for (int j = 0; j < n; j ++)
        cin >> x[j] >> y[j] >> i[j];

    for (int j = 0; j < n; j ++)
        for (int l = max(x[j]-d, 0); l <= min(x[j]+d, s); l ++)
            for (int m = max(y[j]-d, 0); m <= min(y[j]+d, s); m ++)
                b[l][m] += i[j];

    for (int j = 0; j <= s; j ++)
        for (int k = 0; k <= s; k ++)
            if (b[j][k] > mx){
                mx = b[j][k];
                nm = 1;
            }else if (b[j][k] == mx)
                nm ++;

    cout << nm << " " << mx << endl;
    return 0;
}
