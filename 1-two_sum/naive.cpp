#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

std::vector<int> naive(std::vector<int> &nums, int target) {
    int n = nums.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return std::vector<int>{i, j};
            }
        }
    }

    return std::vector<int>{-1, -1};
}
