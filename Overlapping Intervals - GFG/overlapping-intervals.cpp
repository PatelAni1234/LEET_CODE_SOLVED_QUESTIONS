//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        int i = 0;
        vector<vector<int>> ans;
        sort(intervals.begin() , intervals.end());
        while(i<intervals.size()){
            int first = intervals[i][0];
            int second = intervals[i][1];
            while(i<intervals.size()-1 && intervals[i+1][0] <= second){
                second = max(second , intervals[i+1][1]);
                i++;
            }
            ans.push_back({first , second});
            i++;
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends