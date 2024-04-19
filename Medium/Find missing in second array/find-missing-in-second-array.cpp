//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    std::vector<int> findMissing(int a[], int b[], int n, int m) {
        std::vector<int> missingElements;
       std::unordered_map<int, bool> bMap;

    // Populate the map with elements of array b
    for (int i = 0; i < m; ++i) {
        bMap[b[i]] = true;
    }

    // Iterate through array a and find missing elements
    for (int i = 0; i < n; ++i) {
        if (bMap.find(a[i]) == bMap.end()) {
            missingElements.push_back(a[i]);
        }
    }

    return missingElements;
}
};
	

//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin>>n;
        int m;
        cin>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=0;i<m;i++)
        cin >> b[i];
        vector<int> ans;
        

        Solution ob;
        ans=ob.findMissing(a,b,n,m);
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
	    
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends