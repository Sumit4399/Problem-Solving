class MyCalendar {
public:
    
    unordered_map<int, int> bookings;
    MyCalendar() {
        
    }
    
     bool book(int s1, int e1) {
        for(auto& [s2, e2] : bookings) 
            
        // if neither of above condition is satisfied, there exists an intersection
        if( !(s1 >= e2 || s2 >= e1) )   
            return false;
         
        // no intersection found, so insert the new slot and return true
        bookings[s1] = e1;                 
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */