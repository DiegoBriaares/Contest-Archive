import Data.Char
import Data.List
import Control.Applicative

cipher :: Int->[Char]->[Char]
cipher n [] = []
cipher n (x:xs) = if k > 25 then chr ((k-25)+ord 'a'-1):cipher n xs
	else chr (k+ord 'a'):cipher n xs
	where k = ((ord x+n)-ord 'a')

main = do
	xs<-getLine
	n<-readLn
	print (cipher n xs)
