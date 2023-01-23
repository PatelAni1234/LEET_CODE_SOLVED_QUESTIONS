//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Enhttps://practice.geeksforgeeks.org/courses/complete-test-series-product-companiesds
/*You are required to complete this method*/

class Solution{
     private:
    vector<int> nextSmallerElement(int *arr , int size){
        stack<int> s;
        s.push(-1);
        vector<int> ans(size);
        for(int i=size-1;i>=0;i--){
            int curr=arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
            
        }
        return ans;

    }
     vector<int> prevSmallerElement(int *arr , int size){
        stack<int> s;
        s.push(-1);
        vector<int> ans(size);
        for(int i=0;i<size;i++){
            int curr=arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
            
        }
        return ans;

    }
     int largestRectangleArea(int *heights , int n) {
        
        vector<int> next(n);
        next = nextSmallerElement( heights , n );

        vector<int> prev(n);
        prev = prevSmallerElement( heights , n );
       
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
           

            if(next[i] == -1){
                next[i]=n;
            } 
            int b=next[i]-prev[i]-1;
            int maxArea = l*b;
            ans = max(ans , maxArea);

        }
        return ans;
        
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int area=largestRectangleArea(M[0] ,m );
       
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]!=0){
                    M[i][j]+=M[i-1][j];

                }
                else{
                    M[i][j]=0;
                }
                
                
            }
            int newarea=largestRectangleArea(M[i] , m);
                area = max(area , newarea);
           
        }
        return area;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends