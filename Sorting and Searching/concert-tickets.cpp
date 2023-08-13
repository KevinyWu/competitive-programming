#include <iostream>
#include <set>
#define ll long long
using namespace std;


void solve() {
    int n, m; cin >> n >> m;
    multiset<int> tickets;
    for (int i = 0; i < n; ++i) {
        int h; cin >> h;
        tickets.insert(h);
    }
    for (int i = 0; i < m; ++i) {
        int t; cin >> t;
        auto it = tickets.upper_bound(t);
        if (it == tickets.begin()) {
            cout << -1 << '\n';
        }
        else {
            it--;
            cout << *it << '\n';
            tickets.erase(it);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}