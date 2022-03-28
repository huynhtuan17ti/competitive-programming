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
const int N=5e5+5;

int par[N];
int n,k;

int root(int u)
{
    return (par[u]<0?u:par[u]=root(par[u]));
}
void join(int u, int v)
{
    if ((u=root(u))==(v=root(v))) return;
    if (par[u]>par[v]) swap(u,v);
    par[u]+=par[v];
    par[v]=u;
}
void gogo()
{
    cin>>n>>k;
    memset(par,-1,sizeof(par));

    for (int i=1;i<=k;++i)
    {
        int num;
        cin>>num;
        if (num==0) continue;
        int p;
        cin>>p;
        for (int j=1;j<num;++j)
        {
            int x;
            cin>>x;
            join(x,p);
        }
    }

    for (int i=1;i<=n;++i) cout<<-par[root(i)]<<" ";
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