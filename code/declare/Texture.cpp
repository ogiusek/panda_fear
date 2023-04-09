class Texture
{
public:
    string src;
    SDL_Texture *texture;
    Texture(string _src)
    {
        src = _src;
        texture = IMG_LoadTexture(renderer, _src.c_str());
    };
};