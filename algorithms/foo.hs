foo :: (Ord a) => [a] -> [a]
foo a n xs | n==0 = []
           | m==n-b =foo b n vs
           | otherwise =foo a b us
           where
           b = a + 1 + n `div` 2
           us = [ y | y <- xs, y < b]
           vs = [ y | y <- xs, y >= b]
           m = length us


quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) =
    let smallerSorted = quicksort [a | a <- xs, a <= x]
        biggerSorted = quicksort [a | a <- xs, a > x]
    in  smallerSorted ++ [x] ++ biggerSorted
