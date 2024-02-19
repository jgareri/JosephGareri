//Problem1.scala
//Joseph Gareri
//00099183
//jgareri@my.athens.edu
//Asg 04 | Prob. 1
//Used Assignment 2 as reference

import scala.util.Random

class BowlingGame {
  private val rolls = Array.ofDim[Int](21)
  private var currentRoll = 0

  def roll(pins: Int): Unit = {
    rolls(currentRoll) = pins
    currentRoll += 1
  }

  def score(): Int = {
    var score = 0
    var frameIndex = 0
    for (_ <- 0 until 10) {
      if (isStrike(frameIndex)) {
        score += 10 + strikeBonus(frameIndex)
        frameIndex += 1
      } else if (isSpare(frameIndex)) {
        score += 10 + spareBonus(frameIndex)
        frameIndex += 2
      } else {
        score += sumOfBallsInFrame(frameIndex)
        frameIndex += 2
      }
    }
    score
  }

  private def isStrike(frameIndex: Int) = rolls(frameIndex) == 10

  private def isSpare(frameIndex: Int) = rolls(frameIndex) + rolls(frameIndex + 1) == 10

  private def strikeBonus(frameIndex: Int) = rolls(frameIndex + 1) + rolls(frameIndex + 2)

  private def spareBonus(frameIndex: Int) = rolls(frameIndex + 2)

  private def sumOfBallsInFrame(frameIndex: Int) = rolls(frameIndex) + rolls(frameIndex + 1)
}

def main(args: Array[String]): Unit = {
    val game = new BowlingGame
    val rand = new Random

    for(i <- 0 until 10) { // Simulating 10 frames
        val firstRoll = rand.nextInt(11)
        game.roll(firstRoll)

        // Second roll
        val secondRoll = rand.nextInt(11 - firstRoll)
        game.roll(secondRoll)
        
        // Bonus roll if needed
        if(i == 9 && (firstRoll + secondRoll) >= 10){
            val bonusRoll = rand.nextInt(11)
            game.roll(bonusRoll)
        }
    }

    println(game.score())
}

