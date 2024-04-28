#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin>>n;
        vector<int>inc;
        for (int i = 1; i <= n; i*=2) {
            inc.push_back(i);
            n -= i;
        }
        if (n>0) {
            inc.push_back(n);
            sort(inc.begin(), inc.end());
        }
        cout << inc.size() - 1 << "\n";
        for (int i = 1; i < inc.size(); i++) {
            cout << inc[i] - inc[i-1] << ' ';
        }
        cout << "\n";
    }
    return 0;
}