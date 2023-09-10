//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */
void swap(queue<int>&q1,queue<int>&q2){
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
}

void QueueStack :: push(int x)
{
//      q2.push(x);
//      while(!q1.empty()){
//          q2.push(q1.front());
//          q1.pop();
//      }
//     swap(q1,q2);
    q1.push(x);
    int size=q1.size();
    for(int i=0;i<size-1;i++){
        int num=q1.front();
        q1.push(num);
        q1.pop();
    }
}
 
int QueueStack :: pop()
{
    if(q1.empty()) return -1;
    int num=q1.front();
    q1.pop();
    return num;
}
