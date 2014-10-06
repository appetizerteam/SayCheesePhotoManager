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

#include "bundle.h"

/*
 * Represents an arbitrary key-value store similar to an Android SDK Bundle.
 * A reference to a "Bundle" will be passed to all "SayCheeseScreen"s and so
 * data can be stored inside this bundle so that state information can be preserved
 * and so that different "SayCheeseScreen"s can communicate with one another.
 */
SayCheesePhotoManager::Bundle::Bundle(QObject *parent)
    : QObject(parent)
{

}

//TODO: Finish the class definition. Look up the Android SDK Bundle first.
