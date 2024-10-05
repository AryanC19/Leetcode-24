class Solution {
public:
    typedef long long ll;
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        int l=0,r=n-1;
        sort(begin(skill),end(skill));

        ll sum=skill[0]+skill[n-1];
        if(skill.size()==2) return skill[0]*skill[n-1];

        l++;r--;

        vector<pair<int,int>> teams;
        teams.push_back({skill[0],skill[n-1]});

        while(l<r){

            int csum=skill[l]+skill[r];
            if(sum!=csum) return -1;
            else{
                teams.push_back({skill[l], skill[r]});
            }
            l++;
            r--;
        }


        ll product=0;

        for(auto i:teams){
            product+= i.first*i.second;
        }

        return product;

    }
};