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
#include <activemq/commands/TransactionInfo.h>
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
 *  Command and marshaling code for OpenWire format for TransactionInfo
 *
 *
 *  NOTE!: This file is auto generated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
TransactionInfo::TransactionInfo() {

    this->connectionId = NULL;
    this->transactionId = NULL;
    this->type = 0;
}

////////////////////////////////////////////////////////////////////////////////
TransactionInfo::~TransactionInfo() {

    delete this->connectionId;
    delete this->transactionId;
}

////////////////////////////////////////////////////////////////////////////////
TransactionInfo* TransactionInfo::cloneDataStructure() const {
    TransactionInfo* transactionInfo = new TransactionInfo();

    // Copy the data from the base class or classes
    transactionInfo->copyDataStructure( this );

    return transactionInfo;
}

////////////////////////////////////////////////////////////////////////////////
void TransactionInfo::copyDataStructure( const DataStructure* src ) {

    // Protect against invalid self assignment.
    if( this == src ) {
        return;
    }

    // Copy the data of the base class or classes
    BaseCommand::copyDataStructure( src );

    const TransactionInfo* srcPtr = dynamic_cast<const TransactionInfo*>( src );

    if( srcPtr == NULL || src == NULL ) {
        throw decaf::lang::exceptions::NullPointerException(
            __FILE__, __LINE__,
            "TransactionInfo::copyDataStructure - src is NULL or invalid" );
    }
    if( srcPtr->getConnectionId() != NULL ) {
        this->setConnectionId(
            dynamic_cast<ConnectionId*>(
                srcPtr->getConnectionId()->cloneDataStructure() ) );
    }
    if( srcPtr->getTransactionId() != NULL ) {
        this->setTransactionId(
            dynamic_cast<TransactionId*>(
                srcPtr->getTransactionId()->cloneDataStructure() ) );
    }
    this->setType( srcPtr->getType() );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char TransactionInfo::getDataStructureType() const {
    return TransactionInfo::ID_TRANSACTIONINFO;
}

////////////////////////////////////////////////////////////////////////////////
std::string TransactionInfo::toString() const {

    ostringstream stream;

    stream << "Begin Class = TransactionInfo" << std::endl;
    stream << " Value of TransactionInfo::ID_TRANSACTIONINFO = 7" << std::endl;
    stream << " Value of ConnectionId is Below:" << std::endl;
    if( this->getConnectionId() != NULL ) {
        stream << this->getConnectionId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of TransactionId is Below:" << std::endl;
    if( this->getTransactionId() != NULL ) {
        stream << this->getTransactionId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of Type = " << (int)this->getType() << std::endl;
    stream << BaseCommand::toString();
    stream << "End Class = TransactionInfo" << std::endl;

    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
bool TransactionInfo::equals( const DataStructure* value ) const {

    if( this == value ) {
        return true;
    }

    const TransactionInfo* valuePtr = dynamic_cast<const TransactionInfo*>( value );

    if( valuePtr == NULL || value == NULL ) {
        return false;
    }
    if( this->getConnectionId() != NULL ) {
        if( !this->getConnectionId()->equals( valuePtr->getConnectionId() ) ) {
            return false;
        }
    } else if( valuePtr->getConnectionId() != NULL ) {
        return false;
    }
    if( this->getTransactionId() != NULL ) {
        if( !this->getTransactionId()->equals( valuePtr->getTransactionId() ) ) {
            return false;
        }
    } else if( valuePtr->getTransactionId() != NULL ) {
        return false;
    }
    if( this->getType() != valuePtr->getType() ) {
        return false;
    }
    if( !BaseCommand::equals( value ) ) {
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
commands::Command* TransactionInfo::visit( activemq::state::CommandVisitor* visitor ) 
    throw( exceptions::ActiveMQException ) {

    return visitor->processTransactionInfo( this );
}

////////////////////////////////////////////////////////////////////////////////
const ConnectionId* TransactionInfo::getConnectionId() const {
    return connectionId;
}

////////////////////////////////////////////////////////////////////////////////
ConnectionId* TransactionInfo::getConnectionId() {
    return connectionId;
}

////////////////////////////////////////////////////////////////////////////////
void TransactionInfo::setConnectionId( ConnectionId* connectionId ) {
    this->connectionId = connectionId;
}

////////////////////////////////////////////////////////////////////////////////
const TransactionId* TransactionInfo::getTransactionId() const {
    return transactionId;
}

////////////////////////////////////////////////////////////////////////////////
TransactionId* TransactionInfo::getTransactionId() {
    return transactionId;
}

////////////////////////////////////////////////////////////////////////////////
void TransactionInfo::setTransactionId( TransactionId* transactionId ) {
    this->transactionId = transactionId;
}

////////////////////////////////////////////////////////////////////////////////
unsigned char TransactionInfo::getType() const {
    return type;
}

////////////////////////////////////////////////////////////////////////////////
void TransactionInfo::setType( unsigned char type ) {
    this->type = type;
}

