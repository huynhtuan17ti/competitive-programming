#include <bits/stdc++.h>
using namespace std;

vector<int> compute_z(const string &s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l, r;
    r = l = 0;
    for (int i = 1; i < n; ++i) {
        if (i > r) {
            l = r = i;
            while (r < n and s[r - l] == s[r])
                r++;
            z[i] = r - l;
            r--;
        } else {
            int k = i - l;
            if (z[k] < r - i + 1)
                z[i] = z[k];
            else {
                l = i;
                while (r < n and s[r - l] == s[r])
                    r++;
                z[i] = r - l;
                r--;
            }
        }
    }
    return z;
}