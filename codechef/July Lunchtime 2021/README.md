### XORSPRT
Firstly, let's prepare the preprocess, call $sum[i] = sum[i-1] \oplus a[i]$.  

Call $dp[i][j]$ as the number of ways which can divide the array into $j$ parts. It's easy to see that the logarit of maximum value $(10^{16})$ is $\approx 54$, so that the value $j$ we can consider its $\leq 54$ or $55$ btw. And the dynamic formula is $dp[i][j] = dp[k][j-1]$ with $k < i$ and $sum[i] = sum[k]$  

With $j \leq 55$, the answer is $\sum_{j=0}^{55} dp[n][j]$.  

Now consider with $j > 55$, define $cnt[i]$ is the number of index $j >= i$ that $sum[j] = sum[i]$. Now the answer is $\sum_{i=1}^n dp[i][55]*2^{cnt[i]-1}$  

Add two above results together, it's the answer of the problem.
