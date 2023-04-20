class Map_Column
{
public:
    ushort
        *field_size,
        *render_dist,
        *chunk_size;

    int xIndex;

    uint *map_first_column;
    vector<Map_Column> *map;
    Biomes *biomes;
    vector<Chunk> column;

    Map_Column(int _xIndex, ushort *_render_dist, ushort *_field_size, ushort *_chunk_size,
               Biomes *_biomes, vector<Map_Column> *_map, uint *_map_first_column)
        : xIndex(_xIndex), render_dist(_render_dist), field_size(_field_size), chunk_size(_chunk_size),
          biomes(_biomes), map(_map), map_first_column(_map_first_column) {}

    void Draw(int player_x, int player_y, ushort &animation_frame)
    {
        int player_y_chunk = floor(player_y / float(*field_size * *chunk_size));
        for (short i = -*render_dist; i <= *render_dist; i++)
        {
            int ind = Get_index(player_y_chunk + i);
            if (ind != -1)
            {
                column[ind].Draw(player_x, player_y, animation_frame);
            }
        };
    };

    void Update(int &player_x, int &player_y)
    {
        int player_y_chunk = floor(player_y / float(*field_size * *chunk_size));
        auto static_render_dist = *render_dist;
        for (int i = -static_render_dist; i <= static_render_dist; i++)
        {
            if (!Found_in_column(i + player_y_chunk))
            {
                Insert_new_chunk(i + player_y_chunk);
            };
        };
    };

    int Get_index(int index)
    {
        for (int i = 0; i < column.size(); i++)
        {
            if (column[i].yIndex == index)
            {
                return i;
            }
        };

        return -1;
    };

private:
    bool Found_in_column(int index)
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

    void Insert_new_chunk(int index)
    {
        auto insert_pos = column.begin();

        while (insert_pos != column.end() && insert_pos->xIndex < index)
        {
            insert_pos++;
        };

        column.insert(insert_pos, New_chunk(index));
    };

    Chunk New_chunk(int yIndex)
    {
        // return Chunk(xIndex, yIndex, field_size, chunk_size, (*biomes)(xIndex, yIndex));
        return Chunk(xIndex, yIndex, field_size, chunk_size, biomes->get_biom(xIndex, yIndex));
        // return Chunk(xIndex, yIndex, field_size, chunk_size, 0);
    };
};
