#include <bits/stdc++.h>
using namespace std;
    
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
    {
        double n; cin >> n;
        n *= 2.0;
        double pi = 2.0*acos(0.0);
	    double angle = pi/(n);
		double len = 1.0/sin(angle);
		angle /= 2.0;
	    double ans = len*cos(angle);
	    
	    cout << fixed;
        cout << setprecision(9);
        cout << ans << "\n";
    }
 
    return 0;
}
