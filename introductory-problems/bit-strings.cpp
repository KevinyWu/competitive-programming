#include <iostream>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    int MOD = 1e9 + 7;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= 2;
        ans %= MOD;
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}