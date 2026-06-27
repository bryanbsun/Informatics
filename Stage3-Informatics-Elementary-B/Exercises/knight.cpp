#include <bits/stdc++.h>
using namespace std;

int	x[510], y[510], n, k1[3010], k2[3010], k3[3010];
int	ans;

int	main(){
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> x[i] >> y[i];
		
	for (int i = 1; i <= n; i ++)
		for (int j = i+1; j <= n; j ++)
			for (int k = j+1; k <= n; k ++)
				if ((x[i] - x[j]) * (y[j] - y[k]) == (x[j] - x[k]) * (y[i] - y[j])){
					k1[ans] = i;
					k2[ans] = j;
					k3[ans] = k;
					ans ++;
				}
					
	cout << ans << endl;
	for (int i = 0; i < ans; i ++)
		cout << k1[i] << " " << k2[i] << " " << k3[i] << endl;
	
	return 0;
}

