'''
  Algorithm:

  [Step 1 - Read input]:
  Read the input and go to [Step 2].

  [Step 2 - Handle test cases]:
  - If T = 0 then terminate the program.
  - Otherwise, T <- T - 1 and go to [Step 3].

  [Step 3 - Initialize dp]:
  Let i be equal to 0.
  Allocate dp[0..N-1][0..1] and initialize in zeroes.
  Go to [Step 4].

  [Step 4 - Fill dp]:
  - If i = 0, dp[0][0] <- 1, dp[0][1] <- 1, i <- i + 1, and go to [Step 4].
  - Otherwise:
    - If i < N:
      - If S[i] = M, dp[i][0] <- dp[i - 1][0], dp[i][1] <- dp[i - 1][0]
      - If S[i] = O, dp[i][0] <- dp[i - 1][1], dp[i][1] <- dp[i - 1][1]
      i <- i + 1, and go to [Step 4].
    - Otherwise, go to [Step 5].

  [Step 5 - Output possibility]:
  if dp[N][0] output YES, otherwise output NO.
  - If k = 0, go to [Step 2].
  - If k = 1, go to [Step 6].

  [Step 6 - Initialize reconstruction of answer]:
  If not dp[N][0], go to [Step 2].
  Let i be equal to N - 1.
  Let f be equal to 0.
  Let S' be an empty string.
  Let inv(c) be M if c = O, and O if c = M.
  Go to [Step 7].

  [Step 7 - Reconstruct the answer]:
  - If i < 0, go to [Step 8].
  - Otherwise:
    - If f = 0, append S[i] to S'.
    - If f = 1, append inv(S[i]) to S'.
    - If S[i] = M, f <- 0
    - If S[i] = O, f <- 1
    i <- i - 1, and go to [Step 7].

  [Step 8 - Output reconstructed answer]:
  Reverse S', output S', and go to [Step 2].

'''
T, k = list(map(int, input().split()))

while T:
  T -= 1
  N = int(input())
  S = input()

  dp = list([0, 0] for _ in range(N))
  
  dp[0][0] = 1
  dp[0][1] = 1

  for i in range(1, N):
    if S[i] == 'M':
      dp[i][0] = dp[i - 1][0]
      dp[i][1] = dp[i - 1][0]
    else:
      dp[i][0] = dp[i - 1][1]
      dp[i][1] = dp[i - 1][1]

  if dp[N - 1][0]:
    print ("YES")
  else:
    print ("NO")

  if k == 0:
    continue
  
  def inv(c):
    if c == 'M':
      return 'O'
    if c == 'O':
      return 'M'

  f = 0
  ans = ""
  for i in range(N - 1, -1, -1):
    if f == 0:
      ans += S[i]
    if f == 1:
      ans += inv(S[i])

    if S[i] == 'M':
      f = 0
    if S[i] == 'O':
     f = 1

  ans = ans[::-1]
  
  print (ans)
