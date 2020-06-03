/*
There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

 

Example 1:

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.

*/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int price=0;
        int n=costs.size();
      //  int a=0,b=0;
        
        
        sort(costs.begin(),costs.end(),[](vector<int>&v1, vector<int>&v2){  
            return (v1[1]-v1[0])>=(v2[1]-v2[0]); }
            );
            
            
            for(int i=0;i<n/2;++i)
                price+=costs[i][0];
        
        for(int i=n/2;i<n;++i)
            price+=costs[i][1];
        
        return price;
    }
};
