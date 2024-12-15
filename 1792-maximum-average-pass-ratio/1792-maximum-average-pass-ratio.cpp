class Solution {
public:

    double calculateDelta(int pass,int total){

        return double(pass+1)/double(total+1) - double(pass)/total;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        


        //maxheap         //delta       //pass,total
        priority_queue<pair<double, pair<double,double>> > pq;

        for(int i=0;i<classes.size();i++){
            double pass=classes[i][0];
            double total=classes[i][1];
            pq.push( {calculateDelta(pass,total) ,{pass,total}} );
        }

        while(extraStudents--){
            auto topElement=pq.top();
            pq.pop();
            int pass=topElement.second.first;
            int total=topElement.second.second;
            pq.push({calculateDelta(pass+1,total+1) ,{pass+1,total+1}});
        }



        double sum=0;

        while(!pq.empty()){
            auto topElement=pq.top();
            pq.pop();
            int pass=topElement.second.first;
            int total=topElement.second.second;
            sum+= double(pass)/double(total); 
        }
        return sum/double(classes.size());

    }
};