/*
 * Copyright (C) 2014 jambit GmbH
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

#ifndef CAPU_IPHONEOS_ARMV7S_TCPSERVERSOCKET_H
#define CAPU_IPHONEOS_ARMV7S_TCPSERVERSOCKET_H


#include <capu/os/iPhoneOS/TcpServerSocket.h>

namespace capu
{
    namespace os
    {
        namespace arch
        {
            class TcpServerSocket: private capu::iphoneos::TcpServerSocket
            {
            public:
                using capu::iphoneos::TcpServerSocket::accept;
                using capu::iphoneos::TcpServerSocket::close;
                using capu::iphoneos::TcpServerSocket::bind;
                using capu::iphoneos::TcpServerSocket::listen;
                using capu::iphoneos::TcpServerSocket::port;
                using capu::iphoneos::TcpServerSocket::getSocketDescription;
            };
        }
    }
}
#endif // CAPU_IPHONEOS_ARMV7S_TCPSERVERSOCKET_H
