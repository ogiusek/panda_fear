void Draw_Image(int xPos, int yPos, int width, int height, string href)
{
    SDL_Rect rect = {xPos, yPos, width, height};
    for (const auto &elem : textures)
    {
        if (elem.src == href)
        {
            SDL_RenderCopy(renderer, elem.texture, NULL, &rect);
            return;
        };
    };
    textures.push_back(Texture(href.c_str()));
    SDL_RenderCopy(renderer, textures.back().texture, NULL, &rect);
}