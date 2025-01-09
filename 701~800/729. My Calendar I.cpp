class MyCalendar {
private:
    vector<pair<int, int> > booktime;
public:
    MyCalendar() {}
    
    bool book(int startTime, int endTime) {
        for(pair<int, int> &i : booktime){
            if(i.first < endTime && i.second > startTime)
                return false;
        }
        booktime.emplace_back(make_pair(startTime, endTime));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
