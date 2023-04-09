void Draw_Rectangle(int xPos, int yPos, int width, int height)
{
    SDL_Rect rect;
    rect.x = xPos;
    rect.y = yPos;
    rect.w = width;
    rect.h = height;
    SDL_RenderFillRect(renderer, &rect);
}