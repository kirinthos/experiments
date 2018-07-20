module SimilarPolygonArea where

{-

For a regular polygon with n sides and perimeter p, we can find a new similar polygon by extending the radius from the center to each vertex. Given the length of the new radius r, we'd like to find the difference in area between the two shapes.

round to nearest integer
-}

similarPolygonArguments = [
    (5, 40, 16),
    (6, 12, 10)
    ]
similarPolygonAnswers = [ 499, 249 ]

trapArea n p r = round $ a2 - a1
    where half = (360 / n / 2) * pi / 180
          b1 = p / n / 2
          h1 = (b1 / sin half) * cos half
          a1 = b1 * h1 * n
          a2 = r * sin half * r * cos half * n
