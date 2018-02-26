
def isCaseInsensitivePalindrome(inputString: String)= {
  val s = inputString.toLowerCase
  val c = inputString.length % 2
  val w = inputString.length / 2
  val flip = (s drop (w + c)).reverse
  val begin = s take w
  ((flip zip begin) map { x => if (x._1 == x._2) 0 else 1 }).sum == 0
}

println(isCaseInsensitivePalindrome("aaBaa"))
println(isCaseInsensitivePalindrome("AaBaa"))
println(isCaseInsensitivePalindrome("AaBca"))
