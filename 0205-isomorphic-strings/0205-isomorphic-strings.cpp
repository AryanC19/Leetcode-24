class Solution {
public:

bool isIsomorphic(string a, string b)
{
    unordered_map<char, char> mp1;
    unordered_map<char, bool> mp2;

    int n = a.size();
    int m = b.size();
    if (n != m)
        return false;

    for (int i = 0; i < n; i++)
    {

        char ch1 = a[i];
        char ch2 = b[i];
        if (mp1.find(ch1) != mp1.end())
        {
            if(mp1.at(ch1)!=ch2){
                return false;

            }
        }else{
            if(mp2.find(ch2)!=mp2.end()){
                return false;
            }else{
                mp1[ch1] = ch2;
                mp2[ch2] =true;

            }
        }
    }
    return true;
}
};