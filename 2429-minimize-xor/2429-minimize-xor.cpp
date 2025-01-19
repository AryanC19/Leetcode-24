class Solution {
public:

    bool isSet(int &x,int &i){
        return x & (1<<i);
    }
    
    void setBit(int &x,int &i){
        x = x | (1<<i);
    }

    void unSetBit(int &x,int &i){
        x = x & (~(1<<i));
    }

    int minimizeXor(int num1, int num2) {
        
        int currSb=__builtin_popcount(num1);
        int reqSb=__builtin_popcount(num2);

        int x=num1;
        int i=0;

        /*

        currSb<reqSb

         210
         011   
x=       111 


         1101 -> reqSb=3

        currSb>reqSb
             3>2
             
        3210 
        1101
x=      1101
           i 


        110-> reqSb=2
        */
        if(currSb<reqSb){
            while(currSb<reqSb){
                if(!isSet(x,i)){
                    setBit(x,i);
                    currSb++;
                }
                i++;
            }
        }else{
            while(currSb>reqSb){
                if(isSet(x,i)){
                    unSetBit(x,i);
                    currSb--;
                }
                i++;
            }
        }

        return x;
    }
};