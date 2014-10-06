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

#include "settings.h"

#include <QDebug>
#include <QDir>

SayCheesePhotoManager::Settings::Settings(QObject *parent) :
    QObject(parent)
{
    this->settings = new QSettings(this);
}

QString SayCheesePhotoManager::Settings::getPhotosDirectory(bool& ok) const {
    // Load the standard photo directory.
    QString defaultPhotosDirectory = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);

    // Load the saved photo directory.
    auto photoDirectory = this->settings->value(PhotosDirectoryKey, defaultPhotosDirectory).toString();

    // If no default photo directory exists (is empty) and there is no saved photo directory,
    // then this method cannot return an proper value. Return a blank line and set ok to false.
    if (defaultPhotosDirectory.isEmpty()) {
        qDebug() << "SayCheesePhotoManager::Settings(Could not find suitable photos directory)";
        ok = false; // Flags the error.
        return "";
    }

    ok = true; // Flags that the method found a suitable directory.
    return photoDirectory;
}

void SayCheesePhotoManager::Settings::savePhotosDirectory(const QString &photoDirectoryPath) {
    // Check if the directory exists. If it does not, then print an error to the console and return.
    QDir photosDir(photoDirectoryPath);
    if (!photosDir.exists()) {
        qDebug() << "SayCheesePhotoManager::Settings(Cannot save invalid photo directory:" << photoDirectoryPath << ")";
        return;
    }

    this->settings->setValue(PhotosDirectoryKey, photosDir.absolutePath());
}
