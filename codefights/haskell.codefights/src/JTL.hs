module JTL where

import Control.Arrow ( (&&&) )
import Data.List (group, sort, sortBy)
import Data.Ord (comparing, Down(..) )

{- ALGORITHM -}

-- reverse sorts on snd of a pair
reverseSortSnd r = sortBy (comparing (Down . snd)) r

-- sort descending
sortDesc :: Ord a => [a] -> [a]
sortDesc = sortBy (comparing Down)

-- takes list of two-element lists and makes it a list of all integers in between
expandRanges r = concatMap (\x -> [(x!!0)..(x!!1)]) r

-- element frequency counter
countElements xs = map (head &&& length) . group . sort $ xs

-- number to array of digits
digits :: Integral x => x -> [x]
digits 0 = []
digits x = digits (x `div` 10) ++ [x `mod` 10]

-- remove element duplicates
rmdupes :: (Ord a) => [a] -> [a]
rmdupes = map head . group . sort

{- TESTING -}

-- takes a list of [ ( (test, inputs, ...), testAnswer ) ] and a 
-- function and runs the tests against the function
runTest f t = do
    putStrLn ("\ntest: " ++ (show $ fst t))
    putStrLn ("expect:\t" ++ (show $ snd t))
    putStrLn ("actual:\t" ++ (show ((uncurry f) $ fst t)))

runTests f = mapM_ (runTest f)
