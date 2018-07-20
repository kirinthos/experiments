module DigitDifferenceSort where

{-

Given an array of integers, sort its elements by the difference of their largest and smallest digits. In the case of a tie, that with the larger index in the array should come first.

Example

For a = [152, 23, 7, 887, 243], the output should be
digitDifferenceSort(a) = [7, 887, 23, 243, 152].

-}

import Data.List
import Data.Ord
import JTL

m xs = maximum xs - minimum xs

digitDifferenceSort a = map fst $ sortBy (mconcat [comparing (m . digits . fst), comparing snd]) (zip (reverse a) [0..])
