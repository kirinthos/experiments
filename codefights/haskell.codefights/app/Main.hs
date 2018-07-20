module Main where

import DigitDifferenceSort
import DrinkingBeers
import JTL
import MaxSum
import RowsRearranging
import RowsToColsReverseChallenge
import SimilarPolygonArea
import SmallestProduct


testMaxSumRanges f = map f testInputs

main :: IO ()
main = do
    let tests = zip testInputs testAnswers
        in runTests maximumSumRanges tests
