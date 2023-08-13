#include <iostream>
#define ll long long
using namespace std;


void solve() {
    int n, x; cin >> n >> x;
    int p[n];
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    sort(p, p + n);
    int i = 0, j = n - 1, ans = 0;
    while (i <= j) {
        if (p[i] + p[j] <= x) {
            i++;
            j--;
        }
        else {
            j--;
        }
        ans++;
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}