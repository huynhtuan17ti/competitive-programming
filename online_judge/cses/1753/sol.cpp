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

vector<int> compute_z(const string &s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l, r;
    r = l = 0;
    for (int i = 1; i < n; ++i) {
        if (i > r) {
            l = r = i;
            while (r < n and s[r - l] == s[r])
                r++;
            z[i] = r - l;
            r--;
        } else {
            int k = i - l;
            if (z[k] < r - i + 1)
                z[i] = z[k];
            else {
                l = i;
                while (r < n and s[r - l] == s[r])
                    r++;
                z[i] = r - l;
                r--;
            }
        }
    }
    return z;
}

int main() {
	io
	string a, b;
	cin >> a >> b;

	auto z = compute_z(b + " " + a);
	int ans = 0;
	for(int i = b.length(); i < z.size(); ++i)
		ans += (z[i] == b.length());
	cout << ans << '\n';
}
