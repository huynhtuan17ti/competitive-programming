//Tuan Kkura
#include <bits/stdc++.h>

using namespace std;
#define PROB "text"
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef pair <int, int> ii;
typedef vector <ii> vii;
 
#define MAXN 200005

int calc(int val){
    int sum = 0;
    while(val > 0){
        sum += val%10;
        val /= 10;
    
    }
    return sum;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int sumFi = 0, sumSe = 0;
        for(int i = 0; i < n; i++){
            int a, b; cin >> a >> b;
            if(calc(a) == calc(b))   sumFi++, sumSe++;
            if(calc(a) > calc(b))   sumFi ++;
            if(calc(a) < calc(b))   sumSe ++;
        }
        if(sumFi == sumSe)   cout << 2 << ' ' << sumFi << '\n';
        if(sumFi > sumSe)   cout << 0 << ' ' << sumFi << '\n';
        if(sumFi < sumSe)   cout << 1 << ' ' << sumSe << '\n';
    }
}