#include <bits/stdc++.h>  
#include <cmath>
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

template<typename T>
struct Matrix{
	static int dim;
    vector<vector<T>> data;
    
	Matrix(bool identity = false){
        data.resize(dim);
        for(int i = 0; i < dim; ++i)
            data[i].resize(dim, 0);
		if(identity)
			for(int i = 0; i < dim; ++i) data[i][i] = 1;
    }

	Matrix operator * (const Matrix<T> &other) {
		Matrix<T> res;
    	for(int k = 0; k < dim; ++k)
        	for(int i = 0; i < dim; ++i)
            	for(int j = 0; j < dim; ++j) {
                	res.data[i][j] += data[i][k] * other.data[k][j] % MOD;
					res.data[i][j] %= MOD;
				}
    	return res;
	}

	// fast calculating A^b
	static Matrix fastPow(Matrix<T> &A, ll b) {
		if(b == 0) return Matrix(true);
		if(b == 1) return A;
		Matrix t = fastPow(A, b>>1);
		t = t*t;
		if(b&1) t = t*A;
		return t;
	}
};

template<typename T>
int Matrix<T>::dim = 2;

int main() {
	io
	ll n; cin >> n;

	Matrix<ll> trans;
	trans.data[0][0] = 1; trans.data[0][1] = 1;
	trans.data[1][0] = 1; trans.data[1][1] = 0;

	Matrix<ll> base;
	base.data[0][0] = 1;
	base.data[1][0] = 1;

	if(n == 0) return cout << 0, 0;
	if(n == 1) return cout << 1, 0;

	Matrix<ll> ans = base * Matrix<ll>::fastPow(trans, n - 1);
	cout << ans.data[0][0] << '\n';
}
