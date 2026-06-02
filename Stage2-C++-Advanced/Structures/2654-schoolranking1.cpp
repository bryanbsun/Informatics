#include <bits/stdc++.h>
using namespace std;
int n,a,id[1010],tot[1010],ans;
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<4;++j){
            cin>>a;
            tot[i]+=a;
        }
        id[i]=i+1;
    }
    for(int i=n-1;i>0;--i)
        for(int j=0;j<i;++j){
            bool f=false;
            if(tot[j]<tot[j+1])
                f=true;
            else if(tot[j]==tot[j+1])
                f=id[j]>id[j+1];
            if(f){
                swap(id[j],id[j+1]);
                swap(tot[j],tot[j+1]);
            }
        }
    for(int i=0;i<n;++i)
        if(id[i]==1){
            ans=i+1;
            break;
        }
    cout<<ans;
    return 0;
}
