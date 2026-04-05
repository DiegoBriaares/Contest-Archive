'''
Algorithm:
[Input]
N K
a[1..N]

[Step 1 - Create buckets maps] 
Create a matrix bucket[0..K-1][0..floor(N / K)]. 

[Step 2 - Map quotients into residue class buckets] 
For each element a[i], increase bucket[a_i % K][floor(a[i] / K)] by one. 

[Step 3 - Sepparate elements in the map of each bucket optimally]
op = 0
For each b from 0 to K - 1
  if K > 0
    for each i from 0 to floor(N / K)
      if bucket[b][i] > 0
        op += bucket[b][i] - 1
        if i < floor(N / K)
          bucket[b][i + 1] += bucket[b][i] - 1
        else
          last = bucket[b][i] - 1
    if last > 0
      op += gauss(last - 1)
  else
    for each i from floor(N / K) to 0
      if bucket[b][i] > 0
        op += bucket[b][i] - 1
        if i > 0
          bucket[b][i - 1] += bucket[b][i] - 1
        else
          last = bucket[b][i] - 1
    if last > 0
      op += gauss(last - 1)
[Output]
op

'''

T = int(input())

while T:
  N, K = list(map(int, input().split()))
  a = list(map(int, input().split()))
  pos = True
  if K < 0:
    K = abs(K)
    pos = False

  bucket = [[0 for _ in range(N // K + 1)] for _ in range(K)]

  for v in a:
    bucket[v % K][v // K] += 1

  def gauss(n):
    return (n * (n + 1)) // 2

  op = 0
  for b in range(K):
    last = 0
    if pos:
      for i in range(N // K + 1):
        if bucket[b][i] > 0:
          op += bucket[b][i] - 1
          if i < N // K:
            bucket[b][i + 1] += bucket[b][i] - 1
          else:
            last = bucket[b][i] - 1
    else:
      for i in range(N // K, -1, -1):
        if bucket[b][i] > 0:
          op += bucket[b][i] - 1
          if i > 0:
            bucket[b][i - 1] += bucket[b][i] - 1
          else:
            last = bucket[b][i] - 1
    if last > 0:
      op += gauss(last - 1)
      
  print (op)
  T -= 1
  
