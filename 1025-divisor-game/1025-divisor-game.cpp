class Solution {
    bool solve(int n){
        if(n%2==0) return true;
        else return false;
    }
public:
    bool divisorGame(int n) {
        if(n == 1) return false;
        return solve(n);
    }
};