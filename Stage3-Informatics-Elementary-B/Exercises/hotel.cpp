#include <bits/stdc++.h>
using namespace std;

int	main(){
	int n, k, x, y;
	int total;
	
	cin >> n >> k >> x >> y;
	if (k <= n) total = k * x + (n-k) * y;
	else total = n * x;
	
	cout << total << endl;
	
	return 0;
}
