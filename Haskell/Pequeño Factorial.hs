factorial x = product [1..x]

main = do 
	putStrLn . unlines . map (show . factorial . read) . tail . words =<< getContents
