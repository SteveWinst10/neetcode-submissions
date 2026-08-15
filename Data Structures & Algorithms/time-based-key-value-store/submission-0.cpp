#include <string>
#include <unordered_map>
#include <vector>

class TimeMap {
public:
    TimeMap() {

    }
    std::vector<std::pair<std::string,int>> vec;
    std::unordered_map<std::string, std::vector<std::pair<std::string,int>>> map;
    void set(const std::string& key, const std::string& value, int timestamp) {
       map[key].emplace_back(value,timestamp);
    }

    std::string get(const std::string& key, const int timestamp) {
        auto it = map.find(key);
        if (it == map.end()) {
            return "";
        }
        const auto& vec = it->second;
        int l = 0, r = vec.size() - 1;
        std::string res = "";
        int mid;
        while (l<=r)
        {
            mid = l+(r-l)/2;
            if (timestamp < vec[mid].second)
            {
                r=mid-1;
            }
            else if (timestamp > vec[mid].second)
            {
                res = vec[mid].first;
                l=mid+1;
            }
            else
            {
                return vec[mid].first;
            }

        }
        return res;
    }
};
