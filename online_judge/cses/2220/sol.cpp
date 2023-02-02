#include <bits/stdc++.h>  
using namespace std;
 
const int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 3e5 + 5;
const int MAX_DIGITS = 19;

vector<int> getDigits(ll x) {
	vector<int> digits;
	while(x > 0) {
		digits.push_back(x % 10);
		x /= 10;
	}
	reverse(digits.begin(), digits.end());
	return digits;
}

uint64_t dp[MAX_DIGITS + 1][2][2][10]; // [pos][is_greater][is_start][last_digit]

uint64_t calc(int64_t x) {
	if(x < 0) return 0;
	if(x == 0) return 1;

	vector<int> digits = getDigits(x);
	memset(dp, 0, sizeof(dp));
	
	dp[0][0][0][digits[0]] = 1;
	dp[0][1][1][0] = 1;
	for(int d = 1; d < digits[0]; ++d)
		dp[0][1][0][d] = 1;
	
	int n = (int)digits.size();
	for(int i = 1; i < n; ++i) {
		// is_greater = 0
		if(digits[i-1] != digits[i])
			dp[i][0][0][digits[i]] += dp[i-1][0][0][digits[i-1]];
		
		// is_greater = 1
		for(int d = 0; d < 10; ++d) {
			if(d < digits[i] && digits[i-1] != d)
				dp[i][1][0][d] += dp[i-1][0][0][digits[i-1]];
			
			for(int pre_d = 0; pre_d < 10; ++pre_d)
				if(pre_d != d)
					dp[i][1][0][d] += dp[i-1][1][0][pre_d];	

			dp[i][1][d == 0][d] += dp[i-1][1][1][0];
		}
	}
	uint64_t cnt = 0;
	for(int d = 0; d < 10; ++d)
		cnt += dp[n-1][0][1][d] + dp[n-1][1][1][d] + dp[n-1][0][0][d] + dp[n-1][1][0][d];
	// cout << cnt << '\n';
	return cnt;
}

int main() {
	io
	uint64_t a, b;
	cin >> a >> b;

	cout << calc(b) - calc(a-1);
}
