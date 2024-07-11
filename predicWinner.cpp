class Solution {
public:
    int scoreDifference(vector<int>& nums, int s, int e, int turn, vector<vector<vector<int>>>&dp) {
        if (s > e) return 0;
        if(dp[s][e][turn]!=-1) return dp[s][e][turn];
        if (turn == 1) { // Player 1's turn
            int chooseStart = nums[s] + scoreDifference(nums, s + 1, e, 0, dp);
            int chooseEnd = nums[e] + scoreDifference(nums, s, e - 1, 0, dp);
           dp[s][e][turn] = max(chooseStart, chooseEnd);
        } else { // Player 2's turn
            int chooseStart = -nums[s] + scoreDifference(nums, s + 1, e, 1, dp);
            int chooseEnd = -nums[e] + scoreDifference(nums, s, e - 1, 1, dp);
           dp[s][e][turn] = min(chooseStart, chooseEnd);
        }
        return dp[s][e][turn];
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return scoreDifference(nums, 0, nums.size() - 1, 1, dp) >= 0;
    }
};
