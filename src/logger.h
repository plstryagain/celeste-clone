#pragma once

#include <string>
#include <iostream>
#include <unordered_map>

namespace plstryagain {

namespace log {

enum class TextColor
{
  BLACK,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  MAGENTA,
  CYAN,
  WHITE,
  BRIGHT_BLACK,
  BRIGHT_RED,
  BRIGHT_GREEN,
  BRIGHT_YELLOW,
  BRIGHT_BLUE,
  BRIGHT_MAGENTA,
  BRIGHT_CYAN,
  BRIGHT_WHITE,
  COLOR_COUNT
};

template<typename... Args>
void static _log(std::string_view prefix, std::string_view msg, TextColor text_color, Args... args)
{
    std::unordered_map<TextColor, std::string> text_color_table{    
        { TextColor::BLACK, "\x1b[30m" }, // TEXT_COLOR_BLACK
        { TextColor::RED, "\x1b[31m" }, // TEXT_COLOR_RED
        { TextColor::GREEN, "\x1b[32m" }, // TEXT_COLOR_GREEN
        { TextColor::YELLOW, "\x1b[33m" }, // TEXT_COLOR_YELLOW
        { TextColor::BLUE, "\x1b[34m" }, // TEXT_COLOR_BLUE
        { TextColor::MAGENTA, "\x1b[35m" }, // TEXT_COLOR_MAGENTA
        { TextColor::CYAN, "\x1b[36m" }, // TEXT_COLOR_CYAN
        { TextColor::WHITE, "\x1b[37m" }, // TEXT_COLOR_WHITE
        { TextColor::BRIGHT_BLACK, "\x1b[90m" }, // TEXT_COLOR_BRIGHT_BLACK
        { TextColor::BRIGHT_RED, "\x1b[91m" }, // TEXT_COLOR_BRIGHT_RED
        { TextColor::BRIGHT_GREEN, "\x1b[92m" }, // TEXT_COLOR_BRIGHT_GREEN
        { TextColor::BRIGHT_YELLOW, "\x1b[93m" }, // TEXT_COLOR_BRIGHT_YELLOW
        { TextColor::BRIGHT_BLUE, "\x1b[94m" }, // TEXT_COLOR_BRIGHT_BLUE
        { TextColor::BRIGHT_MAGENTA, "\x1b[95m" }, // TEXT_COLOR_BRIGHT_MAGENTA
        { TextColor::BRIGHT_CYAN, "\x1b[96m" }, // TEXT_COLOR_BRIGHT_CYAN
        { TextColor::BRIGHT_WHITE, "\x1b[97m" }// TEXT_COLOR_BRIGHT_WHITE
    };
    std::cout << text_color_table[text_color] << prefix << " " << msg <<  "\033[0m" << std::endl;
}

template<typename... Args>
void trace(std::string_view msg, Args... args)
{
    _log("TRACE:", msg, TextColor::GREEN, args...);
}

template<typename... Args>
void warn(std::string_view msg, Args... args)
{
    _log("WARN:", msg, TextColor::YELLOW, args...);
}

template<typename... Args>
void err(std::string_view msg, Args... args)
{
    _log("ERROR:", msg, TextColor::RED, args...);
}

} // namespacce log

} // namespace plstryagain