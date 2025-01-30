class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values;
        ListNode* temp = head;

        while (temp) {
            values.push_back(temp->val);
            temp = temp->next;
        }

        int n = values.size();
        vector<int> nge(n, 0);
        stack<int> st;

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && st.top() <= values[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? 0 : st.top();
            st.push(values[i]);
        }

        return nge;
    }
};
