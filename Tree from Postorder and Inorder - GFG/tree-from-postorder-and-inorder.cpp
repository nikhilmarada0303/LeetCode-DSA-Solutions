//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node* consTree(int postStart,int postEnd,int postorder[],int inStart,int inEnd,int inorder[],map<int,int>&mp){
        if(postStart>postEnd || inStart>inEnd) return NULL;
        Node* root=new Node(postorder[postEnd]);
        int inRoot=mp[root->data];
        int left=inRoot-inStart;
        root->left=consTree(postStart,postStart+left-1,postorder,inStart,inRoot-1,inorder,mp);
        root->right=consTree(postStart+left,postEnd-1,postorder,inRoot+1,inEnd,inorder,mp);
        return root;   
    }
Node *buildTree(int inorder[], int postorder[], int n) {
     map<int,int>mp;
        for(int i=0;i<n;i++)
            mp[inorder[i]]=i;
        Node* root=consTree(0,n-1,postorder,0,n-1,inorder,mp);
        return root;
}
