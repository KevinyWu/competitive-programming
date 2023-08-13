#include <iostream>
#include <vector>
#include <map>
#define ll long long
using namespace std;


void solve() {
    int n, x; cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // record all pairwise sums and their indices
    map<int, vector<pair<int, int>>> mp;
    vector<pair<int, pair<int, int>>> pairs;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            mp[a[i] + a[j]].push_back({i + 1, j + 1});
            pairs.push_back({a[i] + a[j], {i + 1, j + 1}});
        }
    }
    // loop through each pair
    for (auto p : pairs) {
        auto p1 = p.second;
        // target is the sum you need for the other pair
        int target = x - p.first;
        if (!mp[target].empty()) {
            for (auto p2 : mp[target]) {
                // return a pair that sums to target and uses unique indices
                if (p1.first != p2.first && p1.first != p2.second && p1.second != p2.first && p1.second != p2.second) {
                    cout << p1.first << ' ' << p1.second << ' ' << p2.first << ' ' << p2.second << '\n';
                    return;
                }
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