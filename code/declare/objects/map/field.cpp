class Field
{
public:
    ushort *field_size, biom, image;

    vector<ushort> override_images;

    int xFieldIndex,
        yFieldIndex;
    int xIndex,
        yIndex;

    // vector<vector<Field *> *> *map;

    Field(
        int _xFieldIndex, int _yFieldIndex, int _biom,
        ushort *_field_size
        //   , vector<vector<Field *> *> *_map
        )
        : xFieldIndex(_xFieldIndex), yFieldIndex(_yFieldIndex),
          xIndex(_xFieldIndex), yIndex(_yFieldIndex),
          biom(_biom),
          field_size(_field_size)
    //   , map(_map)
    {
        image = get_field(biom);

        //"img8/9x8", "img8/9x9", "img8/9x10", "img8/9x11"
        //"img8/8x8", "img8/8x9", "img8/8x10", "img8/8x11"
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