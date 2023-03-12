//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
   Node* nodeg(Node* root, int target , map<Node* , Node*> &m ){
      
      Node* res=NULL;
      queue<Node*> q;
      q.push(root);
      m[root]=NULL;
      
      while(!q.empty()){
         Node* temp=q.front();
         q.pop();
         
         
         if(temp->data==target){
             res=temp;
         }
         if(temp->left){
             m[temp->left]=temp;
             q.push(temp->left);
         }
          if(temp->right){
             m[temp->right]=temp;
             q.push(temp->right);
         }
         
      }
      return res;
      
      
    }
    
    int burntree(Node* t , map<Node* , Node*> &m){
        map<Node* , bool> visited;
        queue<Node*> q;
        
        q.push(t);
        
        visited[t]=true;
        
        int ans=0;
        
        while(!q.empty()){
            bool flag=0;

            int size=q.size();
            
            
            for(int i=0;i<size;i++){
                Node* temp=q.front();
                q.pop();
                
                
                if(temp->left && !visited[temp->left]){
                    flag=1;
                    visited[temp->left]=true;
                    q.push(temp->left);
                }
            
                if(temp->right && !visited[temp->right]){
                    flag=1;
                    visited[temp->right]=true;
                    q.push(temp->right);
                }
                if(m[temp] && !visited[m[temp]]){
                    flag=1;
                    visited[m[temp]]=true;
                    q.push(m[temp]);
                }
            }
            
            if(flag==1){
                ans++;
            }
        }
        return ans;
        
    }
    int minTime(Node* root, int target) 
    {
        map<Node* , Node*>  m;
        
        Node* t=nodeg(root , target , m ); 
        
        
        int ans= burntree( t , m );
        return ans;
       
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends