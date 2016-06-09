import Data.List
import Data.Char
import Control.Applicative

solve :: Int->Int->[Int]->Int
solve r n [] = r
solve r n (x:xs) = solve (r + (if x<n then 1 else 0)) n xs

acomoda :: Int->[Int]->Int
acomoda basura (x:xs) = solve 0 x xs

main = do
	n<-readLn
	xs<- map read . words <$> getContents
	print (acomoda n xs)
