class Map_Column
{
private:
    ushort
        *field_size,
        *render_dist;

    uint *map_first_column;
    vector<Map_Column> *map;

    Biomes *biomes;

    bool Found_In_Column(int index)
    {
        for (const auto &elem : column)
        {
            if (elem.yIndex == index)
            {
                return true;
            }
        }
        return false;
    };

    void Insert_New_Field(int index)
    {
        auto insert_pos = column.begin();

        while (insert_pos != column.end() && insert_pos->xIndex < index)
        {
            insert_pos++;
        };

        column.insert(insert_pos, Field(xIndex, index, biomes->get_biom(xIndex, index), field_size));
    };

public:
    int xIndex;

    vector<Field> column;

    Map_Column(int _xIndex, ushort *_render_dist, ushort *_field_size,
               Biomes *_biomes, vector<Map_Column> *_map, uint *_map_first_column)
        : xIndex(_xIndex), render_dist(_render_dist), field_size(_field_size),
          biomes(_biomes), map(_map), map_first_column(_map_first_column) {}

    void Draw(int player_x, int player_y, ushort &animation_frame)
    {
        int player_y_field = floor(player_y / float(*field_size));
        for (short i = -*render_dist; i <= *render_dist; i++)
        {
            int ind = Get_index(player_y_field + i);
            if (ind != -1)
            {
                column[ind].Draw(player_x, player_y, animation_frame);
            }
        };
    };

    void Update(int &player_x, int &player_y)
    {
        int player_y_field = floor(player_y / float(*field_size));
        auto static_render_dist = *render_dist;
        for (int i = -static_render_dist; i <= static_render_dist; i++)
        {
            if (!Found_In_Column(i + player_y_field))
            {
                Insert_New_Field(i + player_y_field);
            };
        };
    };

    int Get_index(int index)
    {
        for (auto &col : column)
        {
            if (col.yIndex == index)
            {
                return &col - &column[0];
            }
        }

        return -1;
    };
};
