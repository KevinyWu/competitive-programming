#include <iostream>
#include <vector>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    vector<int> towers; // stores top cube's size in increasing order
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        // use binary search to find smallest tower that can hold k
        int l = 0, r = towers.size();
        while (l < r) {
            int mid = (l + r)/2;
            if (towers[mid] > k) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        if (l == towers.size()) {
            towers.push_back(k);
        }
        else {
            towers[l] = k;
        }
    }
    cout << towers.size() << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}