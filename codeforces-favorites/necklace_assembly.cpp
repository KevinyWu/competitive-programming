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
        string s; cin >> s;
        map <char, int> cnt;
        for (int i = 0; i < n; i++) {cnt[s[i]]++;}
        for (int i = n; i >= 1; i--) {
            int t = i/__gcd(i, k);
            int c = 0;
            for (auto j : cnt) {c += j.second/t;}
            if (c*t >= i) {
                cout << i << "\n";
                break;
            }
        }
    }

    return 0;
}
