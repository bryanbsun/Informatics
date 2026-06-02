#include <bits/stdc++.h>
using namespace std;
int n,a[110],minn;
int main(){
    cin>>n>>a[0];
    minn=a[0];
    for(int i=1;i<n;++i){
        cin>>a[i];
        if(a[i]<minn)
            minn=a[i];
    }
    cout<<minn;
    for(int i=0;i<n;++i)
        if(a[i]!=minn)
            cout<<" "<<a[i];
    return 0;
}
