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

#include "qcircularprogressbar.h"

#include <QPainter>
#include <QFontMetrics>

#include <QPropertyAnimation>

QCircularProgressBar::QCircularProgressBar(QWidget *parent) :
    QCircularIndicator(parent), minValue(0), maxValue(100), currentValue(0)
{
}

void QCircularProgressBar::reset() {
    this->currentValue = this->minValue;
    this->update();
}

void QCircularProgressBar::setMaximum(int max) {
    if (this->maxValue == max) {
        return;
    }

    this->maxValue = max;
    this->update();
}

void QCircularProgressBar::setMinimum(int min) {
    if (this->minValue == min) {
        return;
    }

    this->minValue = min;
    this->update();
}

void QCircularProgressBar::setRange(int minimum, int maximum) {
    this->setMinimum(minimum);
    this->setMaximum(maximum);
}

void QCircularProgressBar::setValue(int value) {
    if (this->currentValue == value) {
        return;
    }

    else if (value < this->minValue) {
        //TODO: q debug
    }

    else if (value > this->maxValue) {
        //TODO: q debug
    }

    this->currentValue = qMax(this->minValue, qMin(value, this->maxValue));
    this->update();
    emit this->valueChanged(value);
}

int QCircularProgressBar::currentPercentage() const {
    return 100 * (double(this->currentValue - this->minValue) / double(this->maxValue - this->minValue));
}

void QCircularProgressBar::resizeEvent(QResizeEvent *event) {
    QCircularIndicator::resizeEvent(event);
    this->fontSize = this->calculateFontSize();
}

void QCircularProgressBar::paintEvent(QPaintEvent *event) {
    auto percentValue = this->currentPercentage();
    this->setSpanAngle(360 * percentValue/double(100));

    QCircularIndicator::paintEvent(event);

    auto center = this->rect().center();
    auto actualInnerRadius = this->actualInnerRadius();

    auto innerRect = QRect(int(center.x() - actualInnerRadius),
                         int(center.y() - actualInnerRadius),
                         actualInnerRadius * 2,
                         actualInnerRadius * 2);

    QFont font = this->font();
    font.setPointSize(this->fontSize);

    QPainter painter(this);
    painter.setPen(this->palette().foreground().color());
    painter.setFont(font);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.drawText(innerRect, Qt::AlignCenter, QString::number(percentValue) + "%");
}

int QCircularProgressBar::calculateFontSize() const {
    QFont font = this->font();

    auto center = this->rect().center();
    auto actualInnerRadius = this->actualInnerRadius();
    auto innerRect = QRect(int(center.x() - actualInnerRadius),
                         int(center.y() - actualInnerRadius),
                         actualInnerRadius * 2,
                         actualInnerRadius * 2);

    // Going to check sizes up to 200 in point size.
    for (auto i = 2; i < 200; i++) {
        font.setPointSize(i);

        QFontMetrics fontMetrics(font);

        if (fontMetrics.width("100%") > innerRect.width() * .90 || fontMetrics.height() > innerRect.height() * .90) {
            return i - 1;
        }
    }

    return 200;
}
