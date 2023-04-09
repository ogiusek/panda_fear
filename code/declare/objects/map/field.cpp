class Field
{
public:
    ushort *field_size,
        xChunkIndex,
        yChunkIndex;
    string image;
    vector<string> override_images;

    int xFieldIndex,
        yFieldIndex;

    Field(int _xFieldIndex, int _yFieldIndex, ushort _xChunkIndex, ushort _yChunkIndex, ushort *_field_size)
    {
        xFieldIndex = _xFieldIndex;
        yFieldIndex = _yFieldIndex;
        xChunkIndex = _xChunkIndex;
        yChunkIndex = _yChunkIndex;
        field_size = _field_size;
        int rVal = rand() % 8;
        switch (rVal)
        {
        case 0:
            image = "dessert/img1/image9x2.png";
            break;
        case 1:
            image = "dessert/img1/image9x3.png";
            break;
        case 2:
            image = "dessert/img1/image10x2.png";
            break;
        case 3:
            image = "dessert/img1/image10x3.png";
            break;
        case 4:
            image = "dessert/img1/image11x2.png";
            break;
        case 5:
            image = "dessert/img1/image11x3.png";
            break;
        case 6:
            image = "dessert/img1/image11x4.png";
            break;
        case 7:
            image = "dessert/img1/image11x5.png";
            break;
        };

        if (abs(xChunkIndex) % 8 == 0 && abs(yChunkIndex) % 8 == 1)
        {
            override_images.push_back("dessert/img8/9x8.png");
            override_images.push_back("dessert/img8/9x9.png");
            override_images.push_back("dessert/img8/9x10.png");
            override_images.push_back("dessert/img8/9x11.png");
        }
        else if (abs(xChunkIndex) % 8 == 0 && abs(yChunkIndex) % 8 == 0)
        {
            override_images.push_back("dessert/img8/8x8.png");
            override_images.push_back("dessert/img8/8x9.png");
            override_images.push_back("dessert/img8/8x10.png");
            override_images.push_back("dessert/img8/8x11.png");
        };
    };

    void Draw(int player_x, int player_y, ushort *animation_frame)
    {
        int xPos = xFieldIndex * *field_size - player_x + WIDTH / 2;
        int yPos = yFieldIndex * *field_size - player_y + HEIGHT / 2;

        if (xPos + *field_size >= 0 && yPos + *field_size >= 0 && xPos <= WIDTH && yPos <= HEIGHT)
        {
            Draw_Image(xPos, yPos, *field_size, *field_size, "Assets/Images/biomes/" + image);
            if (override_images.size() > 0 && override_images[0] != "")
            {
                auto override_index = *animation_frame / 10 % override_images.size();
                Draw_Image(xPos, yPos, *field_size, *field_size, "Assets/Images/biomes/" + (override_images[override_index]));
            };
        };
    };

    void Update(int player_x, int player_y){};
};