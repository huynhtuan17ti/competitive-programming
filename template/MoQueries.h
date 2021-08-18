#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int block_size;

int a[MAXN+5];
int cnt[MAXN+5];
int exist[MAXN+5];

struct query{
    int l, r, pos;
};

// remove a[pos]
void del(int pos){
    if(pos == 0)
        return;
    // ...
}

// add a[pos]
void add(int pos){
    if(pos == 0)
        return;
    // ...
}

// compute current answer
int calc(){
    // ...
}

vector <int> MoQueries(int n, vector <query> Q){
    block_size = sqrt(n);
    sort(Q.begin(), Q.end(), [](const query &A, const query &B){
        return (A.l/block_size != B.l/block_size)? (A.l/block_size < B.l/block_size) : (A.r < B.r);
    });
    vector <int> res;
    res.resize((int)Q.size());

    int L = 1, R = 0;
    for(query q: Q){
        while (L > q.l) add(--L);
        while (R < q.r) add(++R);

        while (L < q.l) del(L++);
        while (R > q.r) del(R--);
        
        res[q.pos] = calc();
    }
    return res;
}