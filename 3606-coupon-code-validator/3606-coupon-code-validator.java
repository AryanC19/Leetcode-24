class Solution {

    public List<String> validateCoupons(String[] code,
                                        String[] businessLine,
                                        boolean[] isActive) {

        List<String> validCoupons = new ArrayList<>();
        int n = code.length;

        // ❌ was wrong: this was built from input
        // ✅ should be allowed categories
        List<String> order = Arrays.asList(
            "electronics", "grocery", "pharmacy", "restaurant"
        );

        Set<String> businessLineSet = new HashSet<>(order);

        Map<String, Integer> priority = new HashMap<>();
        for (int i = 0; i < order.size(); i++) {
            priority.put(order.get(i), i);
        }

        // -------- validation --------
        for (int i = 0; i < n; i++) {

            if (!isActive[i]) continue;

            if (code[i].isEmpty()) continue;

            boolean valid = true;
            for (char c : code[i].toCharArray()) {
                if (!Character.isLetterOrDigit(c) && c != '_') {
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;

            if (!businessLineSet.contains(businessLine[i])) continue;

            // store index (keeping your structure)
            validCoupons.add(i + "");
        }

        // -------- SORT (comparator) --------
        validCoupons.sort((a, b) -> {
            int i = Integer.parseInt(a);
            int j = Integer.parseInt(b);

            int cmp = priority.get(businessLine[i]) - priority.get(businessLine[j]);
            if (cmp != 0) return cmp;

            return code[i].compareTo(code[j]);
        });

        // -------- build result --------
        List<String> result = new ArrayList<>();
        for (String idx : validCoupons) {
            result.add(code[Integer.parseInt(idx)]);
        }

        return result;
    }
}
