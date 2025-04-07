enum Setting {
    GENERAL_VOLUME,
    MUSIC_VOLUME,
    FX_VOLUME
};

struct Config
{
    unsigned int generalVolume;
    unsigned int musicVolume;
    unsigned int fxVolume;
};

class Settings
{
public:
    static void loadSettings();
    static unsigned int getSetting(Setting key);
    static void setSetting(Setting key, unsigned int value);

private:
    inline static Config config;
    static void writeSettings(Setting key, unsigned int value);
};
