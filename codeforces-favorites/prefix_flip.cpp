#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        string a, b;
        cin >> a >> b;
        bool one = false;
        vector<int> ansa, ansb;
        for (int i = 0; i < n; i++) {
            if (a[i] == '1' && !one) {
                one = true; 
                if (i!= 0) {ansa.push_back(i);}
            }
            if (i == n-1 && a[i] == '1') {ansa.push_back(i+1);}
            if (a[i] == '0' && one) {ansa.push_back(i); one = false;}
        }
        one = false;
        for (int i = 0; i < n; i++) {
            if (b[i] == '1' && !one) {
                one = true; 
                if (i!= 0) {ansb.push_back(i);}
            }
            if (i == n-1 && b[i] == '1') {ansb.push_back(i+1);}
            if (b[i] == '0' && one) {ansb.push_back(i); one = false;}
        }
        cout << ansa.size() + ansb.size() << " ";
        for (int i = 0; i < ansa.size(); i++) {cout << ansa[i] << " ";}
        for (int i = ansb.size()-1; i >= 0; i--) {cout << ansb[i] << " ";}
        cout << "\n";
    }

    return 0;
}