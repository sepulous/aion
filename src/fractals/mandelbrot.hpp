#ifndef MANDELBROT_H
#define MENDELBROT_H

#include <cmath>
#include <wx/wx.h>
#include "fractal.hpp"
#include "../pixel_data.hpp"
#include "color_palettes.hpp"

class Mandelbrot : public Fractal
{
public:
    Mandelbrot() {};

    void Render(PixelData* pixelData, COLOR_PALETTE colorPalette) override
    {
        int width = pixelData->GetWidth();
        int height = pixelData->GetHeight();

        const double scale = 0.005;
        const int max_iteration = 1000;

        double iteration;
        double x0, y0;
        double x2, y2;
        double x, y;

        unsigned int finalColor;
        unsigned int color1;
        unsigned int color2;

        const double log_2 = log2(2);
        double log_zn;
        double nu;

        int xOffset = (int)(width / 1.4);
        int yOffset = (int)(height / 2.08);

        for (int Py = -yOffset; Py < height - yOffset; Py++) {
            for (int Px = -xOffset; Px < width - xOffset; Px++) {
                x0 = Px * scale;
                y0 = Py * scale;
                x2 = 0.0, y2 = 0.0;
                x = 0.0, y = 0.0;
                iteration = 0;
                while (x*x + y*y <= 65536 && iteration <= max_iteration) {
                    y = (x+x)*y + y0;
                    x = x2 - y2 + x0;
                    x2 = x*x;
                    y2 = y*y;
                    iteration++;
                }

                if (iteration <= max_iteration) {
                    log_zn = log2(x*x + y*y) / 2;
                    nu = log2(log_zn / log_2) / log_2;
                    iteration += 1 - nu;

                    color1 = colorPalette[((unsigned int)floor(iteration)) % 20];
                    color2 = colorPalette[((unsigned int)floor(iteration + 1)) % 20];
                    finalColor = lerp(color1, color2, iteration - ((unsigned int)iteration));
                } else {
                    finalColor = 0x0;
                }

                memcpy(&(pixelData->GetData())[3*((Py+yOffset)*width+(Px+xOffset))], &finalColor, 3);
            }
        }
    }

private:
    unsigned int lerp(unsigned int color1, unsigned int color2, double t)
    {
        wxColour c1(color1);
        wxColour c2(color2);
        wxColour c3(
            c1.Red() + (c2.Red() - c1.Red()) * t,
            c1.Green() + (c2.Green() - c1.Green()) * t,
            c1.Blue() + (c2.Blue() - c1.Blue()) * t
        );
        return c3.GetRGB();
    }
};

#endif