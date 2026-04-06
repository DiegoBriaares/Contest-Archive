'''
  Algorithm:
  Let ans be the answer.
  Let N be the number of digits of x.
  Let dig[1..N] be an array with the digits of x from least significant to most significant digit.

  Step [1]:
   - If x is 0, ans <- 0, output ans, and terminate. 
   - If x has non-0-1 digits, ans <- 1, and for every 1 <= i <= n if dig[i] is even then dig[i] <- 0, otherwise dig[i] <- 1, go to Step [2].

  Step [2]:
  Precompute the answer for any sequence of 111..1. Let dp[i] store the answer for a such a sequence of length i.
  - dp[0] = 0.
  - dp[1] = 1.
  - dp[i] = 2 + 2(dp[i]).
  Go to Step [3].

  Step [3]:
  Define a function nxt(i) which finds via linear search the position of the lowest 1 digit to the left of digit at position 1, if there is no such digit, nxt(i) returns 0.
  Let L be the position of the lowest digit of x equal to 1.
  - If dig[N] = 1, L <- N. Otherwise L <- nxt(N).
  Go to Step [4].


  Step[4]:
  - If L = 0, output ans, and terminate.
  - If L = N, ans <- ans + 1, L <- nxt(N) and go to Step [4].
  - Otherwise go to Step [5].

  Step [5]:
    ans <- ans + dp[i - 1], L <- nxt(L), and go to Step [4].

'''
import sys

T = int(input())

dp = [0, 1]
MOD = 1000000007

while T:
  x = list(map(int, input()))
  x.reverse()
  ans = 0

  N = len(x)
  while len(dp) < N:
    dp.append((2 + 2 * dp[-1]) % MOD)

  chg = False
  for i in range(N):
    if x[i] > 1:
      chg = True
    if x[i] & 1:
      x[i] = 1
    else:
      x[i] = 0
  if chg:
    ans += 1

  def nxt(i):
    while i + 1 < N:
      i += 1
      if x[i] == 1:
        return i

    return -1

  L = 0
  if x[0] == 0:
    L = nxt(L)

  while True:
    if L == -1:
      break

    elif L == 0:
      ans += 1

    else:
      ans += 2 + dp[L]

    ans %= MOD
    L = nxt(L)
  
  print (ans)

  T -= 1
