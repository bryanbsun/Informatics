#include <bits/stdc++.h>
using namespace std;

int cur = 0;
int p[3]{0};

int	main(){
	string s[3];
	cin >> s[0] >> s[1] >> s[2];
	
	while (1){
		if (p[cur] == s[cur].length()){
			cout << (char)(cur + 'A') << endl;	
			break;
		}
		cur = s[cur][p[cur]++] - 'a';
	}
	return 0;
}
