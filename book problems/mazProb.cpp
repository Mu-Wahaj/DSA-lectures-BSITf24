
//the worst ha time complexity is O((m*n)) where m and n are the dimensions of the maze, because in the worst case, we may explore all possible paths through the maze. Each cell can lead to up to 8 directions, and if we have m*n cells, the number of paths can grow exponentially.



#include <iostream>
#include <stack>
using namespace std;

// Direction offsets: N, NE, E, SE, S, SW, W, NW
const int dirRow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dirCol[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct Position
{
    int row, col, dir;
    Position(int r = 0, int c = 0, int d = 0) : row(r), col(c), dir(d) {}
};

bool Path(int maze[][7], int startRow, int startCol, int endRow, int endCol)
{
    stack<Position> s;
    int mark[7][7] = {0}; // track visited cells

    // Mark start position
    mark[startRow][startCol] = 1;
    s.push(Position(startRow, startCol, 0));

    while (!s.empty())
    {
        Position current = s.top();
        s.pop();

        int row = current.row;
        int col = current.col;
        int dir = current.dir;

        // Try all directions from current position
        while (dir < 8)
        {
            int nextRow = row + dirRow[dir];
            int nextCol = col + dirCol[dir];

            // Check if we reached the exit
            if (nextRow == endRow && nextCol == endCol)
            {
                cout << "Path found!" << endl;
                cout << "(" << endRow << "," << endCol << ") ";
                cout << "(" << row << "," << col << ") ";
                return true;
            }

            // Check if move is valid
            if (maze[nextRow][nextCol] == 0 && mark[nextRow][nextCol] == 0)
            {
                mark[nextRow][nextCol] = 1;
                s.push(Position(row, col, dir + 1)); // save current state
                row = nextRow;
                col = nextCol;
                dir = 0; // reset direction for new position
            }
            else
            {
                dir++; // try next direction
            }
        }
    }

    cout << "No path exists." << endl;
    return false;
}

int main()
{
    int maze[7][7] = {
        {1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1}};

    Path(maze, 1, 1, 5, 5);
    return 0;
}

// recursive version

#include <iostream>
using namespace std;

const int dirRow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dirCol[] = {0, 1, 1, 1, 0, -1, -1, -1};
int mark[7][7] = {0};

bool PathRecursive(int maze[][7], int row, int col, int endRow, int endCol)
{
    // Base case: reached exit
    if (row == endRow && col == endCol)
    {
        cout << "(" << row << "," << col << ") ";
        return true;
    }

    // Try all 8 directions
    for (int dir = 0; dir < 8; dir++)
    {
        int nextRow = row + dirRow[dir];
        int nextCol = col + dirCol[dir];

        // Check if move is valid
        if (maze[nextRow][nextCol] == 0 && mark[nextRow][nextCol] == 0)
        {
            mark[nextRow][nextCol] = 1;

            if (PathRecursive(maze, nextRow, nextCol, endRow, endCol))
            {
                cout << "(" << row << "," << col << ") ";
                return true;
            }

            // Backtrack (unmark for other paths if needed)
            // mark[nextRow][nextCol] = 0; // Uncomment to find ALL paths
        }
    }

    return false; // No path from this position
}

int main()
{
    int maze[7][7] = {
        {1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1}};

    mark[1][1] = 1;
    cout << "Path (in reverse order): ";
    if (PathRecursive(maze, 1, 1, 5, 5))
    {
        cout << "\nPath found!" << endl;
    }
    else
    {
        cout << "\nNo path exists." << endl;
    }

    return 0;
}