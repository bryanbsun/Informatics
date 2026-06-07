#include <bits/stdc++.h>
using namespace std;

int n, m, g[110][110], vis[110][110];
int que[100010][2];
int f, r;
int dx[4]{1, 0, -1, 0};
int dy[4]{0, -1, 0, 1};

void    findconn(int x, int y){
    que[r][0] = x;
    que[r][1] = y;
    r ++;
    while (f != r){
        x = que[f][0];
        y = que[f][1];
        f ++;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i ++){
            if (g[x + dx[i]][y + dy[i]] && !vis[x + dx[i]][y + dy[i]]){
                que[r][0] = x + dx[i];
                que[r][1] = y + dy[i];
                r ++;    
            }

        }
    }
}


int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> g[i][j];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++){
            if (g[i][j] && !vis[i][j]){
                vis[i][j] = 1;
                findconn(i,j);
            }
        } 
    return 0;
}