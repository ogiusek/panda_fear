class Field
{
public:
    ushort *field_size,
        xChunkIndex,
        yChunkIndex;
    int biom;
    // string directory;
    ushort image;
    vector<ushort> override_images;

    int xFieldIndex,
        yFieldIndex;

    Field(int _xFieldIndex, int _yFieldIndex, ushort _xChunkIndex, ushort _yChunkIndex, int _biom, ushort *_field_size)
        : xFieldIndex(_xFieldIndex), yFieldIndex(_yFieldIndex), xChunkIndex(_xChunkIndex), yChunkIndex(_yChunkIndex), biom(_biom), field_size(_field_size)
    {
        int rVal = rand() % 8;
        switch (rVal)
        {
        case 0:
            image = get_field_image_index("img1/image9x2");
            break;
        case 1:
            image = get_field_image_index("img1/image9x3");
            break;
        case 2:
            image = get_field_image_index("img1/image10x2");
            break;
        case 3:
            image = get_field_image_index("img1/image10x3");
            break;
        case 4:
            image = get_field_image_index("img1/image11x2");
            break;
        case 5:
            image = get_field_image_index("img1/image11x3");
            break;
        case 6:
            image = get_field_image_index("img1/image11x4");
            break;
        case 7:
            image = get_field_image_index("img1/image11x5");
            break;
        };

        if (abs(xChunkIndex) % 8 == 0 && abs(yChunkIndex) % 8 == 1)
        {
            override_images.push_back(get_field_image_index("img8/9x8"));
            override_images.push_back(get_field_image_index("img8/9x9"));
            override_images.push_back(get_field_image_index("img8/9x10"));
            override_images.push_back(get_field_image_index("img8/9x11"));
        }
        else if (abs(xChunkIndex) % 8 == 0 && abs(yChunkIndex) % 8 == 0)
        {
            override_images.push_back(get_field_image_index("img8/8x8"));
            override_images.push_back(get_field_image_index("img8/8x9"));
            override_images.push_back(get_field_image_index("img8/8x10"));
            override_images.push_back(get_field_image_index("img8/8x11"));
        };
    };

    void Draw(int &player_x, int &player_y, ushort &animation_frame)
    {
        int xPos = xFieldIndex * *field_size - player_x + WIDTH / 2;
        int yPos = yFieldIndex * *field_size - player_y + HEIGHT / 2;
        Draw_Image(xPos, yPos, *field_size, *field_size,
                   "Assets/Images/biomes/" + biomes_list[biom] + field_images[image] + ".png");
        if (override_images.size() == 0)
            return;
        auto override_index = animation_frame / 10 % override_images.size();
        Draw_Image(xPos, yPos, *field_size, *field_size,
                   "Assets/Images/biomes/" + biomes_list[biom] + field_images[override_images[override_index]] + ".png");
    };

    void Update(int player_x, int player_y){};
};