#include <iostream>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    ll a[n], sum = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }
    // one person reads in increasing order
    // the other reads the longest book, then the rest in increasing order
    // if the longest book is more than half the sum, there is overlap
    cout << max(sum, 2 * mx) << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}