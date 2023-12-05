class Solution {
public:
    int numberOfMatches(int n) {
        int match=0;
        while(n>1){
            if(n%2 == 0){
               int matchcount=n/2;
               n=n/2;  //n/2 teams go to advance
               match+=matchcount;
            }else{
              //if odd teams- 1 directly go to advance
                  int matchcount=(n-1)/2;
                  n=matchcount+1; //1 additional go to advance
                 match+=matchcount;  
            } 
        }
         
         return match;
    }
};