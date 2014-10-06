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

#include "selectphonetypescreen.h"
#include "bundle.h"

SayCheesePhotoManager::SelectPhoneTypeScreen::SelectPhoneTypeScreen(Bundle *bundle, MainWindow *mainWindow)
    : SelectPhoneTypeScreenView(bundle, mainWindow)
{
    this->connect(this->backButton, &QPushButton::pressed, this, &SelectPhoneTypeScreen::handleBackButtonPressed);
    this->connect(this->iphoneButton, &QPushButton::pressed, this, &SelectPhoneTypeScreen::handleIphoneButtonPressed);
    this->connect(this->androidButton, &QPushButton::pressed, this, &SelectPhoneTypeScreen::handleAndroidButtonPressed);
}

void SayCheesePhotoManager::SelectPhoneTypeScreen::handleBackButtonPressed() {
    this->mainWindow->loadPreviousScreen();
}

void SayCheesePhotoManager::SelectPhoneTypeScreen::handleAndroidButtonPressed() {
    this->mainWindow->loadScreen(Screen::SelectConnectionType);
}

void SayCheesePhotoManager::SelectPhoneTypeScreen::handleIphoneButtonPressed() {
    this->mainWindow->loadScreen(Screen::ServerConfiguration);
}
