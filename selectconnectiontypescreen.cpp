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

#include "selectconnectiontypescreen.h"
#include "bundle.h"

SayCheesePhotoManager::SelectConnectionTypeScreen::SelectConnectionTypeScreen(Bundle *bundle, MainWindow *mainWindow)
    : SelectConnectionTypeScreenView(bundle, mainWindow)
{
    this->connect(this->backButton, &QPushButton::pressed, this, &SelectConnectionTypeScreen::handleBackButtonPressed);
    this->connect(this->wifiButton, &QPushButton::pressed, this, &SelectConnectionTypeScreen::handleWifiButtonPressed);
}

void SayCheesePhotoManager::SelectConnectionTypeScreen::handleUsbButtonPressed() {
}

void SayCheesePhotoManager::SelectConnectionTypeScreen::handleWifiButtonPressed() {
    this->mainWindow->loadScreen(Screen::ServerConfiguration);
}

void SayCheesePhotoManager::SelectConnectionTypeScreen::handleBackButtonPressed() {
    this->mainWindow->loadPreviousScreen();
}
