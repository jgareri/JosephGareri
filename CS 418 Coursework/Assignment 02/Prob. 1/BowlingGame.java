//BowlingGame.java 
//Joseph Gareri
//00099183
//jgareri@my.athens.edu
//Asg 02 | Prob. 1
//Used GPT assistance && instructor samples

import java.util.Random;

public class BowlingGame {
  private int rolls[] = new int[21];
  private int currentRoll = 0;

  public void roll(int pins) {
      rolls[currentRoll++] = pins;
  }

  public int score() {
      int score = 0;
      int frameIndex = 0;
      for (int frame = 0; frame < 10; frame++) {
          if (isStrike(frameIndex)) {
              score += 10 + strikeBonus(frameIndex);
              frameIndex++;
          } else if (isSpare(frameIndex)) {
              score += 10 + spareBonus(frameIndex);
              frameIndex += 2;
          } else {
              score += sumOfBallsInFrame(frameIndex);
              frameIndex += 2;
          }
      }
      return score;
  }

  private boolean isStrike(int frameIndex) {
      return rolls[frameIndex] == 10;
  }

  private boolean isSpare(int frameIndex) {
      return rolls[frameIndex] + rolls[frameIndex + 1] == 10;
  }

  private int strikeBonus(int frameIndex) {
      return rolls[frameIndex + 1] + rolls[frameIndex + 2];
  }

  private int spareBonus(int frameIndex) {
      return rolls[frameIndex + 2];
  }

  private int sumOfBallsInFrame(int frameIndex) {
      return rolls[frameIndex] + rolls[frameIndex + 1];
  }

  public static void main(String[] args) {
    BowlingGame game = new BowlingGame();
    Random rand = new Random();

    for(int i=0; i<10; i++) { // Simulating 10 frames
        int firstRoll = rand.nextInt(11);
        game.roll(firstRoll);

        // Second roll
        int secondRoll = rand.nextInt(11 - firstRoll);
        game.roll(secondRoll);
        
        // Bonus roll if needed
        if(i == 9 && (firstRoll + secondRoll) >= 10){
            int bonusRoll = rand.nextInt(11);
            game.roll(bonusRoll);
        }
    }

    System.out.println(game.score());
}
}

