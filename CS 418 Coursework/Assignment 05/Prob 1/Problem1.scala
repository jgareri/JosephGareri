//Problem1.scala
//Joseph Gareri
//00099183
//jgareri@my.athens.edu
//Asg 05 | Prob. 1
//Used GPT For Troubleshooting

import scala.collection.mutable.Buffer

// pure
def insertionSortPlan[A](list: List[A])(implicit ev: Numeric[A]): List[A] = {
  def insert(elem: A, sortedPart: List[A]): List[A] =
    sortedPart.span(ev.lteq(_, elem)) match {
      case (lower, greater) => lower ++ (elem :: greater)
    }
    
  list.foldLeft(List.empty[A])((sortedPart, elem) => insert(elem, sortedPart))
}

// impure
def executeSortPlan[A](mutableList: scala.collection.mutable.Buffer[A], plan: List[A]): Unit = {
  for ((elem, index) <- plan.zipWithIndex) {
    mutableList(index) = elem
  }
}

def main(args: Array[String]): Unit = {

    val data = Buffer(3, 1, 4, 1, 5, 9)
    println(s"Before sorting: ${data}")

    val plan = insertionSortPlan(data.toList)
    executeSortPlan(data, plan)

    println(s"After sorting: ${data}")
  }