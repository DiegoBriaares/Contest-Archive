'''
  Solution:

  Lets consider a to be 0-indexed.
  For any query x, let b[0..k - 1] be its bits from least significant to most significant bit. 
  We will separate two cases:
  1) k < N:
    For now, assume a[i] to be the lowest possible cost for obtaining 2^i buckets of milks. This may not be true, but we will fix it after solving the two cases with this assumption.
    For any 0 <= i < k, let dp[i] be minimum cost to obtain at least (2^0)(b[0]) + ... + (2^i)(b[i]) buckets of milk by taking deals from 1 to k.
    dp[0] = (a[0])(b[0]). For any 1 <= i < k, we have the following cases.
    1) b[i] = 0. Then dp[i] = min(dp[i - 1], a[i]).
    2) b[i] = 1. Then dp[i] = dp[i - 1] + a[i]. 
    The idea behind this dynamic programming is that taking the i+1-th deal gives as much buckets of milk as the ones that can give taking any subset of previous deals from 1 to i. So if the i-th bit is not active in x, then we can choose to take the i+1-th deal instead of any subset of the previous deals, otherwise if its not set then we have no other option but to take the i+1-th deal (at least by now, it could happen that later we take a bigger deal by the reasons above when computing dp on a bigger bit). Note that b[k - 1] is always equal to 1 because b[k - 1] is the MSB of x. 
    However, we have not considered deals from k + 1 to N. If we take any single one of these deals, it would obtain more than x buckets of milks, because its corresponding bit would be higher than the MSB of x. So, the actual answer is min(dp[k - 1], min(*a[k..N - 1])).
    We can precompute suffix-mins so that we can answer min(*a[k..N - 1]) very quickly.
  2) k >= N:
  we can generate k - N "new deals" to obtain 2^N, ..., 2^k-1 buckets of milks, by computing for 0 <= i < k, cost[i] = minimum cost for obtaining 2^i buckets by taking deals from 1 to min(N, i).
  cost[0] = a[0]. 
  For any 1 <= i < N, cost[i] = min(2 * cost[i - 1], a[i]).
  For any N <= i < k, cost[i] = 2 * cost[i - 1].
  The idea of this dynamic programming is that we can obtain 2^i buckets of milk by either taking a deal that offers it, or taking various previous deals to obtain them. Precisely, the minimum cost to obtain 2^i buckets of milk is the minimum between the cost of a deal that offer it and twice the minumum cost to obtain 2^i-1 buckets of milk.
  Then, we can think this as "expanding N" so that k < N, thus the solution for the first case above applies here. We can pre-expand a to have size greater than 31. 
  Now we fix the assumption for the first case, we also need to update costs of a[0..N-1] by min(a[i], cost[i]) because cost[i] may be lower than a[i].
  The complexities are O(N) for the precomputation, O(log(x)) for computing dp, O(log(max_x)) for computing cost, and O(1) to compute the actual answer.
  Overall complexity is O(N + Q*log(x) + log(max_x)). 

  
  Algorithm:

  Step [1 - Read input]:
  Allocate N, Q, a[0..N-1], x[0..Q-1].
  Read the input correspondingly.
  Go to Step [1.1].

  Step [1.1 - Intialize cost computation]:
  Allocate cost[0..32].
  Allocate p.
  Allocate a[N..32].
  cost[0] = a[0].
  p <- 1.
  Go to Step [1.2].

  Step [1.2 - compute costs of new deals]:
  if p < N:
    cost[i] <- min(2 * cost[i - 1], a[i]).
    p <- p + 1.
    Go to step [1.2].
  Otherwise:
    If p < 32:
      cost[i] <- 2 * cost[i - 1].
      p <- p + 1.
      Go to step [1.2].
    Otherwise:
      Go to Step [1.3].


  Step [1.3 - decide and initialize expanding of a]:
  If N < 32:
    Allocate a[N..32].
    Go to Step [1.4].
  Otherwise, go to Step [2].

  Step [1.4 - expand a]:
  If N < 32:
    a[N] <- cost[N].
    N <- N + 1.
    Go to Step [1.4].
  Otherwise, go to Step [2].
    

  Step [2 - Initalize suffix-mins]:
  Allocate S[0..N-1]. 
  S[N - 1] <- a[N - 1].
  Allocate i.
  i <- N - 2.
  Go to Step [3].

  Step [3 - Compute the suffix-mins]:
  If i < 0, go to Step [4].
  Otherwise:
    S[i] <- min(S[i + 1], A[i]).
    i <- i - 1.
    Go to Step [3].

  Step [4 - Intialize test-case handling]:
  Allocate q.
  Allocate b[0..N-1].
  Allocate k.
  Allocate dp[0..N-1].
  q <- -1.
  Go to Step [5].

  Step [5 - Handle test cases]:
  If Q < 0, terminate the program.
  Otherwise:
    Q <- Q - 1.
    q <- q + 1. 
    i <- 0.
    Go to Step [6].

  Step [6 - Compute active bits of x]:
  If 2^i > x[q], go to Step [7].
  Otherwise:
    If 2^i is not an active bit in x[q], b[i] <- 0.
    Otherwise, b[i] <- 1.
    k <- k + 1.
    Go to Step [6].


  Step [7 - Initialize dp]:
  dp[0] <- a[0] * b[0].
  i <- 1.
  Go to Step [8].

  Step [8 - Compute dp]:
  If i = k, go to Step [9].
  Otherwise:
    If b[i] = 0, dp[i] <- min(dp[i - 1], a[i]).
    If b[i] = 1, dp[i] <- dp[i - 1] + a[i].
    i < i + 1.
    Go to Step [8].

  Step [9]:
  If k < N - 1, output min(dp[k - 1], S[k]).
  Otherwise, output dp[k - 1].
  Go to Step [5].

'''

N, Q = list(map(int, input().split()))

a = list(map(int, input().split()))

cost = list(0 for _ in range(33))
cost[0] = a[0]

for i in range(1, 33):
  if i < N:
    cost[i] = min(2 * cost[i - 1], a[i])
    a[i] = min(a[i], cost[i])
  else:
    cost[i] = 2 * cost[i - 1]

while N < 33:
  a.append(cost[N])
  N += 1

S = list(0 for _ in range(N))
S[N - 1] = a[N - 1]
for i in range(N - 2, -1, -1):
  S[i] = min(S[i + 1], a[i])

b = list(0 for _ in range(33))

dp = list(0 for _ in range(N))

while Q:
  x = int(input())
  k = 0

  while not ((1 << k) > x):
    b[k] = (x & (1 << k))
    k += 1

  dp[0] = a[0] * b[0]
  for i in range(1, k):
    if not b[i]:
      dp[i] = min(dp[i - 1], a[i])
    elif b[i]:
      dp[i] = dp[i - 1] + a[i]

  if k < N - 1:
    print (min(dp[k - 1], S[k]))
  else:
    print (dp[k - 1])

  Q -= 1
