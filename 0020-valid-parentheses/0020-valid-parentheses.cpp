class Solution {
public:
   
bool isValid(std::string s) {
    std::stack<char> op;

    for (char i : s) {
        if (i == '(' || i == '[' || i == '{') {
            op.push(i);
        } else {
            if (op.empty()) {
                return false; // No matching opening bracket
            }

            if ((i == ')' && op.top() == '(') ||
                (i == ']' && op.top() == '[') ||
                (i == '}' && op.top() == '{')) {
                op.pop();
            } else {
                return false; // Mismatched closing bracket
            }
        }
    }

    return op.empty(); // Stack should be empty if all brackets are matched
}
};