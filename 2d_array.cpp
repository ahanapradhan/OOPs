#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Board {
private:
    vector<vector<char>> grid;
    int rows, cols;

public:
    Board(int r, int c) : rows(r), cols(c) {
        grid.assign(rows, vector<char>(cols, '.'));
    }

    void placeObstacle(int count) {
        for (int k = 0; k < count; k++) {
            int r = rand() % rows;
            int c = rand() % cols;
            if (grid[r][c] == '.') {
                grid[r][c] = '#';
            }
        }
    }

    void setCell(int r, int c, char ch) {
        grid[r][c] = ch;
    }

    char getCell(int r, int c) const {
        return grid[r][c];
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Character {
protected:
    int row, col;
    char symbol;

public:
    Character(int r, int c, char sym) : row(r), col(c), symbol(sym) {}

    int getRow() const { return row; }
    int getCol() const { return col; }
    char getSymbol() const { return symbol; }

    void placeOnBoard(Board &board) {
        board.setCell(row, col, symbol);
    }

    void clearFromBoard(Board &board) {
        board.setCell(row, col, '.');
    }

    void move(char direction, const Board &board) {
        int newR = row, newC = col;
        if (direction == 'w') newR--;
        else if (direction == 's') newR++;
        else if (direction == 'a') newC--;
        else if (direction == 'd') newC++;

        if (newR >= 0 && newR < board.getRows() &&
            newC >= 0 && newC < board.getCols() &&
            board.getCell(newR, newC) != '#') {
            row = newR;
            col = newC;
        }
    }

    void moveToward(int targetR, int targetC, const Board &board) {
        if (row < targetR && board.getCell(row + 1, col) != '#') row++;
        else if (row > targetR && board.getCell(row - 1, col) != '#') row--;
        else if (col < targetC && board.getCell(row, col + 1) != '#') col++;
        else if (col > targetC && board.getCell(row, col - 1) != '#') col--;
    }
};

class Game {
private:
    Board board;
    Character tom;
    Character jerry;
    Character cheese;

public:
    Game(int rows, int cols)
        : board(rows, cols),
          tom(0, 0, 'T'),
          jerry(rows - 1, cols - 1, 'J'),
          cheese(rand() % rows, rand() % cols, 'C')
    {
        srand(time(0));
        board.placeObstacle((rows * cols) / 5);

        // Ensure cheese doesn't overlap with Tom, Jerry, or obstacle
        while ((cheese.getRow() == tom.getRow() && cheese.getCol() == tom.getCol()) ||
               (cheese.getRow() == jerry.getRow() && cheese.getCol() == jerry.getCol()) ||
               board.getCell(cheese.getRow(), cheese.getCol()) == '#') {
            cheese = Character(rand() % rows, rand() % cols, 'C');
        }
    }

    void run() {
        cout << "Welcome to Tom & Jerry Chase!\n";
        cout << "Controls: W = up, S = down, A = left, D = right\n";
        cout << "First, choose who moves: T (Tom) or J (Jerry)\n\n";

        while (true) {
            board.print();
            char who;
            cout << "Move who? (T/J): ";
            cin >> who;

            char move;
            cout << "Enter move: ";
            cin >> move;

            if (who == 'T' || who == 't') {
                tom.clearFromBoard(board);
                tom.move(move, board);
            } else {
                jerry.clearFromBoard(board);
                jerry.move(move, board);
            }

            // Jerry auto-moves if player didn't choose him
            if (who == 'T' || who == 't') {
                jerry.clearFromBoard(board);
                jerry.moveToward(cheese.getRow(), cheese.getCol(), board);
            }

            // Win/Lose check
            if (tom.getRow() == jerry.getRow() && tom.getCol() == jerry.getCol()) {
                cout << "\nTom caught Jerry! You win!\n";
                break;
            }
            if (jerry.getRow() == cheese.getRow() && jerry.getCol() == cheese.getCol()) {
                cout << "\nJerry got the cheese! Jerry wins!\n";
                break;
            }

            // Update board
            tom.placeOnBoard(board);
            jerry.placeOnBoard(board);
            cheese.placeOnBoard(board);
        }
    }
};

int main() {
    int rows, cols;
    cout << "Enter board rows: ";
    cin >> rows;
    cout << "Enter board cols: ";
    cin >> cols;

    Game game(rows, cols);
    game.run();

    return 0;
}
