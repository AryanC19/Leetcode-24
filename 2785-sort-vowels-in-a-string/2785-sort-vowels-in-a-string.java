class Solution {
    public String sortVowels(String s) {
        
        StringBuilder sb= new StringBuilder();
        int n=s.length();
        HashSet<Character> vowelSet=new HashSet<>(Arrays.asList('u','o','i','e','a','U','O','I','E','A'));
        List<Character> vowList=new ArrayList<>();
        for(int i=0;i<n;i++){
            if(!vowelSet.contains(s.charAt(i))){
                sb.append(s.charAt(i));
            }else{
                vowList.add(s.charAt(i));
                sb.append('$');
            }
        }
        Collections.sort(vowList);
        int j=0;

        for(int i=0;i<n;i++){
            if(sb.charAt(i)=='$'){
                sb.setCharAt(i, vowList.get(j));
                j++;
            }
        }

        return sb.toString();
    }
}