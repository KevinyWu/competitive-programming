#include <bits/stdc++.h>
#define ll long long
using namespace std;
 

vector<int> getprimes(ll MX) {
    vector<int> primes(MX, 0);
    for (int i = 2; i < MX; i++) {
        if (primes[i]) {continue;}
        for (int j = i; j < MX; j += i) {primes[j] = i;}
    }
    return primes;
}
 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> primes = getprimes(1e7+1);
    int n; cin >> n;
    int a[n];
    vector<int> rtn1(n, -1), rtn2(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int s = primes[a[i]];
        int M = a[i];
        int m = 1;
        while(M%s == 0) {
            m *= s;
            M /= s;
        }
        if (M != 1) {
            rtn1[i] = m;
            rtn2[i] = a[i]/m;
        }
    }
    
    for (int i = 0; i < n; i++) {cout << rtn1[i] << " ";}
    cout << "\n";
    for (int i = 0; i < n; i++) {cout << rtn2[i] << " ";}
    
    return 0;
}
