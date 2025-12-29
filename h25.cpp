#include <bits/stdc++.h>
using namespace std;

class Pixel {
public:
    int R, G, B;

public:
    Pixel() : R(0), G(0), B(0) {}
    Pixel(int r, int g, int b) {
        R = r;
        G = g;
        B = b;
    }

    int get_gray_scale() const {
        return int(0.3 * R + 0.59 * G + 0.11 * B);
    }
};

class Image {
public:
    Pixel Data[32][32];

public:
    void Range(int& minScale, int& maxScale);
    void ToGray();  
};

void Image::Range(int& minScale, int& maxScale) {
    minScale = 255;
    maxScale = 0;

    for (int i = 0; i < 32; ++i)
        for (int j = 0; j < 32; ++j) {
            int gray = Data[i][j].get_gray_scale();
            minScale = min(minScale, gray);
            maxScale = max(maxScale, gray);
        }
}

void Image::ToGray() {
    for (int i = 0; i < 32; ++i)
        for (int j = 0; j < 32; ++j) {
            int gray = Data[i][j].get_gray_scale();
            Data[i][j].R = gray;
            Data[i][j].G = gray;
            Data[i][j].B = gray;
        }
}
