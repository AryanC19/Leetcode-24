class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_map<string, int> mpp;
        sort(begin(folder),end(folder));
        vector<string> ans;
        for (auto i : folder) {
            string temp = "";
            bool flag = true;
            int n = i.size();
            for (int j = 0; j < n; j++) {
                temp += i[j];
                if (mpp.find(temp) != mpp.end()) {

                    if (j < n - 1 && i[j + 1] == '/') {

                        flag = false;
                        break;
                    }
                }
            }

            if (flag) {
                mpp[i]++;
                ans.push_back(i);
            }
        }
        return ans;
    }
};