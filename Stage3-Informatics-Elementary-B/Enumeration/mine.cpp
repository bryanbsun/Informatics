#include <bits/stdc++.h>
using namespace std;

int ans = 5000;

int main(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n/i; j ++)
//            if (n%i%j==0){
            if (n%(i*j)==0){
                int k = n/i/j;
                int a = 2*(i*j+j*k+k*i);
                ans = min(ans, a);
            }
    cout << ans << endl;
    return 0;
}
