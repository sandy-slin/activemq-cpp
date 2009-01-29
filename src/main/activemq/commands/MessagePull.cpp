/*
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
#include <activemq/commands/MessagePull.h>
#include <activemq/state/CommandVisitor.h>
#include <activemq/exceptions/ActiveMQException.h>
#include <decaf/lang/exceptions/NullPointerException.h>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::commands;
using namespace decaf::lang::exceptions;

/*
 *
 *  Command and marshaling code for OpenWire format for MessagePull
 *
 *
 *  NOTE!: This file is auto generated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
MessagePull::MessagePull() {

    this->consumerId = NULL;
    this->destination = NULL;
    this->timeout = 0;
    this->correlationId = "";
    this->messageId = NULL;
}

////////////////////////////////////////////////////////////////////////////////
MessagePull::~MessagePull() {

    delete this->consumerId;
    delete this->destination;
    delete this->messageId;
}

////////////////////////////////////////////////////////////////////////////////
MessagePull* MessagePull::cloneDataStructure() const {
    MessagePull* messagePull = new MessagePull();

    // Copy the data from the base class or classes
    messagePull->copyDataStructure( this );

    return messagePull;
}

////////////////////////////////////////////////////////////////////////////////
void MessagePull::copyDataStructure( const DataStructure* src ) {

    // Protect against invalid self assignment.
    if( this == src ) {
        return;
    }

    // Copy the data of the base class or classes
    BaseCommand::copyDataStructure( src );

    const MessagePull* srcPtr = dynamic_cast<const MessagePull*>( src );

    if( srcPtr == NULL || src == NULL ) {
        throw decaf::lang::exceptions::NullPointerException(
            __FILE__, __LINE__,
            "MessagePull::copyDataStructure - src is NULL or invalid" );
    }
    if( srcPtr->getConsumerId() != NULL ) {
        this->setConsumerId(
            dynamic_cast<ConsumerId*>(
                srcPtr->getConsumerId()->cloneDataStructure() ) );
    }
    if( srcPtr->getDestination() != NULL ) {
        this->setDestination(
            dynamic_cast<ActiveMQDestination*>(
                srcPtr->getDestination()->cloneDataStructure() ) );
    }
    this->setTimeout( srcPtr->getTimeout() );
    this->setCorrelationId( srcPtr->getCorrelationId() );
    if( srcPtr->getMessageId() != NULL ) {
        this->setMessageId(
            dynamic_cast<MessageId*>(
                srcPtr->getMessageId()->cloneDataStructure() ) );
    }
}

////////////////////////////////////////////////////////////////////////////////
unsigned char MessagePull::getDataStructureType() const {
    return MessagePull::ID_MESSAGEPULL;
}

////////////////////////////////////////////////////////////////////////////////
std::string MessagePull::toString() const {

    ostringstream stream;

    stream << "Begin Class = MessagePull" << std::endl;
    stream << " Value of MessagePull::ID_MESSAGEPULL = 20" << std::endl;
    stream << " Value of ConsumerId is Below:" << std::endl;
    if( this->getConsumerId() != NULL ) {
        stream << this->getConsumerId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of Destination is Below:" << std::endl;
    if( this->getDestination() != NULL ) {
        stream << this->getDestination()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of Timeout = " << this->getTimeout() << std::endl;
    stream << " Value of CorrelationId = " << this->getCorrelationId() << std::endl;
    stream << " Value of MessageId is Below:" << std::endl;
    if( this->getMessageId() != NULL ) {
        stream << this->getMessageId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << BaseCommand::toString();
    stream << "End Class = MessagePull" << std::endl;

    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
bool MessagePull::equals( const DataStructure* value ) const {

    if( this == value ) {
        return true;
    }

    const MessagePull* valuePtr = dynamic_cast<const MessagePull*>( value );

    if( valuePtr == NULL || value == NULL ) {
        return false;
    }
    if( this->getConsumerId() != NULL ) {
        if( !this->getConsumerId()->equals( valuePtr->getConsumerId() ) ) {
            return false;
        }
    } else if( valuePtr->getConsumerId() != NULL ) {
        return false;
    }
    if( this->getDestination() != NULL ) {
        if( !this->getDestination()->equals( valuePtr->getDestination() ) ) {
            return false;
        }
    } else if( valuePtr->getDestination() != NULL ) {
        return false;
    }
    if( this->getTimeout() != valuePtr->getTimeout() ) {
        return false;
    }
    if( this->getCorrelationId() != valuePtr->getCorrelationId() ) {
        return false;
    }
    if( this->getMessageId() != NULL ) {
        if( !this->getMessageId()->equals( valuePtr->getMessageId() ) ) {
            return false;
        }
    } else if( valuePtr->getMessageId() != NULL ) {
        return false;
    }
    if( !BaseCommand::equals( value ) ) {
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
commands::Command* MessagePull::visit( activemq::state::CommandVisitor* visitor ) 
    throw( exceptions::ActiveMQException ) {

    return visitor->processMessagePull( this );
}

////////////////////////////////////////////////////////////////////////////////
const ConsumerId* MessagePull::getConsumerId() const {
    return consumerId;
}

////////////////////////////////////////////////////////////////////////////////
ConsumerId* MessagePull::getConsumerId() {
    return consumerId;
}

////////////////////////////////////////////////////////////////////////////////
void MessagePull::setConsumerId( ConsumerId* consumerId ) {
    this->consumerId = consumerId;
}

////////////////////////////////////////////////////////////////////////////////
const ActiveMQDestination* MessagePull::getDestination() const {
    return destination;
}

////////////////////////////////////////////////////////////////////////////////
ActiveMQDestination* MessagePull::getDestination() {
    return destination;
}

////////////////////////////////////////////////////////////////////////////////
void MessagePull::setDestination( ActiveMQDestination* destination ) {
    this->destination = destination;
}

////////////////////////////////////////////////////////////////////////////////
long long MessagePull::getTimeout() const {
    return timeout;
}

////////////////////////////////////////////////////////////////////////////////
void MessagePull::setTimeout( long long timeout ) {
    this->timeout = timeout;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& MessagePull::getCorrelationId() const {
    return correlationId;
}

////////////////////////////////////////////////////////////////////////////////
std::string& MessagePull::getCorrelationId() {
    return correlationId;
}

////////////////////////////////////////////////////////////////////////////////
void MessagePull::setCorrelationId( const std::string& correlationId ) {
    this->correlationId = correlationId;
}

////////////////////////////////////////////////////////////////////////////////
const MessageId* MessagePull::getMessageId() const {
    return messageId;
}

////////////////////////////////////////////////////////////////////////////////
MessageId* MessagePull::getMessageId() {
    return messageId;
}

////////////////////////////////////////////////////////////////////////////////
void MessagePull::setMessageId( MessageId* messageId ) {
    this->messageId = messageId;
}

