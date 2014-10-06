/*
 * Copyright 2014 Team APPetizer
 * Author: Jesse Alas
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>
#include <QStandardPaths>

namespace SayCheesePhotoManager {

/*
 * Represents the settings for the Say Cheese photo manager application.
 * It abstracts the usage and configuration of the "QSettings" class.
 * Only the settings programmed in this class can be saved and loaded.
 * NOTE: No support for storing raw values is planned or needed.
 */
class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent = 0);

    // Returns the absolute path of the directory used to store the
    // transferred photos. If no path is stored, then the default path will be
    // returned. If no standard photo directory exists and there is no saved
    // photo directory, then a blank string will be returned and "ok" will be
    // set to false.
    QString getPhotosDirectory(bool& ok) const;

    // Saves the absolute path of the directory used for storing the
    // transferred photos. If the directory does not exist, then the
    // given directory will not be saved and an error message will be
    // printed to the console.
    void savePhotosDirectory(const QString& photoDirectoryPath);

private:
    // The constant key for getting and setting the Photo directory path.
    static constexpr auto PhotosDirectoryKey = "PhotosDirectory";

    QSettings *settings;
};

}

#endif // SETTINGS_H
