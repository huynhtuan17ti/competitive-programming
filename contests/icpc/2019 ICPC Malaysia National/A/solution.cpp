/* Tuan Kkura */
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define base 31
#define MOD 1e9+7
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORs(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, a, b) for(int i = a; i < b; i++)
#define __FOR(i, a, b, k) for(int i = a; i <= b; i+= k)
#define __REP(i, a, b, k) for(int i = a; i < b; i+= k)
#define pb push_back
#define _io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
#define fi first
#define se second
#define mp make_pair
#define PROB "text"
#define MAXN 1005

char a[MAXN][MAXN];
char b[MAXN][MAXN];

char Next[] = {'<', '^', '>', 'v'};
map <char, int> pos;

void Rotate(int n, int t){
    if(t == 1){
        for(int j = 1, n_i = 1; j <= n; j++, n_i++)
            for(int i = n, n_j = 1; i >= 1; i--, n_j++)
                if(a[i][j] != '.'){
                    int curPos = pos[a[i][j]];
                    int NextPos = (curPos + 1)%4;
                    b[n_i][n_j] = Next[NextPos];
                }else b[n_i][n_j] = '.';
    }else{
        for(int j = n, n_i = 1; j >= 1; j--, n_i++)
            for(int i = 1, n_j = 1; i <= n; i++, n_j++)
                if(a[i][j] != '.'){
                    int curPos = pos[a[i][j]];
                    int NextPos = (curPos - 1 + 4)%4;
                    b[n_i][n_j] = Next[NextPos];
                }else b[n_i][n_j] = '.';
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            a[i][j] = b[i][j];
}

int main(){
    _io
    for(int i = 0; i < 4; i++)
        pos[Next[i]] = i;
    int n; string s;
    cin >> n >> s;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    int sum = 0;
    for(char c: s){
        if(c == 'L')
            sum -= 1;
        else if(c == 'R')
            sum += 1;
    }
    bool isLeft = false;
    if(sum < 0){
        isLeft = true;
        sum = abs(sum);
    }
    sum %= 4;
    if(isLeft){
        for(int i = 1; i <= sum; i++)
            Rotate(n, 0);
    }else{
        for(int i = 1; i <= sum; i++)
            Rotate(n, 1);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << a[i][j];
        cout << '\n';
    }
}