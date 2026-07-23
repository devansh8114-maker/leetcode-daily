class Solution {
public:
    int firstUniqChar(string str) {
        
        unordered_map<char,int>map;

        for(char ch:str){
            map[ch]++;
        }

        for(int i=0;i<str.size();i++){
            if(map[str[i]]==1){
                return i;
            }
        }
        return -1;
    }
};