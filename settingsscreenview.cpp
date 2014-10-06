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

#include "settingsscreenview.h"
#include "bundle.h"

SayCheesePhotoManager::SettingsScreenView::SettingsScreenView(Bundle *bundle, MainWindow *mainWindow)
    : SayCheeseScreen(bundle, mainWindow)
{
    auto mainLayout = new QVBoxLayout(this);

    // Title
    auto titleLabel = new QLabel(tr("Settings"), this);
    titleLabel->setObjectName("SettingsTitleLabel");

    // Photo directory path text box.
    this->photoDirectoryPath = new QLineEdit(this);
    this->setObjectName("PhotoDirectoryPath");

    // Button that should bring up a folder selection dialog to set the new
    // photo directory path.
    this->selectPhotoDirectoryPath = new QPushButton(tr("..."), this);
    this->setObjectName("SelectPhotoDirectoryButton");

    // Group box for the photo directory path text box and button, it will
    // mainly act as a "label" for this option.
    auto photoDirectoryGroupBox = new QGroupBox(this);
    photoDirectoryGroupBox->setObjectName("PhotoDirectoryGroupBox");
    photoDirectoryGroupBox->setTitle(tr("Photo Storage Directory"));
    // Make sure that the group box does not resize its height but does resize its width.
    photoDirectoryGroupBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);

    auto photoDirectoryPathLayout = new QHBoxLayout();
    photoDirectoryPathLayout->addWidget(this->photoDirectoryPath);
    photoDirectoryPathLayout->addWidget(this->selectPhotoDirectoryPath);

    photoDirectoryGroupBox->setLayout(photoDirectoryPathLayout);

    this->backButton = new QThemedImageButton(":/resources/back_down.png", this);
    this->backButton->setObjectName("SettingsBackButton");
    this->backButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);


    // Lay out Widgets
    mainLayout->addWidget(titleLabel);
    mainLayout->addSpacing(25);
    mainLayout->addWidget(photoDirectoryGroupBox);
    mainLayout->addSpacing(150);
    mainLayout->addWidget(this->backButton, Qt::AlignLeft);

    this->setLayout(mainLayout);
}
