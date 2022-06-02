
class PriceBeauty {
public:
    int price;
    int beauty;
    int maxBeauty;

    PriceBeauty(int p_price, int p_beauty) {
        this->price = p_price;
        this->beauty = p_beauty;
    }
};
class Solution {
public:
    static bool itemComparator(const PriceBeauty &i1, const PriceBeauty &i2) {
        return i1.price < i2.price;
    }

    int getMaxClosestPriceIndex(vector<PriceBeauty> &itemArr, int maxPrice) {
        int start = 0;
        int end = (int) itemArr.size() - 1;
        int ans = -1;
        while (start <= end) {
            int mid = start + ((end - start) / 2);
            if (itemArr[mid].price <= maxPrice) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }

    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
        vector<PriceBeauty> itemArray;
        for (vector<int> tmpItem : items) {
            PriceBeauty newItem(tmpItem[0], tmpItem[1]);
            itemArray.push_back(newItem);
        }
        sort(itemArray.begin(), itemArray.end(), itemComparator);
        int maxBeautyVal = INT_MIN;
        for (PriceBeauty& tmpItem : itemArray) {
            maxBeautyVal = max(maxBeautyVal, tmpItem.beauty);
            tmpItem.maxBeauty = maxBeautyVal;
        }
        vector<int> ans;
        for (int query : queries) {
            int index = getMaxClosestPriceIndex(itemArray, query);
            if(index == -1) {
                ans.push_back(0);
                continue;
            }
            ans.push_back(itemArray[index].maxBeauty);
        }
        return ans;
    }
};