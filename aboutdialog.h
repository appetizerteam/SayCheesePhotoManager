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

#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QImage>
#include <QPushButton>

namespace SayCheesePhotoManager {

/*
 * Represents the view and control for the about dialog.
 * This dialog shows the user a description of the application and
 * allows them to view license and credits information.
 */
class AboutDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AboutDialog(QWidget *parent = 0);

signals:

public slots:

private:
    QImage icon;
    QPushButton *creditsButton;
    QPushButton *licenseButton;
    QPushButton *closeButton;

};

}

#endif // ABOUTDIALOG_H
