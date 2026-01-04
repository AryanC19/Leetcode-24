class Solution {
    public int sumFourDivisors(int[] nums) {
        int sum = 0;

        for (int num : nums) {
            int cnt = 0;
            int divSum = 0;

            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    cnt++;
                    divSum += i;

                    if (i != num / i) {
                        cnt++;
                        divSum += num / i;
                    }

                    if (cnt > 4) break;
                }
            }

            if (cnt == 4) sum += divSum;
        }
        return sum;
    }
}
