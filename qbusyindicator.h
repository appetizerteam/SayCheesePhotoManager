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

#ifndef QBUSYINDICATOR_H
#define QBUSYINDICATOR_H

#include "qcircularindicator.h"

#include <QWidget>
#include <QPropertyAnimation>

class QBusyIndicator : public QCircularIndicator
{
    Q_OBJECT

    Q_PROPERTY(bool spinClockwise READ spinClockwise WRITE setSpinClockwise)
    Q_PROPERTY(int spinDuration READ spinDuration WRITE setSpinDuration)

public:
    explicit QBusyIndicator(QWidget *parent = 0);

    const bool& spinClockwise() const { return this->spinClockwiseValue; }
    void setSpinClockwise(bool b);

    const int& spinDuration() const { return this->spinDurationValue; }
    void setSpinDuration(int duration);
    void pause() { this->spinAnimation->pause(); }
    void resume() { this->spinAnimation->resume(); }
    void stop() { this->spinAnimation->stop(); }
    void start() { this->spinAnimation->start(); }

signals:
    void spinClockwiseChanged();
    void spinDurationChanged();

private:
    static constexpr int DEFAULT_SPIN_DURATION = 750; //ms

    bool spinClockwiseValue;
    int spinDurationValue;
    QPropertyAnimation *spinAnimation;

};

#endif // QBUSYINDICATOR_H
