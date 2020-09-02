//////////////////////////////////////////////////////////////////////////////////////
//    akashi - a server for Attorney Online 2                                       //
//    Copyright (C) 2020  scatterflower                                             //
//                                                                                  //
//    This program is free software: you can redistribute it and/or modify          //
//    it under the terms of the GNU Affero General Public License as                //
//    published by the Free Software Foundation, either version 3 of the            //
//    License, or (at your option) any later version.                               //
//                                                                                  //
//    This program is distributed in the hope that it will be useful,               //
//    but WITHOUT ANY WARRANTY; without even the implied warranty of                //
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                 //
//    GNU Affero General Public License for more details.                           //
//                                                                                  //
//    You should have received a copy of the GNU Affero General Public License      //
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.        //
//////////////////////////////////////////////////////////////////////////////////////
#include "include/config_manager.h"

ConfigManager::ConfigManager()
{
    config = new QSettings("config.ini", QSettings::IniFormat);
}

// Validate and set up the config
bool ConfigManager::initConfig()
{
    QFileInfo char_list_info("characters.txt");
    if (!(char_list_info.exists() && char_list_info.isFile())) {
        // TODO: signals go here
        QFile char_list("characters.txt");
        if (!char_list.open(QIODevice::WriteOnly | QIODevice::Text))
            qDebug() << "Couldn't create character list";
        QTextStream file_stream(&char_list);

        qDebug() << "Creating vanilla character list";

        file_stream << "Adrian\n";
        file_stream << "Apollo\n";
        file_stream << "April\n";
        file_stream << "Armstrong\n";
        file_stream << "Atmey\n";
        file_stream << "Butz\n";
        file_stream << "Diego\n";
        file_stream << "Edgeworth\n";
        file_stream << "Edgeworthw\n";
        file_stream << "Ema\n";
        file_stream << "EmaSkye\n";
        file_stream << "Franny\n";
        file_stream << "Franziska\n";
        file_stream << "Gant\n";
        file_stream << "Gavin\n";
        file_stream << "Gavin K\n";
        file_stream << "Godot\n";
        file_stream << "Gregory\n";
        file_stream << "Grossberg\n";
        file_stream << "Gumshoe\n";
        file_stream << "Gumshoey\n";
        file_stream << "Hawk\n";
        file_stream << "Hobo_Phoenix\n";
        file_stream << "Ini\n";
        file_stream << "Judge\n";
        file_stream << "Judge's Bro\n";
        file_stream << "Klav\n";
        file_stream << "Klavier\n";
        file_stream << "Kristoph\n";
        file_stream << "Lana\n";
        file_stream << "Layton\n";
        file_stream << "Lotta\n";
        file_stream << "Luis\n";
        file_stream << "Maggey\n";
        file_stream << "Manfred\n";
        file_stream << "Marshall\n";
        file_stream << "Matt\n";
        file_stream << "Maya\n";
        file_stream << "Mia\n";
        file_stream << "Miles\n";
        file_stream << "Oldbag\n";
        file_stream << "Payne\n";
        file_stream << "Pearl\n";
        file_stream << "Phoenix\n";
        file_stream << "Valant\n";
        file_stream << "Vasquez\n";
        file_stream << "Wellington\n";
        file_stream << "Winston\n";
        file_stream << "WinstonPayne\n";
        file_stream << "Young Mia\n";
        file_stream << "Zak\n";

        char_list.flush();
        char_list.close();
    }

    QFileInfo music_list_info("music.txt");
    if (!(music_list_info.exists() && music_list_info.isFile())) {
        QFile music_list("music.txt");
        if (!music_list.open(QIODevice::WriteOnly | QIODevice::Text))
            qDebug() << "Couldn't create music list";
        QTextStream file_stream(&music_list);

        qDebug() << "Creating vanilla music list";

        file_stream << "Announce The Truth (AA).opus\n";
        file_stream << "Announce The Truth (AJ).opus\n";
        file_stream << "Announce The Truth (JFA).opus\n";
        file_stream << "Announce The Truth (Miles).opus\n";
        file_stream << "Announce The Truth (T&T).opus\n";
        file_stream << "Confrontation ~ Presto 2009.opus\n";
        file_stream << "Crises of Fate.opus\n";
        file_stream << "Forgotten Legend.opus\n";
        file_stream << "Godot - The Fragrance of Dark Coffee.opus\n";
        file_stream << "Great Revival ~ Franziska von Karma.opus\n";
        file_stream << "Great Revival ~ Miles Edgeworth.opus\n";
        file_stream << "Hotline of Fate.opus\n";
        file_stream << "Interesting People.opus\n";
        file_stream << "Logic and Trick.opus\n";
        file_stream << "Luke Atmey ~ I Just Want Love.opus\n";
        file_stream << "Noisy People.opus\n";
        file_stream << "OBJECTION (AA).opus\n";
        file_stream << "Objection (AJ).opus\n";
        file_stream << "OBJECTION (JFA).opus\n";
        file_stream << "Objection (Miles).opus\n";
        file_stream << "OBJECTION (T&T).opus\n";
        file_stream << "Others ~ Guilty love.opus\n";
        file_stream << "Prelude (AA).opus\n";
        file_stream << "Prelude (AJ).opus\n";
        file_stream << "Prologue (AA).opus\n";
        file_stream << "Pursuit (AA) - variation.opus\n";
        file_stream << "Pursuit (AA).opus\n";
        file_stream << "Pursuit (AJ).opus\n";
        file_stream << "Pursuit (DS).opus\n";
        file_stream << "Pursuit (JFA) - variation.opus\n";
        file_stream << "Pursuit (JFA).opus\n";
        file_stream << "Pursuit (Miles).opus\n";
        file_stream << "Pursuit (T&T) - variation.opus\n";
        file_stream << "Pursuit (T&T).opus\n";
        file_stream << "Pursuit ~ I Want to Find the Truth (Orchestra).opus\n";
        file_stream << "Questioning AA (Allegro).opus\n";
        file_stream << "Questioning AA (Moderato).opus\n";
        file_stream << "Questioning AJ (Allegro).opus\n";
        file_stream << "Questioning AJ (Moderato).opus\n";
        file_stream << "Questioning JFA (Allegro).opus\n";
        file_stream << "Questioning JFA (Moderato).opus\n";
        file_stream << "Questioning T&T (Allegro).opus\n";
        file_stream << "Questioning T&T (Moderato).opus\n";
        file_stream << "Speak up Pup.opus\n";
        file_stream << "Suspense (AA).opus\n";
        file_stream << "The Great Truth Burglar.opus\n";
        file_stream << "Trial (AA).opus\n";
        file_stream << "Trial (AJ).opus\n";
        file_stream << "Trial (Miles).opus\n";

        music_list.flush();
        music_list.close();
    }

    config->beginGroup("Info");
    QString config_version = config->value("version", "none").toString();
    config->endGroup();
    if (config_version == "none") {
        QFileInfo check_file("config.ini");
        // TODO: put proper translatable warnings here
        if (!(check_file.exists() && check_file.isFile())) {
            // TODO: send signal config doesn't exist
            generateDefaultConfig(false);
        }
        else {
            // TODO: send signal config is invalid
            generateDefaultConfig(true);
        }
        return false;
    }
    else if (config_version != QString::number(CONFIG_VERSION)) {
        bool version_number_is_valid;
        int current_version = config_version.toInt(&version_number_is_valid);
        if (version_number_is_valid)
            updateConfig(current_version);
        else
            generateDefaultConfig(true); // Version number isn't a number at all
                                         // This means the config is invalid
                                         // TODO: send invalid config signal
        return false;
    }
    else {
        // Config is valid and up to date, so let's go ahead
        return true;
    }
}

// Setting backup_old to true will move the existing config.ini to
// config_old.ini
void ConfigManager::generateDefaultConfig(bool backup_old)
{
    qDebug() << "Config is invalid or missing, making a new one...";
    QDir dir = QDir::current();
    if (backup_old) {
        // TODO: failsafe if config_old.ini already exists
        dir.rename("config.ini", "config_old.ini");
    }

    // Group: Info
    // This contains basic metadata about the config
    config->beginGroup("Info");
    config->setValue("version", CONFIG_VERSION);
    config->endGroup();

    // Group: Options
    // This contains general configuration
    config->beginGroup("Options");
    config->setValue("hostname", "$H");
    config->setValue("max_players", "100");
    config->setValue("port", "27016");
    config->setValue("webao_enable", "true");
    config->setValue("webao_port", "27017");
    config->setValue("modpass", "password");
    config->setValue("advertise", "true");
    config->setValue("ms_ip", "master.aceattorneyonline.com");
    config->setValue("ms_port", "27016");
    config->setValue("server_name", "My First Server");
    config->setValue("server_description", "This is my flashy new server");
    config->setValue("multiclient_limit", "16");
    config->setValue("max_message_size", "256");
    config->endGroup();
}

// Ensure version continuity with config versions
void ConfigManager::updateConfig(int current_version)
{
    if (current_version > CONFIG_VERSION) {
        // Config version is newer than the latest version, and the config is
        // invalid This could also mean the server is out of date, and the user
        // should be shown a relevant message Regardless, regen the config
        // anyways
        // TODO: send signal config is invalid
        generateDefaultConfig(true);
    }
    else if (current_version < 0) {
        // Negative version number? Invalid!
        generateDefaultConfig(true);
    }
    else {
        // TODO: send signal config is out of date, and is being updated
        // Update the config as needed using a switch. This is nice because we
        // can fall through as we go up the version ladder.
        switch (current_version) {
        case 0: // Version 0 doesn't actually exist, but we should check for it
                // just in case
        case 1:
            config->beginGroup("Info");
            config->setValue("version", CONFIG_VERSION);
            config->endGroup();
            break; // This is the newest version, and nothing more needs to be
                   // done
        }
    }
}

// Validate and retriever settings related to advertising and the server
bool ConfigManager::loadServerSettings(server_settings* settings)
{
    bool port_conversion_success;
    bool ws_port_conversion_success;
    bool local_port_conversion_success;
    config->beginGroup("Options");
    settings->ms_ip =
        config->value("ms_ip", "master.aceattorneyonline.com").toString();
    settings->port =
        config->value("port", "27016").toInt(&port_conversion_success);
    settings->ws_port =
        config->value("webao_port", "27017").toInt(&ws_port_conversion_success);
    settings->local_port =
        config->value("port", "27016").toInt(&local_port_conversion_success);
    settings->name = config->value("server_name", "My First Server").toString();
    settings->description =
        config->value("server_description", "This is my flashy new server")
            .toString();
    config->endGroup();
    if (!port_conversion_success || !ws_port_conversion_success ||
        !local_port_conversion_success) {
        return false;
    }
    else {
        config->beginGroup("Options");
        // Will be true of false depending on the key
        settings->advertise_server =
            (config->value("advertise", "true").toString() == "true");

        if (config->value("webao_enable", "true").toString() != "true")
            settings->ws_port = -1;
        config->endGroup();

        return true;
    }
}
