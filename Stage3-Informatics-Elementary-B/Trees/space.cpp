#include <bits/stdc++.h>
using namespace std;

int n, k, c[10010], low[10010];

int main(){
    cin >> n >> k;
    int lowcost = 1000000001;
    for (int i = 1; i <= n; i ++){
        cin >> c[i];
        if (c[i] < lowcost)
            lowcost = c[i];
        low[i] = lowcost;
    }

    int best = -1;
    for (int i = 2; i <= n; i ++){
        int t = f - c[i];

        int l = 1, r = i - 1;
        while (l <= r){
            int mid = (l + r)/2;
            if (low[mid] > t)
                l = mid + 1;
            else
                r = mid - 1;
        }

        if (l <= i - 1)
            best = max(best, i - l + 1);
    }
    
    cout << best << endl;
    
    return 0;
}