class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& sT, vector<int>& eT) {
        
        int n=sT.size();
        //          m/g  duration
        vector<pair<char,int> > events;

        if(sT[0]>0){
            events.push_back({'g',sT[0]});
        }

        for(int i=0;i<n;i++){
            if(i>0){
                //          currStrTime-endTimeLastMeet
                int gapSize=sT[i]-eT[i-1];
                if(gapSize>0)
                    events.push_back({'g',gapSize});
            }
            int meetSize= eT[i]-sT[i];
            events.push_back({'m',meetSize});
        }
        

        if(eT[n-1]<eventTime){
            events.push_back({'g',eventTime-eT[n-1]});
        }

        int l=0,r=0;

        int N=events.size();

        int maxGap=0;
        int gapSize=0,meets=0;
        int maxMeets=k;
        
        while(r<N){
            auto event=events[r];
            int type=event.first;
            int duration=event.second;

            type=='g' ? gapSize+=duration: meets++;

            while(l<r && meets>maxMeets){
                auto lastEvent=events[l];
                int lastType=lastEvent.first;
                int lastDuration=lastEvent.second;
                lastType=='g' ? gapSize-=lastDuration : meets--;
                l++;
            }

            maxGap=max(maxGap,gapSize);
            r++;
        }
        return maxGap;
    }
};