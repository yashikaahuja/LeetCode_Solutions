3) Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int len = str.length();
        int start = 0, end = 0, currLen = 0, longest = 0;
        char currElement;
        unordered_set<char> elementset;
        while(end < len)
        {
            while(end != len && elementset.find(str[end]) == elementset.end())
            {
                elementset.insert(str[end]);
                currLen++;
                end++;
            }
            longest = max(longest, currLen);
            if(end == len) break;
            currElement = str[end];
            while(str[start] != currElement)
            {
                elementset.erase(str[start]);
                currLen--;
                start++;
            }
            if(str[start] == currElement && start != end)
            {
                elementset.erase(str[start]);
                currLen--;
                start++;
            }
        }
        return longest;
    }
};
