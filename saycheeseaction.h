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

#ifndef SAYCHEESEACTION_H
#define SAYCHEESEACTION_H

namespace SayCheesePhotoManager {

class SayCheeseAction {
public:
    static constexpr int TRANSFER_PHOTOS = 0;
    static constexpr int VIEW_STATISTICS = 1;
    static constexpr int CHANGE_SETTINGS = 2;
};

}

#endif // SAYCHEESEACTION_H
