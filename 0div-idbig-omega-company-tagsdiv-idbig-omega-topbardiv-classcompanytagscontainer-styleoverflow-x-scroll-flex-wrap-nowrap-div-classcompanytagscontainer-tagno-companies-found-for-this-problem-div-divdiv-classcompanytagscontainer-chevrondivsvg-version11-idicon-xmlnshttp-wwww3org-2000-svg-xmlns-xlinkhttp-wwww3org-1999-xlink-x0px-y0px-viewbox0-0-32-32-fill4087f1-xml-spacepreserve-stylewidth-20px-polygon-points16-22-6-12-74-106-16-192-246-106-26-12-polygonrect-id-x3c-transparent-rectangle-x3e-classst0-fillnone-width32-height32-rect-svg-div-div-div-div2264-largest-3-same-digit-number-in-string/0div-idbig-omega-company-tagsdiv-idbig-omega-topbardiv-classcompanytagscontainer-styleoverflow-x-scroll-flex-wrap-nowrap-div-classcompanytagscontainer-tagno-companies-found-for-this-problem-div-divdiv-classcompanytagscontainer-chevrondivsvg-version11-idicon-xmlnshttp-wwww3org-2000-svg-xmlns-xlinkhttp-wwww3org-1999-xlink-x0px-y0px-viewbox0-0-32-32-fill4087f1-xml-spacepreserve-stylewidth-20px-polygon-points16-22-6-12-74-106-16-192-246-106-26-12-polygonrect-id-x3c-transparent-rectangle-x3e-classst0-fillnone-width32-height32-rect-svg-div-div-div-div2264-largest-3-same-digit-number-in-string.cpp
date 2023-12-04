class Solution {
public:
    string largestGoodInteger(string num) {
        char maxDigit = '\0';
        for(int i=1;i<num.size()-1;i++){
            if(num[i] == num[i-1] && num[i] == num[i+1])
                maxDigit = max(maxDigit, num[i]);
        }
        return maxDigit == '\0' ? "" : string(3, maxDigit);
    }
};