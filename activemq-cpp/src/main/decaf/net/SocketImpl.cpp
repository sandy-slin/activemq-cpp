/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "SocketImpl.h"

#include <decaf/lang/Integer.h>

using namespace decaf;
using namespace decaf::net;
using namespace decaf::lang;

////////////////////////////////////////////////////////////////////////////////
SocketImpl::SocketImpl() : port(0), localPort(0), address(), fd(NULL) {
}

////////////////////////////////////////////////////////////////////////////////
SocketImpl::~SocketImpl() {
}

////////////////////////////////////////////////////////////////////////////////
std::string SocketImpl::toString() const {

    std::string result = std::string( "Socket[addr=" ) + this->address +
                         ",port=" + Integer::toString( this->port ) + "]";

    return result;
}

////////////////////////////////////////////////////////////////////////////////
void SocketImpl::sendUrgentData( int data ) throw( decaf::io::IOException ) {

    throw decaf::io::IOException(
        __FILE__, __LINE__, "Urgent Data not supported by this implementation." );
}
