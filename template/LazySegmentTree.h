#include <bits/stdc++.h>
using namespace std;

template <typename T, typename F = function <T(const T&, const T&)>>
class LazySegmentTree{
    F func;
    T blank;
    struct node{
        T val, lazy;
        node(){
            val = lazy = 0;
        }
    };
    public:
        vector <node> IT;
        LazySegmentTree(int n, T blank, const F& f){
            IT.resize(4*n+5);
            this->func = f;
            this->blank = blank;
        }
        void push(int id, T val){
            IT[id].val += val;
            IT[id].lazy += val;
        }
        void down(int id){
            T k = IT[id].lazy;
            if(k == blank)
                return;

            push(2*id, k);
            push(2*id+1, k);

            IT[id].lazy = blank;
        }
        void update(int id, int l, int r, int u, int v, T val){
            if(v < l || r < u)
                return;
            if(u <= l && r <= v){
                push(id, val);
                return;
            }
            down(id);
            int mid = (l+r) >> 1;
            update(2*id, l, mid, u, v, val);
            update(2*id+1, mid+1, r, u, v, val);
            IT[id].val = func(IT[2*id].val, IT[2*id+1].val);
        }
        T get(int id, int l, int r, int u, int v){
            if(v < l || r < u)
                return blank;
            if(u <= l && r <= v)
                return IT[id].val;
            down(id);
            int mid = (l+r) >> 1;
            T L = get(2*id, l, mid, u, v);
            T R = get(2*id+1, mid+1, r, u, v);
            return func(L, R);
        }
};