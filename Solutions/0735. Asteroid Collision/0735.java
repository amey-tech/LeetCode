class Solution {
  public int[] asteroidCollision(int[] asteroids) {
    Stack<Integer> stack = new Stack<>();

    for (final int a : asteroids)
      if (a > 0) {
        stack.push(a);
      } else { // a < 0
        // destroy previous positive one(s)
        while (!stack.isEmpty() && stack.peek() > 0 && stack.peek() < -a)
          stack.pop();
        if (stack.isEmpty() || stack.peek() < 0)
          stack.push(a);
        else if (stack.peek() == -a)
          stack.pop(); // both explode
        else           // stack.back() > current
          ;            // destroy current, so do nothing
      }

    int[] ans = new int[stack.size()];
    for (int i = ans.length - 1; i >= 0; --i)
      ans[i] = stack.pop();

    return ans;
  }
}
