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
        int t = myIntRand(1, 3);
        inp << t << '\n';
        while(t--){
            int l = myLLRand(1, 100), r = myLLRand(l, l + 1000);
            inp << l << ' ' << r << '\n';
        }
        // random generate code here
        inp.close();

        system("./sol");
        system("./brute_sol");
        
        if (system(("diff " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}