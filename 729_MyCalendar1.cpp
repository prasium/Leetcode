"""
You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.

A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).

The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

Implement the MyCalendar class:

    MyCalendar() Initializes the calendar object.
    boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.

Input
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
Output
[null, true, false, true]
"""
class MyCalendar {
public:
    set<pair<int,int>> bookings;
    MyCalendar() {
        
    }
    
    bool book(int start, int en) {
        auto slot = bookings.lower_bound({start, en});
             // a booked slot with nearest starting after s1 should also have its end after e1  OR
        // a booked slot with nearest starting before s1 should also end before s1  
        if( slot != end(bookings) && !(slot -> first >= en) || 
           slot != begin(bookings) && !(prev(slot) -> second <= start)) 
			    return false;         // if neither of above conditions satisfy, there exists a intersection
        bookings.insert({start, en});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */