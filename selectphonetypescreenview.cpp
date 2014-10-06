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

#include "selectphonetypescreenview.h"
#include "bundle.h"

SayCheesePhotoManager::SelectPhoneTypeScreenView::SelectPhoneTypeScreenView(Bundle *bundle, MainWindow *parent) :
    SayCheeseScreen(bundle, parent)
{
    auto mainLayout = new QVBoxLayout();
    auto phoneButtonLayout = new QHBoxLayout();

    auto titleLabel = new QLabel(tr("Select Device Type"), this);
    titleLabel->setObjectName("SelectPhoneTypeTitleLabel");

    this->androidButton = new QThemedImageButton(":/resources/android.png", this);
    this->androidButton->setObjectName("SelectPhoneTypeScreenAndroidButton");
    this->androidButton->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    this->androidButton->setFocusPolicy(Qt::NoFocus);

    this->iphoneButton = new QThemedImageButton(":/resources/iphone.png", this);
    this->iphoneButton->setObjectName("SelectPhoneTypeScreenIphoneButton");
    this->iphoneButton->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    this->iphoneButton->setFocusPolicy(Qt::NoFocus);

    this->backButton = new QThemedImageButton(":/resources/back.png", this);
    this->backButton->setObjectName("SelectPhoneTypeScreenBackButton");
    this->backButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    this->backButton->setFocusPolicy(Qt::NoFocus);

    phoneButtonLayout->addWidget(this->androidButton);
    phoneButtonLayout->addWidget(this->iphoneButton);

    mainLayout->addWidget(titleLabel);
    mainLayout->addSpacing(25);
    mainLayout->addLayout(phoneButtonLayout);
    mainLayout->addWidget(this->backButton, Qt::AlignLeft);

    this->setLayout(mainLayout);
}
