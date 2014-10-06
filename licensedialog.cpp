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

#include "licensedialog.h"

#include <QVBoxLayout>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>
#include <QLabel>

LicenseDialog::LicenseDialog(QWidget *parent) :
    QDialog(parent)
{
    this->setMinimumSize(QSize(400, 300));

    auto mainLayout = new QVBoxLayout();

    auto licenseText = new QTextEdit(this);
    licenseText->setAlignment(Qt::AlignCenter);
    licenseText->setReadOnly(true);

    QFile licenseFile(":/resources/license.txt");
    licenseFile.open(QIODevice::ReadOnly);

    QTextStream licenseFileStream(&licenseFile);
    licenseText->setText(licenseFileStream.readAll());

    auto titleLabel = new QLabel("Apache License", this);
    titleLabel->setObjectName("LicenseDialogTitleLabel");

    auto versionLabel = new QLabel("Version 2.0, January 2004", this);
    versionLabel->setObjectName("LicenseDialogVersionLabel");

    auto licenseLink = new QLabel("<a href=\"http://www.apache.org/licenses/\">http://www.apache.org/licenses/</a>", this);
    licenseLink->setObjectName("LicenseDialogLicenseLink");
    licenseLink->setTextFormat(Qt::RichText);
    licenseLink->setTextInteractionFlags(Qt::TextBrowserInteraction);
    licenseLink->setOpenExternalLinks(true);

    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(versionLabel);
    mainLayout->addWidget(licenseLink);
    mainLayout->addSpacing(25);
    mainLayout->addWidget(licenseText);

    this->setLayout(mainLayout);
}
