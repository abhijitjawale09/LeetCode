class Solution {
public:
    string multiply(string num1, string num2) {
        long long n = stoi(num1);
        long long m = stoi(num2);

        long long prod  =  (n * m);

        return  to_string(prod);
    }
};