## Templates for competitive programming

| Template | Verification | Code |
| ----------- | ----------- |------------ |
| [ConvexHullTrick](ConvexHullTrick.h) | None | None |
| [FenwickTree](FenwickTree.h) | [INCVN](https://oj.vnoi.info/problem/incvn) | [incvn.cpp](../online_judge/voj/INCVN/sol.cpp) |
| [SparseTable](SparseTable.h) | [RMQSQ](https://www.spoj.com/problems/RMQSQ/) | [rmqsq.cpp](../online_judge/spoj/RMQSQ/sol.cpp) |
| [LazySegmentTree](LazySegmentTree.h) | [2166](https://cses.fi/problemset/task/2166/) | [2166.cpp](../online_judge/cses/2166/sol.cpp) |
| [SegmentTree](SegmentTree.h) | [2206](https://cses.fi/problemset/task/2206) | [2206.cpp](../online_judge/cses/2206/sol.cpp) |
| [ConvexHull](ConvexHull.h) | [MTRIAREA](https://oj.vnoi.info/problem/mtriarea) | [mtriarea.cpp](../online_judge/voj/MTRIAREA/sol.cpp) |
| [DSU](DSU.h) | [1559D1](https://codeforces.com/contest/1559/problem/D1) | [1559D1.cpp](../online_judge/codeforces/1559D1/sol.cpp) |
| [SieveOfEratosthenes](SieveOfEratosthenes.h) | None | None |
| [MoQueries](MoQueries.h) | [FREQ2](https://www.spoj.com/problems/FREQ2/) | [freq.cpp](../online_judge/spoj/FREQ2/sol.cpp) |
| [LCA](LCA.h)  | None  | None |
| [MatrixMuliplication](MatrixMulti.h) | [222E](https://codeforces.com/problemset/problem/222/E) | [222E.cpp](../online_judge/codeforces/222E/sol.cpp) |
| [Geometry](Geometry.h) | None | None |
| [PersistentSegmentTree](PersistentSegmentTree.h) | [1737](https://cses.fi/problemset/task/1737/) | [1737.cpp](../online_judge/cses/1737/sol.cpp) |
| [MaximumFlow](MaxFlow.h) | [1694](https://cses.fi/problemset/task/1694/) | [1694.cpp](../online_judege/cses/1694/sol.cpp) |
| [StronglyConnectedComponent](SCC.h) | None | None |
| [EulerPath](EulerPath.h) | None | None |
| [HashCounting](HashCounting.h) | None | None |
| [BridgeAndCriticalVertex](BridgeAndCriticalVertex.h) | None | None |
| [Trie](Trie.h) | [1731](https://cses.fi/problemset/task/1731) | [1731.cpp](../online_judge/cses/1731/sol.cpp) |
| [Zfunction](Zfunction.h) | [1753](https://cses.fi/problemset/task/1753) | [1753.cpp](../online_judge/cses/1753/sol.cpp) |
| [LiChaoTree](LiChaoTree.h) | None | None |
| [BellmanFord](BellmanFord.h) | None | None |
| [Floyd](Floyd.h) | None | None |


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

## Set memory stack
```c++
#include <sys/resource.h>

int main(){
    rlimit rlim;
    if (getrlimit(RLIMIT_STACK, &rlim)) return 1;
    rlim.rlim_cur = rlim.rlim_max;
    // You can set the fixed value instead of max value, e.g. rlim.rlim_cur = 1024 * 1024 * 1024
    // will set your stack size to 1 GiB
    if (setrlimit(RLIMIT_STACK, &rlim)) return 2;
}
```

**Reference**: [vnoi tu code tu suong](https://vnoi.info/wiki/algo/skill/viet-trinh-cham.md)
