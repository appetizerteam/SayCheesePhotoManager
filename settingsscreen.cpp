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

#include "settingsscreen.h"
#include "bundle.h"

#include <QFileDialog>
#include <QStandardPaths>

SayCheesePhotoManager::SettingsScreen::SettingsScreen(Bundle *bundle, MainWindow *mainWindow)
    : SettingsScreenView(bundle, mainWindow)
{
    this->settings = new Settings(this);

    this->connect(this->backButton, &QPushButton::pressed, this, &SettingsScreen::handleBackButtonPressed);
    this->connect(this->selectPhotoDirectoryPath, &QPushButton::pressed, this, &SettingsScreen::handleSelectPhotoDirectoryButtonPressed);

    // Set the saved value for the photo directory path.
    bool ok = false;
    this->photoDirectoryPath->setText(this->settings->getPhotosDirectory(ok));
    if (!ok) {
        //TODO: Ask the user to select a proper path.
    }
}

void SayCheesePhotoManager::SettingsScreen::handleBackButtonPressed() {
    this->mainWindow->loadPreviousScreen();
}

void SayCheesePhotoManager::SettingsScreen::handleSelectPhotoDirectoryButtonPressed() {

    auto directoryName = QFileDialog::getExistingDirectory(this,
                                                           tr("Select New Photo Directory"),
                                                           QStandardPaths::writableLocation(QStandardPaths::HomeLocation),
                                                           QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    // If the chosen directory is blank (none chosen) or does not exist, then silently exit.
    QDir dir(directoryName);
    if (directoryName.isEmpty() || !dir.exists()) {
        return;
    }

    // Set the new path and save it in the settings.
    this->photoDirectoryPath->setText(directoryName);
    settings->savePhotosDirectory(directoryName);
}
