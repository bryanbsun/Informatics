#include <bits/stdc++.h>
using namespace std;
int	main(){
	int n, m, points[5010];
	int x, y, nowant;

	cin >> n >> m;
	memset(points, 0, sizeof(int)*5010);

	for (int i = 0; i < n; i ++){
		cin >> x >> y;
		for (int j = x; j <= y; j ++)
			points[j] = 1;
	}

	nowant = 0;
	for (int i = 1; i <= m; i ++)
	       nowant += (points[i] == 0);
	cout << nowant << endl;
	if (!nowant){
		for (int i = 1; i <= m; i ++)
			if (points[i] == 0)
				cout << i << " ";
		cout << endl;	
	}
	
	return 0;
}
