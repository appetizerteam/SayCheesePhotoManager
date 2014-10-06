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

#ifndef QCIRCULARPROGRESSBAR_H
#define QCIRCULARPROGRESSBAR_H

#include "qcircularindicator.h"

#include <QWidget>

class QCircularProgressBar : public QCircularIndicator
{
    Q_OBJECT
public:
    explicit QCircularProgressBar(QWidget *parent = 0);

    int currentPercentage() const;

signals:
    void valueChanged(int value);

public slots:
    void reset();
    void setMaximum(int max);
    void setMinimum(int min);
    void setRange(int minimum, int maximum);
    void setValue(int value);

private:
    int minValue;
    int maxValue;
    int currentValue;
    int fontSize;

private:
    int calculateFontSize() const;

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
};

#endif // QCIRCULARPROGRESSBAR_H
