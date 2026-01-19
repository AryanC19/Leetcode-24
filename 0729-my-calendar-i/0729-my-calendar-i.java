class MyCalendar {
    // keeps keys in sorted order
    TreeSet<int[]> bookings;
    public MyCalendar() {
        bookings=new TreeSet<>((a,b)->{
            //custom comparator, sort by startTime, but if same then sort by endTime
            return a[0]!=b[0] ? Integer.compare(a[0],b[0]) :Integer.compare(a[1],b[1]);
        });
    }
    
    /* 
    intersection condition:
    a<e && s<b    
    a-----b             a-----b             a-------------b  
      s----e           s----e                   s----e 

    not intersecting
    a----b  
           s---e 
    
    */
    public boolean book(int startTime, int endTime) {

        int[] curr= new int[]{startTime,endTime};

        int[] next=bookings.ceiling(curr);

        if(next!=null && next[0] <endTime &&  startTime < next[1]) return false;

        int[] prev=bookings.floor(curr);

        if(prev!=null && prev[0] <endTime &&  startTime < prev[1]) return false;

        bookings.add(new int[]{startTime,endTime});
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(startTime,endTime);
 */