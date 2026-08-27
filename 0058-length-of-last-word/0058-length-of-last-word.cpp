class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int right = s.length()-1;
        int l = 0;

        while(right >= 0 && s[right] == ' ')
            right--;

        if(right == -1)
            return 0;

        while(right>=0 && s[right] != ' ')
        {
            l++;
            right--;
        }

        return l;
    }
};