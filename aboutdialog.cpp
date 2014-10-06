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

#include "aboutdialog.h"
#include "creditsdialog.h"
#include "licensedialog.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>

static const char* const DESCRIPTION_TEXT = "Someone.\n"
                                      "please.\n"
                                      "Write a description.";

SayCheesePhotoManager::AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent)
{
    this->setMinimumSize(QSize(500, 400));

    // All of the "SayCheeseScreen"s have a margin of 25 pixels all around.
    // To keep the look and feel consistent, this dialog will do the same.
    this->setContentsMargins(25, 25, 25, 25);

    // Load the application icon for later use.
    icon.load(":/resources/about_icon.png");

    auto mainLayout = new QVBoxLayout();

    // Application logo
    auto logo = new QLabel(this);
    logo->setObjectName("AboutDialogLogo");
    logo->setPixmap(QPixmap::fromImage(icon));

    // About dialog title
    auto titleLabel = new QLabel(tr("SayCheese\nPhoto Manager"), this);
    titleLabel->setObjectName("AboutDialogTitleLabel");

    // Description
    auto descriptionLabel = new QLabel(tr(DESCRIPTION_TEXT), this);
    descriptionLabel->setObjectName("AboutDialogDescriptionLabel");

    // Copyright notice.
    auto copyrightLabel = new QLabel("© 2014 Team APPetizer", this);
    copyrightLabel->setObjectName("AboutDialogCopyrightLabel");

    // Link to the team's github page.
    auto websiteLinkLabel = new QLabel("<a href=\"https://github.com/appetizerteam\">https://github.com/appetizerteam</a>");
    websiteLinkLabel->setObjectName("AboutDialogWebsiteLinkLabel");

    // Make the link clickable and have it interpret the text as HTML.
    websiteLinkLabel->setTextFormat(Qt::RichText);
    websiteLinkLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    websiteLinkLabel->setOpenExternalLinks(true);

    auto controlButtonsLayout = new QHBoxLayout();

    this->creditsButton = new QPushButton(tr("C&redits"), this);
    this->creditsButton->setObjectName("AboutDialogCreditsButton");

    this->licenseButton = new QPushButton(tr("&License"), this);
    this->licenseButton->setObjectName("AboutDialogLicenseButton");

    this->closeButton = new QPushButton(tr("&Close"), this);
    this->closeButton->setObjectName("AboutDialogCloseButton");

    controlButtonsLayout->addWidget(this->creditsButton);
    controlButtonsLayout->addWidget(this->licenseButton);
    controlButtonsLayout->addStretch(1);
    controlButtonsLayout->addWidget(this->closeButton);

    mainLayout->addWidget(logo);
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(descriptionLabel);
    mainLayout->addSpacing(25);
    mainLayout->addWidget(copyrightLabel);
    mainLayout->addWidget(websiteLinkLabel);
    mainLayout->addStretch(1);
    mainLayout->addLayout(controlButtonsLayout);

    this->setLayout(mainLayout);

    // Set Connections
    this->connect(this->creditsButton, &QPushButton::pressed, this, [this]() {
        auto creditsDialog = new CreditsDialog(this);
        creditsDialog->setModal(true);
        creditsDialog->show();
    });

    this->connect(this->licenseButton, &QPushButton::pressed, this, [this]() {
        auto licenseDialog = new LicenseDialog(this);
        licenseDialog->setModal(true);
        licenseDialog->show();
    });

    this->connect(this->closeButton, &QPushButton::pressed, this, [this]() {
        this->close();
    });
}
