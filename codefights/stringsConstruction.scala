def stringsConstruction(a: String, b: String): Int = {
    val acount = a.groupBy(_.toChar).map(p => (p._1, p._2.length))
    (for ((c, count) <- b.groupBy(_.toChar) if (acount contains c)) 
            yield count.length / acount(c)) match {
        case Nil => 0
        case l => l.min
    }
}

println(stringsConstruction("", ""))
