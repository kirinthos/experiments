module JTL where

import Control.Arrow ( (&&&) )
import Data.List (group, sort, sortBy)
import Data.Ord (comparing, Down(..) )

{- ALGORITHM -}

-- reverse sorts on snd of a pair
reverseSortSnd r = sortBy (comparing (Down . snd)) r

-- takes list of two-element lists and makes it a list of all integers in between
expandRanges r = concatMap (\x -> [(x!!0)..(x!!1)]) r

-- element frequency counter
countElements xs = map (head &&& length) . group . sort $ xs

{- TESTING -}

-- takes a list of [ ( (test, inputs, ...), testAnswer ) ] and a 
-- function and runs the tests against the function
runTest f t = do
    putStrLn ("\ntest: " ++ (show $ fst t))
    putStrLn ("expect:\t" ++ (show $ snd t))
    putStrLn ("actual:\t" ++ (show ((uncurry f) $ fst t)))

runTests f = map (runTest f)
