class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        A = set([i for i in range(n + 1)])
        B = set(nums)
        C = A - B
        assert len(C) == 1
        return list(C)[0]
