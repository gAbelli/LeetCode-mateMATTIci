#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

std::vector<int> hash(std::vector<int> &nums, int target) {
    int n = nums.size();
    std::unordered_map<int, int> pos;

    for (int i = 0; i < n; i++) {
        int diff = target - nums[i];
        if (pos.find(diff) != pos.end()) {
            return std::vector<int>{pos[diff], i};
        }
        pos[nums[i]] = i;
    }

    return std::vector<int>{-1, -1};
}
