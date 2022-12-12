-- questao 1

intersperse :: a -> [a] -> [a]
intersperse _ [a] = [a]
intersperse a (x:xs) = a : x : intersperse a xs  

-- questao 2

insert :: Ord a => a -> [a] -> [a]
insert a [] = [a]
insert a (x:xs) = if a < x then a : x : xs
                  else x : insert a xs

-- questao 3

subidas :: [Float] -> Int
subidas [] = 0
subidas [a] = 0
subidas (x : y : xs) = if y > x then subidas (y : xs) + 1
                       else subidas (y : xs)

-- questao 4
unzip :: [(Int, Int)] -> ([Int], [Int])
unzip [] = ([],[])
unzip [(a, b)] = ([a], [b])
unzip (x : xs) = ([x !! 0],[x !! 1])  

