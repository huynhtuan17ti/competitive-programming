#include <bits/stdc++.h>  
using namespace std;
 
constexpr int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<long, int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr int MAXN = 5001;
constexpr ll INF = -1e14;

int main() {
    io
    int N, M;
    cin >> N >> M;
    vector<int> A(N+1), B(M+1);

    vector<int> S;
    unordered_map<int, bool> mark;
    unordered_map<int, int> index;

    for(int i = 1; i <= N; ++i) {
        cin >> A[i];
        mark[A[i]] = true;
    }
    for(int i = 1; i <= M; ++i) {
        cin >> B[i];
        if(mark[B[i]])
            S.push_back(B[i]);
    }

    S.push_back(INT_MIN);
    sort(S.begin(), S.end());
    int K = (int)S.size() - 1;
    for(int i = 1; i <= K; ++i) {
        index[S[i]] = i;
    }

    vector<ll> tmp(K+1); 
    vector<ll> dp(M+1, -1);
    ll ans = 0;
    for(int i = 1; i <= N; ++i) {
        int P = index[A[i]];
        if(P == 0) continue;
        fill(tmp.begin(), tmp.end(), INF);
        for(int j = 1; j <= M; ++j) {
            if(dp[j] >= 0)
                tmp[P] = max(tmp[P], dp[j] + abs(B[j] - A[i]));
            if(A[i] == B[j]) {
                if(dp[j] < 0) dp[j] = 0;
                dp[j] = max(dp[j], tmp[P]);
            }
            ans = max(ans, dp[j]);
        }
    }

    cout << ans << '\n';
}
