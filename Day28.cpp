/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.
 */
class Solution {
public:
    unordered_map<string, vector<string>> mp;
    
    vector<string> res;
    
    void dfs(string temp)
    {
        
        
       
        for(int i=0;i<mp[temp].size();++i)
        {
            
            string q=mp[temp][i];
           
            mp[temp].erase(mp[temp].begin()+i);
             i--;
            dfs(q);
            
        }
        res.push_back(temp);
        
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        
        for(int i=0;i<tickets.size();++i)
        {
            mp[tickets[i][0]].push_back(tickets[i][1]);
        }
        
      //  for(auto x=mp.begin();x!=mp.end();x++)
        //  sort(x->second.begin(),x->second.end());
            
        for(auto it=mp.begin(); it!=mp.end(); ++it)
        {
            sort(it->second.begin(), it->second.end());
        }
        
        dfs("JFK");
        
        reverse(res.begin(), res.end());
        
        return res;
        
    }
};
