#include <bits/stdc++.h>
using namespace std;

int     n, d[200010], ni[200010];

int     main(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> d[i];
    
    int sum = 0;
    for (int i = n; i > 0; i --){
        sum ++;
        if (ni[d[i]] == 0){
            ni[d[i]] = sum;
            if (i < n)
                for (int j = d[i+1]-1; j > d[i]; j --)
                    ni[j] = ni[d[i+1]];
        } else {
            ni[d[i]] ++;
        }
    }

    for (int i = 1; i <= d[n]; i ++)
        cout << ni[i] << " ";
    cout << endl;

    return 0;

}
