

from datetime import datetime
def d(t):
    return datetime.strptime(t, '%Y-%m-%d')
def roadmap(tasks, queries):
    def c(t):
        return [t[0], d(t[1]), d(t[2])] + t[3:]
    tasks = list(map(c, tasks))
    def f(q):
        qd = d(q[1])
        return [ (t[0], t[2]) for t in tasks if q[0] in t[3:] and qd <= t[2] and qd >= t[1] ]
            
    return list(map(lambda x: sorted(f(x)), queries))


tasks = [["A", "2017-02-01", "2017-03-01", "Sam", "Evan", "Troy"],
 ["B", "2017-01-16", "2017-02-15", "Troy"],
  ["C", "2017-02-13", "2017-03-13", "Sam", "Evan"]]

queries = [["Evan", "2017-03-10"],
 ["Troy", "2017-02-04"]]
