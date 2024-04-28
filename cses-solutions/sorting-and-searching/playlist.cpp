#include <iostream>
#include <map>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    int a[n+1];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    map<int, int> mp; // keep track of the last index of each id
    int unique[n+1], ans = 0; // unique[i] is the longest playlist ending with the ith song
    unique[0] = 0;
    for (int i = 1; i <= n; ++i) {
        // unique[i] is min of unique[i-1] + 1 and the length between the last occurence
        unique[i] = min(unique[i-1] + 1, i - mp[a[i]]);
        mp[a[i]] = i;
        ans = max(ans, unique[i]);
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}