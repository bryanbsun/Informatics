#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, a[1010],b[1010], turns=0;
    string sa, sb;

    cin >> n >> sa >> sb;

    for (int i = 0; i < n; i ++){
        a[i] = sa[i] - '0';
        b[i] = sb[i] - '0';
        turns += min((a[i]-b[i]+10)%10, (b[i]-a[i]+10)%10);
    }

    cout << turns << endl;
    return 0;
}
