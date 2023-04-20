#define WIDTH 1280
#define HEIGHT 720

// template <typename T>

bool fullscreen, running;
float fps_limit = 1000 / 60;
int lastFrame = SDL_GetTicks(), init_frame = SDL_GetTicks(), ticks_beetwen_frames = 0;

int fps = 0;
void add_fps()
{
    fps += 1;
}
void remove_fps()
{
    this_thread::sleep_for(chrono::seconds(1));
    fps -= 1;
}

const string TITLE = "Panda's Fear";
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event event;

#include "Texture.cpp"
vector<Texture> textures;
SDL_Texture *texture;

string assets_directory = "Assets/Images/biomes/";

vector<string> biomes_list = {"dessert/", "forrest/", "swamp/", "taiga/", "tundra/"};

const Uint8 *keystates = SDL_GetKeyboardState(NULL);