//EightQueens.java 
//Joseph Gareri
//00099183
//jgareri@my.athens.edu
//Asg 02 | Prob. 3 (Extra Credit)
//Used GPT assistance && instructor samples



import java.util.*;

public class EightQueens2 {
    private static final int SIZE = 8;

    public static void main(String[] args) {
        EightQueens2 queens = new EightQueens2();
        List<List<Integer>> solutions = queens.placeQueens(0, new ArrayList<>(), new ArrayList<>(), new ArrayList<>());

        for (List<Integer> solution : solutions) {
            System.out.println(solution);
        }
    }

    public List<List<Integer>> placeQueens(int i, List<Integer> a, List<Integer> b, List<Integer> c) {
        List<List<Integer>> results = new ArrayList<>();

        if (i < SIZE) {
            for (int j = 0; j < SIZE; j++) {
                if (!a.contains(j) && !b.contains(i + j) && !c.contains(i - j)) {
                    a.add(j);
                    b.add(i + j);
                    c.add(i - j);
                    results.addAll(placeQueens(i + 1, a, b, c));
                    // Backtrack and remove the values for next solution
                    a.remove(a.size() - 1);
                    b.remove(b.size() - 1);
                    c.remove(c.size() - 1);
                }
            }
        } else {
            results.add(new ArrayList<>(a));
        }

        return results;
    }
}