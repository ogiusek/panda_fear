class Biom_Column
{
private:
    int xPos, *first_column;
    vector<Biom_Column *> *biomes_map;
    vector<Biom> column;

    bool Found_biom(int yPos)
    {
        int left = 0;
        int right = column.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (column[mid].yPos == yPos)
                return true;
            else if (column[mid].yPos < yPos)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }

    uint get_index(int yPos)
    {
        for (uint i = 0; i < column.size(); i++)
        {
            if (column[i].yPos == yPos)
                return i;
        }
        return -1;
    }

    void update_biom_map_width(ushort width)
    {
        while (xPos + (*first_column) - width < 0)
        {
            *first_column += 1;
            biomes_map->insert(biomes_map->begin(), new Biom_Column(-*first_column, biomes_map, first_column));
        }
        while (xPos + *first_column + width > biomes_map->size())
        {
            biomes_map->push_back(new Biom_Column(biomes_map->size() - *first_column, biomes_map, first_column));
        }
    }

    void generate_biom(int yPos)
    {
        ushort width = (rand() % 16) + 7,
               height = (rand() % 18) + 6,
               value = rand() % biomes_list.size();

        short verctical_movement = rand() % 5 - 2,
              horizontal_movement = rand() % 5 - 2;

        update_biom_map_width(width);

        for (auto i = -width; i < width; i++)
        {
            for (auto j = -height; j < height; j++)
            {
                auto abs_i = -abs(i + verctical_movement);
                auto abs_j = -abs(j + horizontal_movement);
                auto bigger_value = width;
                if (bigger_value < height)
                {
                    bigger_value = height;
                }
                if ((abs_i + abs_j) >= ((-width) - height + bigger_value))
                {
                    biomes_map->at(i + xPos + *first_column)->set_biom(j + yPos, value);
                }
            }
        }
    }

public:
    Biom_Column(int _xPos, vector<Biom_Column *> *_biomes_map, int *_first_column)
        : xPos(_xPos), biomes_map(_biomes_map), first_column(_first_column){};

    void set_biom(int index, ushort value)
    {
        if (Found_biom(index))
        {
            return;
        }
        auto insert_pos = column.begin();
        while (insert_pos != column.end() && insert_pos->yPos < index)
        {
            insert_pos += 1;
        };
        column.insert(insert_pos, Biom(xPos, index, value));
    };

    ushort get_biom(int yPos)
    {
        if (!Found_biom(yPos))
        {
            generate_biom(yPos);
        }
        return column[get_index(yPos)].value;
    };
};