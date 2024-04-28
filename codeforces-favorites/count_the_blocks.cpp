#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll mod = 998244353;
ll powmod(ll a, ll e) {
  int p = 1;
  while(e) {
    if (e & 1) p = (p * a) % mod;
    e >>= 1;
    a = (a * a) % mod;
  }
  return p;
}

 
int main()
{
    ll n; cin >> n;
    ll rtn[n];
    ll cur = 0, cur1 = 0;
    for (int i = 0; i < n; i++)
    {
        ll temp = powmod(10, i+1)*(i+1);
        temp += mod;
        temp -= cur;
        temp %= mod;
        
        rtn[i] = temp;
        
        cur1 += rtn[i];
        cur1 %= mod;
        cur += cur1;
        cur %= mod;
        cur += rtn[i];
        cur %= mod;
    }
    
    for (int i = n-1; i >= 0; i--) {cout << rtn[i]%mod << " ";}
    return 0;
}
