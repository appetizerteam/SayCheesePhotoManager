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

#ifndef QCIRCULARINDICATOR_H
#define QCIRCULARINDICATOR_H

#include <QWidget>
#include <QColor>
#include <QPainter>
#include <QConicalGradient>
#include <QPainterPath>
#include <QPointF>
#include <QRect>

class QCircularIndicator : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QColor ringColor READ ringColor WRITE setRingColor)
    Q_PROPERTY(int startAngle READ startAngle WRITE setStartAngle)
    Q_PROPERTY(int spanAngle READ spanAngle WRITE setSpanAngle)
public:
    explicit QCircularIndicator(QWidget *parent = 0);

    void setRingColor(const QColor& color);
    const QColor& ringColor() const { return this->ringColorValue; }

    void setInnerRadius(const qreal& radius);
    qreal innerRadius() const { return this->innerRadiusValue; }
    qreal actualInnerRadius() const;

    void setOuterRadius(const qreal& radius);
    qreal outerRadius() const { return this->outerRadiusValue; }
    qreal actualOuterRadius() const;

    const int& startAngle() const { return this->startAngleValue; }
    void setStartAngle(int angle);

    const int& spanAngle() const { return this->spanAngleValue; }
    void setSpanAngle(int angle);

signals:
    void spinnerColorChanged();
    void innerRadiusChanged();
    void outerRadiusChanged();
    void startAngleChanged();
    void spanAngleChanged();

public slots:

protected:
    virtual void paintEvent(QPaintEvent *);

private:
    qreal outerRadiusValue;
    qreal innerRadiusValue;
    QColor ringColorValue;
    int startAngleValue;
    int spanAngleValue;
};

#endif // QCIRCULARINDICATOR_H
