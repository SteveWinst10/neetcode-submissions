class Solution {
public:
    static inline bool isOp(const std::string& s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
    static inline int evalExpr(const int a,const int b,const char& op)
    {
        switch(op)
        {
            case '+':
            return a+b;

            case '-':
            return a-b;

            case '*':
            return a*b;

            case '/':
            return a/b;
        }
        return -1;
    }
    static int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stack;
        for (const std::string& chr: tokens)
        {
            if (isOp(chr))
            {
                if (stack.empty()) return -1;
                int b = stack.top();stack.pop();
                if (stack.empty()) return -1;
                int a = stack.top();stack.pop();
                stack.push(evalExpr(a,b,chr[0]));
            }
            else
            {
                stack.push(std::stoi(chr));
            }
        }
        return stack.top();
    }
};
