class Solution {
public:
    int bestClosingTime(string customers) {
        int ans =0,p =0;
        for(auto c : customers){
            if(c=='Y')p++;
        }
        //cout<<p<<endl;
        int mini = p;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y')p--;
            else p++;
            if(p<mini){
                mini =p;
                ans = i+1;
            }
        }

        return ans;
    }
};