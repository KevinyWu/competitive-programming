#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    int R, G, B, r[201], g[201], b[201];
	cin >> R >> G >> B;
	for(int i = 0; i < R; i++) {cin >> r[i];}
	for(int i = 0; i < G; i++) {cin >> g[i];}
	for(int i = 0; i < B; i++) {cin >> b[i];}
    int dp[201][201][201];
	sort(r, r+R);
	sort(g, g+G);
	sort(b, b+B);
	for(int i=0; i<=R; i++) {
		for(int j = 0; j <= G; j++) {
			for(int k = 0; k <= B; k++) {
				if(i&&j) {dp[i][j][k] = dp[i-1][j-1][k]+r[i-1]*g[j-1];}
				if(i&&k) {dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1]+r[i-1]*b[k-1]);}
				if(k&&j) {dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1]+g[j-1]*b[k-1]);}
			}
		}
	}
	cout << dp[R][G][B];
}
