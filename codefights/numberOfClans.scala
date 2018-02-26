def numberOfClans(divisors: Array[Int], k: Int) = {
    val d = divisors.toList
    def clan(x: Int) = {
        d.map(x % _ == 0)
    }
    ((1 to k) map clan)
}

val clans = numberOfClans(Array(2, 3), 6)
println(clans.distinct)
