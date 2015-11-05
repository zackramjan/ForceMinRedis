/*
 * Copyright (c) 2008-2015, Hazelcast, Inc. All Rights Reserved.
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
 */
//
// Created by sancar koyunlu on 24/12/13.
//


#ifndef HAZELCAST_ReadHandler
#define HAZELCAST_ReadHandler

#include "hazelcast/util/ByteBuffer.h"
#include "hazelcast/client/connection/IOHandler.h"

namespace hazelcast {
    namespace client {
        namespace serialization {
            namespace pimpl {
                class Packet;

                class PortableContext;
            }
        }
        namespace spi {
            class ClientContext;
        }
        namespace connection {
            class Connection;

            class ConnectionManager;

            class InSelector;

            class ReadHandler : public IOHandler {
            public:
                ReadHandler(Connection &connection, InSelector &iListener, size_t bufferSize, spi::ClientContext& clientContext);

                ~ReadHandler();

                void handle();

                void run();

            private:
                char* buffer;
                util::ByteBuffer byteBuffer;
                serialization::pimpl::Packet *lastData;
                spi::ClientContext& clientContext;

                serialization::pimpl::PortableContext& getPortableContext();


            };
        }
    }
}

#endif //HAZELCAST_ReadHandler
