
class Map_Column
{
public:
    ushort
        *field_size,
        *render_dist,
        *chunk_size;

    int xIndex;

    vector<vector<Chunk> *> neighbours;
    vector<Chunk> column;

    Map_Column(int _xIndex, ushort *_render_dist, ushort *_field_size, ushort *_chunk_size)
    {
        render_dist = _render_dist;
        field_size = _field_size;
        chunk_size = _chunk_size;
        xIndex = _xIndex;
    };

    void Draw(int player_x, int player_y, ushort *animation_frame)
    {
        int player_y_chunk = floor(player_y / float(*field_size * *chunk_size));
        for (short i = -*render_dist; i <= *render_dist; i++)
        {
            column[Get_index(player_y_chunk + i)].Draw(player_x, player_y, animation_frame);
        };
    };

    void Update(int player_x, int player_y)
    {
        int player_y_chunk = floor(player_y / float(*field_size * *chunk_size));
        int required_chunks_size = 2 * *render_dist + 1;
        int required_chunks[required_chunks_size];

        for (int i = -*render_dist; i <= *render_dist; i++)
        {
            required_chunks[i + *render_dist] = player_y_chunk - i;
        };
        for (int i = 0; i <= required_chunks_size; i++)
        {
            if (!Found_in_column(required_chunks[i]))
            {
                Insert_new_chunk(required_chunks[i]);
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

        return 0;
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

    Chunk New_chunk(int yIndex)
    {
        return Chunk(xIndex, yIndex, field_size, chunk_size);
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
};
