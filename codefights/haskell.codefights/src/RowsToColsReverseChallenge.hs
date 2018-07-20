module RowsToColsReverseChallenge where

{-
    [execution time limit] 4 seconds (hs)

    [input] array.integer rows

    Guaranteed constraints:
    1 ≤ rows.length ≤ 16
    0 ≤ rows[i] < 2rows.length

    [output] array.integer

Examples:

Input:
rows: [26, 16, 1, 15, 23]
Expected Output:
[25, 18, 3, 19, 7]

[   26 - 2^0 = 25,
    16 + 2^1 = 18,
    1  - 2^2 = -3,
    15 + 2^3 = 23,
    23 - 2^4 = 17
]

Input:
rows: [138, 58, 88, 157, 81,  86, 129, 103]
Expected Output:
      [146, 45, 65, 124, 240, 21, 197, 27]

[+8, -13, -23, -33, +159, -65, +68, -76]

Input:
rows: [1]
Expected Output:
[1]

Input:
rows: [3, 190, 112, 133, 91, 156, 123, 38]
Expected Output:
[84, 42, 99, 110, 78, 85, 203, 154]

Input:
rows: [13, 1, 1, 10]
Expected Output:
[9, 8, 1, 14]

[
    [ 1, 1, 0, 1 ],
    [ 0, 0, 0, 1 ],
    [ 0, 0, 0, 1 ],
    [ 1, 0, 1, 0 ]
]
ans: [ 9, 8, 1, 14 ]

-}

import Data.List (transpose)

data Bit = Zero | One deriving Show

toBitsBySize :: Int -> Int -> [Bit]
toBitsBySize 1 1 = [One]
toBitsBySize 1 _ = [Zero]
toBitsBySize s 0 = [ Zero | i <- [1..s] ]
toBitsBySize s x
    | xs >= 0   = One  : toBitsBySize sr xs
    | otherwise = Zero : toBitsBySize sr x
    where sr = s - 1
          xs = x - 2^sr

bitsToInt :: [Bit] -> Int
bitsToInt [] = 0
bitsToInt (One:bs) = 2^(length bs) + bitsToInt bs
bitsToInt (Zero:bs) = bitsToInt bs

rowsToCols rows = map bitsToInt (transpose $ map toBits rows)
    where toBits = toBitsBySize (length rows)
