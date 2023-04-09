#define WIDTH 1280
#define HEIGHT 720

bool fullscreen, running;
float fps = 1000 / 60;
int lastFrame = SDL_GetTicks(), init_frame = SDL_GetTicks(), ticks_beetwen_frames = 0;

const string TITLE = "Panda's Fear";
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event event;

#include "Texture.cpp"

vector<Texture> textures;
SDL_Texture *texture;

const Uint8 *keystates = SDL_GetKeyboardState(NULL);