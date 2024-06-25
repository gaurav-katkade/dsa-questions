//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
bool comp(Item a,Item b){
    return a.value/(a.weight*1.0)>b.value/(b.weight*1.0);
}
class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        double total = 0.0;
        sort(arr,arr+n,comp);
        for(int i=0;i<n&&w>0;i++){
            if(arr[i].weight<=w){
                total += arr[i].value;
                w -= arr[i].weight;
            }else{
                total += (arr[i].value/(arr[i].weight*1.0))*w;
                break;
            }
        }
        return total;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends