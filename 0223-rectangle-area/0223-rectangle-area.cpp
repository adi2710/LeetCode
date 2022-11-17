class Solution {
public:
    
    inline int calculateArea(int &x1, int &y1, int &x2, int &y2)
    {
        return (x2 - x1) * (y2 - y1);
    }
    
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area = calculateArea(ax1, ay1, ax2, ay2) + calculateArea(bx1, by1, bx2, by2);
        int left = max(ax1, bx1), right = min(ax2, bx2);
        int bottom = max(ay1, by1), top = min(ay2, by2);
        if(left <= right && bottom <= top)
            area -= calculateArea(left, bottom, right, top);
        return area;
    }
};