#include <bits/stdc++.h>
using namespace std;

int n, m, h[100010], s[100010], p[100010];
int bl[100010], br[100010];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> h[i];
    for (int i = 1; i <= m; i ++)
        cin >> s[i];
    for (int i = 1; i <= m; i ++)
        cin >> p[i];

    fill(bl, bl+n+2, INT_MAX);
    fill(br, br+n+2, INT_MAX);
    
    int j = 1;
    for (int i = 1; i <= n; i ++){
        if (bl[i-1] != INT_MAX)
            bl[i] = bl[i-1] + h[i] - h[i-1];
        while (s[j] < h[i]){
            bl[i] = min(bl[i], p[j] + h[i] - s[j]);
            j ++;
        }
    }

    j = m;
    for (int i = m; i >= 1; i --){
        if (br[i+1] != INT_MAX)
            br[i] = br[i+1] + h[i+1] - h[i];
        while (s[j] > h[i]){
            br[i] = min(br[i], p[j] + s[j] - h[i]);
            j --;
        }
    }

    for (int i =      1; i <= n; i ++)
        cout << min(bl[i], br[i]) << " ";
    cout << endl;
    return 0;
}