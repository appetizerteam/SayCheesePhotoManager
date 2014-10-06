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

#include "selectconnectiontypescreenview.h"
#include "bundle.h"

SayCheesePhotoManager::SelectConnectionTypeScreenView::SelectConnectionTypeScreenView(Bundle *bundle, MainWindow *mainWindow)
    : SayCheeseScreen(bundle, mainWindow)
{
    auto mainLayout = new QVBoxLayout();
    auto buttonsLayout = new QHBoxLayout();

    auto titleLabel = new QLabel(tr("Select Connection Type"), this);
    titleLabel->setObjectName("SelectConnectionTypeTitleLabel");

    this->usbButton = new QThemedImageButton(":/resources/androidusb.png", this);
    this->usbButton->setObjectName("SelectConnectionTypeUsbButton");
    this->usbButton->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    this->usbButton->setFocusPolicy(Qt::NoFocus);

    this->wifiButton = new QThemedImageButton(":/resources/androidwifi.png", this);
    this->wifiButton->setObjectName("SelectConnectionTypeWifiButton");
    this->wifiButton->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    this->wifiButton->setFocusPolicy(Qt::NoFocus);

    this->backButton = new QThemedImageButton(":resources/back.png", this);
    this->backButton->setObjectName("SelectConnectionTypeBackButton");
    this->backButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    buttonsLayout->addWidget(this->usbButton);
    buttonsLayout->addWidget(this->wifiButton);

    mainLayout->addWidget(titleLabel);
    mainLayout->addSpacing(25);
    mainLayout->addLayout(buttonsLayout);
    mainLayout->addWidget(this->backButton);

    this->setLayout(mainLayout);
}
