void Draw_Text(int xPos, int yPos, SDL_Color color, int font_size, string text)
{
    TTF_Font *font = TTF_OpenFont("Assets/Fonts/bitByBit.ttf", font_size);

    SDL_Surface *surface =
        TTF_RenderText_Solid(font, text.c_str(), color);

    SDL_Texture *Message = SDL_CreateTextureFromSurface(renderer, surface);

    int surfaceWidth = surface->w;
    int surfaceHeight = surface->h;

    SDL_Rect Message_rect;
    Message_rect.x = xPos;
    Message_rect.y = yPos;
    Message_rect.w = surfaceWidth;
    Message_rect.h = surfaceHeight;
    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(Message);
    TTF_CloseFont(font);
}
