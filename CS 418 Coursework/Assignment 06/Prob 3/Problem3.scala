//Problem1.scala
//Joseph Gareri
//00099183
//jgareri@my.athens.edu
//Asg 06 | Prob. 3
// Used GPT for troubleshooting

import scala.io.Source
import scala.util.matching.Regex

object CathodeRayTube {
  case class State(x: Int, cycles: List[Int])

  def noop(state: State): State =
    state.copy(cycles = state.cycles :+ state.x)

  def addx(n: Int, state: State): State =
    state.copy(x = state.x + n, cycles = state.cycles ::: List(state.x, state.x))

  def execute(state: State, lines: List[String]): State = lines match {
    case Nil => state
    case line :: rest =>
     val noopRegex = new Regex("noop")
     val addxRegex = new Regex("addx (-?\\d+)")
     line match {
       case noopRegex() => execute(noop(state), rest)
       case addxRegex(n) => execute(addx(n.toInt, state), rest)
       case _ => throw new Exception("TILT")
     }
  }

  def executeFile(filename: String): List[Int] = {
    val lines = Source.fromFile(filename).getLines().toList
    val startingState = State(1, List())
    val endingState = execute(startingState, lines)
    endingState.cycles
  }

  def renderCycles(cycles: List[Int]): List[String] = {

    def loop(cycles: List[Int], screen: String, t: Int): List[String] =
      cycles match {
        case Nil => screen.grouped(40).toList
        case x :: rest =>
          val offset = t - x
          val pixel = if (-1 <= offset && offset <= 1) "#" else "."
          loop(rest, screen + pixel, (t + 1) % 40) 
      }
      
    loop(cycles, "", 0)
  }

  def printScreen(lines: List[String]): Unit =
    lines.foreach(println)

  def main(args: Array[String]): Unit = {
    val cycles = executeFile("input")
    val lines = renderCycles(cycles)
    printScreen(lines)
  }
}