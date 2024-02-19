file:///C:/Users/JeeperGary/source/repos/JosephGareri/CS%20418%20Coursework/Assignment%2002/Prob.%201/BowlingGame.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

presentation compiler configuration:
Scala version: 3.3.1
Classpath:
<HOME>\AppData\Local\Coursier\cache\v1\https\repo1.maven.org\maven2\org\scala-lang\scala3-library_3\3.3.1\scala3-library_3-3.3.1.jar [exists ], <HOME>\AppData\Local\Coursier\cache\v1\https\repo1.maven.org\maven2\org\scala-lang\scala-library\2.13.10\scala-library-2.13.10.jar [exists ]
Options:



action parameters:
uri: file:///C:/Users/JeeperGary/source/repos/JosephGareri/CS%20418%20Coursework/Assignment%2002/Prob.%201/BowlingGame.java
text:
```scala
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


```



#### Error stacktrace:

```
scala.collection.Iterator$$anon$19.next(Iterator.scala:973)
	scala.collection.Iterator$$anon$19.next(Iterator.scala:971)
	scala.collection.mutable.MutationTracker$CheckedIterator.next(MutationTracker.scala:76)
	scala.collection.IterableOps.head(Iterable.scala:222)
	scala.collection.IterableOps.head$(Iterable.scala:222)
	scala.collection.AbstractIterable.head(Iterable.scala:933)
	dotty.tools.dotc.interactive.InteractiveDriver.run(InteractiveDriver.scala:168)
	scala.meta.internal.pc.MetalsDriver.run(MetalsDriver.scala:45)
	scala.meta.internal.pc.PcCollector.<init>(PcCollector.scala:44)
	scala.meta.internal.pc.PcSemanticTokensProvider$Collector$.<init>(PcSemanticTokensProvider.scala:61)
	scala.meta.internal.pc.PcSemanticTokensProvider.Collector$lzyINIT1(PcSemanticTokensProvider.scala:61)
	scala.meta.internal.pc.PcSemanticTokensProvider.Collector(PcSemanticTokensProvider.scala:61)
	scala.meta.internal.pc.PcSemanticTokensProvider.provide(PcSemanticTokensProvider.scala:90)
	scala.meta.internal.pc.ScalaPresentationCompiler.semanticTokens$$anonfun$1(ScalaPresentationCompiler.scala:109)
```
#### Short summary: 

java.util.NoSuchElementException: next on empty iterator