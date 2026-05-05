class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

     // sort both wrt to position
     stack<double>s;
     int n = speed.size();
     vector<pair<int,int>>vec;

     for(int i=0;i<n;i++)
     {
        vec.push_back({position[i], speed[i]});
     }

     sort(begin(vec),end(vec));

     for(int i=n-1;i>=0;i--)
     {
        double t = ((target-vec[i].first)/(1.0*vec[i].second));
        //cout<<"time "<<t<<endl;
        if(s.size()>0 and s.top()>=t) continue;
        s.push(t);
     }

     return s.size();
     
     

    }
};
