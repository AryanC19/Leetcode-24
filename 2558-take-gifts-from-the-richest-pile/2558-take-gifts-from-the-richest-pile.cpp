class Solution {
public:
    typedef long long ll;
    long long pickGifts(vector<int>& gifts, int k) {

        priority_queue<ll> q;

        for(auto i:gifts) q.push(i);


        while(k--){
            ll p=q.top();
            q.pop();
            q.push(floor(sqrt(p)) );
        }

        ll sum=0;

        while(!q.empty()){
            sum+=q.top();
            q.pop();
        }

        return sum;

    }
};