class Map
{
public:
    ushort *field_size, *render_dist;
    uint first_column = 0;
    vector<Map_Column> map;
    // vector<vector<Field *> *> *field_map = new vector<vector<Field *> *>();
    Biomes biomes_map;

    Map(ushort *_field_size, ushort *_render_dist)
        : field_size(_field_size), render_dist(_render_dist)
    {
        map.push_back(New_map_column(0));
        // biomes_map.get_biom(-1, -1);
        Update(0, 0);
    }

    void Draw(int player_x, int player_y, ushort &animation_frame)
    {
        int player_x_field = floor(player_x / float(*field_size));
        int chunk_dist = *render_dist;
        for (short i = -chunk_dist; i <= chunk_dist; ++i)
        {
            auto it = map.begin() + player_x_field + first_column + i;
            it->Draw(player_x, player_y, animation_frame);
        }
    }

    void Update(int player_x, int player_y)
    {
        while ((*render_dist - 3) * *field_size < (WIDTH > HEIGHT ? WIDTH / 2 : HEIGHT / 2))
        {
            *render_dist += 1;
        }

        int player_x_field = floor(player_x / float(*field_size));
        int chunk_dist = *render_dist;
        while (int(player_x_field - chunk_dist) < int(-first_column))
        {
            ++first_column;
            map.insert(map.begin(), New_map_column(-first_column));
        }

        while (int(player_x_field + chunk_dist) >= int(map.size() - first_column))
        {
            map.push_back(New_map_column(map.size() - first_column));
        }

        for (short i = -chunk_dist; i <= chunk_dist; ++i)
        {
            auto it = map.begin() + player_x_field + first_column + i;
            // update_threads.push_back(thread(&Map_Column::Update, it, ref(player_x), ref(player_y)));
            // Map_Column->Update, it, ref(player_x), ref(player_y);
            it->Update(player_x, player_y);
        }
    }

private:
    Map_Column New_map_column(int xIndex)
    {
        return Map_Column(xIndex, render_dist, field_size, &biomes_map, &map, &first_column);
    }
};