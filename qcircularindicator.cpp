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

#include "qcircularindicator.h"

QCircularIndicator::QCircularIndicator(QWidget *parent) :
    QWidget(parent), outerRadiusValue(1.0), innerRadiusValue(0.7), startAngleValue(0), spanAngleValue(0)
{
    this->ringColorValue = this->palette().highlight().color();
}

void QCircularIndicator::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setRenderHint(QPainter::Antialiasing);

    auto backgroundColor = this->palette().color(this->backgroundRole());
    auto midlightColor = this->palette().shadow().color();
    auto actualInnerRadius = this->actualInnerRadius();
    auto actualOuterRadius = this->actualOuterRadius();
    auto center = (QPointF)this->rect().center();

    painter.setBrush(midlightColor);
    painter.drawEllipse(center, actualOuterRadius, actualOuterRadius);

    auto pieRect = QRectF(int(center.x() - actualOuterRadius),
                         int(center.y() - actualOuterRadius),
                         actualOuterRadius * 2,
                         actualOuterRadius * 2);

    painter.setBrush(this->ringColorValue);
    painter.drawPie(pieRect, this->startAngleValue, this->spanAngleValue);

    painter.setBrush(backgroundColor);
    painter.drawEllipse(center, actualInnerRadius, actualInnerRadius);
}

void QCircularIndicator::setRingColor(const QColor &color) {
    this->ringColorValue = color;
    emit this->spinnerColorChanged();
    this->update();
}

void QCircularIndicator::setInnerRadius(const qreal &radius) {
    if (qFuzzyCompare(this->innerRadiusValue, radius)) {
        return;
    }

    this->innerRadiusValue = qMax(qMin(radius, 1.0), 0.0);
    emit this->innerRadiusChanged();
    this->update();
}

qreal QCircularIndicator::actualInnerRadius() const {
    auto minDimension = qMin(this->width(), this->height());
    return (this->innerRadiusValue * minDimension)/2 - 10;
}

void QCircularIndicator::setOuterRadius(const qreal &radius) {
    if (qFuzzyCompare(this->outerRadiusValue, radius)) {
        return;
    }

    this->outerRadiusValue = qMax(qMin(radius, 1.0), 0.0);
    emit this->outerRadiusChanged();
    this->update();

}

qreal QCircularIndicator::actualOuterRadius() const {
    auto minDimension = qMin(this->width(), this->height());
    return (this->outerRadiusValue * minDimension)/2 - 10;
}

void QCircularIndicator::setStartAngle(int angle) {
    if (this->startAngleValue == angle * 16) {
        return;
    }

    this->startAngleValue = angle * 16;
    emit this->startAngleChanged();
    this->update();
}

void QCircularIndicator::setSpanAngle(int angle) {
    if (this->spanAngleValue == angle * 16) {
        return;
    }

    this->spanAngleValue = angle * 16;
    emit this->spanAngleChanged();
    this->update();
}
