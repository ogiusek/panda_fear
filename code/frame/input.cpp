void Input()
{
    while (SDL_PollEvent(&event))
    {
        keystates = SDL_GetKeyboardState(NULL);

        if (keystates[SDL_SCANCODE_ESCAPE])
            running = 0;

        if (event.type == SDL_QUIT)
            running = 0;

        if (event.type == SDL_KEYDOWN && keystates[SDL_SCANCODE_F11])
            fullscreen = !fullscreen;
    }
    game->Input();
}