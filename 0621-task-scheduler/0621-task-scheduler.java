class Solution {
    public int leastInterval(char[] tasks, int n) {
        PriorityQueue<Integer> pq=new PriorityQueue<>((a,b)-> b-a);

        Map<Character , Integer> freq=new HashMap<>();

        for(char c:tasks) freq.put(c, freq.getOrDefault(c,0)+1);
        for(Map.Entry<Character,Integer> e: freq.entrySet()) pq.add(e.getValue());

        int time=0;

        while(!pq.isEmpty()){

            int cooldown=n+1;
            List<Integer> temp=new ArrayList<>();

            while(cooldown> 0 &&  !pq.isEmpty()){
                int task=pq.peek();
                pq.poll();
                time++;
                task--;
                cooldown--;
                if(task>0) temp.add(task);
            }

            for(int task:temp) pq.offer(task);

            if(!pq.isEmpty()) time+=cooldown;
        } 
        return time;
    }
}