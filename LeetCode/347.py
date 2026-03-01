class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        freq = {}
        for v in nums:
            freq[v] = freq.get(v, 0) + 1

        F = sorted(freq.items(), key= lambda x: x[1], reverse=True)
        return [v[0] for v in F[:k]]
        
