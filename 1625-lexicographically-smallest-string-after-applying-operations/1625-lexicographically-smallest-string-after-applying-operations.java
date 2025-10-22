class Solution {
    String ans;
    Set<String> visited = new HashSet<>();

    public void func(String s, int a, int b){
        if (visited.contains(s)) return;
        visited.add(s);

        if (s.compareTo(ans) < 0)
            ans = s;

        StringBuilder op1= new StringBuilder(s);
        for(int i=1;i<op1.length();i+=2){
            char ch=op1.charAt(i);
            int num= ch-'0';
            num= (num+a)%10;
            char newCh= (char)('0'+num);
            op1.setCharAt(i,newCh);
        }

        
        String rotated = s.substring(s.length() - b) + s.substring(0, s.length() - b);
        func(op1.toString(), a,b);
        func(rotated, a,b);
        return;
    }
    public String findLexSmallestString(String s, int a, int b) {
        StringBuilder sb=new StringBuilder(s);
        ans=s;
        func(s,a,b);
        return ans;

    }
}