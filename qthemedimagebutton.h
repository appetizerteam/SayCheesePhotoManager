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

#ifndef QTHEMEDIMAGEBUTTON_H
#define QTHEMEDIMAGEBUTTON_H

#include <QPushButton>
#include <QPixmap>
#include <QBitmap>
#include <QFile>
#include <QDebug>

class QThemedImageButton : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(bool resizeImage READ resizeImage WRITE setResizeImage)
public:
    explicit QThemedImageButton(const QString& iconPath, QWidget *parent = 0);

    bool resizeImage() const { return this->resizeImageValue; }
    void setResizeImage(bool value) {
        if (this->resizeImageValue == value) {
            return;
        }

        this->resizeImageValue = value;
        emit this->resizeImageChanged();
    }

signals:
    void resizeImageChanged();

protected:
    virtual void resizeEvent(QResizeEvent *event);

private:
    bool resizeImageValue;

};

#endif // QTHEMEDIMAGEBUTTON_H
