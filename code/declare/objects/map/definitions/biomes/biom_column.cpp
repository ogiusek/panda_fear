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
        int left = 0;
        int right = column.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (column[mid].yPos == yPos)
                return mid;
            else if (column[mid].yPos < yPos)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    void update_biom_map_width(ushort width)
    {
        while (xPos + (*first_column) - width < 1)
        {
            *first_column += 1;
            biomes_map->insert(biomes_map->begin(), new Biom_Column(-*first_column, biomes_map, first_column));
        }
        while (xPos + *first_column + width >= biomes_map->size() - 1)
        {
            biomes_map->push_back(new Biom_Column(biomes_map->size() - *first_column, biomes_map, first_column));
        }
    }

    void generate_biom(int yPos)
    {
        const ushort width = (rand() % 100) + 40;
        const ushort height = (rand() % 100) + 40;
        const ushort value = rand() % biomes_list.size();

        update_biom_map_width(width);

        biomes_map->at(xPos + *first_column)->set_biom(yPos, value);
        for (auto x = -width; x <= width; x++)
        {
            for (auto y = -height; y <= height; y++)
            {
                if (x == 0 && y == 0)
                {
                    biomes_map->at(x + xPos + *first_column)->set_biom(y + yPos, value);
                    continue;
                }
                const auto dist = sqrt((x * x) + (y * y));
                const float aspect = abs(x) + abs(y);
                const auto max_dist = (((abs(x)) / aspect) * width) + (((abs(y)) / aspect) * height);
                if (dist <= max_dist)
                {
                    biomes_map->at(x + xPos + *first_column)->set_biom(y + yPos, value);
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
        }

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
