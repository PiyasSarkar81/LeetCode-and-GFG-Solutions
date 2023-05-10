class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num = 1;
        
        int top,down,left,right,dir;
        top =left = dir = 0;
        down = n-1;
        right = n-1;
        vector<vector<int>> ans(n, vector<int>(n));
        
        while(top<=down && left <= right){
            if(dir == 0){
                for(int i = left;i<=right;i++)
                    ans[top][i] = num++;
                top++;
            }
            else if(dir == 1){
                for(int i = top;i<=down;i++)
                    ans[i][right] = num++;
                right--;
            }
            else if(dir == 2){
                for(int i = right;i>=left;i--)
                    ans[down][i] = num++;
                down--;
            }
            else if(dir == 3){
                for(int i = down;i>=top;i--)
                    ans[i][left] = num++;
                left++;
            }
            dir = (dir + 1)%4;
        }
        return ans;
        
    }
};