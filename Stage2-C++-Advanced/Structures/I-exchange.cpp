#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int a[6]{0}, b[6]{0};
	int n, x, ans=0;
	
	cin >> n;
	for (int i = 0; i < n; i ++){
		cin >> x;
		a[x] ++;
	}
	for (int i = 0; i < n; i ++){
		cin >> x;
		b[x] ++;
	}
	
	for (int i = 1; i < 6; i++){
		if ((a[i] + b[i]) % 2){
			cout << -1 << endl;
			return 0;
		}
		ans += abs(a[i]-b[i]);
	}
	
	cout << ans/2 << endl;
	return 0;
}

