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

#include "mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QMenuBar(parent)
{
    this->quitAction = new QAction(tr("&Quit"), this);
    this->quitAction->setShortcut(QKeySequence::Quit);

    this->aboutAction = new QAction(tr("&About"), this);

    auto fileMenu = this->addMenu(tr("&File"));
    fileMenu->addAction(this->quitAction);

    auto helpMenu = this->addMenu(tr("&Help"));
    helpMenu->addAction(this->aboutAction);

    // Set up the signals and slots for each action.
    this->connect(this->quitAction, &QAction::triggered, this, [this]() { emit this->quitActionTriggered(); });
    this->connect(this->aboutAction, &QAction::triggered, this, [this]() { emit this->aboutActionTriggered(); });
}
