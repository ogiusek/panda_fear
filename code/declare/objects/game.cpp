class Game
{
private:
    ushort
        animation_frame = 0,
        animation_time = 10;
    ulong last_animation_frame = SDL_GetTicks() / animation_time;

    void animate()
    {
        auto now = SDL_GetTicks() / animation_time;
        if (now != last_animation_frame)
        {
            animation_frame++;
            last_animation_frame = now;
        };
    };

public:
    float seed;
    Player *player;
    Map *map;
    ushort difficultyLevel = 1,
           field_size = 32,
           chunk_size = 8,
           render_dist = 6;

    Game()
    {
        seed = time(NULL);
        map = new Map(&field_size, &chunk_size, &render_dist);
        player = new Player();
    };

    void Draw()
    {
        animate();
        map->Draw(player->xPos, player->yPos, &animation_frame);
        player->Draw(&animation_frame);
    };

    void Input()
    {
        player->Input();
    };

    void Update()
    {
        map->Update(player->xPos, player->yPos);
        player->Update();
    };
};