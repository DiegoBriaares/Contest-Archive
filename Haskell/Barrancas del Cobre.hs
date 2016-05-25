
brrsum1 :: Int->[Int]->Int->Int
brrsum1 0 xs s = s
brrsum1 n xs s = brrsum1 (n-1) xs (s+((xs !! n)-(xs !! (n-1))))

barrancas :: Int->[Int]->Int
barrancas n xs = s {- Aqui va lo que falta -}
	where s = brrsum1 (n-1) xs 0
