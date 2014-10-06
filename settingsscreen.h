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

#ifndef SETTINGSSCREEN_H
#define SETTINGSSCREEN_H

#include "settingsscreenview.h"
#include "mainwindow.h"
#include "settings.h"
#include "bundle.h"

namespace SayCheesePhotoManager {

/*
 * Represents the control logic for the "SettingsScreenView".
 */
class SettingsScreen : public SettingsScreenView
{
public:
    explicit SettingsScreen(Bundle *bundle, MainWindow *mainWindow);

private slots:
    // This slot is called when the back button is pressed.
    void handleBackButtonPressed();

    // This slot is called when the "select new photo directory" button
    // is pressed.
    void handleSelectPhotoDirectoryButtonPressed();

private:
    // Stores a pointer to a "SayCheesePhotoManager::Settings" instance.
    // This variable should be used to store and retrieve the settings for the
    // settings screen.
    Settings *settings;
};

}

#endif // SETTINGSSCREEN_H