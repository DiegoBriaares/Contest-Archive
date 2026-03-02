class Solution:
    def maxArea(self, height: List[int]) -> int:
        N = len(height)
        L = [-1] * N
        R = [-1] * N

        m, M = N - 1, 0
        for (v, i) in sorted([(v, i) for i, v in enumerate(height)], key = lambda x: (x[0], -x[1]), reverse=True):
            if m < i:
                L[i] = m
            if M > i:
                R[i] = M                
            m = min(m, i)
            M = max(M, i)

        mx = 0
        for i in range(N):
            print (i, height[i], L[i], R[i], mx)
            if L[i] != -1:
                mx = max(mx, height[i] * (i - L[i]))
            if R[i] != -1:
                mx = max(mx, height[i] * (R[i] - i))
            print (mx)
        return mx

