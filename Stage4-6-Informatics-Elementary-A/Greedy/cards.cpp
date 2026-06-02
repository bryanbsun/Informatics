#include <bits/stdc++.h>
using namespace std;

int n;
int avg;
int ans;
int a[110];

int main(){
    cin >> n;
    for (int i = 0; i < n; i ++){
        cin >> a[i];
        avg += a[i];
    }

    avg /= n;

    for (int i = 0; i < n; i ++)
        a[i] -= avg;

    for (int i = 0; i < n; i ++)
        if (a[i]){
            ans ++;
            a[i+1] += a[i];
        }

    cout << ans << endl;

    return 0;
}
