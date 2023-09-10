class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() {  
    }
    
    void push(int x) {
         while(!s1.empty()){
           s2.push(s1.top());
           s1.pop();
       }s2.push(x);
       while(!s2.empty()){
           s1.push(s2.top());
           s2.pop();
       }
    }
    
    int pop() {
        int num=-1;
       if(s1.empty()) return -1;
       num=s1.top();
       s1.pop();
       return num;
    }
    
    int peek() {
         int num=-1;
       if(s1.empty()) return -1;
       num=s1.top();
       return num; 
    }
    
    bool empty() {
        return s1.empty()?1:0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */