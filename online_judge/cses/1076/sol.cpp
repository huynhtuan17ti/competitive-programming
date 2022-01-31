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
const int MAXN = 500005;

class MedianQueue{
private:
    multiset <int, greater <int>> left; // max set
    multiset <int> right; // min set;

    void makeBalance(){
        while(*left.begin() > *right.begin()){
            auto it = left.begin();
            right.insert(*it);
            left.erase(it);
        }
        while(left.size() < right.size()){
            auto it = right.begin();
            left.insert(*it);
            right.erase(it);
        }
        while(left.size() > right.size() + 1){
            auto it = left.begin();
            right.insert(*it);
            left.erase(it);
        }
    }

public:
    void push(int val){
        left.insert(val);
        makeBalance();
    }
    int get(){
        assert(left.size() > 0);
        return *left.begin();
    }
    void pop(int val){
        if(val <= get()){
            auto it = left.find(val);
            left.erase(it);
        }
        else{
            auto it = right.find(val);
            right.erase(it);
        }
        makeBalance();
    }
// debugging
public:
    void print(){
        cout << "------------------------" << '\n';
        cout << "Left: ";
        for(auto it: left)
            cout << it << ' ';
        cout << '\n';
        cout << "Right: ";
        for(auto it: right)
            cout << it << ' ';
        cout << '\n';
    }
};

int main(){
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    io
    int n, k;
    cin >> n >> k;
    vector <int> a(n+1);
    MedianQueue q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        q.push(a[i]);
        if(i > k)
            q.pop(a[i-k]);
        //q.print();
        if(i >= k)
            cout << q.get() << ' ';
    }
}