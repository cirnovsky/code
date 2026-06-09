import Data.List (foldl')

solve :: [Int] -> (Bool, [Int])
solve (n:rest) =
    let (a, rest') = splitAt n rest
    in (resolve a 0 && resolve a 1, rest')
solve _ = error "invalid input"

resolve :: [Int] -> Int -> Bool
resolve a rem =
    let
        selected = filter (\x -> x `mod` 2 == rem) a
        others   = filter (\x -> x `mod` 2 /= rem) a

        premax = scanl1 max selected

        minOther =
            if null others then maxBound :: Int
            else minimum others

        maxOther =
            if null others then minBound :: Int
            else maximum others

        check i =
            let pm  = premax !! (i - 1)
                cur = selected !! i
            in not (pm > cur && cur < minOther && maxOther < pm)
    in
        all check [1 .. length selected - 1]

main :: IO ()
main = do
    input <- getContents
    let nums = map read (words input) :: [Int]
    let t = head nums
    let rest = tail nums
    run t rest

run :: Int -> [Int] -> IO ()
run 0 _ = return ()
run t nums = do
    let (ok, nums') = solve nums
    putStrLn $ if ok then "yes" else "no"
    run (t - 1) nums'
