class Structure
{
private:
    class Assets
    {
    private:
        vector<string> assets_;

    public:
        Assets(initializer_list<string> asset_list) : assets_{}
        {
            for (const auto &asset : asset_list)
            {
                add(asset);
            }
        };

        Assets &operator=(const Assets &other)
        {
            if (this != &other)
            {
                assets_ = other.assets_;
            };
            return *this;
        };

        void add(const string &asset)
        {
            assets_.push_back(asset);
        };
        const vector<string> &get() const
        {
            return assets_;
        };
    };

public:
    ushort
        width,
        height;

    vector<vector<Assets>> images;

    // Structure(ushort _width, ushort _height, vector<vector<Assets>> _images)
    Structure(ushort _width, ushort _height)
    {
        width = _width;
        height = _height;
        Assets xx{"dessert/img8/8x8.png", "dessert/img8/8x9.png", "dessert/img8/8x10.png", "dessert/img8/8x11.png"};
        // Assets xx;
        // images = _images;
    };
};