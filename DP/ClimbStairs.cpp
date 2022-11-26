// class Solution {
// public:
//     unordered_map<int, int> stepToWay;
//     int climbStairs(int n) {
//         // terminal conditions
//         if (n==1) return 1;
//         if (n==2) return 2;
//         if (stepToWay.count(n)){
//             return stepToWay[n];
//         }
//         else{
//             int result = climbStairs(n-1)+climbStairs(n-2);
//             stepToWay[n] = result;
//             return result;
//         }
//     }
// };

// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> dp(n+1);
//         dp[0] = 1;
//         dp[1] = 1;
//         for (int i=2;i<=n;++i){
//             dp[i] = dp[i-1]+dp[i-2];
//         }
//         return dp[n];
//     }
// };


class Solution {
 public:
  int climbStairs(int n) {
    int prev1 = 1;  // dp[i - 1]
    int prev2 = 1;  // dp[i - 2]

    for (int i = 2; i <= n; ++i) {
      const int dp = prev1 + prev2;
      prev2 = prev1;
      prev1 = dp;
    }

    return prev1;
  }
};
