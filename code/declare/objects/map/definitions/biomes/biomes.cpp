class Biomes
{
private:
    int first_column = 0;
    vector<Biom_Column *> biomes_map;

public:
    Biomes(){};

    ushort get_biom(int xPos, int yPos)
    {
        while (xPos + first_column < 0)
        {
            first_column += 1;
            biomes_map.insert(biomes_map.begin(), new Biom_Column((-first_column), &biomes_map, &first_column));
        }
        while (xPos + first_column > biomes_map.size())
        {
            biomes_map.push_back(new Biom_Column((biomes_map.size() - first_column), &biomes_map, &first_column));
        }
        return biomes_map[first_column + xPos]->get_biom(yPos);
    };
};