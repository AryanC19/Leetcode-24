class Solution {
public:
    /* BIT MANIPULATION LOT OF CONCEPTS IMP:
        given q:

        setBits=sb
        find x such that
        1.sbX=sb2
        x XOR num1=minimal

        cases:

        1. sb1>sb2:
        num1=010101 , sb1=3
        num2=   011 , sb2=2

        num1=010101
        x=      101
                -->
        start from l->r && set bits as 1 in x that are 1 in num1 till sbX=2.
                   (mostsignifaicatnt -> Least significatn)
        2.sb1==sb2
         return num1,
         as num1^num1==0 ehich is min and sb1==sbX, x=n1;



        3. sb1 < sb2:
           num1 =  011 (sb1 = 2)
           num2 = 10101 (sb2 = 3)

           Start from the least significant bit (LSB) and set bits in `x` that
    are currently unset, until the total number of set bits in `x` matches
    `sb2`.



    So we need to set and unset specific bits from a number
    Set Bit= turn a bit to 1
    Unset Bit=turn a bit to 0


    1.How to set a bit positon?
          543210
        x=010100

        suppose you want to set 0th bit.
          543210
        x=010100
          000001
       =  010101
          first left shift 1 by n positions, (0 in this case) ans OR x and
    leftShift1


        * how to left shift 1?
            ** IMP REMEMBER

            bit =no of times u want to leftShift
            (1<<bit)

            let y=1<<0.

            thus, x=010100
            y      =000001
            x||y   =010101
            thus 1st bit has been set.

            therefore to set nth bit in x, we have to perform OR
            operation on x and (1<<n)

            x with nth bit as SET(0->1):
            x= x || (1<<n)

        2. How to unset a bit postiont?
              543210
            x=010101

            lets unset 2nd bit. is

            first ,find the leftshift bit again,
             find y=1<<bit (2 in thsi case)

            now, to unset first perform x NOT y.



            perfomrm inverse(NOT) on y.
            y=000100
            y=~y
           ~y=111011

            now, perform AND & operationg between x& ~y
              543210
            x=010101
           ~y=111011
              010001
            the result is x with 2nd bit as unset.

            in summary to unset nth bit in x,
            1. find y=1<<n , y=1 leftshift by n.
            2. find ~y = inverse y
            3. res= x AND ~y

            x with nth bit UNSET (1->0)
            x= x & (~(1<<n))

        3. How to check if a bit is set or not
         (because we will only set unset bits or unset set bits)

          543210
        x=010101

        tell if 2nd bit is set or not.

        y=1<<n (n=2)

          543210
        x=010101
        y=000100
        &
        x&y=000100

        since x&y is not equal to zero this means that the nth bit WAS set.
        or else x&y would be 0.
        for ex, suppose 2nd bit was not set ie not 1

          543210
        x=010001
        y=000100
      x&y=000000.

      x&y==0. thus this is how we check if the nth bit is set or not.

      summary, to check if nth bit is set from x.

      res=x & (1<<n).
      if(res==0) nuset
      else set.

    */

    bool isSet(int& x, int& i) {
        // if its set, it returns 1 ie true
        // else it returns 0 ie false
        return x & (1 << i);
    }

    void setBit(int& x, int& i) {
        /*  43210
            01100
            set 1st bit.
            y=1<<1
            y=10
            x || y
            01100
            00010
      res   01110
        */

        // y=1<<i

        x = x | (1 << i);
    }

    void unSetBit(int& x, int& i) {

        // int y=1<<i;
        // y=~y;
        x = x & (~(1 << i));
    }
    int minimizeXor(int num1, int num2) {
        int x = num1;

        int reqSetBit = __builtin_popcount(num2);
        int currSetBit = __builtin_popcount(num1);

        // cases refer above
        int i = 0; // like a pointer, traverses from left to right

        // case1 :left to right and unset the setBits
        if (currSetBit < reqSetBit) {

            while (currSetBit < reqSetBit) {
                // if ith bit of x is notset
                if (!isSet(x, i)) {
                    // set ith bit of x
                    setBit(x, i);
                    currSetBit++;
                }
                i++;
            }
        } else if(currSetBit>reqSetBit){
            while(currSetBit>reqSetBit){

                if(isSet(x,i)){
                    unSetBit(x,i);
                    currSetBit--;
                }
                i++;
            }
        }

        return x;
    }
};