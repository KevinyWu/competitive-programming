#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.length();
        int w, m; cin >> w >> m;
 
        vector<int> f(n + 1);
        for (int i = 0; i < n; i++) {
            f[i + 1] = f[i] + s[i] - '0';
        }
 
        vector<vector<int>> a(9);
        for (int i = 0; i + w <= n; i++) {
            int x = (f[i + w] - f[i]) % 9;
            a[x].push_back(i);
        }
 
        while(m--) {
            int l, r, k; cin >> l >> r >> k;

            int x = (f[r] - f[l - 1]) % 9;
            int ans1 = n, ans2 = n;
            for (int u = 0; u < 9; u++) {
                if (a[u].size() > 1 && (u * x + u) % 9 == k) {
                    if (a[u][0] < ans1) {
                        ans1 = a[u][0];
                        ans2 = a[u][1];
                    }
                    else if (a[u][0] == ans1 && a[u][1] < ans2) {
                        ans2 = a[u][1];
                    }
                }
                for (int v = 0; v < 9; v++) {
                    if (u != v && !a[u].empty() && !a[v].empty() && (u * x + v) % 9 == k) {
                        if (a[u][0] < ans1) {
                            ans1 = a[u][0];
                            ans2 = a[v][0];
                        }
                        else if (a[u][0] == ans1 && a[v][0] < ans2) {
                            ans2 = a[v][0];
                        }
                    }
                }
            }
            if (ans1 == n && ans2 == n) {cout << -1 << " " << -1 << "\n";} 
            else {cout << ans1 + 1 << " " << ans2 + 1 << "\n";}
        }
    }
    return 0;
}
