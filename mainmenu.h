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

#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMenuBar>
#include <QAction>

class MainMenu : public QMenuBar
{
    Q_OBJECT
public:
    explicit MainMenu(QWidget *parent = 0);

signals:
    void quitActionTriggered();
    void aboutActionTriggered();

public slots:

private:
    QAction *quitAction;
    QAction *aboutAction;

};

#endif // MAINMENU_H
