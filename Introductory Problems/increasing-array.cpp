#include <iostream>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    int a[n];
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0 && a[i] < a[i-1]) {
            ans += a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}