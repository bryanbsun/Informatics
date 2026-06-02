#include <bits/stdc++.h>
using namespace std;
int n,tot[1010],x,ans;
int main(){
    cin>>n;
    for(int i=0;i<n;++i)
        for(int j=0;j<4;++j){
            cin>>x;
            tot[i]+=x;
        }
    for(int i=1;i<n;++i)
        if(tot[i]>tot[0])
            ++ans;
    cout<<ans+1;
    return 0;
}
