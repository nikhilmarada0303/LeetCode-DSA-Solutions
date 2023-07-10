//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    Node* reverse(Node* head){
        Node* dummy=NULL;
        while(head){
            Node* new_node=head->next;
            head->next=dummy;
            dummy=head;
            head=new_node;
        }return dummy;
    }
    Node* add(Node* l1,Node* l2){
            Node* dummy=new Node(0);
       Node* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry!=NULL){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->data;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->data;
                l2=l2->next;
            }
            sum=sum+carry;
            carry=sum/10;
            Node* new_node=new Node(sum%10);
            temp->next=new_node;
            temp=new_node;
        }return dummy->next;
    }
    public:
    
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
       l1=reverse(l1);
       l2=reverse(l2);
     
        Node* ans=add(l1,l2);
        return reverse(ans);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends