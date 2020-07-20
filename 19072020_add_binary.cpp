class Solution {
public:
    int getBit(string bin, int idx) {
        return bin[idx] == '0' ? 0 : 1;
    }
    string addBinary(string a, string b) {
        if (a == "0" || b == "0") return a == "0" ? b : a;
        auto carry = 0;
        auto bit = 0;
        auto sum = list<char>{};
        int lhs = size(a) - 1;
        int rhs = size(b) - 1;
        while (lhs >= 0 && rhs >= 0) {
            auto a_val = getBit(a, lhs);
            auto b_val = getBit(b, rhs);
            bit = a_val + b_val + carry;
            sum.push_front(bit % 2 == 0 ? '0' : '1');
            carry = bit > 1 ? 1 : 0;
            --lhs;
            --rhs;
        }
        while (lhs >= 0) {
            auto a_val = getBit(a, lhs);
            bit = a_val + carry;
            sum.push_front(bit % 2 == 0 ? '0' : '1');
            carry = bit > 1 ? 1 : 0;
            --lhs;
        }
        while (rhs >= 0) {
            auto b_val = getBit(b, rhs);
            bit = b_val + carry;
            sum.push_front(bit % 2 == 0 ? '0' : '1');
            carry = bit > 1 ? 1 : 0;
            --rhs;
        }
        if (carry) {
            sum.push_front('1');
        }
        auto result = string{};
        for (auto c : sum) {
            result.push_back(c);
        }
        return result;
    }
};
