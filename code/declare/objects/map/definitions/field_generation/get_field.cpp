vector<string> field_images;

ushort get_field_image_index(string image)
{
    for (auto i = 0; i < field_images.size(); i++)
    {
        if (image == field_images[i])
        {
            return i;
        }
    }
    field_images.push_back(image);
    return field_images.size() - 1;
}

ushort get_field(int biom)
{
    switch (rand() % 20)
    {
    case 0:
        return get_field_image_index("img1/image9x2");
    case 1:
        return get_field_image_index("img1/image9x3");
    case 2:
        return get_field_image_index("img1/image10x2");
    case 3:
        return get_field_image_index("img1/image10x3");
    case 4:
        return get_field_image_index("img1/image11x2");
    case 5:
        return get_field_image_index("img1/image11x3");
    case 6:
        return get_field_image_index("img1/image11x4");
    case 7:
        return get_field_image_index("img1/image11x5");
    default:
        return get_field_image_index("img1/image8x7");
    };
};