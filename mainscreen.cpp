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

#include "mainscreen.h"
#include "saycheeseaction.h"
#include "screen.h"

SayCheesePhotoManager::MainScreen::MainScreen(Bundle *bundle, MainWindow *mainWindow)
    : MainScreenView(bundle, mainWindow)
{
    this->actionNavigationComboBox->addItem(tr("Transfer Photos"), SayCheeseAction::TRANSFER_PHOTOS);
    this->actionNavigationComboBox->addItem(tr("View Statistics"), SayCheeseAction::VIEW_STATISTICS);
    this->actionNavigationComboBox->addItem(tr("Change Settings"), SayCheeseAction::CHANGE_SETTINGS);

    this->connect(this->beginActionButton, &QPushButton::pressed, this, &MainScreen::handleBeginActionButtonPressed);
}

void SayCheesePhotoManager::MainScreen::handleBeginActionButtonPressed() {
    auto currentIndex = this->actionNavigationComboBox->currentIndex();
    switch (this->actionNavigationComboBox->itemData(currentIndex).toInt()) {

    case SayCheeseAction::TRANSFER_PHOTOS:
        this->mainWindow->loadScreen(Screen::SelectPhoneType);
        break;

    case SayCheeseAction::VIEW_STATISTICS:
        this->mainWindow->loadScreen(Screen::ViewStatistics);
        break;

    case SayCheeseAction::CHANGE_SETTINGS:
        this->mainWindow->loadScreen(Screen::Settings);
        break;
    }
}
