#include <iostream>
#include <set>
#define ll long long
using namespace std;


void solve() {
    int n, k; cin >> n >> k;
    int a[n], b[k];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        // if k = 1 just print the elements
        if (k == 1) {
            cout << a[i] << ' ';
        }
        if (i < k) {
            b[i] = a[i];
        }
    }
    if (k == 1) {
        return;
    }
    // store initial window of elements left and right of median
    multiset<int> left, right;
    sort(b, b + k);
    for (int i = 0; i < k; i++) {
        if (i < (k + 1)/2) {
            left.insert(b[i]);
        }
        else if (i < k) {
            right.insert(b[i]);
        }
    }
    int median = *--left.end();
    cout << median << ' ';
    // as the window slides, update left and right accordingly
    for (int i = k; i < n; i++) {
        if (a[i - k] > median) {
            // erasing at a position (rather than an element)
            // removes only one occurrence of it in the multiset
            right.erase(right.find(a[i - k]));
            if (a[i] > median) {
                right.insert(a[i]);
            }
            else {
                right.insert(median);
                left.erase(--left.end());
                left.insert(a[i]);
                median = *--left.end();
            }
        }
        else {
            left.erase(left.find(a[i - k]));
            if (a[i] < *right.begin()) {
                left.insert(a[i]);
            }
            else {
                left.insert(*right.begin());
                right.erase(right.begin());
                right.insert(a[i]);
            }
            median = *--left.end();
        }
        cout << median << ' ';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}