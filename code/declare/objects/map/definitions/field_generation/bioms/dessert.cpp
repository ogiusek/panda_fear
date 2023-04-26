string get_dessert_field()
{
    switch (rand() % 20)
    {
    case 0:
        return "img1/image9x2";
    case 1:
        return "img1/image9x3";
    case 2:
        return "img1/image10x2";
    case 3:
        return "img1/image10x3";
    case 4:
        return "img1/image11x2";
    case 5:
        return "img1/image11x3";
    case 6:
        return "img1/image11x4";
    case 7:
        return "img1/image11x5";
    default:
        return "img1/image8x7";
    }
};