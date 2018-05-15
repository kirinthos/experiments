module Main where

import MaxSum

testMaxSumRanges f = map f testInputs

main :: IO ()
main = do
    let wrapMax = uncurry maximumSumRanges
    putStrLn (show (testMaxSumRanges wrapMax))
