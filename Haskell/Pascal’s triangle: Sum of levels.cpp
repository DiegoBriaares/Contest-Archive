import Data.List
import Data.Char
import Control.Applicative

pascal :: Integer->Integer->Integer
pascal a b
	| a>b = 0
	|otherwise = mod k 1000007+pascal (a+1) b
	where k = 2^a

main = do
	let loop = do
		[x,y] <- map read . words <$> getLine
    	if x /= -1 || y /= -1
    	then do
    		print (pascal x y)
    		loop
    	else return ()
    	return ()
    loop
