import Data.List
import Data.Char
import Control.Applicative

solve :: Int->[Integer]->Integer
solve b [] = 0
solve b (x:y:xs) = (y-x)+ solve b xs

main = do
	n<-readLn
	xs<- map read . words <$> getContents 
	print (solve n (sort xs))
