#include <bits/stdc++.h>

using namespace std;

constexpr int inf = 1e9;
using Edge = tuple<int, int, int>; // u, v, w

/**
 * @brief Bellman-ford algorithm
 *
 * @return
 *  - dist[u] = inf => no path from s to u
 *  - dist[u] = -inf => path from s to u includes cycles
 *  - else dist[u] is the shortest path from s to u
 */
vector<int> bellman_ford(int n, int s, const vector<Edge>& edges) {
    vector<int> dist(n, inf);
    dist[s] = 0;
    for(int i = 1; i <= 2 * n - 1; ++i) {
        for(auto [u, v, w]: edges)      
            if(dist[u] != inf && dist[v] > dist[u] + w) { 
                if(i >= n)
                    dist[v] = -inf;                 
                else dist[v] = dist[u] + w;     
            }
    }
    return dist;
}

/**
 * @brief Detect negative cycle using Bellman-ford algorithm
 */
bool detect_negative_cycle(int n, int s, const vector<Edge>& edges) {
    vector<int> dist(n, inf);
    dist[s] = 0;
    for(int i = 1; i <= n; ++i) {
        for(auto [u, v, w]: edges)      
            if(dist[u] != inf && dist[v] > dist[u] + w) { 
                if(i == n)
                    return true;                 
                else dist[v] = dist[u] + w;     
            }
    }
    return false;
}
