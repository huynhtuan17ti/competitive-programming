## Template for competitive programming

| Template | Verification | Code |
| ----------- | ----------- |------------ |
| [FenwickTree](FenwickTree.h) | [INCVN](https://oj.vnoi.info/problem/incvn) |[incvn.cpp](../voj/INCVN%20(BIT%20TREE,%20DP)/sol.cpp) |
| [SparseTable](SparseTable.h) | [RMQSQ](https://www.spoj.com/problems/RMQSQ/) |[rmqsq.cpp](../spoj/RMQSQ%20(SPARSE%20TABLE)/sol.cpp) |
| [LazySegmentTree](LazySegmentTree.h) | [1555E](https://codeforces.com/contest/1555/problem/E) |[1555E.cpp](../codeforces/1555E%20(IT%20TREE,%20TWO%20POINTERS)/sol.cpp) |


## Code checking
```c++
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

        // random generate code here
        inp.close();

        system("./sol");
        system("./accept_sol");
        
        if (system(("diff " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
```
**Reference**: [vnoi tu code tu suong](https://vnoi.info/wiki/algo/skill/viet-trinh-cham.md)