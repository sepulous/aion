#include "pixel_data.hpp"

PixelData::PixelData(int width, int height)
{
    m_width = width;
    m_height = height;
    m_data = new unsigned char[3*width*height];
}

int PixelData::GetWidth()
{
    return m_width;
}

int PixelData::GetHeight()
{
    return m_height;
}

unsigned char* PixelData::GetData()
{
    return m_data;
}