class Chunk
{
public:
    ushort *field_size, *chunk_size;

    int xIndex, yIndex;

    vector<Chunk_Column> column;

    Chunk(int _xIndex, int _yIndex, ushort *_field_size, ushort *_chunk_size)
    {
        xIndex = _xIndex;
        yIndex = _yIndex;

        field_size = _field_size;
        chunk_size = _chunk_size;

        for (short x = 0; x < *chunk_size; x++)
        {
            column.push_back(Chunk_Column(xIndex * *chunk_size + x, yIndex * *chunk_size, x, field_size, chunk_size));
        };

        if (rand() % 3 != 0)
            return;
    };

    void Draw(int player_x, int player_y, ushort *animation_frame)
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