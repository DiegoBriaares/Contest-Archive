import Data.List
import Data.Char

fib :: Int ->Int
fib 0 = 0
fib 1 = 1
fib n = fib(n-1)+fib(n-2)

mayus :: [Char]->[Char]
mayus arr = [c |c<-arr,c `elem` ['A'..'Z']]

suma :: [Int]-> Int
suma [] = 0
suma (x:arr)=x+suma arr

imc :: (RealFloat a)=>a->a->a
imc peso altura = (peso/altura^2)

maxi :: (Ord a)=>[a]->a
maxi []= error "Lista sin elementos"
maxi [x] = x
maxi (x:xs) =x`max`(maxi xs)

tomar :: Int->[Int]->[Int]
tomar n (x:xs)
	| n<=0      = []
	| otherwise = x:tomar (n-1) xs 

revertir :: [Int]->[Int]
revertir [] = []
revertir (x:xs) = revertir xs ++ [x]

quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) =
    let smaller = quicksort [a | a <- xs, a <= x]
        bigger  = quicksort [a | a <- xs, a > x]
    in  smaller ++ [x] ++ bigger

strlen :: [Int] -> Int
strlen [] = 0
strlen (_:xs) = 1 + strlen xs

collatz :: Int->[Int]
collatz 1 = [1]
collatz n
	|even n = n:collatz (n `div` 2)
	|odd n  = n:collatz (n*3+1)

solve :: Int->[Int]
solve 1 = [1]
solve n = strlen (collatz n):solve (n-1) 

solucionar :: [Int]->[Int]
solucionar arr= [x |x<-arr,x>=15]

duplicar :: Int->Int->[Int]
duplicar n x 
	| n <= 0 = []
	|otherwise = x:duplicar (n-1) x
dcount :: Int->Int
dcount 0 = 0;
dcount x = 1+ dcount (div x 10)

sumdig :: Int->Int
sumdig 0 = 0
sumdig n = (mod n 10)+sumdig (div n 10)

pares :: Int->Int
pares 0 = 0
pares n
	| (mod k 2)==0 = 1+pares (div n 10)
	| otherwise = pares (div n 10)
	where k = (mod n 10) 

isdiv :: Int->Int->Bool
isdiv x y = (mod x y)==0 

men :: Int->Int->Int
men x 0 = x
men x n 
	| x<y = men x (div n 10)
	| otherwise = men y (div n 10)
	where y = (mod n 10)

dless :: Int->Int
dless n = men (mod n 10) n

minpred :: [Int]->Int->Int
minpred [] n = 0
minpred (x:xs) n 
	| x==n = 1+minpred xs n
	| otherwise = minpred xs n

facto :: Int->Int
facto 0 =1
facto n = n*facto (n-1)

factserie :: Int->[Int]
factserie n = [facto x |x<-[1..n]]

divisores :: Int->[Int]
divisores n = [x |x<-[1..n],isdiv n x]

isprime :: Int->Bool
isprime n = strlen (divisores n) == 2

primos :: Int->[Int]
primos n = [x |x<-[1..n],isprime x]

may::Int->Int->Int
may x 0 = x
may x n 
	| x<k = may x (div n 10)
	| otherwise = may k (div n 10)
	where k = mod n 10

maxdig :: Int->Int
maxdig n = may (mod n 10) n

cont :: [Int]->Int->Int
cont [] n = 0
cont (x:xs) n
	| x==n = 1+cont xs n
	| otherwise = cont xs n

fibo :: Int->Int->Int->String
fibo 0 a b= ""
fibo n a b = show(a+b) ++ " "++fibo (n-1) b (a+b)

fibonnaci :: Int->String
fibonnaci n = fibo n 0 1

pairs :: [Int]->[Int]
pairs xs = [x |x<-xs,odd x]

unpairs :: [Int]->[Int]
unpairs xs = [x |x<-xs,even x]

separar :: [Int]->String
separar xs=show(pairs xs) ++" "++ show(unpairs xs)

vocales :: [Char]->[Char]
vocales xs = [x |x<-xs,x`elem`['A','E','I','O','U']]

sumdiv :: Int->Int->Int
sumdiv n 0 = 0
sumdiv n x
	| isdiv n x = x+sumdiv n (x-1) 
	|otherwise = sumdiv n (x-1)

isperfect :: Int->Bool
isperfect n = sumdiv n (n-1) == n

perfect :: Int->[Int]
perfect n = [x |x<-[1..n],isperfect x]

repy :: Int->[Int]->Bool
repy n [] = False
repy n (x:xs) 
	| x==n = True
	| otherwise = repy n xs

repetidos :: [Int]->[Int]->[Int]
repetidos xs ys = [x |x<-xs,repy x ys]

sustimpar :: [Int]->[Int]
sustimpar xs = [if x`mod`2>0 then x+1 else x | x<-xs]

lis :: [Int]->Int->Int
lis [] pa = 0
lis (x:xs) pa
	| x > pa = max (1+lis xs x) (lis xs pa)
	| otherwise = lis xs pa

elis :: [Int]->Int
elis xs = lis xs 0

wordprefix :: String->String->String
wordprefix a b
	|take 1 (drop 2 b) == a = b
	| otherwise = ""

buscaword :: String->[String]->[String]
buscaword _ [] = []
buscaword a (x:xs) 
	| wordprefix a x == "" = buscaword a xs
	| otherwise = wordprefix a x: buscaword a xs

viglenght :: [Char]->Int
viglenght [] = 0
viglenght (_:xs) = 1+ viglenght xs

vigcript :: [Char]->[Char]->[Char]
vigcript [] [] = []
vigcript (x:xs) (y:ys) = if k > (ord 'Z'-ord 'A') then  chr (k-(ord 'Z'-ord 'A'+1)+ord 'A'): vigcript xs ys else  chr (k+ord 'A'): vigcript xs ys
	where k=(ord x+ord y-(ord 'A'*2))

vigcript2 :: [Char]->[Char]->[Char]
vigcript2 [] [] = []
vigcript2 (x:xs) (y:ys) = if k <0 then  chr (k+26+ord 'A'): vigcript2 xs ys else  chr (k+ord 'A'): vigcript2 xs ys
	where k=(ord x-ord y)

vigenere1 :: [Char]->[Char]->[Char]
vigenere1 a b = vigcript a (take (viglenght a) (cycle b))

vigenere2 :: [Char]->[Char]->[Char]
vigenere2 a b = vigcript2 a (take (viglenght a) (cycle b))
