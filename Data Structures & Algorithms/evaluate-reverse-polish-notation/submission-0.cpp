class Solution {
public:
    static inline bool isOp(const std::string& x)
    {
        return x == "+" || x == "-" || x == "*" || x == "/";
    }
    static inline int evalExpr(const int a,const int b,const std::string& op)
    {
        if ( op == "+")
            return a + b;
        if ( op == "-")
            return a - b;
        if ( op == "*")
            return a * b;
        if (op == "/")
            return a / b;

        return -1;
    }
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stack;
        for (const std::string& chr: tokens)
        {
            if (isOp(chr))
            {
                if (stack.empty()) return -1;
                int b = stack.top();stack.pop();
                if (stack.empty()) return -1;
                int a = stack.top();stack.pop();
                stack.push(evalExpr(a,b,chr));
            }
            else
            {
                stack.push(std::stoi(chr));
            }
        }
        return stack.top();
    }
};
