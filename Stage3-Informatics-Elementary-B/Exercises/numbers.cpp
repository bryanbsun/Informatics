#include <bits/stdc++.h>
using namespace std;
int n;
int a[1010];
int c[110];
int x;
int ans;

int	main(){
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	
	cin >> n;
	if (n <= 1000){
		for (int i = 0; i < n; i ++)
			cin >> a[i];
		sort(a, a+n);
		ans = 1;
		for (int i = 1; i < n; i ++)
			if (a[i] != a[i-1])
				ans ++;
	}else{
        for (int i = 0; i < n; i ++){
            scanf("%d", &x);
            //            cin >> x;
            c[x]++;
        }
        for (int i = 0; i < 110;i ++)
            if (c[i]) ans ++;
    }
	
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
