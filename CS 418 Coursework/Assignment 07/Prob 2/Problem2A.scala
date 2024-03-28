//Problem2.scala
//Joseph Gareri
//00099183
//jgareri@my.athens.edu
//Asg 07 | Prob. 2A
//Mergesort from instructor 
// [Done] exited with code=0 in 3.203 seconds

import scala.annotation.tailrec
import scala.util.Random
import scala.math.Ordering.Implicits._ //added library

object test {

  def msort[T : Ordering](xs: List[T]): List[T] = { //changed to Ordering

    @tailrec
    def merge(res: List[T], xs: List[T], ys: List[T]): List[T] = (xs, ys) match {
      case (_, Nil) => res.reverse ::: xs
      case (Nil, _) => res.reverse ::: ys
      case (x :: xs1, y :: ys1) =>
        if (x < y) merge(x :: res, xs1, ys)
        else merge(y :: res, xs, ys1)
    }

    val n = xs.length / 2
    if (n == 0) xs
    else {
      val (ys, zs) = xs splitAt n
      merge(Nil, msort(ys), msort(zs))
    }
  }

    def main(args: Array[String]): Unit = { //corrected main function
    val list = Seq.fill(50000)(Random.nextInt(500)).toList
    println(msort(list))
  }
}

// [Done] exited with code=0 in 3.203 seconds