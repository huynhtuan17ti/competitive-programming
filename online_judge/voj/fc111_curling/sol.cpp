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
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 5e5 + 5;

// (x1 - x2)^2 + (y1 - y2)^2 = 4*r^2
// => (y1 - y2)^2 = 4*R^2 - (x1 - x2)^2

int main(){
	io
	int n, r;
	cin >> n >> r;
	vector <int> xList(n);
	for(int &x: xList)
		cin >> x;
	
	vector <double> yList(n);
	for(int i = 0; i < n; i++){
		double ans = r;
		for(int j = 0; j < i; j++){
			int sqr_sumy = 4*r*r - (xList[i] - xList[j])*(xList[i] - xList[j]);
			if(sqr_sumy < 0)
				continue;
			double sumy = (double)sqrt(sqr_sumy);
			//cout << i << ' ' << sumy << '\n';
			double y = max(sumy - yList[j], yList[j] + sumy);
			ans = max(ans, y);
		}
		yList[i] = ans;
		cout << fixed << setprecision(4) << ans << ' ';
	}
}
