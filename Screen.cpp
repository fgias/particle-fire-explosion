#include "Screen.h"

namespace fgias {

Screen::Screen(): 
    m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {
}

bool Screen::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false; // return positive integers when the program fails
    }

    m_window = SDL_CreateWindow(
        "Particle Fire Explosion", 
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN
    );

    if (m_window == NULL) {
        SDL_Quit(); 
        return false; // return positive integers when the program fails
    }

    m_renderer = SDL_CreateRenderer(
        m_window, -1, SDL_RENDERER_PRESENTVSYNC
    );

    m_texture = SDL_CreateTexture(
        m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,
        SCREEN_WIDTH, SCREEN_HEIGHT
        // RGB: colours, A: "alpha" - transparency
    );

    if (m_renderer == NULL) {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    if (m_texture == NULL) {
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    m_buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT]; 
    // buffer: a temporary memory area in which data is stored while it is 
    // being processed or transferred, especially one used while streaming 
    // video or downloading audio.

    memset(m_buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
    // set all the bytes to the maximum possible value
    // 0x: hexadecimal, FF: 255 (max for 1 byte/ 8 bits)

    m_buffer[30000] = 0xFFFFFFFF; // set all 4 bytes (RGBA) to the max value (255)
    // a pair = 1 byte

    for (int i=0; i<SCREEN_WIDTH*SCREEN_HEIGHT; i++) {
        m_buffer[i] = 0xFFFF00FF;
    }

    SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH*sizeof(Uint32));
    SDL_RenderClear(m_renderer); 
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);

    return true;
}
    
bool Screen::processEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        };
    };
    return true;
}

void Screen::close() {
    delete [] m_buffer;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();  
}
    
}