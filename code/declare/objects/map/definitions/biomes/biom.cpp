class Biom
{
public:
    int xPos;
    int yPos;
    ushort value;
    Biom(int _xPos, int _yPos, ushort _value)
        : xPos(_xPos), yPos(_yPos), value(_value){};
};

//
//
//
//
//
//
//
//
//

int Get_rand_biom(vector<int> exceptions = {})
{
    // return rand() % biomes_list.size();
    vector<int> available_bioms;
    for (int i = 0; i < biomes_list.size(); i++)
    {
        bool found = false;
        for (auto j = 0; j < exceptions.size(); j++)
        {
            if (i == exceptions[j])
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            available_bioms.push_back(i);
        }
    }
    // cout << biomes_list[available_bioms[rand() % available_bioms.size()]] << endl;
    return available_bioms[rand() % available_bioms.size()];
};
