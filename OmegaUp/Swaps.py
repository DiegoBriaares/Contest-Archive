N = int(input())
a = list(map(int, input().split()))

perm = list(0 for _ in range(N))
vis = list(0 for _ in range(N))

for i, v in enumerate(a):
  perm[v] = i

swaps = N

for i in range(N):
  if vis[i]:
    continue

  p = i
  while not vis[p]:
    vis[p] = True
    p = perm[p]

  swaps -= 1

print (swaps)
