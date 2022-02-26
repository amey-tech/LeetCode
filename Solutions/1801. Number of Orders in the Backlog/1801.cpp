class Solution {
 public:
  int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
    constexpr int kMod = 1e9 + 7;
    int ans = 0;
    priority_queue<vector<int>> buysMaxHeap;
    priority_queue<vector<int>, vector<vector<int>>, greater<>> sellsMinHeap;

    for (const auto& order : orders) {
      if (order[2] == 0)
        buysMaxHeap.push(order);
      else
        sellsMinHeap.push(order);
      while (!buysMaxHeap.empty() && !sellsMinHeap.empty() &&
             buysMaxHeap.top()[0] >= sellsMinHeap.top()[0]) {
        const int minAmount = min(buysMaxHeap.top()[1], sellsMinHeap.top()[1]);
        vector<int> buysMaxHeapTop = buysMaxHeap.top();
        buysMaxHeap.pop();
        buysMaxHeapTop[1] -= minAmount;
        if (buysMaxHeapTop[1] > 0)
          buysMaxHeap.push(buysMaxHeapTop);

        vector<int> sellsMinHeapTop = sellsMinHeap.top();
        sellsMinHeap.pop();
        sellsMinHeapTop[1] -= minAmount;
        if (sellsMinHeapTop[1] > 0)
          sellsMinHeap.push(sellsMinHeapTop);
      }
    }

    while (!buysMaxHeap.empty())
      ans = (ans + buysMaxHeap.top()[1]) % kMod, buysMaxHeap.pop();

    while (!sellsMinHeap.empty())
      ans = (ans + sellsMinHeap.top()[1]) % kMod, sellsMinHeap.pop();

    return ans;
  }
};
