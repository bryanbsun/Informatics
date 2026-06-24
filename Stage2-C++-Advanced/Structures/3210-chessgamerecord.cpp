#include <bits/stdc++.h>
using namespace std;
int n,x=1,y=2,z=3,a;
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a;
        if (a!=x&&a!=y) {
            cout<<"NO";
            return 0;
        }
        if (a==x) swap(y,z);
        else swap(x,z);
    }
    cout<<"YES";
    return 0;
}
