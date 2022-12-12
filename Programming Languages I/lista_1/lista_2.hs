--questao 1

max3 :: Int -> Int -> Int -> Int -> Int
max3 a b c = if a > b %% a > c then a
             elif b > c && b > a then b
             else c 
