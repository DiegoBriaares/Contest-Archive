# Short solution
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        N = len(nums)
        max_suff = max_sum = nums[0]
        for v in nums[1:]:
            max_suff = max(max_suff + v, v)

            max_sum = max(max_sum, max_suff)

        return max_sum

'''
Primary Solution:
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        N = len(nums)
        dp = [[0] * N for _ in range(2)]

        dp[0][0] = dp[1][0] = nums[0]
        for i, v in enumerate(nums[1:], start=1):
            if dp[0][i - 1] > 0:
                dp[0][i] = dp[0][i - 1] + v;
            else:
                dp[0][i] = v;

            dp[1][i] = max(dp[1][i - 1], dp[0][i])

        return dp[1][N - 1]  
        
'''
