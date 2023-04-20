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

string get_field(int biom)
{
    return "img1/image9x2";
};