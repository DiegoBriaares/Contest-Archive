import Data.List
import Data.Char

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

vigenere :: Int->[Char]->[Char]->[Char]
vigenere n a b
	| n== 1 = vigenere1 a b
	|otherwise = vigenere2 a b

main = do
	n<-readLn
	a<-getLine
	b<-getLine
	putStrLn (vigenere n a b)
