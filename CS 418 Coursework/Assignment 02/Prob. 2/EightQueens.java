//EightQueens.java 
//Joseph Gareri
//00099183
//jgareri@my.athens.edu
//Asg 02 | Prob. 2
//Used GPT assistance && instructor samples


public class EightQueens {
    private static final int SIZE = 8;
    private int[] columns = new int[SIZE];

    public void placeQueens() {
        putQueen(columns, 0);
    }

    private void putQueen(int[] locations, int targetRow) {
        if (targetRow == SIZE) {
            printBoard(columns);
        } else {
            for (int column = 0; column < SIZE; column++) {
                columns[targetRow] = column;
                if (checkValid(columns, targetRow)) {
                    putQueen(locations, targetRow + 1);
                }
            }
        }
    }

    private boolean checkValid(int[] columnsForRow, int checkRow) {
        for (int currentRow = 0; currentRow < checkRow; currentRow++) {
            if (columnsForRow[checkRow] == columnsForRow[currentRow] || 
                checkRow - currentRow == Math.abs(columnsForRow[checkRow] - columnsForRow[currentRow])) {
                return false;
            }
        }
        return true;
    }

    private void printBoard(int[] columns) {
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                if(columns[i] == j) {
                    System.out.print("Q ");
                } else {
                    System.out.print("| ");
                }
            }
            System.out.println("\n-----------------");
        }
        System.out.println("\n=================\n");
    }

    public static void main(String[] args) {
        EightQueens eightQueens = new EightQueens();
        eightQueens.placeQueens();
    }
}
