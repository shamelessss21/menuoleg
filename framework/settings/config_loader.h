#ifndef CONFIG_LOADER_H
#define CONFIG_LOADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "settings.h"

namespace cfg {

inline std::string trim(std::string s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch){ return !std::isspace(ch); }));
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch){ return !std::isspace(ch); }).base(), s.end());
    return s;
}

inline bool parse_color(const std::string& value, ImVec4& out)
{
    std::istringstream ss(value);
    int r,g,b,a=255;
    if(!(ss >> r >> g >> b))
        return false;
    if(!(ss >> a)) a = 255;
    out = ImColor(r, g, b, a);
    return true;
}

inline bool parse_vec2(const std::string& value, ImVec2& out)
{
    std::istringstream ss(value);
    float x,y;
    if(!(ss >> x >> y))
        return false;
    out = ImVec2(x,y);
    return true;
}

inline bool load_style_from_file(const std::string& path, c_settings& s, c_colors& c)
{
    std::ifstream file(path);
    if(!file.is_open())
        return false;
    std::string section;
    std::string line;
    while(std::getline(file, line))
    {
        line = trim(line);
        if(line.empty() || line[0]=='#' || line[0]==';')
            continue;
        if(line.front()=='[' && line.back()==']')
        {
            section = line.substr(1, line.size()-2);
            continue;
        }
        auto pos = line.find('=');
        if(pos==std::string::npos) continue;
        std::string key = trim(line.substr(0,pos));
        std::string value = trim(line.substr(pos+1));
        if(section=="window") {
            if(key=="size")
                parse_vec2(value, s.c_window.window_size);
            else if(key=="padding")
                parse_vec2(value, s.c_window.padding);
            else if(key=="item_spacing")
                parse_vec2(value, s.c_window.item_spacing);
            else if(key=="scrollbar")
                s.c_window.scrollbar_size = std::stof(value);
            else if(key=="border")
                s.c_window.border_size = std::stof(value);
            else if(key=="rounding")
                s.c_window.rounding = std::stof(value);
        } else if(section=="colors") {
            if(key=="accent")
                parse_color(value, c.c_other_clr.accent_clr);
            else if(key=="window_layout")
                parse_color(value, c.c_window.layout);
            else if(key=="window_stroke")
                parse_color(value, c.c_window.stroke);
            else if(key=="text")
                parse_color(value, c.c_text.text);
            else if(key=="text_active")
                parse_color(value, c.c_text.text_active);
            else if(key=="text_hov")
                parse_color(value, c.c_text.text_hov);
        }
    }
    return true;
}

} // namespace cfg

inline c_settings::c_settings()
{
    load("style.ini");
}

inline bool c_settings::load(const std::string& path)
{
    return cfg::load_style_from_file(path, *this, *clr);
}

inline void c_settings::apply_style(ImGuiStyle& style) const
{
    style.WindowBorderSize = SCALE(c_window.border_size);
    style.WindowRounding = SCALE(c_window.rounding);
    style.WindowPadding = SCALE(c_window.padding);
    style.ScrollbarSize = SCALE(c_window.scrollbar_size);
    style.ItemSpacing = SCALE(c_window.item_spacing);
    style.ChildRounding = SCALE(c_child.rounding);
    style.FrameRounding = SCALE(c_element.rounding);
    style.FrameBorderSize = SCALE(c_button.border);
}

#endif // CONFIG_LOADER_H
