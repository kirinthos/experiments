module SmallestProduct where

{-
Hi all, I have a tiny challenge for all of you today. I was given some arrays of integers and my mission is to find the smallest product of 3 elements in an array. I will need your help on this problem.

Please note that our integers can be negative and positive.

Examples

For arr = [1, 2, 3], the output should be smallestProduct(arr) = 6

The only option is 1 * 2 * 3 = 6.



cases:
3 smallest negative numbers
smallest negative number * 2 largest positive
3 largest negative number
3 smallest positive numbers
-}

import Data.List
import Data.Maybe

p xs 
    | l < 3 = Nothing
    | otherwise = Just (product xs)
    where l = length xs
smallestProduct as = minimum $ catMaybes [t1, t2, t3, t4]
    where pa = partition (<0) as
          pn = sort $ fst pa
          pp = sort $ snd pa
          t1 = p $ take 3 pn
          t2 = p $ (take 1 pn) ++ (take 2 (reverse pp))
          t3 = p $ take 3 (reverse pn)
          t4 = p $ take 3 pp
