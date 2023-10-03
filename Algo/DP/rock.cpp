#include <iostream>
#include <climits>

using namespace std;

#define ROWS 5 
#define COLS 10

// Prints optimal path for reaching cell (i, j) 
void printPath(int A[][COLS], int i, int j) {

  if (i == 0 && j == 0) {
    cout << i << " " << j << endl; 
    return;
  }

  if (A[i-1][j-1] <= A[i][j-1] && A[i-1][j-1] <= A[i-1][j+1])
    printPath(A, i-1, j-1);

  else if (A[i][j-1] <= A[i-1][j-1] && A[i][j-1] <= A[i-1][j+1]) 
    printPath(A, i, j-1);

  else
    printPath(A, i-1, j+1);

  cout << i << " " << j << endl;
}

// Returns minimum danger value of getting to cell (m, n) 
int getMinDanger(int danger[][COLS], int m, int n) {
  
  int A[ROWS][COLS];

  // Initialize base cases
  for(int i=0; i<ROWS; i++)
    A[i][0] = INT_MAX, A[i][COLS-1] = INT_MAX;

  for(int j=0; j<COLS; j++)
    A[0][j] = 0;

  // Build up DP table
  for(int i=1; i<ROWS; i++) {
    for(int j=1; j<COLS-1; j++) {
      A[i][j] = danger[i][j] + min(A[i-1][j-1], min(A[i-1][j], A[i-1][j+1]));
    }
  }

  // Print optimal path
  printPath(A, ROWS-1, COLS-1);

  // Return minimum danger 
  return A[ROWS-1][COLS-1];
}

int main() {
  
  int danger[ROWS][COLS] = { {3, 2, 1, 2, 3},
                             {4, 1, 3, 3, 1},
                             {2, 1, 4, 1, 2},
                             {3, 1, 5, 4, 3},
                             {2, 2, 1, 2, 4} };

  cout << getMinDanger(danger, ROWS-1, COLS-1);

  return 0;
}
