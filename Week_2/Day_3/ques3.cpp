class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        int n = s.size();
        int m = p.size();

        if (m > n) return result;

        vector<int> pCount(26, 0);
        vector<int> windowCount(26, 0);

        // Frequency of characters in p
        for (char c : p) {
            pCount[c - 'a']++;
        }

        for (int i = 0; i < n; i++) {
            // Add current character to window
            windowCount[s[i] - 'a']++;

            // Remove character that is out of window
            if (i >= m) {
                windowCount[s[i - m] - 'a']--;
            }

            // Compare frequencies
            if (windowCount == pCount) {
                result.push_back(i - m + 1);
            }
        }

        return result;
    }
};