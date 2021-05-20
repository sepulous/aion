#ifndef PIXEL_DATA_H
#define PIXEL_DATA_H

class PixelData
{
private:
    unsigned char* m_data;
    int m_width;
    int m_height;

public:
    PixelData(int width, int height);
    int GetWidth();
    int GetHeight();
    unsigned char* GetData();
};

#endif