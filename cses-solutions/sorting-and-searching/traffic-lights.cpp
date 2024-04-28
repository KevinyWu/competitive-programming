#include <iostream>
#include <set>
#define ll long long
using namespace std;


void solve() {
    int x, n; cin >> x >> n;
    set<int> pos{0, x}; // stores positions
    multiset<int> len{x}; // stores lengths
    for (int i = 0; i < n; ++i) {
        int p; cin >> p;
        // find neighbors of p
        auto it_upper = pos.upper_bound(p);
        auto it_lower = it_upper;
        --it_lower;
        len.erase(len.find(*it_upper - *it_lower));
        len.insert(*it_upper - p);
        len.insert(p - *it_lower);
        pos.insert(p);
        auto ans = len.end();
        --ans;
        cout << *ans << " ";
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}