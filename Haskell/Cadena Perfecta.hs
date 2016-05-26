cpc :: [Char]->Char->Int
cpc [] uso = 0
cpc (x:xs) uso
	|x==uso = 1+cpc xs uso
	|otherwise = cpc xs uso

cpint :: [Char]->[Int]
cpint arr = [(cpc arr x) |x<-['a'..'z'],(cpc arr x)/=0 ]

cpchar :: [Char]->[Char]
cpchar xs = [x |x<-['a'..'z'],(cpc xs x)/=0]

cpsolve :: [Char]->[(Int,Char)]
cpsolve xs = zip (cpint xs) (cpchar xs)

cptostring :: [(Int,Char)]->String
cptostring [] = ""
cptostring (x:xs) = show (fst x)++ show(snd x)++ cptostring xs

cadenaperfecta :: [Char]->String
cadenaperfecta xs = cptostring (cpsolve xs)
