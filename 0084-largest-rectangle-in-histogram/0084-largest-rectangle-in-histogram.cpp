class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n),right(n);
        
        stack<int> myStack;
        for(int i =0;i<n;i++){
            if(myStack.empty()){
                left[i] = 0;
                myStack.push(i);
            }
            else{
                while(!myStack.empty() && heights[myStack.top()]>=heights[i])
                    myStack.pop();
                left[i] = myStack.empty()? 0 : myStack.top()+1;
                myStack.push(i);
            }
        }
        while(!myStack.empty())
            myStack.pop();
        
        for(int i =n-1;i>=0;i--){
            if(myStack.empty()){
                right[i] = n-1;
                myStack.push(i);
            }
            else{
                while(!myStack.empty() && heights[myStack.top()] >= heights[i])
                    myStack.pop();
                right[i] = myStack.empty()? n-1: myStack.top()-1;
                myStack.push(i);
            }
        }
        int max_area =0;
        for(int i =0;i<n;i++){
            max_area = max(max_area, heights[i]*(right[i]-left[i]+1));
        }
        return max_area;
    }
};