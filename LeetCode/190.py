class Solution:
    def reverseBits(self, n: int) -> int:
        b = [0] * 32
        for i in range(32):
            b[i] = bool(n & (1 << i))

        n = 0
        for i, v in enumerate(reversed(b)):
            n += v * (1 << i)

        return n
