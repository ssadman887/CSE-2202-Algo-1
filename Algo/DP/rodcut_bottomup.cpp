#include <iostream>
#include <climits>

using namespace std;

int cutRod(int *p, int n) {
  int r[n+1];
  
  r[0] = 0;
  
  for (int j=1; j<=n; j++) {
    int q = INT_MIN;
    for (int i=1; i<=j; i++) {
      q = max(q, p[i-1] + r[j-i]); 
    }
    r[j] = q;
  }

  return r[n];
}

int main() {

  int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout << "Maximum Obtainable Value is " << cutRod(arr, n);
  
  return 0;
}