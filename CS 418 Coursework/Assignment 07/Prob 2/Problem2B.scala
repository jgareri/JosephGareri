//Problem2.scala
//Joseph Gareri
//00099183
//jgareri@my.athens.edu
//Asg 07 | Prob. 2B
//Implementing Parallel Mergesort from instructor code
// [Done] exited with code=0 in 4.387 seconds
// Used GPT Assistance

import scala.concurrent.Future
import scala.concurrent.ExecutionContext.Implicits.global
import scala.util.Random
import scala.concurrent.Await
import scala.concurrent.duration._
import scala.math.Ordering.Implicits._
import scala.collection.mutable.ListBuffer

object ParallelMergeSort {

  def parallelMergeSort[T : Ordering](xs: List[T]): Future[List[T]] = {
    val n = xs.length / 2
    if (n == 0) Future.successful(xs)
    else {
      val (left, right) = xs.splitAt(n)
      val leftSorted = parallelMergeSort(left)
      val rightSorted = parallelMergeSort(right)

      for {
        l <- leftSorted
        r <- rightSorted
      } yield merge(l, r)
    }
  }


  @scala.annotation.tailrec
  def merge[T: Ordering](left: List[T], right: List[T], acc: ListBuffer[T] = ListBuffer.empty[T]): List[T] = {
    (left, right) match {
      case (ls, Nil) => acc ++= ls; acc.toList
      case (Nil, rs) => acc ++= rs; acc.toList
      case (l::ls, r::rs) =>
        if (implicitly[Ordering[T]].lt(l, r)) merge(ls, right, acc += l)
        else merge(left, rs, acc += r)
    }
  }

  def main(args: Array[String]): Unit = {
    val rng = new scala.util.Random
    val list = List.fill(10)(rng.shuffle(1 to 100000)).flatten
    val sorted = Await.result(parallelMergeSort(list), Duration.Inf)
    println(sorted.take(50000))
  }
}

//[Done] exited with code=0 in 4.387 seconds