class Solution:
    def calculate(self, s: str) -> int:
        N = len(s)
        # Normalize expresion
        expr = ['(']
        for i in range(N):
            if s[i] == '-' and (i == 0 or s[i - 1] == '('):
                    expr.append('0')
            if s[i] != ' ':
                expr.append(s[i])

        expr.append(')')
        N = len(expr)
        p = -1
        def evaluate():
            nonlocal N
            nonlocal p
            stack = [0]
            op = '+'
            n = 0
            def do_op():
                nonlocal n
                nonlocal stack
                nonlocal op
                if op == '+':
                    stack.append(n)
                if op == '-':
                    stack.append(-n)
                if op == '*':
                    stack.append(stack.pop() * n)
                if op == '/':
                    stack.append(stack.pop() // n)

                n = 0

            while p + 1 < N and expr[p + 1] != ')':
                p += 1
                if expr[p].isdigit():
                    n = n * 10 + int(expr[p])
                else:
                    if expr[p] == '(':
                        n = evaluate()
                        continue
                    else:
                        do_op()
                        op = expr[p]
            if n:
                do_op()
            p += 1
            return sum(stack)
        
        return evaluate()


        
        
