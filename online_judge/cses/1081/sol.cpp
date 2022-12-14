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
const int MAX_VALUE = 1e6;
int cnt[MAX_VALUE + 1];

int main() {
	io
	int n; cin >> n;
	for(int i = 1; i <= n; i++) {
		int x; cin >> x;
		cnt[x]++;
	}

	for(int g = MAX_VALUE; g >= 1; g--) {
		int num = 0;
		for(int d = g; d <= MAX_VALUE; d += g) {
			num += cnt[d];
		}
		if(num >= 2)
			return cout << g, 0;
	}
}
