class Solution {
public:
    int x1 = 0x5555 | (0x5555 << 16);
    int x2 = 0x3333 | (0x3333 << 16);
    int x3 = 0x0f0f | (0x0f0f << 16);
    int x4 = 0x00ff | (0x00ff << 16);
    int x5 = 0xffff;
    int cnt(int num) {
        num = (num & x1) + ((num >> 1) & x1);
        num = (num & x2) + ((num >> 2) & x2);
        num = (num & x3) + ((num >> 4) & x3);
        num = (num & x4) + ((num >> 8) & x4);
        num = (num & x5) + ((num >> 16) & x5);
        return num;
    }
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        for (int i = 0; i < num + 1; ++i)
            res[i] = cnt(i);
        return res;
    }
};
