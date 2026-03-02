class Solution:
    def longestPalindrome(self, s: str) -> str:
        N = len(s)
        k = 0
        p = 0
        sz = 1
        odd = True

        # Find largest odd palindrome of length greater than 1
        for i in range(N):
            j = 0
            while i - j - 1 >= 0 and i + j + 1 < N and s[i - j - 1] == s[i + j + 1]:
                j += 1

            if 2 * j + 1 > sz:
                k = j
                p = i
                sz = 2 * j + 1
                odd = True
        
        #Find largest even palindrome
        for i in range(1, N):
            if s[i - 1] != s[i]:
                continue

            j = 0
            while i - 1 - j - 1 >= 0 and i + j + 1 < N and s[i - 1 - j - 1] == s[i + j + 1]:
                j += 1

            if 2 * j + 2 > sz:
                k = j
                p = i
                sz = 2 * j + 2
                odd = False
        
        if odd:
            return s[p - k:p + k + 1]
        else:
            return s[p - 1 - k: p + k + 1]
        
