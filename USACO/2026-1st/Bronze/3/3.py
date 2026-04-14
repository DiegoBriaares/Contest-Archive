'''
  Resolution:

  [Observation 1]
  For any given field:
  - There are exactly (n - K + 1)^2 distinct pictures. 
    
    For any picture:
     - There exists an up-left-most location (i, j).
      
       Any up-left-most location:
       - Satisfies 1 <= i, j < (n - K + 1).

       For any two distict pictures:
        - Its up-left-most locations are distinct.

  [Idea 1]
  For every picture lets maintain its attractiveness index.

  Let:
  - S[i][j] be the attractiveness index of the picture with up-most-location (i, j).
  
  For every update on location (r, c):
  - There are exacly K^2 distinct pictures which its attractiveness index needs to be updated.
    
    For each update, iterating over all the up-left-most locations of the pictures which its attractiveness index need to be updated can be done in O(Q * K^2) time.

  [Solution 1]
  Lets process the Q updates. Let the current update be at location (r, c). Iterate over all the up-left-most locations (i, j) which its attractiveness index need to be updated for i from (r - K + 1) to r and for j from (c - K + 1) to c. Let v be the current beauty value at location (r, c), and let v' be the next beauty value at location (r, c). Update the attractiveness index from S[i][j] to S[i][j] + v' - v. Let A be the maximum attractiveness index of the updated attractiveness indexes. Let M be the maximum attractiveness index of a picture before the current update. Initially M = 0. Let M' be the maximum attractiveness index of a picture after the current update. M' = max(M, A). Update m[r][c] to v. After each update, output M'. Overall time complexity is O(Q * K^2). It can be implemented with small constants. 

'''

'''
  Algorithm:
  
  Step [1 - Read Input]:
  Allocate N, K, and Q.
  Read N, K and Q.
  Allocate m[0..N-1][0..N-1].
  Allocate r, c, and v.
  Allocate s[0..N-1][0..N-1].
  Allocate a.
  Allocate mx.
  mx <- 0.
  Go to Step [2].

  Step [2 - Handle test cases]:
  If Q < 0, terminate the program.
  Otherwise:
    Q <- Q - 1.
    Read r, c, and v.
    i <- max(0, r - K + 1).
    j <- max(0, c - K + 1).
    a <- 0.
    Go to Step [3].

  Step [3 - Update attractiveness indexes]:
  If i > r, go to Step [4].
  Otherwise:
    If j > c:
      i <- i + 1.
      j <- 0.
      Go to Step [3].
    Otherwise:
      s[i][j] <- s[i][j] + v - m[r][c].
      a <- max(a, s[i][j]).
      Go to Step [3].

  Step [4 - Update beauty value and output maximum attractiveness index]:
  m[r][c] <- v.
  mx <- max(mx, a).
  output mx.
  Go to Step [2].

'''

N, K = list(map(int, input().split()))
Q = int(input())

m = [[0 for _ in range(N)] for _ in range(N)]
s = [[0 for _ in range(N)] for _ in range(N)]

mx = 0
r, c, v = 0, 0, 0
a = 0

while Q:
  r, c, v = list(map(int, input().split()))
  r -= 1
  c -= 1

  a = 0
  for i in range(max(0, r - K + 1), r + 1):
    for j in range(max(0, c - K + 1), c + 1):
      s[i][j] = s[i][j] + v - m[r][c]
      a = max(a, s[i][j])

  m[r][c] = v

  mx = max(mx, a)
  print (mx)

  Q -= 1


