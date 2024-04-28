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
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {cin >> a[i];}
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = (l + r + 1)/2;
            vector<int> b = a;
            int ops = 0;
            for (int i = 0; i < n; ++i) {
                if (b[i] * 2 < mid) {
                    b[i] = 1e9;
                    ops++;
                }
            }
            if (k == ops) {
                bool good = false;
                for (int j = 0; j < n - 1; ++j) {
                    if (min(b[j], b[j+1]) >= mid) {
                        good = true;
                        break;
                    }
                }
                if (good) {l = mid;}
                else {r = mid - 1;}
            }
            else if (k - ops == 1 && *max_element(b.begin(), b.end()) >= mid) {l = mid;}
            else if (k - ops > 1) {l = mid;}
            else {r = mid - 1;}
        }
        cout << l << "\n";
    }
    return 0;
}