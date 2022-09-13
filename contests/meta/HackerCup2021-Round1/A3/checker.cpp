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

        int t = 2;
        inp << t << '\n';
        while(t--){
            int k = myIntRand(10, 50);
            inp << k << '\n';
            for(int i = 0; i < k; i++){
                int p = myIntRand(0, 2);
                if(i == 0)  p = 1;
                if(p == 0)
                    inp << '.';
                else{
                    char d[] = {'O', 'F', 'X'};
                    inp << d[myIntRand(0, 2)];
                }
            }
            inp << '\n';
        }
        inp.close();

        system("./sol");
        system("./trau");
        
        if (system(("diff " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
