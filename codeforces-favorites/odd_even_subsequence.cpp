#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int n, k;
int a[200000];
 
bool check(int x, int cur)
{
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if(!cur) {ans++; cur = 1;}
        else {
            if(a[i] <= x) {ans++; cur = 0;}
        }
    }
    return ans >= k;
}
 

int binsearch(int lo, int hi)
{
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid, 0) || check(mid, 1)) {hi = mid;}
        else {lo = mid + 1;}
    }
    return lo;
}
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {cin >> a[i];}
    cout << binsearch(1, 1e9) << "\n";
}