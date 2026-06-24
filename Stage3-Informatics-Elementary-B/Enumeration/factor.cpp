#include <bits/stdc++.h>
using namespace std;

int ans = -1;

int main(){
    int n,m;
    cin >> n >> m;

    for(int a = 1; a*a <=n ; a++)
        if ((m-a)>0 && (n%a)==0 && (n%(m-a)==0)){
                ans = a;
                break;
        }

    cout << ans << endl;

    return 0;
}
