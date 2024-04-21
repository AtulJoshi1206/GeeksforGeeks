//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    void merge(int arr[] , int low, int mid, int high, int *ans, int temp[])
    {
        int l = low;
        int r = mid + 1;
        int k = low;
        while(l <= mid && r <= high)
        {
            if(arr[l] > arr[r])
            {
                temp[k] = arr[r];
                k++;
                r++;
                *ans += mid -l + 1;
            }
            else
            {
                temp[k] = arr[l];
                k++;
                l++;
            }
        }
        while(l <= mid)
        {
            temp[k] = arr[l];
            k++;
            l++;
        }
        
        while(r <= high)
        {
            temp[k] = arr[r];
            k++;
            r++;
        }
        for(int k = low; k <= high; k++)
        {
            arr[k] = temp[k];
        }
    }
    void mergesort(int arr[] , int low, int high, int *ans, int temp[])
    {
        if(low == high)
            return;
        int mid = (low + high)/2;
        mergesort(arr, low, mid, ans, temp);
        mergesort(arr, mid + 1, high, ans, temp);
        merge(arr, low, mid, high, ans, temp);
    }
    int countPairs(int arr[] , int n ) 
    {
         int count = 0;
         int temp[10005];
         for(int i = 0; i < n; i++)
         {
             arr[i] = i * arr[i];
         }
         mergesort(arr, 0 , n-1, &count, temp);
         return count;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends