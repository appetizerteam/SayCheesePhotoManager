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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "screenmanager.h"
#include "screen.h"
#include "transitiondirection.h"
#include "bundle.h"
#include "mainmenu.h"

#include <QMainWindow>
#include <QApplication>
#include <QDesktopWidget>
#include <QPair>
#include <QStack>

namespace SayCheesePhotoManager
{

/*
 * Represents the main window of the Say Cheese Photo Manager application.
 * Every "SayCheesePhotoManager::SayCheeseScreen" takes a reference to a
 * "SayCheesePhotoManager::MainWindow" instance, so "SayCheeseScreen"s have the
 * ability to load new screens and get information regarding the Say Cheese
 * Application by using this class. This class is also responsible for loading
 * and managing the currently visible screen.
 *
 * NOTE: All "Screen" enum values must be registered in this class' "screenToWidget(Screen)"
 * method. If a newly added "SayCheeseScreen" is not registered, the call to
 * "loadScreen(Screen)" is ignored and a debug message is printed to the console.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow() = default;

    // Begins loading the current screen given a "SayCheesePhotoManager::Screen" enum value.
    // The screen loading is not instant as a screen transition animation is shown.
    // Once the screen transition has finished and the new "SayCheeseScreen" is given focus,
    // the "screenLoaded()" signal will be emitted.
    void loadScreen(Screen screen);

    // Begins loading the previous screen. An internal "Screen" history stack is kept, so
    // this method may be called repeatedly to load any amount of previously loaded screens
    // assuming that they are in the history stack. After the screen transition animation is
    // finished and the previous "SayCheeseScreen" is given focus, the "screenLoaded()" signal
    // will be emitted.
    //
    // NOTE: "SayCheeseScreen" objects should use this method to implement a "back button".
    void loadPreviousScreen();

signals:
    // This signal is emitted after a call to "loadScreen(Screen)" or "loadPreviousScreen()".
    void screenLoaded();

private:
    // Holds a pointer to the screen manager.
    ScreenManager *screenManager;

    // Keeps track of the current screen enum value. It can be used by the main window to
    // show help information regarding the current screen.
    Screen currentScreen;

    // Keeps track of the next screen to load. The next screen is set after a call to
    // "loadScreen(Screen)" so that the current screen can be set to the next screen
    // after the screen transition animation finished and focus is given to the newly
    // loaded "SayCheeseScreen".
    Screen nextScreen;

    // Keeps track of the next transition direction. The next transition direction is
    // set after a call to "loadScreen(Screen)" so that it can be used if the
    // "loadPreviousScreen()" method is called. The "loadPreviousScreen()" method will
    // use this variable to figure out the opposite transition to use when loading the
    // previous screen. For example, if a screen was loaded with a transition moving to
    // the right of the screen. It is natural for a "back button" to result in a
    // transition movingin the the opposite direction (to the left).
    TransitionDirection nextTransitionDirection;

    // Keeps track of the "Screen"s that have been loaded. When the "loadPreviousScreen()"
    // method is called, a "Screen" enum value is popped from the stack and is loaded.
    // NOTE: This screen history stack should never contain "Screen" enum values that were
    // not loaded or were not registered. Meaning, one can assume that the screen history
    // stack always has valid loadable "Screen" enum values inside.
    QStack<Screen> screenHistoryStack;

    // Keeps track of the bundle that will be shared amongst all of the "SayCheeseScreen"
    // instances.
    Bundle *bundle;

    // Holds a pointer to the Say Cheese Photo Manager main menu.
    MainMenu *mainMenu;

private:
    // Returns the appropriate "SayCheeseScreen" instance given a "Screen" enum value.
    // It acts as a 1 to 1 mapping for "Screen" -> "SayCheeseScreen*".
    // IMPORTANT: All "SayCheeseScreen"s must be registered within this method.
    // If a "SayCheeseScreen" is not registered to it's corresponding "Screen" enum value
    // in this method, it will return a nullptr.
    QWidget* screenToScreenWidget(Screen screen);

private slots:
    void handleScreenLoaded();
};

}

#endif // MAINWINDOW_H
