#pragma once
#ifndef SCREEN_H
#define SCREEN_H
#include <string>
class Screen {
public:
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd) :height(ht), width(wd) ,contents(ht*wd,' '){}
    Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c){}
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &move(pos r, pos c);
    Screen &display(std::ostream &);
    const Screen &display(std::ostream &) const;
    char get() const { return contents[cursor]; }
    char get(pos r, pos s) const;
    pos size() const { return height*width }
private:
    pos width = 0, height = 0;
    pos cursor = 0;                 //¹â±ê
    std::string contents;
    void do_display(std::ostream &os) const { os << contents; }
};
#endif