#include <iostream>
#include <map>
#define ll long long
using namespace std;


void solve() {
    int n, x; cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        if (mp.count(x - a[i])) {
            cout << i + 1 << ' ' << mp[x - a[i]] << '\n';
            return;
        }
        mp[a[i]] = i + 1;
    }
    cout << "IMPOSSIBLE\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}