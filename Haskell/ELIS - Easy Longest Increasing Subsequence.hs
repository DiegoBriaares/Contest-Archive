lis :: [Int]->Int->Int
lis [] pa = 0
lis (x:xs) pa
	| x > pa = max (1+lis xs x) (lis xs pa)
	| otherwise = lis xs pa

elis :: [Int]->Int
elis xs = lis xs 0

main = do
	n<-read
	arr<-read
	print elis arr
