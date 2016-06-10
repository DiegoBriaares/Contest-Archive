import Data.List
import Data.Char
import Control.Applicative

solve :: Int->Int->[Int]->Int
solve b p [] = 0
solve b p (x:xs) = if x>p then (max (1 + solve b x xs) (solve b p xs)) else solve b p xs

main = do
	n<-readLn
	xs<- map read . words <$> getContents
	print (solve n 0 xs)
