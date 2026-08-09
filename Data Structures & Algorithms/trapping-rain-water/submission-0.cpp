    #include <print>
    #include <vector>

    class Solution {
    public:
        int static trap(std::vector<int>& height) {
            int maxArea = 0;
            int l=0; int r=height.size()-1;
            int lmax=0; int rmax =0;
            while (l<r)
            {
                if (height[l] < height[r])
                {
                    if (height[l] >= lmax)
                        lmax = height[l];
                    else
                        maxArea += lmax - height[l];
                    ++l;
                }
                else
                {
                    if (height[r] >= rmax)
                        rmax = height[r];
                    else
                        maxArea += rmax - height[r];
                    --r;
                }
            }
            return maxArea;

        }


    };