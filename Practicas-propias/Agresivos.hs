import Data.List
import Data.Char
import Control.Applicative

slt :: [Int]->Int->Int->Int->Int
slt xs i uso uso2 = if(xs !! i)>=uso2 then uso+1 else uso

slt2 :: [Int]->Int->Int->Int->Int
slt2 xs i uso2 v = if(xs !! i)>=uso2 then xs !! i + v else uso2

solve :: Int->Int->Int->Int->Int->Int->[Int]->Int
solve uso uso2 i (-1) p v xs = if uso>=p then 1 else 0
solve uso uso2 i n p v xs = solve (slt xs i uso uso2) (slt2 xs i uso2 v) (i+1) (n-1) p v xs  

bs :: [Int]->Int->Int->Int->Int
bs xs ini fin p 
	| ini == fin = ini
	| solve 0 0 0 (length xs - 1) p mid xs == 0  = bs xs ini (mid-1) p
	| otherwise = bs xs (mid) fin p
	where mid = div (ini+fin+1) 2

agv :: Int->[Int]->Int
agv p xs = bs xs 1 (10^9) p

main = do
	[x,y]<-map read . words <$> getLine
	xs<-map read . words <$> getContents
	print (agv y (sort xs))
