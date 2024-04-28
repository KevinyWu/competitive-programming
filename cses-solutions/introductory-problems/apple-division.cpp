#include <iostream>
#include <vector>
#define ll long long
using namespace std;


vector<int> a;
ll tot = 0;

// recursively check the minimum difference if we include/don't include the ith apple
ll min_diff(int i, ll cursum) {
    if (i == 0) {
        return abs(tot - 2*cursum);
    }
    return min(min_diff(i-1, cursum + a[i]), min_diff(i-1, cursum));
}


void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a.push_back(x);
        tot += x;
    }
    cout << min_diff(n-1, 0) << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}