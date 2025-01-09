class MyCalendar {
private:
    map<int, int> booktime;
public:
    MyCalendar() {}
    
    bool book(int startTime, int endTime) {
        map<int, int>::iterator it = booktime.upper_bound(startTime);
        if(it != booktime.end() && it->second < endTime)
            return false;
        booktime[endTime] = startTime;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
