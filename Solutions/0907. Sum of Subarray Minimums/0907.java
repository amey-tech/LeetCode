class Solution {
  public int sumSubarrayMins(int[] arr) {
    final int kMod = (int) 1e9 + 7;
    final int n = arr.length;
    long ans = 0;
    int[] prev = new int[n];
    int[] next = new int[n];
    Stack<Integer> stack = new Stack<>();

    Arrays.fill(prev, -1);
    Arrays.fill(next, n);

    for (int i = 0; i < arr.length; ++i) {
      while (!stack.isEmpty() && arr[stack.peek()] > arr[i]) {
        final int index = stack.pop();
        next[index] = i;
      }
      if (!stack.isEmpty())
        prev[i] = stack.peek();
      stack.add(i);
    }

    for (int i = 0; i < arr.length; ++i)
      ans = (ans + (long) arr[i] * (i - prev[i]) * (next[i] - i)) % kMod;

    return (int) ans;
  }
}
