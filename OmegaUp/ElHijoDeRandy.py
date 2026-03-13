N = int(input())
a = list(map(int, input().split()))

mx = 0

stack = [0]
for i in range(1, N):
  while stack and a[stack[-1]] < a[i]:
    mx = max(mx, a[i] ^ a[stack[-1]])
    stack.pop()
  stack.append(i)

stack = [N - 1]
for i in range (N - 2, -1, -1):
  while stack and a[stack[-1]] < a[i]:
    mx = max(mx, a[i] ^ a[stack[-1]])
    stack.pop()
  stack.append(i)

print(mx)
