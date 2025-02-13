class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int ops=0;
        priority_queue<long long,vector<long long> , greater<long long>  > pq;
        bool flag=true;

        for(auto &i:nums){
            if(i<k) flag=false;
            pq.push(i);
        }

        if(flag) return 0;
        
        while(pq.size()>=2){
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            long long i= min(a,b)*2 +max(a,b);
            pq.push(i);
            ops++;
            if(pq.top() >=k ){cout<<pq.top()<<endl; return ops;}
        }
        return -1;
    }
};