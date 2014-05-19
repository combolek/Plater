#include "PlacedPart.h"

namespace Plater
{
    PlacedPart::PlacedPart()
        : part(NULL), x(0), y(0), rotation(0)
    {
    }

    PlacedPart::~PlacedPart()
    {
    }

    void PlacedPart::setPart(Part *part_)
    {
        part = part_;
    }

    void PlacedPart::setOffset(float x_, float y_)
    {
        x = x_;
        y = y_;
    }

    void PlacedPart::setRotation(int r)
    {
        rotation = r;
    }

    Part *PlacedPart::getPart()
    {
        return part;
    }

    float PlacedPart::getX()
    {
        return x;
    }

    float PlacedPart::getY()
    {
        return y;
    }
    
    Bitmap *PlacedPart::getBmp()
    {
        return part->getBmp(rotation);
    }
            
    float PlacedPart::getGX()
    {
        Bitmap *bmp = getBmp();
        return (bmp->sX/(float)bmp->pixels)*part->precision;
    }

    float PlacedPart::getGY()
    {
        Bitmap *bmp = getBmp();
        return (bmp->sY/(float)bmp->pixels)*part->precision;
    }
}
