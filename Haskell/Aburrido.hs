import Data.List
import Data.Char
import Control.Applicative

solve :: Int->Int->Int->Int
solve imp x 1 = x
solve imp x n = solve (imp+2) (x+imp) (n-1)

main = do
	n<-readLn
	print (solve 3 3 n)
