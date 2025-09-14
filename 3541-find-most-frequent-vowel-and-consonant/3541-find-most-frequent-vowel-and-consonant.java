class Solution {
    public int maxFreqSum(String s) {
        int ans=0;

        HashSet<Character> vowSet=new HashSet<>(Arrays.asList('a','e','i','o','u'));

        int maxConst=0;
        int maxVow=0;
        HashMap<Character,Integer> freqMap=new HashMap<>();

        for(char c:s.toCharArray()){
            freqMap.put(c,1+freqMap.getOrDefault(c,0));
            int freqChar=freqMap.get(c);
            if(vowSet.contains(c)){
                maxVow=Math.max(maxVow,freqChar);
            }else{
                maxConst=Math.max(maxConst,freqChar);
            }
        }
        return maxConst+maxVow;
    }
}