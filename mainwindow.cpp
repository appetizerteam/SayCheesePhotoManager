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

#include "mainwindow.h"

#include "transitiondirection.h"
#include "mainscreen.h"
#include "settingsscreen.h"
#include "serverconfigurationscreen.h"
#include "selectphonetypescreen.h"
#include "selectconnectiontypescreen.h"
#include "statisticsscreen.h"
#include "phototransferscreen.h"
#include "aboutdialog.h"

#include <QMessageBox>
#include <QDebug>

SayCheesePhotoManager::MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->bundle = new Bundle(this);
    this->setMinimumSize(QSize(640, 480));

    // Center the window on the user's scren.
    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
    this->setWindowTitle(tr("SayCheese Photo Manager"));
    this->screenManager = new ScreenManager(new MainScreen(this->bundle, this), this);
    this->currentScreen = Screen::Main;
    this->screenManager->setContentsMargins(0, 0, 0, 0);
    this->setCentralWidget(screenManager);

    this->mainMenu = new MainMenu(this);
    this->setMenuBar(this->mainMenu);

    this->connect(this->screenManager, &ScreenManager::screenLoaded, this, &MainWindow::handleScreenLoaded);
    this->connect(this->mainMenu, &MainMenu::aboutActionTriggered, this, [this]() {
        auto aboutDialog = new AboutDialog(this);
        aboutDialog->setModal(true);
        aboutDialog->show();
    });
}

void SayCheesePhotoManager::MainWindow::loadScreen(Screen screen) {
    auto screenWidget = this->screenToScreenWidget(screen);

    // Do not contine loading the screen if the given "Screen" was not registered and
    // an instance of it's corresponding "SayCheeseScreen" could not be created.
    if (screenWidget == nullptr) {
        qDebug() << "MainWindow(Cannot load unknown screen. Please register all Screens.)";
        return;
    }

    // Save the current screen in the history stack. Since we are prematurely returning
    // above if the "Screen" was not registered and could not be loaded, from here on out
    // we can assume that the screen history stack will only contain valid screens that
    // were actually loaded.
    this->screenHistoryStack.push(this->currentScreen);
    this->nextScreen = screen;

    // Figure out the appropriate transition direction for this "Screen".
    // By default all screen transition directions will be going to the left
    // and only special cases need to be programmed below.
    TransitionDirection transition = TransitionDirection::Left;
    if (screen == Screen::Settings) {
        transition = TransitionDirection::Down;
    }

    this->nextTransitionDirection = transition;

    this->screenManager->loadScreen(screenWidget, transition);
}

void SayCheesePhotoManager::MainWindow::loadPreviousScreen() {
    TransitionDirection transition;

    // Figure out the opposite transition direction given the last
    // transition direction used. Since we are loading the previous
    // screen, it is natural to use the opposite direction used when
    // transitioning to the previous screen.
    switch (this->nextTransitionDirection) {
    case TransitionDirection::Up:
        transition = TransitionDirection::Down;
        break;

    case TransitionDirection::Down:
        transition = TransitionDirection::Up;
        break;

    case TransitionDirection::Left:
        transition = TransitionDirection::Right;
        break;

    case TransitionDirection::Right:
        transition = TransitionDirection::Left;
        break;
    }

    this->nextScreen = this->screenHistoryStack.top();
    QWidget* screenWidget = this->screenToScreenWidget(this->screenHistoryStack.pop());

    // Being pedantic. The code below should not run. It will only run if the screen
    // history stack contains a "Screen" that was not registered and thus never loaded.
    // Make sure that the "loadScreen(Screen)" method checks that each "Screen" given
    // to it is valid and loadable before pushing it onto the screen history stack.
    if (screenWidget == nullptr) {
        auto errorMessage = "MainWindow(Critical Error. This should not have occurred."
                "Make sure that the screen history stack only contains Screens that "
                "were successfully loaded)";
        qDebug() << errorMessage;
        return;
    }

    this->screenManager->loadScreen(screenWidget, transition);
}

QWidget* SayCheesePhotoManager::MainWindow::screenToScreenWidget(Screen screen) {
    // Figure out which screen to load given a "Screen".
    QWidget *screenWidget = nullptr;
    switch (screen) {
    case Screen::Main:
        screenWidget = new MainScreen(this->bundle, this);
        break;

    case Screen::SelectConnectionType:
        screenWidget = new SelectConnectionTypeScreen(this->bundle, this);
        break;

    case Screen::SelectPhoneType:
        screenWidget = new SelectPhoneTypeScreen(this->bundle, this);
        break;

    case Screen::ServerConfiguration:
        screenWidget = new ServerConfigurationScreen(this->bundle, this);
        break;

    case Screen::Settings:
        screenWidget = new SettingsScreen(this->bundle, this);
        break;

    case Screen::TransferPhotos:
        screenWidget = new PhotoTransferScreen(this->bundle, this);
        break;

    case Screen::ViewStatistics:
        screenWidget = new StatisticsScreen(this->bundle, this);
        break;
    }

    return screenWidget;
}

void SayCheesePhotoManager::MainWindow::handleScreenLoaded() {
    this->currentScreen = this->nextScreen;
    emit this->screenLoaded();
}
