#include <bits/stdc++.h>
using namespace std;

int m, n;
int g[110][110];
int vis[110][110];
int que[10010][2];
int dx[4]{1,0,-1,0};
int dy[4]{0,-1,0, 1};
int f,r;
int ans;

void    search(int x, int y){
    f = r = 0;
    que[r][0] = x;
    que[r][1] = y;
    r ++;
    while (f != r){
        x = que[f][0];
        y = que[f][1];
        f ++;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i ++){
            if (g[x+dx[i]][y+dy[i]] && (vis[x+dx[i]][y+dy[i]] == 0)){
                que[r][0] = x + dx[i];
                que[r][1] = y + dy[i];
                r ++;
            }
        }
    }
}

int     main(){
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            cin >> g[i][j];

    for (int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++){
            if (g[i][j] && (vis[i][j] == 0)){
                vis[i][j] = 1;
                ans ++;
                search(i,j);
            }
        }

    cout << ans << endl;
    return 0;
}
