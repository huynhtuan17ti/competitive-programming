#include<bits/stdc++.h>
 
using namespace std;
 
#define task "sol"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(),(v).end()
#define endl '\n'
 
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
 
const int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const int dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod = 1000000007; /// 998244353
const ll base = 331;
 
int n,e[305][305];
int m, a[305];
bool virus[305],vis[305];
int sub[305];
 
bool dfs(int u)
{
    sub[u]=1;
    vis[u]=1;
    bool ok=(virus[u]==0);
    for (int v=1;v<=n;++v) if (!vis[v]&&e[u][v])
    {
        ok&=dfs(v);
        sub[u]+=sub[v];
    }
    return ok;
}
int solve()
{
    for (int i=1;i<=n;++i) vis[i]=0, sub[i]=0;
    int ans=0;
    for (int i=1;i<=n;++i) if (!vis[i])
    {
        if (!dfs(i))
        {
//            cout<<sub[i]<<'\n';
            ans+=sub[i];
        }
    }
    return ans;
}
void gogo()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    for (int j=1;j<=n;++j) cin>>e[i][j];
    while (true)
    {
        int x=-1;
        cin>>x;
        if (x==-1) break;
        x++;
        virus[x]=1;
    }
 
    int ans=solve(), node=1;
//    cout<<ans<<endl;
    for (int i=1;i<=n;++i) if (virus[i])
    {
        bool ok=0;
        if (virus[i]) ok=1;
 
        virus[i]=0;
        int val=solve();
        if (val<ans)
        {
            cout<<i-1;
            return;
        }
 
        virus[i]=ok;
    }
 
    for (int i=1;i<=n;++i) if (virus[i])
    {
        cout<<i-1;
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r"))
    {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    gogo();
}
