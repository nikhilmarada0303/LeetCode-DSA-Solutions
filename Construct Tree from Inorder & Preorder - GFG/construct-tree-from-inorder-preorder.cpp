//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
        private:
    Node* consTree(int preStart,int preEnd,int preorder[],int inStart,int inEnd,int inorder[],unordered_map<int,queue<int>>&mp){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        Node* root=new Node(preorder[preStart]);
        int inRoot=mp[root->data].front();
        mp[root->data].pop();
        int left=inRoot-inStart;
        root->left=consTree(preStart+1,preStart+left,preorder,inStart,inRoot-1,inorder,mp);
        root->right=consTree(preStart+left+1,preEnd,preorder,inRoot+1,inEnd,inorder,mp);
        return root;   
    }
    public:
    Node* buildTree(int inorder[],int preorder[], int n)
    {
        unordered_map<int,queue<int>>mp;
        for(int i=0;i<n;i++)
            mp[inorder[i]].push(i);
        Node* root=consTree(0,n-1,preorder,0,n-1,inorder,mp);
        return root;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends