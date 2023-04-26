class Biom
{
public:
    int xPos;
    int yPos;
    ushort value = -1;
    Biom(int _xPos, int _yPos, ushort _value)
        : xPos(_xPos), yPos(_yPos), value(_value){};
};