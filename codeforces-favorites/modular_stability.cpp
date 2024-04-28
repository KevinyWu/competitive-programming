#include <iostream>
#define ll long long
using namespace std;
 

const ll MOD = 998244353, MAXN = 500005;
ll fact[MAXN];
 
void calcFacts() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
}
 

ll powMod(ll a, ll e) {
    int r = 1;
    while (e) {
        if (e & 1)
            r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

 
ll invMod(ll a) {
    return powMod(a, MOD - 2);
}
 
 
ll choose(ll n, ll k) {
    if (k > n)
        return 0;
    return (fact[n] * invMod((fact[k] * fact[n - k]) % MOD)) % MOD;
}
 

int main() {
    calcFacts();
 
    ll n, k;
    cin >> n >> k;
 
    ll answer = 0;
    for (int i = 1; i < MAXN; i++) {
        answer = (answer + choose(n / i - 1, k - 1)) % MOD;
    }
 
    cout << answer;
}