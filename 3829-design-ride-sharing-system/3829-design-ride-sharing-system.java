class RideSharingSystem {

    Queue<Integer> riderQueue=new LinkedList<>();
    Queue<Integer> driverQueue=new LinkedList<>();
    
    HashMap<Integer,Integer> riderToDriverMap= new HashMap<>();

    public RideSharingSystem() {
        
    }
    
    public void addRider(int riderId) {
        riderQueue.offer(riderId);
    }
    
    public void addDriver(int driverId) {
        driverQueue.offer(driverId);      
    }
    
    public int[] matchDriverWithRider() {
        
        int[] match = {-1, -1};
        if(driverQueue.isEmpty() || riderQueue.isEmpty()) return match;
        int driverId=driverQueue.peek();
        int riderId=riderQueue.peek();
        driverQueue.poll();
        riderQueue.poll();
        match[1]=riderId;
        match[0]=driverId;
        riderToDriverMap.put(riderId,driverId);
        return match;
    }
    
    public void cancelRider(int riderId) {
        if(!riderToDriverMap.containsKey(riderId)){
            Queue<Integer> temp=new LinkedList<>();
            while(!riderQueue.isEmpty()){
                int waitingRiderId=riderQueue.peek();
                riderQueue.poll();
                if(waitingRiderId!=riderId) temp.offer(waitingRiderId);
            }
            while(!temp.isEmpty()){
                riderQueue.offer(temp.peek());
                temp.poll();
            }
        }
    }
}

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem obj = new RideSharingSystem();
 * obj.addRider(riderId);
 * obj.addDriver(driverId);
 * int[] param_3 = obj.matchDriverWithRider();
 * obj.cancelRider(riderId);
 */