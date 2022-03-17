#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace fgias {

class Screen {
public:
    static const int SCREEN_WIDTH = 800;
    static const int SCREEN_HEIGHT = 600;

private:
    SDL_Window * m_window; // convention: member variables: prefix with `m_`
    SDL_Renderer * m_renderer;
    SDL_Texture * m_texture;
    Uint32 * m_buffer;

public:
    Screen();
    bool init();
    bool processEvents();
    void close();    
};

}

#endif