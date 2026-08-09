class Solution {
public:
    static std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::stack<int> monoStack;
        std::vector<int> result(temperatures.size(), 0);
        for (int i=0;i<temperatures.size();++i)
        {
                while (!monoStack.empty() && temperatures[i] > temperatures[monoStack.top()]) {
                    int prevIndex = monoStack.top();
                    monoStack.pop();
                    result[prevIndex] = i - prevIndex;
                }
                monoStack.push(i);
        }
        return result;
    }
};
