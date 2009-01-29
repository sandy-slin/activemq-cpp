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
#include <activemq/commands/MessageDispatchNotification.h>
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
 *  Command and marshaling code for OpenWire format for MessageDispatchNotification
 *
 *
 *  NOTE!: This file is auto generated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
MessageDispatchNotification::MessageDispatchNotification() {

    this->consumerId = NULL;
    this->destination = NULL;
    this->deliverySequenceId = 0;
    this->messageId = NULL;
}

////////////////////////////////////////////////////////////////////////////////
MessageDispatchNotification::~MessageDispatchNotification() {

    delete this->consumerId;
    delete this->destination;
    delete this->messageId;
}

////////////////////////////////////////////////////////////////////////////////
MessageDispatchNotification* MessageDispatchNotification::cloneDataStructure() const {
    MessageDispatchNotification* messageDispatchNotification = new MessageDispatchNotification();

    // Copy the data from the base class or classes
    messageDispatchNotification->copyDataStructure( this );

    return messageDispatchNotification;
}

////////////////////////////////////////////////////////////////////////////////
void MessageDispatchNotification::copyDataStructure( const DataStructure* src ) {

    // Protect against invalid self assignment.
    if( this == src ) {
        return;
    }

    // Copy the data of the base class or classes
    BaseCommand::copyDataStructure( src );

    const MessageDispatchNotification* srcPtr = dynamic_cast<const MessageDispatchNotification*>( src );

    if( srcPtr == NULL || src == NULL ) {
        throw decaf::lang::exceptions::NullPointerException(
            __FILE__, __LINE__,
            "MessageDispatchNotification::copyDataStructure - src is NULL or invalid" );
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
    this->setDeliverySequenceId( srcPtr->getDeliverySequenceId() );
    if( srcPtr->getMessageId() != NULL ) {
        this->setMessageId(
            dynamic_cast<MessageId*>(
                srcPtr->getMessageId()->cloneDataStructure() ) );
    }
}

////////////////////////////////////////////////////////////////////////////////
unsigned char MessageDispatchNotification::getDataStructureType() const {
    return MessageDispatchNotification::ID_MESSAGEDISPATCHNOTIFICATION;
}

////////////////////////////////////////////////////////////////////////////////
std::string MessageDispatchNotification::toString() const {

    ostringstream stream;

    stream << "Begin Class = MessageDispatchNotification" << std::endl;
    stream << " Value of MessageDispatchNotification::ID_MESSAGEDISPATCHNOTIFICATION = 90" << std::endl;
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
    stream << " Value of DeliverySequenceId = " << this->getDeliverySequenceId() << std::endl;
    stream << " Value of MessageId is Below:" << std::endl;
    if( this->getMessageId() != NULL ) {
        stream << this->getMessageId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << BaseCommand::toString();
    stream << "End Class = MessageDispatchNotification" << std::endl;

    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
bool MessageDispatchNotification::equals( const DataStructure* value ) const {

    if( this == value ) {
        return true;
    }

    const MessageDispatchNotification* valuePtr = dynamic_cast<const MessageDispatchNotification*>( value );

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
    if( this->getDeliverySequenceId() != valuePtr->getDeliverySequenceId() ) {
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
commands::Command* MessageDispatchNotification::visit( activemq::state::CommandVisitor* visitor ) 
    throw( exceptions::ActiveMQException ) {

    return visitor->processMessageDispatchNotification( this );
}

////////////////////////////////////////////////////////////////////////////////
const ConsumerId* MessageDispatchNotification::getConsumerId() const {
    return consumerId;
}

////////////////////////////////////////////////////////////////////////////////
ConsumerId* MessageDispatchNotification::getConsumerId() {
    return consumerId;
}

////////////////////////////////////////////////////////////////////////////////
void MessageDispatchNotification::setConsumerId( ConsumerId* consumerId ) {
    this->consumerId = consumerId;
}

////////////////////////////////////////////////////////////////////////////////
const ActiveMQDestination* MessageDispatchNotification::getDestination() const {
    return destination;
}

////////////////////////////////////////////////////////////////////////////////
ActiveMQDestination* MessageDispatchNotification::getDestination() {
    return destination;
}

////////////////////////////////////////////////////////////////////////////////
void MessageDispatchNotification::setDestination( ActiveMQDestination* destination ) {
    this->destination = destination;
}

////////////////////////////////////////////////////////////////////////////////
long long MessageDispatchNotification::getDeliverySequenceId() const {
    return deliverySequenceId;
}

////////////////////////////////////////////////////////////////////////////////
void MessageDispatchNotification::setDeliverySequenceId( long long deliverySequenceId ) {
    this->deliverySequenceId = deliverySequenceId;
}

////////////////////////////////////////////////////////////////////////////////
const MessageId* MessageDispatchNotification::getMessageId() const {
    return messageId;
}

////////////////////////////////////////////////////////////////////////////////
MessageId* MessageDispatchNotification::getMessageId() {
    return messageId;
}

////////////////////////////////////////////////////////////////////////////////
void MessageDispatchNotification::setMessageId( MessageId* messageId ) {
    this->messageId = messageId;
}

