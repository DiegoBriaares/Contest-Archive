vcnsolve0 :: [Int]->Int->Int
vcnsolve0 xs n
	|n>=(length xs -1) = 0
	| otherwise = max ((xs !! n)+vcnsolve0 xs (n+2)) (vcnsolve0 xs (n+1))

vcnsolve1 :: [Int]->Int->Int
vcnsolve1 xs n
	|n>=(length xs) = 0
	| otherwise = max ((xs !! n)+vcnsolve1 xs (n+2)) (vcnsolve1 xs (n+1))


vecinos :: [Int]->Int
vecinos xs = max (vcnsolve0 xs 0) (vcnsolve1 xs 1)
