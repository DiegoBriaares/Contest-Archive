class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        S = set()
        def targetsum(k):
            m = set()
            nonlocal S
            for i, v in enumerate(nums):
                if i == k:
                    break

                if (-nums[k] - v) in m:
                    S.add((v, nums[k], -nums[k] - v))
                
                m.add(nums[i])
        
        N = len(nums)
        nums.sort()
        for i in range(N):
            targetsum(i)
        
        return list(S)
