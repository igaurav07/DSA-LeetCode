#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        if (numRows <= 0) {
            return {};
        }
        
        std::vector<std::vector<int>> triangle;
        triangle.push_back({1});
        
        for (int i = 1; i < numRows; ++i) {
            const std::vector<int>& prev_row = triangle.back();
            std::vector<int> current_row;
            current_row.push_back(1);
            
            for (size_t j = 1; j < prev_row.size(); ++j) {
                current_row.push_back(prev_row[j - 1] + prev_row[j]);
            }
            
            current_row.push_back(1);
            triangle.push_back(current_row);
        }
        
        return triangle;
    }
};