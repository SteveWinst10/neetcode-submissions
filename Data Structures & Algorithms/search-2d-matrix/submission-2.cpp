class Solution {
public:
    static bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int l=0;
        int r=matrix.size()*matrix[0].size()-1;
        int mid = l + (r-l)/2;

        while (l<=r)
        {
            const int value = matrix[mid/matrix[0].size()][mid%matrix[0].size()];
            if (target < value) r = mid-1;
            else if (target > value) l=mid+1;
            else return true;
            mid = l + (r-l)/2;
        }
        return false;
    }
};