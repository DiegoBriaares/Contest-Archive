'''
  Solution:

  [Idea 1]:
    Before receiving any random chips, lets exchange as most chips of type B as possible for chips of type A.
      
      Let E be equal to floor(B / c_B). We can exchange E * c_B chips of type B for E * c_A chips of type A.

        From now on, lets consider A := A + E * c_A and B := B % c_B.

          If A >= f_A then the answer is 0.

            From now on, lets consider A < f_A. 

              Let D be equal to f_A - A.


  [Strategy 1]:
    Lets divide the problem by cases.      
     Case 1) D <= c_A:

      We need to receive D chips of type A; receiving c_B - B or more chips of type B would be enough. 

        The worst-case is receiving c_B - B - 1 chips of type B, and receiving D chips of type A.

          The answer is c_B - B - 1 + D.

    Case 2) D > c_A:

        Case 2.1) c_A >= c_B:

          Receiving c_B chips of type B ends up gaining more chips of type A than the chips that end ups gaining receiving c_B chips of type A; thus the worst-case implies never receiving c_B or more chips of type B.

            The worst-case is receving c_B - B - 1 chips of type B, and receiving D chips of type A.

              The answer is c_B - B - 1 + D.

        Case 2.2) c_A < c_B:

           Receiving c_B chips of type A ends up gaining more chips of type A than the chips that end ups gaining receiving c_B chips of type B; thus the worst-case implies never receiving c_B or more chips of type A.

            Let R be equal D % c_A, and Q be equal to floor(D / c_A). 

              Case 2.2.1) R != 0:

                The worst-case is receiving (R)(c_B) - B + c_B - 1 chips of type B, and receiving D - (R)(c_A) chips of type A.

                  The answer is (R)(c_B) - B + c_B - 1 + D - (R)(c_A).

              Case 2.2.2) R = 0:

                The worst-case is receiving (R - 1)(c_B) - B + c_B - 1 chips of type B, and receiving D - (R - 1)(c_A) chips of type A.

                  The answer is (R - 1)(c_B) - B + c_B - 1 +  D - (R - 1)(c_A).

  [Solution 1]:
    First, reassign the value of A to A + (floor(B / c_B))(c_A), and reassign the value of B to B % c_B. 
    If A >= f_A the answer is 0. Otherwise, assign the value f_A - A to D, assign the value D % c_A to R, and assign the value floor(D / c_A) to Q.
    - Case 1) D <= c_A:  
      The answer is c_B - B - 1 + D.

    - Case 2) D > c_A and c_A >= C_B:
      The answer is c_B - B - 1 + D.

    - Case 3) D > c_A and c_A < c_B and R != 0:
      The answer is (Q)(c_B) - B + c_B - 1 + D - (Q)(c_A).

    - Case 4) D > c_A and c_A < c_B and R = 0:
      The answer is (Q - 1)(c_B) - B + c_B - 1 +  D - (Q - 1)(c_A).
'''

'''
  Algorithm:

    Step [1 - Read input]:
    Allocate T, A, B, cA, cB, and f.
    Read T.
    Go to Step [2].

    Step [2 - Handle test cases]:
    If T < 0, terminate the program.
    Otherwise:
      Read A, B, cA, cB, and f.
      A <- A + floor(B / cB) * cA.
      B <- B % cB.
      Allocate D.
      D <- f - A.
      T <- T - 1.
      Go to Step [3].

    Step [3]:
    If D <= 0, output 0 and go to Step [2].
    Otherwise:
      If D <= cA, output cB - B - 1 + D, and go to Step [2].
      Otherwise:
        If cA >= cB, output cB - B - 1 + D, and go to Step [2].
        Otherwise:
          Allocate R, and Q.
          R <- D % cA.
          Q <- floor(D / cA).
          If R != 0, output (Q) * (cB) - B + cB - 1 + D - (Q) * (cA), and go to Step [2].
          Otherwise, output (Q - 1) * (cB) - B + cB - 1 +  D - (Q - 1) * (cA), and go to Step [2].
        
'''

T = int(input())

while T:
  T -= 1

  A, B, cA, cB, f = list(map(int, input().split()))

  A += (B // cB) * cA
  B = B % cB

  D = f - A

  if D <= 0:
    print (0)
    continue

  if D <= cA:
    print (cB - B - 1 + D)

  elif cA >= cB:
    print (cB - B - 1 + D)

  else:
    R = D % cA
    Q = D // cA

    if R:
      print (Q * cB - B + cB - 1 + D - Q * cA)
    else:
      print ((Q - 1) * cB - B + cB - 1 +  D - (Q - 1) * cA)
