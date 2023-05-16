class Solution {
public:
    // vector<vector<int>> generate(int numRows) {
        // vector<vector<int>> r(numRows);
        // for(int i=0;i<numRows;i++){
        //     r[i].resize(i+1);
        //     r[i][i]=r[i][0]=1;
        //     for(int j=1;j<i;j++){
        //         r[i][j]=r[i-1][j]+r[i-1][j-1];
        //     }
        // }
        // return r; 
    // }
    
     vector<int> genarateRow(int row) {
        int ans = 1;
        vector<int> temp;
        temp.push_back(1);
        for(int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans /= col;
            temp.push_back(ans);
        }
        return temp;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r;
        for(int i=1;i<=numRows; i++) {
            r.push_back(genarateRow(i));
        }
        return r;
    }
};