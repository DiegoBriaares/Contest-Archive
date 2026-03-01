# Short Solution
class Solution:

    def BS (self, nums, l, r, check):
        idx = 0
        while l <= r:
            mid = (l + r) >> 1
            if check(mid):
                l = mid + 1
            else:
                idx = mid
                r = mid - 1
                
        return idx

    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)

        p = -1
        if nums[n - 1] < nums[0]:
            p = self.BS(nums, 0, n - 1, (lambda mid: nums[n - 1] < nums[mid]))

        idx = 0
        if (p == -1):
            idx = self.BS(nums, 0, n - 1, (lambda mid: nums[mid] < target))
        
        else:
            idx = max(self.BS(nums, 0, p - 1, (lambda mid: nums[mid] < target)), 
            self.BS(nums, p, n - 1, (lambda mid: nums[mid] < target)))

        if nums[idx] == target:
            return idx
        else:
            return -1

'''
Primary Solution
class Solution:

    def BS (self, nums, l, r, v):
        idx = -1
        while l <= r:
            mid = (l + r) >> 1
            if nums[mid] < v:
                l = mid + 1
            else:
                if nums[mid] == v:
                    idx = mid
                r = mid - 1

        return idx

    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)

        p = -1
        if nums[n - 1] < nums[0]:
            l, r = 0, n - 1
            while l <= r:
                mid = (l + r) >> 1
                if nums[n - 1] < nums[mid]:
                    l = mid + 1
                else:
                    p = mid
                    r = mid - 1

        idx = -1
        if (p == -1):
            idx = self.BS(nums, 0, n - 1, target)
        
        else:
            idx = max(self.BS(nums, 0, p - 1, target), 
            self.BS(nums, p, n - 1, target))

        return idx
'''
