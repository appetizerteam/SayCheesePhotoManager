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

#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QIODevice>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("TeamAPPetizer");
    QCoreApplication::setApplicationName("SayCheesePhotoManager");

    // Set the default application look and feel.
    QFile applicationStyle(":/resources/default.css");
    applicationStyle.open(QIODevice::ReadOnly);
    QTextStream styleStream(&applicationStyle);

    a.setStyleSheet(styleStream.readAll());

    SayCheesePhotoManager::MainWindow mainWindow;
    mainWindow.show();

    return a.exec();
}
