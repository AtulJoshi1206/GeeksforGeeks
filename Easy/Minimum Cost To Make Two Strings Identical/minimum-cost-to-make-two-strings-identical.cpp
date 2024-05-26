//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findMinCost(string x, string y, int costx, int costy) {
        // Your code goes here
        int n=x.length(),m=y.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=i*costx;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=j*costy;
        }
        // if(dp[i][j]!=-1)return dp[i][j];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(x[i-1]==y[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else {
                    int deletefromx=costx+dp[i-1][j];
                    int deletefromy=costy+dp[i][j-1];
                    dp[i][j]=min(deletefromx,deletefromy);
                    
                }
            }
        }
        return dp[n][m];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends