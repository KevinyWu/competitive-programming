#include <iostream>
#define ll long long
using namespace std;


// check number of adjacent decreases around the two indices anum and bnum (max 4)
int check_dec(int inds[], int anum, int bnum, int n) {
    int num_dec = (anum > 1 && inds[anum] < inds[anum-1]) + (inds[anum+1] < inds[anum]) +
                  (inds[bnum] < inds[bnum-1]) + (bnum < n && inds[bnum+1] < inds[bnum]) -
                  (anum + 1 == bnum && inds[bnum] < inds[anum]); // subtract 1 when double counting is possible
    return num_dec;
}


void solve() {
    int n, m; cin >> n >> m;
    int num[n+1], inds[n+1], ans = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
        inds[num[i]] = i;
    }
    // count the number of adjacent decreases in the inds array
    for (int i = 2; i <= n; ++i) {
        if (inds[i] < inds[i-1]) {
            ans++;
        }
    }
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        if (a == b) {
            cout << ans << '\n';
            continue;
        }
        // max and min of the two numbers the indices a and b access
        int anum = min(num[a], num[b]), bnum = max(num[a], num[b]);
        // we want to check the number of adjacent decreases around anum and bnum,
        // then swap them and check again to get the difference, and add this to ans
        // like in collecting-numbers, ans is always the total number of adjacent decreases
        int num_dec_before = check_dec(inds, anum, bnum, n);
        swap(inds[anum], inds[bnum]);
        int num_dec_after = check_dec(inds, anum, bnum, n);
        swap(num[a], num[b]);
        ans += (num_dec_after - num_dec_before);
        cout << ans << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}