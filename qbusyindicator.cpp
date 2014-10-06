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

#include "qbusyindicator.h"

QBusyIndicator::QBusyIndicator(QWidget *parent) :
    QCircularIndicator(parent), spinClockwiseValue(true), spinDurationValue(DEFAULT_SPIN_DURATION)
{
    this->setSpanAngle(90);

    this->spinAnimation = new QPropertyAnimation(this, "startAngle");
    this->spinAnimation->setStartValue(360);
    this->spinAnimation->setEndValue(0);
    this->spinAnimation->setLoopCount(-1);
    this->spinAnimation->setDuration(DEFAULT_SPIN_DURATION);
}

void QBusyIndicator::setSpinClockwise(bool b) {
    if (this->spinClockwiseValue == b) {
        return;
    }

    this->spinClockwiseValue = b;

    if (b) {
        this->spinAnimation->pause();
        this->spinAnimation->setStartValue(360);
        this->spinAnimation->setEndValue(0);
        this->spinAnimation->resume();
    }

    else {
        this->spinAnimation->pause();
        this->spinAnimation->setStartValue(0);
        this->spinAnimation->setEndValue(360);
        this->spinAnimation->resume();
    }

    emit this->spinClockwiseChanged();
}

void QBusyIndicator::setSpinDuration(int duration) {
    if (this->spinDurationValue == duration) {
        return;
    }

    this->spinDurationValue = duration;

    this->spinAnimation->pause();
    this->spinAnimation->setDuration(duration);
    this->spinAnimation->resume();

    emit this->spinDurationChanged();
}
