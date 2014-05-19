#include <iostream>
#include "Part.h"
#include "modelFile/modelFile.h"

using namespace std;

namespace Plater
{
    Part::Part()
        : model(NULL)
    {
    }

    Part::~Part()
    {
        if (model != NULL) {
            delete model;
        }
        if (bmp != NULL) {
            delete[] bmp;
        }
    }

    void Part::load(std::string filename_, float precision_, float deltaR)
    {
        int bmps = (M_PI*2)/deltaR;
        precision = precision_;
        filename = filename_;
        FMatrix3x3 id;
        model = loadModelFromFile(filename.c_str(), id);
        bmp = new Bitmap*[bmps];
        bmp[0] = model->pixelize(precision, 2000);

        for (int k=1; k<bmps; k++) {
            Bitmap *rotated = Bitmap::rotate(bmp[0], k*deltaR);
            bmp[k] = Bitmap::trim(rotated);
        }
    }
            
    float Part::getSurface()
    {
        return precision*bmp[0]->pixels;
    }

    std::string Part::getFilename()
    {
        return filename;
    }
            
    Bitmap *Part::getBmp(int index)
    {
        return bmp[index];
    }
}
