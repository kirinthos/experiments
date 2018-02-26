
/* Note: 1-indexed
 * okay, lets loop over each character in word 2
 * yield w2=(w1index, w2index) that are acceptable placements
 *
 * for each char in word 3
 * yield w3=(w1index, w3index) in word1.drop word2.w1index, acceptable placements
 *
 * for each pair of pairs of indices
 * yield (word2.drop w2.w2index, word3.drop w3.w3index, d=w3.w1index - w2.w1index)
 *
 * for each remaining word pair
 * for each position in w4
 * yield acceptable positions where w4.char and w4.char + d match
 * 
*/

val testWords1 = Array("crossword", "square", "formation", "something")
val testWords2 = Array("eternal", "texas", "chainsaw", "massacre")

def crosswordFormation(words: Array[String]) = {

  def findIndices(w: String, c: Char) = w.zipWithIndex.filter(_._1 == c).map(_._2)

  val allwords = words.permutations
  val testwords = Array(words)

  val indices = for ( (w2Char, w2Index) <- words(1).zipWithIndex ; if words(0) contains w2Char ;
                      w2IndexIn1 <- findIndices(words(0), w2Char) ;
                      (w3Char, w3Index) <- words(2).zipWithIndex ; if words(0).drop(w2IndexIn1 + 1) contains w3Char ;
                      w3IndexIn1 <- findIndices(words(0).drop(w2IndexIn1 + 1), w3Char) ; 
                      (w4Char, w4Index) <- words(3).zipWithIndex ; if words(1).drop(w2Index + 1) contains w4Char ;
                      w4IndexIn2 <- findIndices(words(1).drop(w2Index + 1), w4Char) ; 
                        if w3IndexIn1 > 0 && w4IndexIn2 > 0 &&
                          w4IndexIn2 < words(2).drop(w3Index + 1).length && 
                          w4Index + w3IndexIn1 + 1 < words(3).length &&
                          words(2).drop(w3Index + 1)(w4IndexIn2) == words(3)(w4Index + w3IndexIn1 + 1)) 
                    yield 1
  indices.length
}

val ps = testWords2.permutations
println(crosswordFormation(testWords2))
(ps map crosswordFormation) foreach { x => if (x != 0) println(x) }

