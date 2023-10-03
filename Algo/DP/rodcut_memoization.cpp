#include <iostream>
#include <climits>
//eta top down approach
using namespace std;

int memoizedCutRodAux(int *p, int n, int *r) {
  if (r[n] >= 0) 
    return r[n];
  
  int q;
  if (n == 0) 
    q = 0;
  else {
    q = INT_MIN;
    for (int i = 1; i <= n; i++) 
      q = max(q, p[i-1] + memoizedCutRodAux(p, n-i, r));
  }
  
  r[n] = q;
  return q;
}

int cutRod(int *p, int n) {
  int r[n+1];
  for (int i = 0; i <= n; i++)
    r[i] = INT_MIN;
  
  return memoizedCutRodAux(p, n, r);  
}

int main() {
  int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
  int size = sizeof(arr)/sizeof(arr[0]);
  cout << "Maximum Obtainable Value is " << cutRod(arr, size) << endl;
  return 0;
}