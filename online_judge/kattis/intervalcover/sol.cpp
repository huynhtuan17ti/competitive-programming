#include <bits/stdc++.h>  
using namespace std;
 
constexpr int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<double, double> dd;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};
constexpr int MAXN = 3e5 + 5;
constexpr int INF = 1e9;

struct Interval {
    double u, v;
    int id;
};

int main() {
    io
    double A, B;
    while(cin >> A >> B) {
        int n; cin >> n;
        vector<Interval> intervals;
        for(int i = 0; i < n; ++i) {
            double u, v;
            cin >> u >> v;
            intervals.push_back({u, v, i});
        }
        sort(intervals.begin(), intervals.end(), [](const Interval &C, const Interval &D){
            return C.u == D.u ? C.v > D.v : C.u < D.u;
        });

        vector<int> ans;
        int i = 0;
        int max_right_idx = -1;
        for(; i < n && intervals[i].u <= A; ++i) {
            if(max_right_idx == -1 || intervals[max_right_idx].v < intervals[i].v)
                max_right_idx = i;
        }
        if(max_right_idx == -1 || intervals[max_right_idx].v < A) {
            cout << "impossible\n";
            continue;
        }
        ans.push_back(intervals[max_right_idx].id);
        int j = i;
        while(j < n && intervals[max_right_idx].v < B) {
            int k = max_right_idx;
            while(j < n && intervals[j].u <= intervals[max_right_idx].v) {
                if(intervals[k].v < intervals[j].v)
                    k = j;
                ++j;
            }
            if(k == max_right_idx) {
                break;
            }
            ans.push_back(intervals[k].id);
            max_right_idx = k;
        }
        if(intervals[max_right_idx].v < B) {
            cout << "impossible\n";
            continue;
        }
        cout << ans.size() << '\n';
        for(int u: ans)
            cout << u << " ";
        cout << '\n';
    }
}
