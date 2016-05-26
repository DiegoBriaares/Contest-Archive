import Data.List
import Data.Char

brrsum1 :: Int->[Int]->Int->Int
brrsum1 0 xs s = s
brrsum1 n xs s = brrsum1 (n-1) xs (s+((xs !! n)-(xs !! (n-1))))

brrop :: Int->Int->[Int]->Int
brrop i k xs= (xs !! (i-1))-(xs !! (i-2))

brrop2 :: Int->Int->[Int]->Int
brrop2 i k xs= (xs !! (i+k-2))-(xs !! (i+k-3))

brrsolve :: Int->Int->Int->Int->[Int]->Int
brrsolve 0 mini i k arr = mini
brrsolve n mini i k arr = brrsolve (n-1) uso (i+1) k arr
	where uso = max mini (mini-(brrop i k arr)+brrop2 i k arr)

barrancas :: Int->[Int]->Int
barrancas n xs = brrsolve ((length xs)-n) s 2 n xs
	where s = brrsum1 (n-1) xs 0
