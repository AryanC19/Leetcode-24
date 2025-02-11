class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        string slots = "0123456789";
        unordered_set<string> deadend(deadends.begin(), deadends.end());
        string str = "0000";

        if(deadend.count(str)) return -1;

        queue<string> q;

        unordered_set<string> vis;
        vis.insert(str);

        q.push(str);
        int turns = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                string cur = q.front();
                q.pop();

                if (cur == target) {
                    return turns;
                }

                // inc
                for (int i = 0; i < cur.size(); i++) {
                    char num = cur[i];
                    string temp = cur;
                    char inc = num == '9' ? '0' : num + 1;
                    char dec = num == '0' ? '9' : num - 1;

                    temp[i] = inc;
                    if (!deadend.count(temp) && !vis.count(temp)) {
                        q.push(temp);
                        vis.insert(temp);
                    }
                    temp[i] = dec;
                    if (!deadend.count(temp) && !vis.count(temp)) {
                        q.push(temp);
                        vis.insert(temp);
                    }
                }
            }
            turns++;
        }

        return -1;
    }
};