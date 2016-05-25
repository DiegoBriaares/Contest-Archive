import Data.List
import Data.Char

strlen :: [Int]->Int  {-Implemento mi propio length porque soy crack -}
strlen [] = 0
strlen (_:xs) = 1+ strlen xs

isdiv :: Int->Int->Bool
isdiv x y = mod x y == 0

divisores :: Int->[Int]
divisores n = [x |x<-[2..(n-1)],isdiv n x]

isprime :: Int->Bool
isprime n = (strlen (divisores n)== 0)

primos :: Int->[Int]
primos n = [x |x<-[2..n],isprime x]
