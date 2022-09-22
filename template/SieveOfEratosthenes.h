#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e6;
int factor[MAXN + 5];

vector <int> primes;

void build_sieve(){
    for(int i = 2; i <= MAXN; i++)
        factor[i] = i;
    for(int i = 4; i <= MAXN; i+=2)
        factor[i] = 2;
    for(int i = 3; i*i <= MAXN; i++)
        if(factor[i] == i)
            for(int j = i*i; j <= MAXN; j+=i)
                if(factor[j] == j)
                    factor[j] = i;

    
    for(int i = 2; i <= MAXN; i++){
        if(factor[i] == i)
            primes.push_back(i);
    }
}