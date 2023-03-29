class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> rom = { { 'I' , 1 },{ 'V' , 5 },{ 'X' , 10 },{ 'L' , 50 },{ 'C' , 100 },{ 'D' , 500 },{ 'M' , 1000 } };
                                   
   int sum = rom[s.back()];
   for (int i = s.length() - 2; i >= 0; --i) 
   {
       if (rom[s[i]] < rom[s[i + 1]])
       {
           sum -= rom[s[i]];
       }
       else
       {
           sum += rom[s[i]];
       }
   }
   
   return sum;
    }
};