class Solution {
  public int findDerangement(int n) {
    final long kMod = (long) 1e9 + 7;
    int[] dp = new int[n + 1];

    dp[0] = 1;

    for (int i = 2; i <= n; ++i)
      dp[i] = (int) ((i - 1L) * (dp[i - 1] + dp[i - 2]) % kMod);

    return dp[n];
  }
}
