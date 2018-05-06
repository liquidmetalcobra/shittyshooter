
#pragma once
#include "TextBox.hpp"


class IntTextBox : public TextBox
{
public:
    IntTextBox(Vector_2D loc, Vector_2D size, std::string t, ALLEGRO_COLOR *c, int * i) : TextBox(loc,size,t,c)
    {
        num = i;
        
        
    }
    ~IntTextBox() {}
    void update();
    void init();
    void draw(ALLEGRO_DISPLAY *display);
    void destroy();
private:
    int *num;
    
    
};