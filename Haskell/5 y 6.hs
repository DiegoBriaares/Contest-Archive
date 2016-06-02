import Data.List
import Data.Char
import Control.Applicative

solvea :: Int->Int->Int
solvea 0 n = 0
solvea a n 
	| k ==5 = (6*n)+solvea (div a 10) (n*10)
	|otherwise = (k*n)+solvea (div a 10) (n*10)
	where k = (mod a 10)

solveb :: Int->Int->Int
solveb 0 n = 0
solveb a n 
	| k ==6 = (5*n)+solveb (div a 10) (n*10)
	|otherwise = (k*n)+solveb (div a 10) (n*10)
	where k = (mod a 10)

solve :: [Int]->Int
solve (x:y:xs) = solveb x 1 + solveb y 1

solve2 :: [Int]->Int
solve2 (x:y:xs) = solvea x 1 + solvea y 1

main = do
	a<-map read . words <$> getContents
	print ((solve a))
	print ((solve2 a))
