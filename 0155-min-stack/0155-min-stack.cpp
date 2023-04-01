class MinStack {
    int stack[10000];
    int min[10000];
    int topPtr;
    int mintop;
public:
    MinStack() {
        topPtr = -1;
        mintop = -1;
    }
    
    void push(int val) {
        if(topPtr >=10000) return;
        stack[++topPtr]= val;
        if(mintop >= 0){
            if(min[mintop] > val){
                min[++mintop] = val;
            }
            else{
                min[mintop+1]= min[mintop];
                mintop++;
            }
        }
        else{
            min[++mintop] = val;
        }
    }
    
    void pop() {
        if(topPtr < 0) return;
        topPtr--;
        mintop--;
    }
    
    int top() {
        return stack[topPtr];
    }
    
    int getMin() {
        return min[mintop];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */