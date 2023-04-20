class Player
{
private:
    bool animate = true;
    string direction = "down-";

public:
    short
        hp = 100,
        maxHp = 100,
        regeneration = 5,
        regeneration_delay = 3,
        player_size = 32;

    float xPos = 0,
          yPos = 0,
          speed = .2,
          mining_speed = 0,
          cutting_speed = 0;
    // short eq[6] = {0, 0, 0, 0, 0, 0};

    Player()
    {
        xPos = 0;
        yPos = 0;
    };

    void Draw(ushort &animation_frame)
    {
        string img = "Assets/Images/player/";
        img += direction;
        if (!animate)
        {
            img += "0.png";
        }
        else
        {
            img += to_string(animation_frame / 7 % 4) + ".png";
        };
        Draw_Image(WIDTH / 2, HEIGHT / 2, player_size, player_size, img);
    };

    void Input()
    {
        string animate_direction = "";
        bool up = keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W];
        bool left = keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A];
        bool down = keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S];
        bool right = keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D];
        if (left && !right)
        {
            animate_direction = "left-";
            xPos += speed * ticks_beetwen_frames;
        };
        if (right && !left)
        {
            animate_direction = "right-";
            xPos -= speed * ticks_beetwen_frames;
        };
        if (up && !down)
        {
            animate_direction = "up-";
            yPos += speed * ticks_beetwen_frames;
        }
        if (down && !up)
        {
            animate_direction = "down-";
            yPos -= speed * ticks_beetwen_frames;
        };

        if (animate_direction != "")
        {
            direction = animate_direction;
        };
        animate = animate_direction != "";
    };

    void Update(){

    };
};