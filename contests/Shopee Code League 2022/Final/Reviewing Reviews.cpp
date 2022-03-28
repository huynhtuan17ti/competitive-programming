#include<bits/stdc++.h>
 
using namespace std;
 
#define task "sol"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define zs(v) ((ll)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(),(v).end()
#define endl '\n'
 
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
 
const ll dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const ll dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod = 998244353; /// 998244353
const ll base1 = 883;
const ll base2 = 907;
const ll N=1005;
 
ll n,m,r,c,a[1005][1005];
ll f[1005][1005];
ll pw1[N*N],pw2[N*N];
 
ll get(ll x, ll y, ll u, ll v)
{
    return (f[u][v]-f[x-1][v]-f[u][y-1]+f[x-1][y-1]+mod*mod)%mod;
}
void gogo()
{
    cin>>n>>m>>r>>c;
    for (ll i=1;i<=n;++i)
    for (ll j=1;j<=m;++j) cin>>a[i][j];
 
    pw1[0]=pw2[0]=1;
    for (ll i=1;i<=n*m;++i) pw1[i]=pw1[i-1]*base1%mod;
    for (ll i=1;i<=n*m;++i) pw2[i]=pw2[i-1]*base2%mod;
 
    ll val=0;
    for (ll i=1;i<=r;++i)
    for (ll j=1;j<=c;++j)
    {
        ll x;
        cin>>x;
        val=(val+(ll)x*pw1[i]%mod*pw2[j]%mod)%mod;
    }
 
    for (ll i=1;i<=n;++i)
    for (ll j=1;j<=m;++j)
    {
        f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
        f[i][j]%=mod;
        f[i][j]=(f[i][j]+mod)%mod;
        f[i][j]=(f[i][j]+(ll)a[i][j]*pw1[i]%mod*pw2[j]%mod)%mod;
    }
 
    ll ans=0;
 
    for (ll i=1;i<=n-r+1;++i)
    for (ll j=1;j<=m-c+1;++j)
    {
        ll temp=get(i,j,i+r-1,j+c-1);
        assert(temp>=0);
        ll mul=pw1[i-1]*pw2[j-1]%mod;
        if (temp==val*mul%mod) ans++;
    }
 
    cout<<ans;
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
 
 
