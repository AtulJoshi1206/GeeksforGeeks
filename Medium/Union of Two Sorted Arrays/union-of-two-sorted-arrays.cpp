//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    vector<int> first_vector(arr1, arr1 + n);
    vector<int> second_vector(arr2, arr2 + m);
    vector<int> union_vector(n + m);
    auto it = set_union(first_vector.begin(), first_vector.end(), 
                        second_vector.begin(), second_vector.end(), 
                        union_vector.begin());
    union_vector.resize(distance(union_vector.begin(), it));
    union_vector.erase(unique(union_vector.begin(), union_vector.end()), union_vector.end());
    return union_vector;
}
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends