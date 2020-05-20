#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>

#include "classes/circle.hpp"
#include "classes/rectangle.hpp"


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  //My inits
  myShapes::Circle c1{ {300, 300}, {100}, {255, 128, 0} };
  myShapes::Circle c2{ {500, 350}, {200}, {50, 150, 0} };
  myShapes::Circle c3{ {350, 600}, {75}, {80, 0, 255} };

  myShapes::Rectangle r1{ {150, 650}, {300, 750}, {122, 0, 0} };
  myShapes::Rectangle r2{ {400, 300}, {500, 600}, {255, 255, 255} };
  //End of my inits

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    //Code moved to bottom, to draw shapes after mouse cursor creation

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto mouse_position = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);



    //My stuff
    std::array<myShapes::Circle, 3> hoveredCircleArr{c1, c2, c3};
    std::array<myShapes::Rectangle, 2> hoveredRectArr{ r1, r2 };

    for (myShapes::Circle c : hoveredCircleArr)
    {
        if (c.is_inside({ (float)mouse_position.first, (float)mouse_position.second }))
            c.draw(&win, 50, 2.0f);
        else
            c.draw(&win, 50);
    }
    for (myShapes::Rectangle r : hoveredRectArr)
    {
        if (r.is_inside({ (float)mouse_position.first, (float)mouse_position.second }))
            r.draw(&win, 2.0f);
        else
            r.draw(&win);
    }

    /*c1.draw(&win); old drawings, I like to keep them here for more thickness/accuracy tests
    c2.draw(&win, 9);
    c3.draw(&win, 50, 5.0f);

    r1.draw(&win);
    r2.draw(&win, 0.2f);*/
    //End of my stuff


    win.update();
  }

  return 0;
}
