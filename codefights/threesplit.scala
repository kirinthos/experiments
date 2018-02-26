def threeSplit(a: Array[Int])= {
val l = a.length
  (for (i1 <- 1 until l - 1;
        i2 <- i1 + 1 until l; 
        s = a.slice(i1, i2).sum;
        if a.take(i1).sum == s && a.drop(i2).sum == s)
        yield (i1, i2))

}

println(threeSplit(Array(0, -1, 0, -1, 0, -1)))
println(threeSplit(Array(-1, 1, -1, 1, -1, 1, -1, 1)))
