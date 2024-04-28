#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {cin >> a[i];}
        int forward[n+1][n] = {0}, reverse[n+1][n] = {0};
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n-1; j++) {
                if (a[j] == i) {forward[i][j]++;}
                if (j > 0) {forward[i][j] += forward[i][j-1];}
            }
            for (int j = n-1; j >= 0; j--) {
                if (a[j] == i) {reverse[i][j]++;}
                if (j < n-1) {reverse[i][j] += reverse[i][j+1];}
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n-3; i++) {
            for (int j = i+1; j <= n-2; j++) {
                ans += forward[a[j]][i-1]*reverse[a[i]][j+1];
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
