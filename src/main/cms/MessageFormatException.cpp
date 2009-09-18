/**
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "MessageFormatException.h"

using namespace cms;

////////////////////////////////////////////////////////////////////////////////
MessageFormatException::MessageFormatException() throw() : CMSException() {
}

////////////////////////////////////////////////////////////////////////////////
MessageFormatException::MessageFormatException( const MessageFormatException& ex )
    throw() : CMSException( ex ) {
}

////////////////////////////////////////////////////////////////////////////////
MessageFormatException::MessageFormatException( const std::string& message, const std::exception* cause )
    throw() : CMSException( message, cause ) {
}

////////////////////////////////////////////////////////////////////////////////
MessageFormatException::MessageFormatException( const std::string& message,
                                                const std::exception* cause,
                                                const std::vector< std::pair< std::string, int> >& stackTrace )
    throw() : CMSException( message, cause, stackTrace ) {
}

////////////////////////////////////////////////////////////////////////////////
MessageFormatException::~MessageFormatException() throw() {
}