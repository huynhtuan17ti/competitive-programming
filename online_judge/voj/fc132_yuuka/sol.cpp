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

int a[3][3], sum[3][3];
ll totalLevel[20];
int mapLevelSize[20];

struct Block{
    int x, y;
    int u, v;
    ii norm(int blockSize){
        // cerr << blockSize << '\n';
        // cerr << x << ' ' << y << ' ' << u << ' ' << v << '\n';
        assert(x/blockSize == u/blockSize && y/blockSize == v/blockSize);
        int X = x/blockSize;
        int Y = y/blockSize;
        x %= blockSize;
        y %= blockSize;
        u %= blockSize;
        v %= blockSize;
        return {X, Y};
    }
};

vector <Block> getDividedBlocks(Block cur, vector <int> x_points, vector <int> y_points){
    vector <Block> ans;

    for(int iy = 0; iy < y_points.size() - 1; iy++)
        for(int ix = 0; ix < x_points.size() - 1; ix++){
            Block cur = {x_points[ix], y_points[iy], x_points[ix+1]-1, y_points[iy+1]-1};
            if(cur.x <= cur.u && cur.y <= cur.v)
                ans.push_back(cur);
        }
    
    return ans;
}

ll calc(int deepLevel, Block cur){
    if(cur.x == 0 && cur.y == 0 && 
        cur.u == mapLevelSize[deepLevel]-1 && cur.v == mapLevelSize[deepLevel]-1)
        return totalLevel[deepLevel];

    if(deepLevel == 1){
        int total = sum[cur.v][cur.u];
        if(cur.x >= 1) total -= sum[cur.v][cur.x-1];
        if(cur.y >= 1) total -= sum[cur.y-1][cur.u];
        if(cur.x >= 1 && cur.y >= 1) total += sum[cur.y-1][cur.x-1];
        return total;
    }
    int curBlockSize = mapLevelSize[deepLevel] / 3;
    vector <int> x_points = {cur.x};
    vector <int> y_points = {cur.y};
    vii in_points;
    for(int p = curBlockSize-1; p < 2*curBlockSize; p += curBlockSize){
        if(cur.x <= p && p <= cur.u)
            x_points.push_back(p+1); 
        if(cur.y <= p && p <= cur.v)
            y_points.push_back(p+1);
    }

    x_points.push_back(cur.u+1);
    y_points.push_back(cur.v+1);
    // for(int x: x_points)
    //     cout << x << ' ';
    // cout << '\n';
    // for(int y: y_points)
    //     cout << y << ' ';
    // cout << '\n';

    vector <Block> blocks = getDividedBlocks(cur, x_points, y_points);
    ll total = 0;
    for(Block u: blocks){
        auto [ix, iy] = u.norm(curBlockSize);
        //cout << u.x << ' ' << u.y << ' ' << u.u << ' ' << u.v << '\n';
        if(a[iy][ix] == 1)
            total += calc(deepLevel-1, u);
    }
    return total;
}

int main(){
    io
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    mapLevelSize[0] = 1;
    for(int i = 1; i <= 19; i++)
        mapLevelSize[i] = mapLevelSize[i-1] * 3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> a[i][j];

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++){
            if(i >= 1) sum[i][j] += sum[i-1][j];
            if(j >= 1) sum[i][j] += sum[i][j-1];
            if(i >= 1 && j >= 1) sum[i][j] -= sum[i-1][j-1];
            sum[i][j] += a[i][j];
        }
    totalLevel[1] = sum[2][2];

    for(int level = 2; level <= 19; level++){
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                totalLevel[level] += a[i][j] * totalLevel[level-1];
    }

    int q; cin >> q;
    while(q--){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        cout << calc(19, {y, x, v, u}) << '\n';
    }
}