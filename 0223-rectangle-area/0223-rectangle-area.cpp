class Solution {
public:
    
    int calculateArea(int x1, int y1, int x2, int y2)
    {
        return (x2 - x1) * (y2 - y1);
    }
    
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area = calculateArea(ax1, ay1, ax2, ay2) + calculateArea(bx1, by1, bx2, by2);
        if(((ax1 <= bx1 && bx1 <= ax2) || (ax1 <= bx2 && bx2 <= ax2) || (bx1 <= ax1 && ax1 <= bx2) || (bx1 <= ax2 && ax2 <= bx2)) && ((ay1 <= by1 && by1 <= ay2) || (ay1 <= by2 && by2 <= ay2) || (by1 <= ay1 && ay1 <= by2) || (by1 <= ay2 && ay2 <= by2)))
            area -= calculateArea(max(ax1, bx1), max(ay1, by1), min(ax2, bx2), min(ay2, by2));
        return area;
    }
};