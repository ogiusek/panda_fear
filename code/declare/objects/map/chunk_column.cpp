class Chunk_Column
{
public:
    ushort *field_size, *chunk_size,
        xChunkIndex;

    int xFieldIndex,
        yFieldIndex;

    int biom;

    vector<Field> column;

    Chunk_Column(int _xFieldIndex, int _yFieldIndex, ushort _xChunkIndex, int _biom, ushort *_field_size, ushort *_chunk_size)
        : xFieldIndex(_xFieldIndex), yFieldIndex(_yFieldIndex), xChunkIndex(_xChunkIndex), biom(_biom), field_size(_field_size), chunk_size(_chunk_size)
    {
        for (int i = 0; i < *chunk_size; i++)
        {
            column.push_back(Field(xFieldIndex, yFieldIndex + i, xChunkIndex, i, biom, field_size));
        };
    };

    void Draw(int &player_x, int &player_y, ushort &animation_frame)
    {
        for (short y = 0; y < *chunk_size; y++)
        {
            column[y].Draw(player_x, player_y, animation_frame);
        };
    };

    void Update(int player_x, int player_y)
    {
        for (short y = 0; y < *chunk_size; y++)
        {
            column[y].Update(player_x, player_y);
        };
    };
};