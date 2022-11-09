
class StockSpanner {
    stack<pair<int, int>> stockSpanStack;
    int cntDay;
public:
    StockSpanner() {
        cntDay = 1;
    }

    int next(int price) {
        if (stockSpanStack.empty()) {
            stockSpanStack.push(make_pair(price, cntDay));
            cntDay++;
            return 1;
        } else {
            while (!stockSpanStack.empty() && stockSpanStack.top().first <= price) {
                stockSpanStack.pop();
            }
            if (!stockSpanStack.empty()) {
                int ans = cntDay - stockSpanStack.top().second;
                stockSpanStack.push(make_pair(price, cntDay));
                cntDay++;
                return ans;
            }
            int ans = cntDay;
            stockSpanStack.push(make_pair(price, cntDay));
            cntDay++;
            return ans;
        }
        return 1;
    }
};