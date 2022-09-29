/**
 * 
 * @author Hao Yu Hung
 * @date 2022/09/29
 * 
 * The algorithm implementation of convex hull problem
 * 
 */ 

#include <iostream>
#include <vector>
#include <cmath>

class Point
{ 
public:
    int x; int y;
};

/**
 * The orientation of p1->p2 to p2->p3
 * 
 * 0 if p1->p2 and p2->p3 are collinear
 * 1 if p1->p2 to p2->p3 are clockwise
 * 2 if p1->p2 to p2->p3 are counter clockwise
 */
int orientation(Point p1, Point p2, Point p3)
{
    int compare = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);

    if(compare > 0)
        return 1;
    else if(compare < 0)
        return 2;
    else
        return 0;
}

/**
 * length of the two point
 * 
 * @param point1
 * @param point2
 * 
 */
int distance(Point point1, Point point2)
{
    return (int)sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}

/**
 * The Jarvis's Algorithm use to sove convex hull problem
 * 
 * time complexity O(nh) where h is convex hull vertices
 * 
 * @param points[] the set of points in the graph
 * @param size the array size of the points
 * 
 */
std::vector<Point> convexHull(const std::vector<Point>& points)
{

    // get the leftmost point in the graph
    int startPointIdx = 0;
    for(int i = 1; i < points.size(); ++i)
    {
        if(points[i].x < points[startPointIdx].x)
            startPointIdx = i;
    }



    // every iteration find the next point of result
    std::vector<Point> result;
    result.push_back(points[startPointIdx]);
    int currentPointIdx = startPointIdx;
    while(true)
    {
        int nextPointIdx = (currentPointIdx + 1) % points.size();
        int direction;
        for(int i = 0; i < points.size(); ++i)
        {
            if(i == nextPointIdx)
                continue;

            // currentPoint->points[i] to points[i]->points[nextPointIdx] are counterclock wise
            // points[i] need should be chose before points[nextPointIdx]
            direction = orientation(points[currentPointIdx], points[i], points[nextPointIdx]);
            if (direction == 2 || 
                (direction == 0 && distance(points[currentPointIdx], points[i]) > distance(points[currentPointIdx], points[nextPointIdx])))
                nextPointIdx = i;
        }
        if(nextPointIdx == startPointIdx) 
            break;
        result.push_back(points[nextPointIdx]);
        currentPointIdx = nextPointIdx;
        
    }
    
    return result;
}


int main(int argc, char** argv)
{
    std::vector<Point> points = {
        {0, 3},
        {2, 2},
        {1, 1},
        {2, 1},
        {3, 0},
        {0, 0},
        {3, 3}
    };

    std::vector<Point> result = convexHull(points);
    for(int i = 0; i < result.size(); ++i)
    {
        std::cout << "(" << result[i].x << ", " << result[i].y << ")\n";
    }

    return 0;
}