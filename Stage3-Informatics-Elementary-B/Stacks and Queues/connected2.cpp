#include <bits/stdc++.h>
using namespace std;
const int MAXN=110;
const int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m,ans,a[MAXN][MAXN];
bool vis[MAXN][MAXN];
int q[MAXN*MAXN][2],front,rear;
void bfs(int x,int y)
{
    front=rear=0;
    q[rear][0]=x,q[rear][1]=y;
    ++rear;
    while (front!=rear) {
        x=q[front][0],y=q[front][1];
        ++front;
        for (int i=0;i<4;i++){
            int x1=x+dir[i][0],y1=y+dir[i][1];
            if (a[x1][y1]&&!vis[x1][y1]) {
                vis[x1][y1]=true;
                q[rear][0]=x1,q[rear][1]=y1;
                ++rear;
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>a[i][j];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]&&!vis[i][j]) {
                ans++;
                bfs(i,j);
            }
    cout<<ans<<endl;
    return 0;
}
