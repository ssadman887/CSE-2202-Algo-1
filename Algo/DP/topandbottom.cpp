#include <iostream>
#include <climits>

using namespace std;

// Memoized cut rod 
int cutRodAux(int *p, int n, int *r) {
  if (r[n] >= 0) return r[n];
  
  int q = INT_MIN; 
  if (n == 0) q = 0;
  else {
    for (int i = 1; i <= n; i++) {
      q = max(q, p[i-1] + cutRodAux(p, n-i, r)); 
    }
  }
  
  r[n] = q;
  return q;
}

int cutRod(int *p, int n) {
  int r[n+1];
  for (int i = 0; i <= n; i++) r[i] = INT_MIN;
  return cutRodAux(p, n, r);
}

// Bottom up tabular
int cutRodBottomUp(int *p, int n) {
  int r[n+1];
  r[0] = 0;
  
  for (int j = 1; j <= n; j++) {
    int q = INT_MIN;
    for (int i = 1; i <= j; i++) {
      q = max(q, p[i-1] + r[j-i]);
    }
    r[j] = q;
  }
  
  return r[n];
}

int main() {
  int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
  int size = sizeof(arr)/sizeof(arr[0]);

  cout << "Memoized Cut Rod: " << cutRod(arr, size) << endl;
  cout << "Bottom Up Cut Rod: " << cutRodBottomUp(arr, size) << endl;

  return 0;
}