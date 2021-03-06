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

#ifndef SELECTPHONETYPESCREEN_H
#define SELECTPHONETYPESCREEN_H

#include "selectphonetypescreenview.h"
#include "screen.h"
#include "mainwindow.h"
#include "bundle.h"

namespace SayCheesePhotoManager {

class SelectPhoneTypeScreen : public SelectPhoneTypeScreenView
{
public:
    explicit SelectPhoneTypeScreen(Bundle *bundle, MainWindow *mainWindow);

private slots:
    void handleBackButtonPressed();
    void handleAndroidButtonPressed();
    void handleIphoneButtonPressed();
};

}

#endif // SELECTPHONETYPESCREEN_H
