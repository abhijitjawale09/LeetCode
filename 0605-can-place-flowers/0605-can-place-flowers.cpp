class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int minplanted = 0;
        int i = 0;

        while (i < size) {
            if (flowerbed[i] == 1) {
                i++;
                continue;
            }
            int count = 0;
            while (i < size && flowerbed[i] == 0) {
                count++;
                i++;
            }
            if (i == count || i == size) {
                minplanted += count / 2;
            } 
            else {
                minplanted += (count - 1) / 2;
            }
        }

        return minplanted >= n;
    }
};
