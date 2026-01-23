class Solution {
    public String reverseWords(String s) {
        List<String> words= new ArrayList<>();

        int n=s.length();
        int i=0;

        while(i<n){
            StringBuilder sb=new StringBuilder();
            while(i<n && s.charAt(i)!=' '){
                sb.append(s.charAt(i));
                i++;
            }
            if(!sb.isEmpty()) words.add(sb.toString());
            if(i< n && s.charAt(i)==' ') i++;
        }

        StringBuilder sb=new StringBuilder();
        for(int j=words.size()-1;j>=0;j--){
            sb.append(words.get(j));
            if(j!=0) sb.append(" ");
        }
        return sb.toString();
    }
}