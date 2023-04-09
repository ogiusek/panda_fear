class Map
{
public:
    ushort
        *field_size,
        *render_dist,
        *chunk_size;

    uint first_column = 0;

    vector<Map_Column> map;

    Map(ushort *_field_size, ushort *_chunk_size, ushort *_render_dist)
    {
        field_size = _field_size;
        render_dist = _render_dist;
        chunk_size = _chunk_size;
        map.push_back(New_map_column(0));
        Update(0, 0);
    };

    void Draw(int player_x, int player_y, ushort *animation_frame)
    {
        int player_x_chunk = floor(player_x / float(*field_size * *chunk_size));
        for (short i = -*render_dist; i <= *render_dist; i++)
        {
            map[player_x_chunk + first_column + i].Draw(player_x, player_y, animation_frame);
        };
    };

    void Update(int player_x, int player_y)
    {
        int player_x_chunk = floor(player_x / float(*field_size * *chunk_size));
        while (int(player_x_chunk - *render_dist) <= int(-first_column))
        {
            first_column++;
            map.insert(map.begin(), New_map_column(-first_column));
        };

        while (int(player_x_chunk + *render_dist) >= int(map.size() - first_column))
        {
            map.push_back(New_map_column(map.size() - first_column));
        };

        for (short i = -*render_dist; i <= *render_dist; i++)
        {

            map[int(player_x_chunk + first_column + i)].Update(player_x, player_y);
        };
    };

private:
    Map_Column New_map_column(int xIndex)
    {
        return Map_Column(xIndex, render_dist, field_size, chunk_size);
    };
};