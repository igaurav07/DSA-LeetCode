class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int count=0;
        int total =row*col;
         //indexing 
         int strow=0;
         int stcol=0;
         int enrow=row-1;
         int encol=col-1;

         //loop
         while(count<total){
            for(int index=stcol;count<total && index <= encol; index++){
                ans.push_back(matrix[strow][index]);
                count++;
            }
            strow++;
            for(int index=strow;count<total && index<=enrow;index++){
                 ans.push_back(matrix[index][encol]);
                count++;

            }
            encol--;
            for(int index=encol;count<total && index>=stcol;index--){
                 ans.push_back(matrix[enrow][index]);
                count++;
         }
            enrow--;
            for(int index=enrow;count<total && index>=strow;index--){
                 ans.push_back(matrix[index][stcol]);
                count++;
            }
            stcol++;
         }
         return ans;
    }
};