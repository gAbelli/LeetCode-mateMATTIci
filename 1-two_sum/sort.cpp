#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

std::vector<int> sort(std::vector<int> &nums, int target) {
    int n = nums.size();
    std::vector<int> indices(n);
    std::iota(indices.begin(), indices.end(), 0);
    std::sort(indices.begin(), indices.end(),
              [&](int x, int y) { return nums[x] < nums[y]; });

    int i = 0;
    int j = n - 1;
    while (true) {
        int sum = nums[indices[i]] + nums[indices[j]];
        if (sum == target) {
            return std::vector<int>{indices[i], indices[j]};
        }
        if (sum < target) {
            i++;
        } else {
            j--;
        }
    }

    return std::vector<int>{-1, -1};
}
