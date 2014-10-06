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

#ifndef SERVERCONFIGURATIONSCREENVIEW_H
#define SERVERCONFIGURATIONSCREENVIEW_H

#include "saycheesescreen.h"
#include "mainwindow.h"
#include "qbusyindicator.h"
#include "qthemedimagebutton.h"
#include "bundle.h"

#include <QVBoxLayout>
#include <QLabel>

namespace SayCheesePhotoManager {

class ServerConfigurationScreenView : public SayCheeseScreen
{
public:
    explicit ServerConfigurationScreenView(Bundle *bundle, MainWindow *mainWindow);

protected:
    QThemedImageButton *backButton;
};

}

#endif // SERVERCONFIGURATIONSCREENVIEW_H
