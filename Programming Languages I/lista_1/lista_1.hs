isPar :: Int -> Bool
isPar n = mod n 2 == 0

--questao 1

--primUlt :: [Int] 

--questao 2

--palindrome :: Int -> Int -> [Int]
--palindrome 

--questao 3 OK

getElement :: [Int] -> Int -> Int
getElement [] _ = -1
getElement z 1 = head(z)
getElement (x:xs) y = if y == 1 then x
                      else getElement xs (y-1)


--questao 4 OK

contais :: (Eq a) => a -> [a] -> Bool
contais _ [] = False
contais a (x:xs) = if a == x then True
                   else contais a xs

--questao 5 OK

sizeList :: [a] -> Int
sizeList [] = 0
sizeList (x:xs) = 1 + sizeList xs


--questao 6 OK

nMedia :: Int -> [Int] -> Double
nMedia _ [] = 0
nMedia a lista = fromIntegral (sum(selecionaInteiros a lista)) / fromIntegral a



selecionaInteiros :: Int -> [Int] -> [Int]
selecionaInteiros _ [] = []
selecionaInteiros pos (x:xs) = if pos > 0 then x : selecionaInteiros (pos-1) xs 
                               else selecionaInteiros pos []



--questao 7

mult :: Int -> Int -> Int
mult a 1 = a
mult a b = if b > 1 mult

suc :: Int -> Int
suc a = a + 1


Ant :: Int -> Int
Ant a = a + 1

-- funcional
--f1 a = do a <- getLine
  --  if a > 10 then f1 a
    --else return ()