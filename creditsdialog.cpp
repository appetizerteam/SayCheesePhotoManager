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

#include "creditsdialog.h"

#include <QVBoxLayout>
#include <QLabel>

CreditsDialog::CreditsDialog(QWidget *parent) :
    QDialog(parent)
{
    auto mainLayout = new QVBoxLayout();

    auto titleLabel = new QLabel(tr("Credits"), this);
    titleLabel->setObjectName("CreditsDialogTitleLabel");

    auto programmersLabel = new QLabel(tr("Programmers"), this);
    programmersLabel->setObjectName("CreditsDialogProgrammersLabel");

    auto iconsLabel = new QLabel(tr("Icons"), this);
    iconsLabel->setObjectName("CreditsDialogIconsLabel");

    auto icons8LinkLabel = new QLabel("<a href=\"http://icons8.com/\">http://icons8.com/</a>", this);
    icons8LinkLabel->setObjectName("CreditsDialogIcons8LinkLabel");
    icons8LinkLabel->setTextFormat(Qt::RichText);
    icons8LinkLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    icons8LinkLabel->setOpenExternalLinks(true);

    mainLayout->addWidget(titleLabel);

    mainLayout->addWidget(programmersLabel);

    mainLayout->addWidget(iconsLabel);
    mainLayout->addWidget(icons8LinkLabel);

    this->setLayout(mainLayout);
}
