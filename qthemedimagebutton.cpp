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

#include "qthemedimagebutton.h"

QThemedImageButton::QThemedImageButton(const QString& iconPath, QWidget *parent)
    : QPushButton(parent), resizeImageValue(false)
{
    if (QFile::exists(iconPath)) {
        QPixmap iconPixmap(iconPath);
        auto iconMask = iconPixmap.createMaskFromColor(Qt::transparent, Qt::MaskInColor);

        QPixmap newPixmap(iconPixmap.size());
        newPixmap.fill(this->palette().foreground().color());
        newPixmap.setMask(iconMask);

        this->setIcon(newPixmap);
    }

    else {
        qDebug() << "QThemedImageButton(Could not load icon: " << iconPath << ")";
    }
}

void QThemedImageButton::QThemedImageButton::resizeEvent(QResizeEvent *event) {
    if (this->resizeImageValue) {
        this->setIconSize(this->size() * 0.9);
    }

    QPushButton::resizeEvent(event);
}

