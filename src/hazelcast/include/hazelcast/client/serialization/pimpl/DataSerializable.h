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
// Created by sancar koyunlu on 8/12/13.




#ifndef HAZELCAST_DataSerializable
#define HAZELCAST_DataSerializable

#include "hazelcast/util/HazelcastDll.h"

namespace hazelcast {
    namespace client {
        namespace serialization {
            class ObjectDataOutput;

            class ObjectDataInput;
            namespace pimpl {
                class HAZELCAST_API DataSerializable {
                public:

                    virtual ~DataSerializable();

                    virtual void writeData(serialization::ObjectDataOutput &writer) const = 0;

                    virtual void readData(serialization::ObjectDataInput &reader) = 0;

                };
            }
        }


    }
}


#endif //HAZELCAST_DataSerializable

