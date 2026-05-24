#include "MazeSolver.h"
#include <iostream>

using namespace std;

const Pixel MazeSolver::WALL_COLOR = Pixel(0, 0, 0);
const Pixel MazeSolver::PATH_COLOR = Pixel(255, 255, 255);
const Pixel MazeSolver::START_COLOR = Pixel(237, 28, 36);
const Pixel MazeSolver::END_COLOR = Pixel(34, 177, 76);
const Pixel MazeSolver::ROUTE_COLOR = Pixel(0, 255, 255);

MazeSolver::MazeSolver(BMPImage* img) : image(img), start(0, 0), end(0, 0) {}

// Добавлен const
bool MazeSolver::colorMatch(const Pixel& a, const Pixel& b) const {
    int dr = (int)a.r - (int)b.r;
    int dg = (int)a.g - (int)b.g;
    int db = (int)a.b - (int)b.b;
    return (dr * dr + dg * dg + db * db) <= 300;
}

// Добавлен const
Point MazeSolver::findColor(const Pixel& targetColor) const {
    int w = image->width();
    int h = image->height();

    long long sumX = 0, sumY = 0, count = 0;

    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            Pixel p = image->pixelAt(x, y);
            if (colorMatch(p, targetColor)) {
                sumX += x;
                sumY += y;
                ++count;
            }
        }
    }

    if (count == 0) return Point(-1, -1);
    return Point(static_cast<int>(sumX / count), static_cast<int>(sumY / count));
}

bool MazeSolver::findStartAndEnd() {
    start = findColor(START_COLOR);
    end = findColor(END_COLOR);

    if (start.x == -1) {
        cerr << "Ошибка: не найдена красная точка (вход)" << endl;
        return false;
    }
    if (end.x == -1) {
        cerr << "Ошибка: не найдена зелёная точка (выход)" << endl;
        return false;
    }

    cout << "Найден вход: (" << start.x << ", " << start.y << ")" << endl;
    cout << "Найден выход: (" << end.x << ", " << end.y << ")" << endl;
    return true;
}

bool MazeSolver::isPassable(int x, int y) const {
    if (!image->isInside(x, y)) return false;
    Pixel p = image->pixelAt(x, y);
    return colorMatch(p, PATH_COLOR) ||
        colorMatch(p, START_COLOR) ||
        colorMatch(p, END_COLOR);
}

bool MazeSolver::solve() {
    if (!findStartAndEnd()) return false;

    int w = image->width();
    int h = image->height();

    vector<vector<int>> dist(h, vector<int>(w, -1));
    vector<vector<Point>> parent(h, vector<Point>(w, Point(-1, -1)));

    queue<Point> q;
    q.push(start);
    dist[start.y][start.x] = 0;

    const int dx[4] = { 0, 0, -1, 1 };
    const int dy[4] = { -1, 1, 0, 0 };

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        if (cur.x == end.x && cur.y == end.y) break;

        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (image->isInside(nx, ny) && dist[ny][nx] == -1 && isPassable(nx, ny)) {
                dist[ny][nx] = dist[cur.y][cur.x] + 1;
                parent[ny][nx] = cur;
                q.push(Point(nx, ny));
            }
        }
    }

    if (dist[end.y][end.x] == -1) {
        cerr << "Ошибка: путь не найден" << endl;
        return false;
    }

    cout << "Длина пути: " << dist[end.y][end.x] << " шагов" << endl;

    vector<Point> path;
    Point cur = end;
    while (!(cur.x == start.x && cur.y == start.y)) {
        path.push_back(cur);
        cur = parent[cur.y][cur.x];
        if (cur.x == -1) {
            cerr << "Ошибка: некорректный путь" << endl;
            return false;
        }
    }
    path.push_back(start);

    drawPath(path);
    return true;
}

void MazeSolver::drawCross(int cx, int cy, int size, const Pixel& color) {
    for (int dy = -size; dy <= size; ++dy) {
        for (int dx = -size; dx <= size; ++dx) {
            int px = cx + dx;
            int py = cy + dy;
            if (image->isInside(px, py) && isPassable(px, py)) {
                image->setPixelAt(px, py, color);
            }
        }
    }
}

void MazeSolver::drawPath(const vector<Point>& path) {
    for (size_t i = 0; i < path.size(); ++i) {
        drawCross(path[i].x, path[i].y, 2, ROUTE_COLOR);
    }
    image->setPixelAt(start.x, start.y, START_COLOR);
    image->setPixelAt(end.x, end.y, END_COLOR);
}

Point MazeSolver::getStart() const {
    return start;
}

Point MazeSolver::getEnd() const {
    return end;
}