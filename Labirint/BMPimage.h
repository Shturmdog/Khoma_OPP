#pragma once
#include <cstdint>
#include <string>
#include <vector>

using namespace std;

struct Pixel {
    uint8_t r = 0, g = 0, b = 0;
    Pixel() = default;
    Pixel(uint8_t red, uint8_t green, uint8_t blue) : r(red), g(green), b(blue) {}
};

class BMPImage {
public:
    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename) const;
    int width() const;
    int height() const;
    Pixel pixelAt(int x, int y) const;
    void setPixelAt(int x, int y, const Pixel& pixel);
    bool isInside(int x, int y) const;

private:
    int width_ = 0;
    int height_ = 0;
    vector<Pixel> pixels_;
};