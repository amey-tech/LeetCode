class Solution:
  def minimumCost(self, n: int, highways: List[List[int]], discounts: int) -> int:
    graph = [[] for _ in range(n)]
    minHeap = [(0, 0, discounts)]  # (dist, u, d) (d := remaining discounts)
    minDiscounts = {}

    for city1, city2, toll in highways:
      graph[city1].append((city2, toll))
      graph[city2].append((city1, toll))

    while minHeap:
      dist, u, d = heapq.heappop(minHeap)
      if u == n - 1:
        return dist
      if u in minDiscounts and minDiscounts[u] >= d:
        continue
      minDiscounts[u] = d
      for v, w in graph[u]:
        heapq.heappush(minHeap, (dist + w, v, d))
        if d > 0:
          heapq.heappush(minHeap, (dist + w // 2, v, d - 1))

    return -1
