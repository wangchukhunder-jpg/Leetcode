class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())return true;
        string double_s=s+s;
        return double_s.find(goal)!=string::npos;
    }
};