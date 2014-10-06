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

#include "mainscreenview.h"

SayCheesePhotoManager::MainScreenView::MainScreenView(Bundle *bundle, MainWindow *mainWindow)
    : SayCheeseScreen(bundle, mainWindow)
{
    this->mainLayout = new QVBoxLayout();
    this->mainLayout->setAlignment(Qt::AlignCenter);

    this->titleLabel = new QLabel(tr("SayCheese"), this);
    this->titleLabel->setObjectName("TitleLabel");

    this->subtitleLabel = new QLabel(tr("Photo Transfer Desktop Application"), this);
    this->subtitleLabel->setObjectName("SubtitleLabel");

    this->actionNavigationLayout = new QHBoxLayout();

    this->actionNavigationComboBox = new QComboBox(this);
    this->actionNavigationComboBox->setObjectName("TaskNavigationComboBox");

    this->beginActionButton = new QPushButton(tr("&Begin"), this);
    this->beginActionButton->setObjectName("BeginTaskButton");

    // Lay out widgets
    this->mainLayout->addSpacing(50);
    this->mainLayout->addWidget(this->titleLabel);
    this->mainLayout->addWidget(this->subtitleLabel);
    this->mainLayout->addSpacing(50);
    this->mainLayout->addLayout(this->actionNavigationLayout);
    this->mainLayout->addSpacing(50);

    this->actionNavigationLayout->addSpacing(50);
    this->actionNavigationLayout->addWidget(this->actionNavigationComboBox, Qt::AlignCenter);
    this->actionNavigationLayout->addSpacing(20);
    this->actionNavigationLayout->addWidget(this->beginActionButton, Qt::AlignCenter);
    this->actionNavigationLayout->addSpacing(50);

    this->setLayout(this->mainLayout);
}
