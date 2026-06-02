#include <bits/stdc++.h>
using namespace std;

string line;
int p = 0;

int pol(){
    char c = line[p ++];
    if (isdigit(c))
        return c-'0';
    else {
        if (c == '+')
            return pol() + pol();
        else if (c == '-')
            return pol() - pol();
        else if (c == '*')
            return pol() * pol();
        else if (c == '/')
            return pol() / pol();
    }
}

int     main(){
    cin >> line;
    cout << pol() << endl;
    return 0;
}
