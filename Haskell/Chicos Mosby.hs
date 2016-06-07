import Data.List
import Data.Char
import Control.Applicative

mosby:: Int->Int->Int
mosby a 0 = 0
mosby 0 b = 0
mosby a 1 = a
mosby 1 b = b
mosby a b = uso+mosby b (a-(b*uso))
	where uso = ((div a b))

solve :: [Int]->Int
solve (x:y:xs) = mosby (max x y) (min x y)

main = do
	a<- map read . words <$> getContents
	print (solve a)
