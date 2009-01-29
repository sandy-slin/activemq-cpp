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
#include <activemq/commands/ProducerInfo.h>
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
 *  Command and marshaling code for OpenWire format for ProducerInfo
 *
 *
 *  NOTE!: This file is auto generated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
ProducerInfo::ProducerInfo() {

    this->producerId = NULL;
    this->destination = NULL;
    this->dispatchAsync = false;
    this->windowSize = 0;
}

////////////////////////////////////////////////////////////////////////////////
ProducerInfo::~ProducerInfo() {

    delete this->producerId;
    delete this->destination;
    for( size_t ibrokerPath = 0; ibrokerPath < brokerPath.size(); ++ibrokerPath ) {
        delete brokerPath[ibrokerPath];
    }
}

////////////////////////////////////////////////////////////////////////////////
ProducerInfo* ProducerInfo::cloneDataStructure() const {
    ProducerInfo* producerInfo = new ProducerInfo();

    // Copy the data from the base class or classes
    producerInfo->copyDataStructure( this );

    return producerInfo;
}

////////////////////////////////////////////////////////////////////////////////
void ProducerInfo::copyDataStructure( const DataStructure* src ) {

    // Protect against invalid self assignment.
    if( this == src ) {
        return;
    }

    // Copy the data of the base class or classes
    BaseCommand::copyDataStructure( src );

    const ProducerInfo* srcPtr = dynamic_cast<const ProducerInfo*>( src );

    if( srcPtr == NULL || src == NULL ) {
        throw decaf::lang::exceptions::NullPointerException(
            __FILE__, __LINE__,
            "ProducerInfo::copyDataStructure - src is NULL or invalid" );
    }
    if( srcPtr->getProducerId() != NULL ) {
        this->setProducerId(
            dynamic_cast<ProducerId*>(
                srcPtr->getProducerId()->cloneDataStructure() ) );
    }
    if( srcPtr->getDestination() != NULL ) {
        this->setDestination(
            dynamic_cast<ActiveMQDestination*>(
                srcPtr->getDestination()->cloneDataStructure() ) );
    }
    for( size_t ibrokerPath = 0; ibrokerPath < srcPtr->getBrokerPath().size(); ++ibrokerPath ) {
        if( srcPtr->getBrokerPath()[ibrokerPath] != NULL ) {
            this->getBrokerPath().push_back(
                dynamic_cast<BrokerId*>(
                    srcPtr->getBrokerPath()[ibrokerPath]->cloneDataStructure() ) );
        } else {
            this->getBrokerPath().push_back( NULL );
        }
    }
    this->setDispatchAsync( srcPtr->isDispatchAsync() );
    this->setWindowSize( srcPtr->getWindowSize() );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char ProducerInfo::getDataStructureType() const {
    return ProducerInfo::ID_PRODUCERINFO;
}

////////////////////////////////////////////////////////////////////////////////
std::string ProducerInfo::toString() const {

    ostringstream stream;

    stream << "Begin Class = ProducerInfo" << std::endl;
    stream << " Value of ProducerInfo::ID_PRODUCERINFO = 6" << std::endl;
    stream << " Value of ProducerId is Below:" << std::endl;
    if( this->getProducerId() != NULL ) {
        stream << this->getProducerId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of Destination is Below:" << std::endl;
    if( this->getDestination() != NULL ) {
        stream << this->getDestination()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    for( size_t ibrokerPath = 0; ibrokerPath < this->getBrokerPath().size(); ++ibrokerPath ) {
        stream << " Value of BrokerPath[" << ibrokerPath << "] is Below:" << std::endl;
        if( this->getBrokerPath()[ibrokerPath] != NULL ) {
            stream << this->getBrokerPath()[ibrokerPath]->toString() << std::endl;
        } else {
            stream << "   Object is NULL" << std::endl;
        }
    }
    stream << " Value of DispatchAsync = " << this->isDispatchAsync() << std::endl;
    stream << " Value of WindowSize = " << this->getWindowSize() << std::endl;
    stream << BaseCommand::toString();
    stream << "End Class = ProducerInfo" << std::endl;

    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
bool ProducerInfo::equals( const DataStructure* value ) const {

    if( this == value ) {
        return true;
    }

    const ProducerInfo* valuePtr = dynamic_cast<const ProducerInfo*>( value );

    if( valuePtr == NULL || value == NULL ) {
        return false;
    }
    if( this->getProducerId() != NULL ) {
        if( !this->getProducerId()->equals( valuePtr->getProducerId() ) ) {
            return false;
        }
    } else if( valuePtr->getProducerId() != NULL ) {
        return false;
    }
    if( this->getDestination() != NULL ) {
        if( !this->getDestination()->equals( valuePtr->getDestination() ) ) {
            return false;
        }
    } else if( valuePtr->getDestination() != NULL ) {
        return false;
    }
    for( size_t ibrokerPath = 0; ibrokerPath < this->getBrokerPath().size(); ++ibrokerPath ) {
        if( this->getBrokerPath()[ibrokerPath] != NULL ) {
            if( !this->getBrokerPath()[ibrokerPath]->equals( valuePtr->getBrokerPath()[ibrokerPath] ) ) {
                return false;
            }
        } else if( valuePtr->getBrokerPath()[ibrokerPath] != NULL ) {
            return false;
        }
    }
    if( this->isDispatchAsync() != valuePtr->isDispatchAsync() ) {
        return false;
    }
    if( this->getWindowSize() != valuePtr->getWindowSize() ) {
        return false;
    }
    if( !BaseCommand::equals( value ) ) {
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
commands::Command* ProducerInfo::visit( activemq::state::CommandVisitor* visitor ) 
    throw( exceptions::ActiveMQException ) {

    return visitor->processProducerInfo( this );
}

////////////////////////////////////////////////////////////////////////////////
const ProducerId* ProducerInfo::getProducerId() const {
    return producerId;
}

////////////////////////////////////////////////////////////////////////////////
ProducerId* ProducerInfo::getProducerId() {
    return producerId;
}

////////////////////////////////////////////////////////////////////////////////
void ProducerInfo::setProducerId( ProducerId* producerId ) {
    this->producerId = producerId;
}

////////////////////////////////////////////////////////////////////////////////
const ActiveMQDestination* ProducerInfo::getDestination() const {
    return destination;
}

////////////////////////////////////////////////////////////////////////////////
ActiveMQDestination* ProducerInfo::getDestination() {
    return destination;
}

////////////////////////////////////////////////////////////////////////////////
void ProducerInfo::setDestination( ActiveMQDestination* destination ) {
    this->destination = destination;
}

////////////////////////////////////////////////////////////////////////////////
const std::vector<BrokerId*>& ProducerInfo::getBrokerPath() const {
    return brokerPath;
}

////////////////////////////////////////////////////////////////////////////////
std::vector<BrokerId*>& ProducerInfo::getBrokerPath() {
    return brokerPath;
}

////////////////////////////////////////////////////////////////////////////////
void ProducerInfo::setBrokerPath( const std::vector<BrokerId*>& brokerPath ) {
    this->brokerPath = brokerPath;
}

////////////////////////////////////////////////////////////////////////////////
bool ProducerInfo::isDispatchAsync() const {
    return dispatchAsync;
}

////////////////////////////////////////////////////////////////////////////////
void ProducerInfo::setDispatchAsync( bool dispatchAsync ) {
    this->dispatchAsync = dispatchAsync;
}

////////////////////////////////////////////////////////////////////////////////
int ProducerInfo::getWindowSize() const {
    return windowSize;
}

////////////////////////////////////////////////////////////////////////////////
void ProducerInfo::setWindowSize( int windowSize ) {
    this->windowSize = windowSize;
}

