#include <iostream>
#include <vector>
#define ll long long
using namespace std;


void solve() {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());
    // look through the array and make a new target
    // the problem then becomes sum of two values
    for (int i = 0; i < n; i++) {
        int target = x - v[i].first;
        if (target < 2) {
            continue;
        }
        int l = 0, r = n - 1;
        while (l < r) {
            l += (l == i);
            r -= (r == i);
            if (l == r) {
                break;
            }
            if (v[l].first + v[r].first == target) {
                cout << v[i].second << ' ' << v[l].second << ' ' << v[r].second << '\n';
                return;
            }
            else if (v[l].first + v[r].first < target) {
                l++;
            }
            else {
                r--;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}