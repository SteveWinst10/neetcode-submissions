class Solution {
public:
    static inline int timeToEat(const int pile, const int rate)
    {
        return (pile + rate - 1) / rate;
    }
    static inline int timeToEatAll(const std::vector<int>& piles, const int rate)
    {
        int time = 0;
        for (const int x:piles)
        {
            time+=timeToEat(x,rate);
        }
        return time;
    }

    static int minEatingSpeed(std::vector<int>& piles, int h) {
        //1 is the left bound
        //max of piles is the right bound
        //of the binary search that is k needs to be atleast 1 and atmost max of piles since anything more would  be a waste since you cant eat more than one pile
        int lK =1;
        int rK = *std::max_element(piles.begin(),piles.end());
        int midK ;
        while (lK <= rK)
        {
            midK = lK + (rK-lK)/2;
            int totalTime = timeToEatAll(piles,midK);
            if (totalTime > h) {
                lK = midK + 1;
            } else {
                rK = midK-1;
            }
        }
        return lK;
    }
};
