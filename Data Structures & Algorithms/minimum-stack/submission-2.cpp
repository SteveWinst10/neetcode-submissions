class MinStack {
public:
    std::stack<int> stack;
    std::stack<int> min_stack;
   int min=std::pow(2,31)-1;
    MinStack() {

    }
    void push(int value) {
        stack.push(value);
        if (value < min) min = value;
        min_stack.push(min);
    }
    void pop() {
        stack.pop();
        min_stack.pop();
         if (min_stack.empty())min = std::pow(2,31)-1;
        else min = min_stack.top();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
