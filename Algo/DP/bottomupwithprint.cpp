#include <iostream>
#include <climits>

using namespace std;

void printCutRodSolution(int *p, int n) {
  int r[n+1]; 
  int s[n+1];
  
  r[0] = 0;

  for (int j=1; j<=n; j++) {
    int q = INT_MIN;
    for (int i=1; i<=j; i++) {
      if (q < p[i-1] + r[j-i]) {
        q = p[i-1] + r[j-i];
        s[j] = i; 
      }
    }
    r[j] = q;
  }

  cout << "Optimal Revenue: " << r[n] << endl;
  
  while (n > 0) {
    cout << s[n] << " ";
    n = n - s[n];
  }
}

int main() {
  int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
  int size = sizeof(arr)/sizeof(arr[0]);

  printCutRodSolution(arr, size);
  
  return 0;
}