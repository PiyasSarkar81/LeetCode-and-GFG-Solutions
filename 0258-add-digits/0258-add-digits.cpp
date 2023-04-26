class Solution {
public:
    void add(int& num){
        int t = num%10;
        num /= 10;
        while(num!=0){
            t += num%10;
            num /= 10;
        }
        num = t;
    }
    int addDigits(int num) {
        while(num>9){
            add(num);
        }
        return num;
    }
};