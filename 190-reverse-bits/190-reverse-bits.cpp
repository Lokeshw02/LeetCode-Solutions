class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if (n == 0) return 0;
        string str = bitset<32>(n).to_string();
        reverse(str.begin(), str.end());
        return bitset<32>(str).to_ullong();
    }
};