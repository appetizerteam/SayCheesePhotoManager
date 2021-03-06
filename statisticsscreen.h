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

#ifndef STATISTICSSCREEN_H
#define STATISTICSSCREEN_H

#include "statisticsscreenview.h"
#include "mainwindow.h"
#include "bundle.h"

namespace SayCheesePhotoManager {

/*
 * This class helps to separate the control logic from the "StatisticsScreenView".
 */
class StatisticsScreen : public StatisticsScreenView
{
public:
    explicit StatisticsScreen(Bundle *bundle, MainWindow *mainWindow);
};

}

#endif // STATISTICSSCREEN_H
