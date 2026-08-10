class Solution {
   public:
     static int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        std::vector<std::pair<int,int>> posSpeed((position.size()));
        for (int i=0;i<position.size();++i)
        {
            posSpeed[i] = {position[i],speed[i]};
        }
        std::sort(posSpeed.rbegin(),posSpeed.rend());
        int fleetCount=0;
        double prevTime = 0;
        for (int i=0; i<position.size();++i)
        {
            double curTime = (double)(target - posSpeed[i].first)/posSpeed[i].second;
            if (curTime > prevTime)
            {
                ++fleetCount;
                prevTime = curTime;
            }
        }
        return fleetCount;
    }
};
