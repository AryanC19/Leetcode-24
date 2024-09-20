class Solution {
public:
    typedef pair<int,char> P;
    string reorganizeString(string s) {
        int n=s.size();

        vector<int> count(26,0);

        for(auto &c:s){
            count[c-'a']++;
            if(count[c-'a']> (n+1)/2) return "";
        }

        priority_queue<P,vector<P>> pq;


        for(char ch='a';ch<='z';ch++){

            if(count[ch-'a']>0){
                pq.push({count[ch-'a'],ch});
            }
        }

        string res="";
        while(pq.size()>=2){
            auto p1=pq.top();
            pq.pop();
            auto p2=pq.top();
            pq.pop();  

            res+=p1.second; p1.first--;
            res+=p2.second;p2.first--;

            if(p1.first >0) pq.push(p1);
            if(p2.first >0) pq.push(p2);
        }

        if(!pq.empty()) res+=pq.top().second;

        return res;


    }
};