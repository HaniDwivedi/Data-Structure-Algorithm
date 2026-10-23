class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       int cnt =0;
 int size = flowerbed.size();
         if (size > 0 && flowerbed[0] == 0) {
            if (size == 1 || flowerbed[1] == 0) {
                cnt++;
                flowerbed[0] = 1;
            }
        }
       for (int i = 1; i < size - 1; i++) {
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                cnt++;
                flowerbed[i] = 1; // Mark as planted so neighbors won't overlap
            }
        }
   if (size > 1 && flowerbed[size - 1] == 0 && flowerbed[size - 2] == 0) {
            cnt++;
            flowerbed[size - 1] = 1;
        }
        
        return cnt >= n;
    }
};