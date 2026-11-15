/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
    vector<pair<int,int>>meet;
    int n11=intervals.size();
    for(int i=0;i<n11;i++){
        meet.push_back({intervals[i].start,intervals[i].end});
    }
    sort(meet.begin(),meet.end());
    priority_queue<int,vector<int>,greater<int>>pq;
    int ans=0;
    for(int i=0;i<n11;i++){
        if(!pq.empty()&& pq.top()<=meet[i].first){
            pq.pop();
        }
        pq.push(meet[i].second);
        ans=max(ans,(int)pq.size());
    }
    return ans;
    }
};
