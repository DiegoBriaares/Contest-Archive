subsolve :: [Int]->Int->Int->Int
subsolve [] p sb = 0
subsolve (x:xs) p sb
	| sb==1&&x>p = max (1+subsolve xs x 0) (subsolve xs p sb)
	| sb==0&&x<p = max (1+subsolve xs x 1) (subsolve xs p sb)
	| otherwise = (subsolve xs p sb)

subaltibaja :: [Int]->Int
subaltibaja xs = max (subsolve xs (-1500000) 1) (subsolve xs (1500000) 0)
