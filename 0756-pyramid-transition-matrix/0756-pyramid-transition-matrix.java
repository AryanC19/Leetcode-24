class Solution {

    public boolean func(int i, String curr,HashMap<String, List<Character>> allowedMap, StringBuilder nextSb){
        if(curr.length()==1) return true;
        if(i==curr.length()-1) return func(0,nextSb.toString(),allowedMap, new StringBuilder());
        

        String prefix="" + curr.charAt(i)+curr.charAt(i+1);
        
        if(allowedMap.containsKey(prefix)==false) return false;
        
        for(char c:allowedMap.get(prefix)){
            nextSb.append(c);
            if(func(i+1,curr, allowedMap,nextSb)==true) return true;
            nextSb.deleteCharAt(nextSb.length() - 1);
        }
    
        return false;
    }

    public boolean pyramidTransition(String bottom, List<String> allowed) {
        HashMap<String, List<Character>> allowedMap=new HashMap<>();
        int n=allowed.size();

         
        for(String str:allowed){
            char first= str.charAt(0);
            char second=str.charAt(1);
            String key = ""+first+second;
            List<Character> charList= allowedMap.getOrDefault(key, new ArrayList<>());
            charList.add(str.charAt(2));
            allowedMap.put(key, charList);
        }
        return func(0,bottom, allowedMap,new StringBuilder());

    }
}