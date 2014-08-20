
## A. DP

先分别累计每个num的总和sums[num]，然后DP：

dp[i]: 大小为i时的最大值

dp[i] = max(dp[i-1], dp[i-2] + sums[num])


## C. DFS

题目给出一系列深林，并执行两种操作：

1. 求一个深林内的最长路：先用dfs求出最深的点，然后从最深的点再做一次dfs，最大深度就是最长路
2. 合并两个深林i, j
    合并后的深林最长路：max(longest_path[i], longest_path[j],
                         (up_floor(longest_path[i]/2) + upfloor(longest_path[j]/2)) / 2)
