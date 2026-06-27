#include <bits/stdc++.h>
using namespace std;
int	main(){
	int n, a[105], c=0;
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> a[i];

	sort(a, a + n);
	for (int i = 0; i < n; i ++){
		if (a[i]){
			for (int j = i+1; j <= n; j++)
				if (a[j]%a[i] == 0)
					a[j] = 0;
			c ++;
		}
	}

	cout << c << endl;

	return 0;
}
