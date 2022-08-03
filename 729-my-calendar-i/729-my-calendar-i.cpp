
class MyCalendar {
//  <endTime,startTime>
    map<int, int> calendarMap;
    int cntCount;
public:
    MyCalendar() {
        cntCount = 0;
    }

    bool book(int start, int end) {
//      Finding first end time greater than given start time
        auto itr = calendarMap.upper_bound(start);
//      if no entry is found or given end time is less than equal to start time of found interval
        if (itr == calendarMap.end() || end <= itr->second) {
            cntCount++;
            calendarMap[end] = start;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */