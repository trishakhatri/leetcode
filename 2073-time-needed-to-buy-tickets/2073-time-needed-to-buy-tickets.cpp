class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int index =0;
        queue<int> q;
        for(int i =0; i<tickets.size(); i++){
            q.push(i);
        }
        int t=0;
        while(!q.empty()){
            int person = q.front();
            q.pop();
            tickets[person]--;
            t++;
            if(person == k && tickets[person] == 0){
                return t;
            }
            if(tickets[person]> 0){
                q.push(person);
            }
        }
        return t;
    }
};