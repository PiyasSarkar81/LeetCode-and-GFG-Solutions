class Solution {
public:
    int squreOfDigits(int n){
        int sum =0,temp;
        while(n){
            temp = n%10;
            sum += temp*temp;
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow =n,fast =n;
        do{
            slow = squreOfDigits(slow);
            fast = squreOfDigits(fast);
            fast = squreOfDigits(fast);
        }
        while(slow!=fast);
        if(slow == 1) return true;
        else return false;
    }
};