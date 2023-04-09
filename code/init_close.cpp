void Init()
{
    running = 1;
    fullscreen = 0;

    TTF_Init();

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        cout << "ERROR AT SDL INIT\n";
    if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, fullscreen, &window, &renderer) < 0)
        cout << "ERROR AT SDL CREATE WINDOW AND RENDERER\n";

    SDL_SetWindowTitle(window, TITLE.c_str());
    SDL_ShowCursor(1);

    SDL_Surface *icon = IMG_Load("Assets/Images/red-panda.png");
    SDL_SetWindowIcon(window, icon);
    SDL_SetWindowTitle(window, "Panda's fear");

    SDL_FreeSurface(icon);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
}

void SHUT_DOWN()
{
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}