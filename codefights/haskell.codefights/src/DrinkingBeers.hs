module DrinkingBeers where

{-

Three brothers walk into a bar. All the beverages are placed in one line at the long bar table. The size of each glass is represented in an array of integers, glasses.

The brothers will drink a round if they can find 3 consecutive glasses of the same size. The barman removes the empty glasses from the table immediately after each round.

Find the maximum number of rounds the three brothers can drink.

Example

For glasses = [1, 1, 2, 3, 3, 3, 2, 2, 1, 1], the output should be brothersInTheBar(glasses) = 3.

-}

import Data.List (group, foldl')

barTest = [1, 1, 2, 3, 3, 3, 2, 2, 1, 1]
barAnswer = 3

{- slow answer
f (x, xs) g = (x + q, xs ++ (drop (3 * q) g))
    where q = quot (length g) 3
p x xs 
    | x == r = x
    | otherwise = p r gs
    where (r, gs) = foldl' f (x, []) (group xs)
brothersInTheBar gs = p 0 gs
-}

{-

[ 1, 1, 2, 3, 3, 3, 2, 2, 1, 1 ]


-}

process (x:y:[]) = (0, x:y:[])
process (x:xs)
    | ((length n2) == 2) && (and $ map (==x) n2) = (1 + fst n, drop 2 (snd n))
    | otherwise = (fst n, x:(snd n))
    where n = process xs
          n2 = take 2 (snd n)


brothersInTheBar gs = process gs
