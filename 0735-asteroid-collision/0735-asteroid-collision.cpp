class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack <int> st;

        for(auto &i : asteroids){
            // whether incoming asteroid survives
            bool survive=true;

            while(!st.empty() && st.top() >0 && i<0 && survive){

                int sum=st.top()+i;
                
                 // st |  i
                // 15  10 -20
                // 15 -20
                if(sum<0){
                    st.pop();
                    //survive remains true since it crashed incoming 

                // 15 10 -10
                // 15    
                }else if(sum==0){
                    st.pop();
                    survive=false;

                // else sum >0
                // 15 10 5
                // survive is false since its destroyed by larger asteroid on right
                }else{
                    survive=false;
                }
            }


            if(i!=0 && survive) st.push(i);

        }

        int n=st.size();

        vector<int> res(n);

        int i=n-1;

        while(!st.empty()){

            res[i]=st.top();
            st.pop();
            i--;
        }   
        return res;


    }
};