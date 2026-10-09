class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack <int> st;
        vector<pair<int,int>> cars;
        int n = position.size();
        for(int i = 0; i < n; i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(), cars.end(),greater<pair<int,int>>());
        int ans = 1;
        st.push(0);
        for(int i = 1; i < n; i++){
            double test = (double)(target - cars[st.top()].first) / cars[st.top()].second;
            double tmp = (double)(target - cars[i].first) / cars[i].second;
            if(test < tmp){
                ans++;
                st.push(i);
            }
        }
        return ans;
    }
};
