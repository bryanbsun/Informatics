#include <bits/stdc++.h>
using namespace std;

long long memo[20][2][2]; 
bool vis[20][2][2];
string s;

long long dfs(int pos,bool tight,bool started){
    if(pos==(int)s.size()) return 1;
    if(vis[pos][tight][started]) return memo[pos][tight][started];
    vis[pos][tight][started]=1;
    int lim=tight?(s[pos]-'0'):9;
    long long ans=0;
    for(int d=0;d<=lim;d++){
        if((started||d)&& (d==3||d==7)) continue;
        ans+=dfs(pos+1,tight&&d==lim,started||d);
    }
    return memo[pos][tight][started];
}

long long avoid37(long long x){
    if(x<0) return 0;
    s=to_string(x);
    memset(vis,0,sizeof(vis));
    return dfs(0,1,0);
}

long long good(long long x){ 
    return x<0?0:(x+1)-avoid37(x); 
}

long long countInRange(long long m,long long n){
    if(m>n) swap(m,n);
    if(n<0) return good(-m)-good(-n-1);
    if(m>=0) return good(n)-good(m-1);
    return good(n)+good(-m);
}

int main(){
    long long m,n; 
    cin>>m>>n;
    cout<<countInRange(m,n);
}