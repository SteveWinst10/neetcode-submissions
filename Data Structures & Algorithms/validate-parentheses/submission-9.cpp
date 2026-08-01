class Solution {
public:
    inline static bool isOpen(char chr)
    {
        return chr == '(' || chr == '[' || chr == '{';
    }

    inline static bool isClose(char chr)
    {
        return chr == ')' || chr == ']' || chr == '}';
    }
    inline static char oppPara(char chr)
    {
        switch (chr)
        {
        case '(':
            return ')';
        case ')':
            return '(';
        case '{':
            return '}';
        case '}':
            return '{';
        case '[':
            return ']';
        case ']':
            return '[';    
        }
    }
    bool isValid(std::string s) {
        if(s.size() == 1) [[unlikely]]
        {
            return false;
        }
        int count = 0;
        std::stack<char> paran;
        bool isValid = true;
        for (char chr:s)
        {
            if (isClose(chr))
            {
                if (count == 0) {isValid =false; break;}
                if (paran.top() == oppPara(chr))
                {
                    paran.pop();
                    --count;
                }
                else
                {
                    isValid = false; break;
                }
                
            }
            else
            {
                paran.push(chr);
                ++count;
            }
            }
        return isValid && paran.empty();
    }
};
