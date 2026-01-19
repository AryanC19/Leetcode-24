class Solution {
    public int leastInterval(char[] tasks, int n) {

        //freqMap    
        int[] freq = new int[26];
        
        for (char c : tasks) freq[c - 'A']++;

        // here in PQ, Integer = Frequency only and no mapping with char. why?
        // here , we only need the freq in PQ because REGASRDLESS of the tasks , the time will be saem whter
        // A :3 B:2 OR A:2 , B:3.
        // So we will only need chars if they ask us to return the sequence. 

                                                        // comparator 4 max heap
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> b - a);
        // push freq to pq so maxFreq on top
        for (int f : freq) {
            if (f > 0) pq.offer(f);
        }

        // total time passed, 1s == 1 task or interval . thus time= min config of tasks + intevals 
        int time = 0;


        while (!pq.isEmpty()) {
            //temp list to store processed tassks that have been popped out of queue till cooldown
            List<Integer> temp = new ArrayList<>();
            
            
            // n+1 because for a task to be put back in the CPU, can come at n(gap)+1 postion
            //                                                0 1 2 n+1
            // if task=A, then and n=2, A can come back after A _ _  A . cant have A at 1 or 2. 
            int cooldown = n + 1;

            // VV IMP :
            //keep exec tasks while I have slots & tasks.
            while (cooldown > 0 && !pq.isEmpty()) {
              
                int currTaskFreq = pq.poll();
                currTaskFreq--; // execute task
                 
                if (currTaskFreq > 0) temp.add(currTaskFreq); 
                /*  if currTaskFreq >0, then we've added 1 task to CPU 
                    and rest of the tasks go in temp to wait till 
                    cooldown expires
               */

                // since we've done 1 task, we add 1s to the time. 
                time++;

                //since we've moved past 1 task, the cycle (cooldown period) 
                // of the same next element coming reduced
                cooldown--;
            }
            // after the while loop for cooldown ends, whatever was in the temp arrr
            // can be added back to pq
            for (int t : temp) pq.offer(t);
            

            // if after the cooldown is over, the pq is not empty
            // AND the cooldown !=0 , then this means that even though theres CPU slots to execute tasjs,
            // because cooldown is their it has to stay as empty interval . thus add it to the total time

            if (!pq.isEmpty()) {
                time += cooldown;   // idle slots
            }
        }

        return time;
    }
}
