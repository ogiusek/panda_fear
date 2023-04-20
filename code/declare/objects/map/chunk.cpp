class Chunk
{
public:
    ushort *field_size, *chunk_size,
        biom, bottom_biom, left_biom;

    int xIndex, yIndex;

    vector<Chunk_Column> column;

    Chunk(int _xIndex, int _yIndex, ushort *_field_size, ushort *_chunk_size, ushort _biom)
        : xIndex(_xIndex), yIndex(_yIndex), field_size(_field_size), chunk_size(_chunk_size), biom(_biom)
    {
        for (short x = 0; x < *chunk_size; x++)
        {
            column.push_back(Chunk_Column(xIndex * *chunk_size + x, yIndex * *chunk_size, x, biom, field_size, chunk_size));
        };
    };

    void Draw(int &player_x, int &player_y, ushort &animation_frame)
    {
        for (short x = 0; x < *chunk_size; x++)
        {
            column[x].Draw(player_x, player_y, animation_frame);
        };
    };

    void Update(int player_x, int player_y)
    {
        for (short x = 0; x < *chunk_size; x++)
        {
            column[x].Update(player_x, player_y);
        };
    };
};