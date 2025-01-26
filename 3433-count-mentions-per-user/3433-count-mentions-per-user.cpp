class Solution {
public:

/*         
          0                                                    1

  0            1               2                   0           1            2
["MESSAGE", "timestampi", "mentions_stringi"], ["OFFLINE", "timestampi", "idi"]
  "MESSAGE", "10",         "id1 id0"],          ["OFFLINE", "11"         ,"0"]

             i
*/
    static bool comp(vector<string> &a,vector<string>&b){
        return stoi(a[1])==stoi(b[1]) ? a[0]=="OFFLINE" : stoi(a[1])<stoi(b[1]);
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {

        sort(events.begin(),events.end(),comp);
        
        vector<int> mentions(numberOfUsers,0);
        
        //             id     isOnline
        unordered_map<string,bool> status;
        
        //        timestamp, id
        queue<pair<int,string>> offlineToOnline;
        
        
        for(int i=0;i<numberOfUsers;i++){
            status["id"+to_string(i)]=true;
        }


        for(auto &event:events){

            string type=event[0];
            int timestamp=stoi(event[1]);
            string users=event[2];
            
          //  cout<<type<<" " << users<< " " <<timestamp<<endl;
            
            while(!offlineToOnline.empty() && timestamp>=offlineToOnline.front().first){

             //   cout<<"currtimestamp:"<<timestamp<<" "<< "prevUserTimestamp:"<<offlineToOnline.front().first<<endl;
                auto prevUser=offlineToOnline.front();

                int backOnline=prevUser.first;
                string id=prevUser.second;
                offlineToOnline.pop();
                status[id]=true;
            }
            
            if(type=="MESSAGE"){


                if(users=="ALL"){
                    for(auto &id:status){
                        int num=stoi(id.first.substr(2));
                        mentions[num]++;
                    }
                
                }else if(users=="HERE"){
                    for(auto &id:status){
                        // **  WAS DOING int num=id.first[2]-'0'; WHICH DOESNT WORK FOR DOUBLE DIIGT
                        int num=stoi(id.first.substr(2));
                        if(id.second)
                            mentions[num]++;
                    }     
                    
                }else{ //id0,id1,... 
                    
                    vector<string> ids;
                    stringstream ss(users);
                    string token="";
                    while(getline(ss,token,' ')){
                        ids.push_back(token);
                    }
                    for(auto &id:ids){
                        int num=stoi(id.substr(2));
                        mentions[num]++;
                    }
                }              
            }else{// "OFFLINE"
               // cout<<"We in the offline"<<endl;
                string id="id"+users;
                
                status[id]=false;
                
                int backOnline=timestamp+60;
                offlineToOnline.push({backOnline,id});  
                
               // cout<<"backnONline: " << backOnline<< " "<< id <<endl;
                
            }
        }
        
        // for(auto i:mentions){
        //     cout<<i<<" ";
        // }
        cout<<endl;
        return mentions;
        
    }
};