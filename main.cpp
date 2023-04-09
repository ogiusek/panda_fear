#include "code/imports.cpp"

int main(int argc, char *args[])
{
    Init();

    while (running)
    {
        if ((SDL_GetTicks() - lastFrame) >= (fps))
        {
            ticks_beetwen_frames = lastFrame - SDL_GetTicks();
            lastFrame = SDL_GetTicks();
            update();
            Draw();
            input();
        }
    }

    SHUT_DOWN();
    return 0;
}

// g++ main.cpp -o program -lSDL2 -lSDL2_ttf -lSDL2_image
// ./program