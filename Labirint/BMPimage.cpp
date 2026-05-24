#include "BMPImage.h"
#include <fstream>

bool BMPImage::loadFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        return false;
    }

    uint8_t signature[2];
    file.read(reinterpret_cast<char*>(signature), 2);
    if (signature[0] != 'B' || signature[1] != 'M') return false;

    uint32_t dataOffset;
    file.seekg(10);
    file.read(reinterpret_cast<char*>(&dataOffset), 4);

    file.seekg(18);
    file.read(reinterpret_cast<char*>(&width_), 4);
    file.read(reinterpret_cast<char*>(&height_), 4);

    uint16_t bitsPerPixel;
    file.seekg(28);
    file.read(reinterpret_cast<char*>(&bitsPerPixel), 2);
    if (bitsPerPixel != 24) return false;

    int rowSize = ((width_ * 3 + 3) / 4) * 4;
    int padding = rowSize - width_ * 3;

    pixels_.resize(width_ * height_);

    file.seekg(dataOffset);
    std::vector<uint8_t> row(rowSize);

    for (int y = height_ - 1; y >= 0; --y) {
        file.read(reinterpret_cast<char*>(row.data()), rowSize);
        for (int x = 0; x < width_; ++x) {
            uint8_t b = row[x * 3];
            uint8_t g = row[x * 3 + 1];
            uint8_t r = row[x * 3 + 2];
            pixels_[y * width_ + x] = Pixel(r, g, b);
        }
    }
    return true;
}

bool BMPImage::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (!file) return false;

    int rowSize = ((width_ * 3 + 3) / 4) * 4;
    int padding = rowSize - width_ * 3;
    int imageSize = rowSize * height_;
    int fileSize = 54 + imageSize;

    uint8_t fileHeader[14] = {
        'B', 'M',
        static_cast<uint8_t>(fileSize), static_cast<uint8_t>(fileSize >> 8),
        static_cast<uint8_t>(fileSize >> 16), static_cast<uint8_t>(fileSize >> 24),
        0, 0, 0, 0,
        54, 0, 0, 0
    };

    uint8_t infoHeader[40] = { 0 };
    infoHeader[0] = 40;
    *reinterpret_cast<uint32_t*>(&infoHeader[4]) = width_;
    *reinterpret_cast<uint32_t*>(&infoHeader[8]) = height_;
    infoHeader[12] = 1;
    infoHeader[14] = 24;
    infoHeader[16] = 0;
    *reinterpret_cast<uint32_t*>(&infoHeader[20]) = imageSize;

    file.write(reinterpret_cast<const char*>(fileHeader), 14);
    file.write(reinterpret_cast<const char*>(infoHeader), 40);

    std::vector<uint8_t> row(rowSize, 0);
    for (int y = height_ - 1; y >= 0; --y) {
        for (int x = 0; x < width_; ++x) {
            const Pixel& p = pixels_[y * width_ + x];
            row[x * 3] = p.b;
            row[x * 3 + 1] = p.g;
            row[x * 3 + 2] = p.r;
        }
        file.write(reinterpret_cast<const char*>(row.data()), rowSize);
    }
    return true;
}

int BMPImage::width() const {
    return width_;
}

int BMPImage::height() const {
    return height_;
}

Pixel BMPImage::pixelAt(int x, int y) const {
    if (!isInside(x, y)) return Pixel();
    return pixels_[y * width_ + x];
}

void BMPImage::setPixelAt(int x, int y, const Pixel& pixel) {
    if (isInside(x, y)) {
        pixels_[y * width_ + x] = pixel;
    }
}

bool BMPImage::isInside(int x, int y) const {
    return x >= 0 && x < width_ && y >= 0 && y < height_;
}