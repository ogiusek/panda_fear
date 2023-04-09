void Draw()
{
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    Draw_Rectangle(0, 0, WIDTH, HEIGHT);

    game.Draw();

    SDL_RenderPresent(renderer);
}
// Draw_Image(0, 0, 800, 300, "Assets/Images/test.jpg");
// Draw_Wheel(50, pX, pY);
// Draw_Text(0, HEIGHT / 2, {255, 255, 255, 150}, 24, ("01234567890"));
// Draw_Text(0, HEIGHT / 2 + 24, {255, 255, 255, 150}, 24, ("!$%*()[]:|;-=_+,./?"));
// Draw_Text(0, HEIGHT / 2 + 48, {255, 255, 255, 150}, 24, ("qwertyuiopasdfghjklzxcvbnm"));
// Draw_Text(0, HEIGHT / 2 + 72, {255, 255, 255, 150}, 24, ("QWERTYUIOPASDFGHJKLZXCVBNM"));