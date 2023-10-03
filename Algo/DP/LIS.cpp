#include <iostream>

using namespace std;
int binarySearch(int tail[], int low, int high, int key) {
  while(low <= high) {
    int mid = low + (high - low)/2;
    if(key == tail[mid])
      return mid;
    if(key > tail[mid])
      low = mid + 1;
    else 
      high = mid - 1;
  }
  return low;
}
int lis(int arr[], int n) {
  int tail[n];
  int length = 1;

  tail[0] = arr[0];

  for(int i=1; i<n; i++) {
    if(arr[i] > tail[length-1])
      tail[length++] = arr[i];
    else {
      int idx = binarySearch(tail, 0, length-1, arr[i]);
      tail[idx] = arr[i];
    }
  }

  return length;
}




int main() {
  int arr[] = {2, 5, 3, 7, 11, 8, 10, 13, 6};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout << "Length of LIS is " << lis(arr, n);
  
  return 0;
}