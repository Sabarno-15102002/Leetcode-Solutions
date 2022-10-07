class MyCalendarThree {
public:
    map<int,int> m;
    int mx;
    MyCalendarThree() {
        mx = 0;
    }
    
    int book(int s, int e) {
        m[s]++;
        m[e]--;
        int t=0;
        
        for(auto it:m)
        {
            if(it.first>=e)
                break;
            
            t+=it.second;
            mx=max(mx,t);
        }
                
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */