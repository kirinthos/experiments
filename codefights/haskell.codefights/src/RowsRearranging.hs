module RowsRearranging where

{-

Rows Rearranging
Given a rectangular matrix of integers, check if it is possible to rearrange its rows in such a way that all its columns become strictly increasing sequences (read from top to bottom).

matrix = [[2, 7, 1], 
          [0, 2, 0], 
          [1, 3, 1]]

-}
import Data.List

check [] = True
check [x] = True
check (x:y:xs) = x < y && check (y:xs)

rowsRearranging m = or $ map (and . map check . transpose) ps
    where ps = permutations m
