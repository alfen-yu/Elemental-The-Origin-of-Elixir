#ifndef __LoaderParams__
#define __LoaderParams
#include <iostream>

class LoaderParams
{
private:
    // variables for loading an image
    int x, y;
    std::string textureID;
    int currentFrame, currentRow;
    int width, height;

public:
    LoaderParams(int lx, int ly, int lwidth, int lheight, std::string lTextureID, int LCR, int LCF) : x(lx), y(ly),
                                                                                                      width(lwidth),
                                                                                                      height(lheight),
                                                                                                      textureID(lTextureID),
                                                                                                      currentRow(LCR),
                                                                                                      currentFrame(LCF) {}

    // getter functions to the variables
    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int getCurrentFrame() const { return currentFrame; }
    int getCurrentRow() const { return currentRow; }
    std::string getID() const { return textureID; }

    // int setCurrentFrame(int frame) { currentFrame = frame; }
    // int setCurrentRow(int row) { currentRow = row; }
};

#endif