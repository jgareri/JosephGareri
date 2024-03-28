//Problem1.scala
//Joseph Gareri
//00099183
//jgareri@my.athens.edu
//Asg 07 | Prob. 1
// Notes Below...

import scala.concurrent.Future
import scala.concurrent.ExecutionContext.Implicits.global
import scala.util.{Failure, Success}
import scala.concurrent.Await
import scala.concurrent.duration.Duration
import scala.collection.mutable._
import scala.util.Random

object QuickSort {
    def sort(a:Array[Int]): Array[Int] = {
        if (a.length < 2) return a
        val pivot = a(a.length / 2)
        sort(a filter (_ > pivot)) ++ (a filter (_ == pivot)) ++ sort(a filter (_ < pivot))
    }
}

object QuickSortFutures {
  def sort(a: Array[Int]): Array[Int] = {
    if (a.length < 2) return a
    val pivot = a(a.length / 2)
    val lessFuture = Future { sort(a filter (_ < pivot)) }  // Corrected filter condition
    val equal = a filter (_ == pivot)
    val moreFuture = Future { sort(a filter (_ > pivot)) }  // Corrected filter condition

    // Await results from futures 
    val less = Await.result(lessFuture, Duration.Inf)
    val more = Await.result(moreFuture, Duration.Inf)
    
    less ++ equal ++ more
  }
}

object Main {
    def initArrayWith(limit: Int): Array[Int] = {
        val list: ListBuffer[Int] = new ListBuffer()
        val randGen = new Random()
        (0 until limit).foreach(i => list += randGen.nextInt(1000000))
        list.toArray
    }

    def main(args: Array[String]): Unit = {
        val a = initArrayWith(200)
        val t1 = System.currentTimeMillis
        QuickSort.sort(a)
        val t2 = System.currentTimeMillis
        QuickSortFutures.sort(a)
        val t3 = System.currentTimeMillis
        println("NonParallel = " + (t2 - t1))
        println("Parallel = " + (t3 - t2))
    }
}


// First Run Outcomes

//-- [E040] Syntax Error: Problem1.scala:9:30

//-- [E040] Syntax Error: Problem1.scala:9:54

//-- [E040] Syntax Error: Problem1.scala:10:36

//-- Error in main function

// "Not Found Error" -- `scala.actors.Futures._` does not exists in the scala library. Deprecated.

//-----------------------------------------------------------------------------------------------

// Second Run Outcomes 

//-- Actors is not a member of scala. Deprecated. Replaced with "import scala.concurrent.Future"

// changed future to Future

//-- added "import scala.concurrent.ExecutionContext.Implicits.global"

//-- Error- less()++ equal()++ more() - does not take parameters.
    //longer explanation available when compiling with '-explain'
    //Added libraries and await results
        //import scala.util.{Failure, Success}
        //import scala.concurrent.Await
        //import scala.concurrent.duration.Duration

//---------------------------------------------------------------------------------------------------

// Third Attempt Outcomes

// NonParallel = 11
// Parallel = 85