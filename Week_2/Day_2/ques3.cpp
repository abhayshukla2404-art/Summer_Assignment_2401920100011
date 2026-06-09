class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int n = s.size(), m = p.size();

        if (m > n) return ans;

        vector<int> pCount(26, 0);
        vector<int> window(26, 0);

        for (char c : p)
            pCount[c - 'a']++;

        for (int i = 0; i < m; i++)
            window[s[i] - 'a']++;

        if (window == pCount)
            ans.push_back(0);

        for (int i = m; i < n; i++) {
            window[s[i] - 'a']++;        // add new char
            window[s[i - m] - 'a']--;    // remove old char

            if (window == pCount)
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};