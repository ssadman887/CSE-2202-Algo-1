#include <iostream>
#include <climits>

using namespace std;

// Item structure 
struct Item {
  int value;
  int weight;
};

// Returns maximum value that can be put in knapsack of capacity W
int knapSack(int W, Item arr[], int n) {
  
  // dp[i] represents maximum value with capacity i
  int dp[W+1]; 

  // Base case
  dp[0] = 0; 

  // Build dp table valuing items 1 to n
  for(int i=1; i<=W; i++) {
    dp[i] = 0;
    for(int j=0; j<n; j++) {
      if(arr[j].weight <= i) {
        int val = arr[j].value + dp[i-arr[j].weight];
        if(val > dp[i])
          dp[i] = val;
      }
    }
  }

  return dp[W]; // Return maximum value for full knapsack
}

int main() {

  Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
  int W = 50; 
  int n = sizeof(arr)/sizeof(arr[0]);

  cout << knapSack(W, arr, n);

  return 0;
}