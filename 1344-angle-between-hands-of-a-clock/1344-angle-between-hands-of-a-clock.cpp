class Solution {
public:
    double angleClock(int hour, int minutes) {
       double res = abs(minutes*6.0 - (30*(hour%12)+ 0.5* minutes));
       return min(res , 360.0 - res);

    }
};