class Solution:
  def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
    graph = [[] for _ in range(n)]
    minHeap = [(0, src, k + 1)]  # (dist, u, stops)
    minDist = [[math.inf] * (k + 2) for _ in range(n)]

    for u, v, price in flights:
      graph[u].append((v, price))

    while minHeap:
      dist, u, stops = heapq.heappop(minHeap)
      if u == dst:
        return dist
      if stops > 0:
        for v, w in graph[u]:
          newDist = dist + w
          if newDist < minDist[v][stops - 1]:
            minDist[v][stops - 1] = newDist
            heapq.heappush(minHeap, (newDist, v, stops - 1))

    return -1
