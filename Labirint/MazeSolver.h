#pragma once
#include "BMPImage.h"
#include <vector>
#include <queue>

struct Point {
    int x, y;
    Point(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
};

class MazeSolver {
public:
    explicit MazeSolver(BMPImage* img);
    bool solve();
    Point getStart() const;
    Point getEnd() const;

private:
    static const Pixel WALL_COLOR;
    static const Pixel PATH_COLOR;
    static const Pixel START_COLOR;
    static const Pixel END_COLOR;
    static const Pixel ROUTE_COLOR;

    bool colorMatch(const Pixel& a, const Pixel& b) const;          // добавлено const
    Point findColor(const Pixel& targetColor) const;               // добавлено const
    bool findStartAndEnd();                                         // не const, т.к. меняет start,end
    bool isPassable(int x, int y) const;
    void drawCross(int cx, int cy, int size, const Pixel& color);
    void drawPath(const std::vector<Point>& path);

    BMPImage* image;
    Point start, end;
};