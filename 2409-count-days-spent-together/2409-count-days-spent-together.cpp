class Solution {
public:
    // Helper function to convert "MM-DD" string into the day of the year (1 to 365)
    int getDayOfYear(string dateStr) {
        vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        // Parse month (characters 0 and 1)
        int month = 0;
        for (int i = 0; i < 2; i++) {
            month = month * 10 + (dateStr[i] - '0');
        }
        
        // Parse day (characters 3 and 4)
        int day = 0;
        for (int i = 3; i < 5; i++) {
            day = day * 10 + (dateStr[i] - '0');
        }
        
        // Add days of preceding months
        int totalDays = 0;
        for (int i = 0; i < month - 1; i++) {
            totalDays += daysInMonths[i];
        }
        
        totalDays += day;
        return totalDays;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // Convert all four date strings into numeric day-of-the-year equivalents
        int aliceArrival = getDayOfYear(arriveAlice);
        int aliceLeave = getDayOfYear(leaveAlice);
        int bobArrival = getDayOfYear(arriveBob);
        int bobLeave = getDayOfYear(leaveBob);
        
        // Find the latest arrival date and the earliest leave date
        int latestArrival = max(aliceArrival, bobArrival);
        int earliestLeave = min(aliceLeave, bobLeave);
        
        // If the latest arrival is after the earliest leave, they never overlap
        if (latestArrival > earliestLeave) {
            return 0;
        }
        
        // Otherwise, return the number of overlapping days inclusive
        return earliestLeave - latestArrival + 1;
    }
};