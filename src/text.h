#ifndef TEXT_H
#define TEXT_H

#include <SDL_ttf.h>
#include <string>
#include "texture.h"
#include "color.h"
#include "font.h"


class Text {
public:
    Text(TTF_Font * font, std::string string_={}, Color color = {0.f, 0.f, 0.f});
    ~Text() = default;

    void render();
    void load();

    void setString(std::string string_) {
        string = string_;
        loaded = false;
    }
    void setColor(const Color& color_) {
        color.set(color_);
        loaded = false;
    }
    //void setColor(const Color&& color_) {
    //    setColor(color_);
    //}
    void setScale(double scale_) {
        scale = scale_;
        // Update texture if loaded
        if (loaded) tex.setScale(scale);
    }

    [[nodiscard]] int getWidth() const { return tex.getWidth(); }
    [[nodiscard]] int getHeight() const { return tex.getHeight(); }

    int x, y;

    bool loaded = false;
    TTF_Font * font;
    std::string string;
    Color color;
    float scale;

private:
    Texture tex;
};

#endif
