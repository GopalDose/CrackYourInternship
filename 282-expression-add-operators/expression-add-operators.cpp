class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string path;
        helper(num, target, ans, path, 0, 0, 0);
        return ans;
    }

    void helper(string num, int target, vector<string>& ans, string path, int index, long curr, long prev) {
        if (index == num.size()) {
            if (curr == target) {
                ans.push_back(path);
            }
            return;
        }

        for (int i = index; i < num.size(); ++i) {
            if (i != index && num[index] == '0') break;

            string part = num.substr(index, i - index + 1);
            long currentNum = stol(part);

            if (index == 0) {
                helper(num, target, ans, path + part, i + 1, currentNum, currentNum);
            } else {
                helper(num, target, ans, path + "+" + part, i + 1, curr + currentNum, currentNum);

                helper(num, target, ans, path + "-" + part, i + 1, curr - currentNum, -currentNum);

                helper(num, target, ans, path + "*" + part, i + 1, curr - prev + prev * currentNum, prev * currentNum);
            }
        }
    }
};
