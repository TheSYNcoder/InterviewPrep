class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if (!matrix.size() || !matrix[0].size()) return false;
        
        int i = 0;
        int j = matrix[0].size() - 1;
        
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target) {
                i++;
            }
            else {
                j--;
            }
        }
        
        return false;
        
    }
};
