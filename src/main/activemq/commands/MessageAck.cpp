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
#include <activemq/commands/MessageAck.h>
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
 *  Command and marshaling code for OpenWire format for MessageAck
 *
 *
 *  NOTE!: This file is auto generated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
MessageAck::MessageAck() {

    this->destination = NULL;
    this->transactionId = NULL;
    this->consumerId = NULL;
    this->ackType = 0;
    this->firstMessageId = NULL;
    this->lastMessageId = NULL;
    this->messageCount = 0;
}

////////////////////////////////////////////////////////////////////////////////
MessageAck::~MessageAck() {

    delete this->destination;
    delete this->transactionId;
    delete this->consumerId;
    delete this->firstMessageId;
    delete this->lastMessageId;
}

////////////////////////////////////////////////////////////////////////////////
MessageAck* MessageAck::cloneDataStructure() const {
    MessageAck* messageAck = new MessageAck();

    // Copy the data from the base class or classes
    messageAck->copyDataStructure( this );

    return messageAck;
}

////////////////////////////////////////////////////////////////////////////////
void MessageAck::copyDataStructure( const DataStructure* src ) {

    // Protect against invalid self assignment.
    if( this == src ) {
        return;
    }

    // Copy the data of the base class or classes
    BaseCommand::copyDataStructure( src );

    const MessageAck* srcPtr = dynamic_cast<const MessageAck*>( src );

    if( srcPtr == NULL || src == NULL ) {
        throw decaf::lang::exceptions::NullPointerException(
            __FILE__, __LINE__,
            "MessageAck::copyDataStructure - src is NULL or invalid" );
    }
    if( srcPtr->getDestination() != NULL ) {
        this->setDestination(
            dynamic_cast<ActiveMQDestination*>(
                srcPtr->getDestination()->cloneDataStructure() ) );
    }
    if( srcPtr->getTransactionId() != NULL ) {
        this->setTransactionId(
            dynamic_cast<TransactionId*>(
                srcPtr->getTransactionId()->cloneDataStructure() ) );
    }
    if( srcPtr->getConsumerId() != NULL ) {
        this->setConsumerId(
            dynamic_cast<ConsumerId*>(
                srcPtr->getConsumerId()->cloneDataStructure() ) );
    }
    this->setAckType( srcPtr->getAckType() );
    if( srcPtr->getFirstMessageId() != NULL ) {
        this->setFirstMessageId(
            dynamic_cast<MessageId*>(
                srcPtr->getFirstMessageId()->cloneDataStructure() ) );
    }
    if( srcPtr->getLastMessageId() != NULL ) {
        this->setLastMessageId(
            dynamic_cast<MessageId*>(
                srcPtr->getLastMessageId()->cloneDataStructure() ) );
    }
    this->setMessageCount( srcPtr->getMessageCount() );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char MessageAck::getDataStructureType() const {
    return MessageAck::ID_MESSAGEACK;
}

////////////////////////////////////////////////////////////////////////////////
std::string MessageAck::toString() const {

    ostringstream stream;

    stream << "Begin Class = MessageAck" << std::endl;
    stream << " Value of MessageAck::ID_MESSAGEACK = 22" << std::endl;
    stream << " Value of Destination is Below:" << std::endl;
    if( this->getDestination() != NULL ) {
        stream << this->getDestination()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of TransactionId is Below:" << std::endl;
    if( this->getTransactionId() != NULL ) {
        stream << this->getTransactionId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of ConsumerId is Below:" << std::endl;
    if( this->getConsumerId() != NULL ) {
        stream << this->getConsumerId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of AckType = " << (int)this->getAckType() << std::endl;
    stream << " Value of FirstMessageId is Below:" << std::endl;
    if( this->getFirstMessageId() != NULL ) {
        stream << this->getFirstMessageId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of LastMessageId is Below:" << std::endl;
    if( this->getLastMessageId() != NULL ) {
        stream << this->getLastMessageId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of MessageCount = " << this->getMessageCount() << std::endl;
    stream << BaseCommand::toString();
    stream << "End Class = MessageAck" << std::endl;

    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
bool MessageAck::equals( const DataStructure* value ) const {

    if( this == value ) {
        return true;
    }

    const MessageAck* valuePtr = dynamic_cast<const MessageAck*>( value );

    if( valuePtr == NULL || value == NULL ) {
        return false;
    }
    if( this->getDestination() != NULL ) {
        if( !this->getDestination()->equals( valuePtr->getDestination() ) ) {
            return false;
        }
    } else if( valuePtr->getDestination() != NULL ) {
        return false;
    }
    if( this->getTransactionId() != NULL ) {
        if( !this->getTransactionId()->equals( valuePtr->getTransactionId() ) ) {
            return false;
        }
    } else if( valuePtr->getTransactionId() != NULL ) {
        return false;
    }
    if( this->getConsumerId() != NULL ) {
        if( !this->getConsumerId()->equals( valuePtr->getConsumerId() ) ) {
            return false;
        }
    } else if( valuePtr->getConsumerId() != NULL ) {
        return false;
    }
    if( this->getAckType() != valuePtr->getAckType() ) {
        return false;
    }
    if( this->getFirstMessageId() != NULL ) {
        if( !this->getFirstMessageId()->equals( valuePtr->getFirstMessageId() ) ) {
            return false;
        }
    } else if( valuePtr->getFirstMessageId() != NULL ) {
        return false;
    }
    if( this->getLastMessageId() != NULL ) {
        if( !this->getLastMessageId()->equals( valuePtr->getLastMessageId() ) ) {
            return false;
        }
    } else if( valuePtr->getLastMessageId() != NULL ) {
        return false;
    }
    if( this->getMessageCount() != valuePtr->getMessageCount() ) {
        return false;
    }
    if( !BaseCommand::equals( value ) ) {
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
commands::Command* MessageAck::visit( activemq::state::CommandVisitor* visitor ) 
    throw( exceptions::ActiveMQException ) {

    return visitor->processMessageAck( this );
}

////////////////////////////////////////////////////////////////////////////////
const ActiveMQDestination* MessageAck::getDestination() const {
    return destination;
}

////////////////////////////////////////////////////////////////////////////////
ActiveMQDestination* MessageAck::getDestination() {
    return destination;
}

////////////////////////////////////////////////////////////////////////////////
void MessageAck::setDestination( ActiveMQDestination* destination ) {
    this->destination = destination;
}

////////////////////////////////////////////////////////////////////////////////
const TransactionId* MessageAck::getTransactionId() const {
    return transactionId;
}

////////////////////////////////////////////////////////////////////////////////
TransactionId* MessageAck::getTransactionId() {
    return transactionId;
}

////////////////////////////////////////////////////////////////////////////////
void MessageAck::setTransactionId( TransactionId* transactionId ) {
    this->transactionId = transactionId;
}

////////////////////////////////////////////////////////////////////////////////
const ConsumerId* MessageAck::getConsumerId() const {
    return consumerId;
}

////////////////////////////////////////////////////////////////////////////////
ConsumerId* MessageAck::getConsumerId() {
    return consumerId;
}

////////////////////////////////////////////////////////////////////////////////
void MessageAck::setConsumerId( ConsumerId* consumerId ) {
    this->consumerId = consumerId;
}

////////////////////////////////////////////////////////////////////////////////
unsigned char MessageAck::getAckType() const {
    return ackType;
}

////////////////////////////////////////////////////////////////////////////////
void MessageAck::setAckType( unsigned char ackType ) {
    this->ackType = ackType;
}

////////////////////////////////////////////////////////////////////////////////
const MessageId* MessageAck::getFirstMessageId() const {
    return firstMessageId;
}

////////////////////////////////////////////////////////////////////////////////
MessageId* MessageAck::getFirstMessageId() {
    return firstMessageId;
}

////////////////////////////////////////////////////////////////////////////////
void MessageAck::setFirstMessageId( MessageId* firstMessageId ) {
    this->firstMessageId = firstMessageId;
}

////////////////////////////////////////////////////////////////////////////////
const MessageId* MessageAck::getLastMessageId() const {
    return lastMessageId;
}

////////////////////////////////////////////////////////////////////////////////
MessageId* MessageAck::getLastMessageId() {
    return lastMessageId;
}

////////////////////////////////////////////////////////////////////////////////
void MessageAck::setLastMessageId( MessageId* lastMessageId ) {
    this->lastMessageId = lastMessageId;
}

////////////////////////////////////////////////////////////////////////////////
int MessageAck::getMessageCount() const {
    return messageCount;
}

////////////////////////////////////////////////////////////////////////////////
void MessageAck::setMessageCount( int messageCount ) {
    this->messageCount = messageCount;
}

