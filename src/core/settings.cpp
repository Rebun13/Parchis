#include "settings.h"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/writer.h"
#include <iostream>
#include <fstream>

void Settings::loadSettings()
{
    FILE *fp = fopen("resources/config/settings.json", "r");

    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    rapidjson::Document d;
    d.ParseStream(is);
    fclose(fp);

    config.generalVolume = d[GENERAL_VOLUME].GetUint();
    config.musicVolume = d[MUSIC_VOLUME].GetUint();
    config.fxVolume = d[FX_VOLUME].GetUint();
}

void Settings::writeSettings(Setting key, unsigned int value)
{
    FILE *fp = fopen("resources/config/settings.json", "rb"); // non-Windows use "r"
    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    rapidjson::Document d;
    d.ParseStream(is);
    fclose(fp);

    rapidjson::Value &s = d[key];
    s.SetUint(value);

    // Write JSON file
    FILE *fp2 = fopen("resources/config/settings.json", "wb"); // non-Windows use "w"
    char writeBuffer[65536];
    rapidjson::FileWriteStream os(fp2, writeBuffer, sizeof(writeBuffer));
    rapidjson::Writer<rapidjson::FileWriteStream> writer(os);
    d.Accept(writer);
    fclose(fp2);
}

void Settings::setSetting(Setting key, unsigned int value)
{
    switch (key)
    {
    case GENERAL_VOLUME:
        config.generalVolume = value;
        break;
    case MUSIC_VOLUME:
        config.musicVolume = value;
        break;
    case FX_VOLUME:
        config.fxVolume = value;
        break;
    default:
        return;
    }
    writeSettings(GENERAL_VOLUME, value);
}

unsigned int Settings::getSetting(Setting key)
{
    switch (key)
    {
    case GENERAL_VOLUME:
        return config.generalVolume;
    case MUSIC_VOLUME:
        return config.musicVolume;
    case FX_VOLUME:
        return config.fxVolume;
    default:
        return 0;
        break;
    }
}
