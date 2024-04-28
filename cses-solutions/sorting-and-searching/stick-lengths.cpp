#include <iostream>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    ll p[n];
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    sort(p, p + n);
    ll median = p[n/2], ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(median - p[i]);
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}