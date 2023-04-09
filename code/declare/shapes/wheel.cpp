void Draw_Wheel(int radius, int xPos, int yPos)
{
    for (int y = -radius; y <= radius; y++)
    {
        int xLimit = (int)sqrt(radius * radius - y * y);
        for (int x = -xLimit; x <= xLimit; x++)
        {
            SDL_RenderDrawPoint(renderer, xPos + x, yPos + y);
        }
    }
}
