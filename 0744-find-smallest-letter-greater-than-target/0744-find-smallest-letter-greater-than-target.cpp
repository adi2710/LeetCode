class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = -1, r = letters.size() - 1;
        while(r - l > 1)
        {
            int mid = l + (r - l) / 2;
            if(letters[mid] > target)
                r = mid;
            else
                l = mid;
        }
        if(letters[r] > target)
            return letters[r];
        return letters[0];
    }
};