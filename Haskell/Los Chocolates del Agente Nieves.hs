chcsolve :: [Int]->Int->Int->Int->Int
chcsolve xs i j x
	| i>j = 0
	| otherwise = max ((xs !! i)*x+(chcsolve xs (i+1) j (x+1))) ((xs !! j)*x+(chcsolve xs i (j-1) (x+1)))

chocolates :: [Int]->Int
chocolates xs = chcsolve xs 0 (length xs-1) 1
