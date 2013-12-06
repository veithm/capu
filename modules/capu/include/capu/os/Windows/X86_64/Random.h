/*
 * Copyright (C) 2012 BMW Car IT GmbH
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CAPU_WINDOWS_X86_64_RANDOM_H
#define CAPU_WINDOWS_X86_64_RANDOM_H

#include "capu/os/Generic/Random.h"

namespace capu
{
    namespace os
    {
        namespace arch
        {
            class Random: public capu::generic::Random
            {
            public:
                using capu::generic::Random::nextUInt8;
                using capu::generic::Random::nextUInt16;
                using capu::generic::Random::nextUInt32;
            };
        }
    }
}

#endif // CAPU_WINDOWS_X86_64_RANDOM_H
