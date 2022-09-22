#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef vector <ii> vii;
#define fi first
#define se second

// input and output file name
const string NAME = "test";
// number of testcases
const int NTEST = 100;

random_device device;
mt19937 generator(device());

int myIntRand(int lo, int hi) {
    uniform_int_distribution<int> rd(lo, hi);
    return rd(generator);
}

ll myLLRand(ll lo, ll hi) {
    uniform_int_distribution<ll> rd(lo, hi);
    return rd(generator);
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        int n = myIntRand(3, 6);
        int q = myIntRand(1, 3);
        inp << n << ' ' << q << '\n';
        for(int i = 1; i <= n; i++)
            inp << myIntRand(1, 8) << " \n"[i == n];
        vector<int> perm(n);
        for(int i = 0; i < n; i++) perm[i] = i+1;
        random_shuffle(perm.begin(), perm.end());
        for(int i = 1; i < n; i++){
            int u = perm[i];
            int v = perm[myIntRand(0, i-1)];
            inp << u << ' ' << v << '\n';
        }
        while(q--){
            int u = myIntRand(1, n);
            int v = myIntRand(1, n);
            inp << u << ' ' << v << '\n';
        }
        inp.close();

        system("./sol");
        system("./brute");
        
        if (system(("diff " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}