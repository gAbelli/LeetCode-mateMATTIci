#include <iostream>

class Solution {
  public:
    int pos[128];

    int lengthOfLongestSubstring(std::string s) {
        std::fill(pos, pos + 128, -1);

        int n = s.size();
        int left = 0;
        int right = 0;
        int max_len = 0;

        for (; right < n; ++right) {
            if (pos[s[right]] != -1) {
                for (int i = left; i < pos[s[right]]; ++i) {
                    pos[s[i]] = -1;
                }
                left = pos[s[right]] + 1;
            }

            pos[s[right]] = right;
            max_len = std::max(max_len, right - left + 1);
        }

        return max_len;
    }
};
