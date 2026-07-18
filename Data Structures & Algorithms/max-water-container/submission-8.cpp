class Solution {
public:
    int static area(std::vector<int>& height,int l,int r)
    {
        return std::min(height[l],height[r])*(r-l);
    }
    int static maxArea(std::vector<int>& height) {
        int maxArea = 0;
        int l =0;int r=height.size()-1;
        while (l<r)
        {
            int tempArea = area(height,l,r);
            if (tempArea > maxArea) maxArea = tempArea;
            if (height[l]<height[r])++l;
            else --r;
        }
        return maxArea;
    }
};
