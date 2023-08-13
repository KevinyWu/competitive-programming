#include <iostream>
#include <set>
#define ll long long
using namespace std;


set<string> strings;

// for every character suff[i] in the suffix, we can add it to the prefix
// recursively solve the problem with the new prefix and the suffix without suff[i]
void add_strings(string pref, string suff) {
    int n = suff.length();
    if (n == 0) {
        strings.insert(pref);
        return;
    }
    for (int i = 0; i < n; ++i) {
        add_strings(pref + suff[i], suff.substr(0, i) + suff.substr(i + 1));
    }
}


void solve() {
    string s; cin >> s;
    add_strings("", s);
    cout << strings.size() << '\n';
    for (const auto& str : strings) {
        cout << str << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}