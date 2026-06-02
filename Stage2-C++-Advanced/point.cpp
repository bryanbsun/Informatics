#include <bits/stdc++.h>
using namespace std;
int n,m,a[5010],x,y,cnt;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>x>>y;
        for(int j=x;j<=y;++j)
            if(!a[j]){
                ++cnt;
                a[j]=1;
            }
    }
    cout<<m-cnt<<endl;
    for(int i=1;i<=m;++i)
        if(!a[i])
            cout<<i<<" ";
    return 0;
}
