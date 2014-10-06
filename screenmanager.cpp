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

#include "screenmanager.h"

#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QPoint>

SayCheesePhotoManager::ScreenManager::ScreenManager(QWidget *startScreen, QWidget *parent) :
    QStackedWidget(parent)
{
    this->addWidget(startScreen);
    this->setCurrentIndex(0);
}

void SayCheesePhotoManager::ScreenManager::loadScreen(QWidget *screen, TransitionDirection direction) {
    QWidget *currentScreen = this->currentWidget();

    this->addWidget(screen);
    this->setCurrentIndex(this->indexOf(currentScreen));

    // Disable mouse events for both screens while they are transitioning.
    screen->show();
    screen->raise();
    screen->setAttribute(Qt::WA_TransparentForMouseEvents);

    currentScreen->show();
    currentScreen->raise();
    currentScreen->setAttribute(Qt::WA_TransparentForMouseEvents);

    // Compute the position deltas for both screens
    // Move the new screen to its position outside of the window.
    screen->setGeometry(this->frameRect());
    int dx = this->width();
    int dy = this->height();

    switch (direction) {
    case TransitionDirection::Up:
        dx = 0;
        dy = -dy;
        screen->move(0, this->height());
        break;

    case TransitionDirection::Down:
        dx = 0;
        screen->move(0, -this->height());
        break;

    case TransitionDirection::Left:
        dx = -dx;
        dy = 0;
        screen->move(this->width(), 0);
        break;

    case TransitionDirection::Right:
        dy = 0;
        screen->move(-this->width(), 0);
        break;
    }

    // Configure the animations for the current and next screens.
    QPropertyAnimation *currentScreenAnimation = new QPropertyAnimation(currentScreen, "pos");
    currentScreenAnimation->setDuration(TRANSITION_DURATION);
    currentScreenAnimation->setStartValue(currentScreen->pos());
    currentScreenAnimation->setEndValue(currentScreen->pos() + QPoint(dx, dy));

    QPropertyAnimation *nextScreenAnimation = new QPropertyAnimation(screen, "pos");
    nextScreenAnimation->setDuration(TRANSITION_DURATION);
    nextScreenAnimation->setStartValue(screen->pos());
    nextScreenAnimation->setEndValue(screen->pos() + QPoint(dx, dy));

    QParallelAnimationGroup *animationGroup = new QParallelAnimationGroup();
    animationGroup->addAnimation(currentScreenAnimation);
    animationGroup->addAnimation(nextScreenAnimation);

    this->connect(animationGroup, &QParallelAnimationGroup::finished, this, &ScreenManager::screenAnimationDone);

    animationGroup->start();
}

void SayCheesePhotoManager::ScreenManager::screenAnimationDone() {
    QWidget *currentWidget = this->currentWidget();
    currentWidget->hide();
    currentWidget->close();
    delete currentWidget;

    this->removeWidget(currentWidget);
    this->setCurrentIndex(0);

    // Re-enable mouse events.
    QWidget *newScreen = this->currentWidget();
    newScreen->setAttribute(Qt::WA_TransparentForMouseEvents, false);

    emit this->screenLoaded();
}
