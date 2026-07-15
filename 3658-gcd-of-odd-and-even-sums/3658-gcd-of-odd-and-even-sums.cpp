class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return gcd(n*(n+1),n*n);
    }
};