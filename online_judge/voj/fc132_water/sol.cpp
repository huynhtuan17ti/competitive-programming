#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int MAXN = 5e5 + 5;

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n + 1] = 0;

    vector<int> L(n + 1), R(n + 1);
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && a[i] >= a[st.top()])
            st.pop();
        if (st.empty())
            L[i] = 0;
        else
            L[i] = st.top();
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n; i >= 1; i--)
    {
        while (!st.empty() && a[i] >= a[st.top()])
            st.pop();
        if (st.empty())
            R[i] = n + 1;
        else
            R[i] = st.top();
        st.push(i);
    }
    ll total = 0;
    vector<int> maxL(n + 2), maxR(n + 2);
    for (int i = 1; i <= n; i++)
        maxL[i] = max(maxL[i - 1], a[i]);
    for (int i = n; i >= 1; i--)
    {
        maxR[i] = max(maxR[i + 1], a[i]);
        total += max(0, min(maxR[i], maxL[i]) - a[i]);
    }
    int bonus = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[L[i]] > a[i] && a[i] > a[R[i]])
            bonus = max(bonus, i - L[i] - 1);

        if (a[L[i]] <= a[i] && a[i] < a[R[i]])
            bonus = max(bonus, R[i] - i - 1);
    }
    cout << total + bonus;
}