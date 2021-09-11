class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1 || n == 0) return n == 1; 
        if (n%3 == 0) return isPowerOfThree(n / 3);
        return false;
    }
};