vector<vector<string> > Anagrams(vector<string>& string_list) {
        
        
        unordered_map<string,vector<string>> mp;
        
        for(int i=0;i<string_list.size();i++)
        {
            string s=string_list[i];
            
            sort(s.begin(),s.end());  // sare elements of string sort hogye
            
            mp[s].push_back(string_list[i]); // sare sorted elments ko map kr krdiya
        }
        
         vector<vector<string>> ans;
         
         for(auto i:mp)  // traverse in map
         {
            ans.push_back(i.second); 
         }
         
         return ans;
        
        
    }