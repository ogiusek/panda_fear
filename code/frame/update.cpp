void update()
{
    if (fullscreen)
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    else
        SDL_SetWindowFullscreen(window, 0);

    game.Update();
    // if (keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W])
    //     pY += pS * ticks_beetwen_frames;
    // if (keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A])
    //     pX += pS * ticks_beetwen_frames;
    // if (keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S])
    //     pY -= pS * ticks_beetwen_frames;
    // if (keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D])
    //     pX -= pS * ticks_beetwen_frames;
};