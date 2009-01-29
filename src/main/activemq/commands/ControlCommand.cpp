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
#include <activemq/commands/ControlCommand.h>
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
 *  Command and marshaling code for OpenWire format for ControlCommand
 *
 *
 *  NOTE!: This file is auto generated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
ControlCommand::ControlCommand() {

    this->command = "";
}

////////////////////////////////////////////////////////////////////////////////
ControlCommand::~ControlCommand() {

}

////////////////////////////////////////////////////////////////////////////////
ControlCommand* ControlCommand::cloneDataStructure() const {
    ControlCommand* controlCommand = new ControlCommand();

    // Copy the data from the base class or classes
    controlCommand->copyDataStructure( this );

    return controlCommand;
}

////////////////////////////////////////////////////////////////////////////////
void ControlCommand::copyDataStructure( const DataStructure* src ) {

    // Protect against invalid self assignment.
    if( this == src ) {
        return;
    }

    // Copy the data of the base class or classes
    BaseCommand::copyDataStructure( src );

    const ControlCommand* srcPtr = dynamic_cast<const ControlCommand*>( src );

    if( srcPtr == NULL || src == NULL ) {
        throw decaf::lang::exceptions::NullPointerException(
            __FILE__, __LINE__,
            "ControlCommand::copyDataStructure - src is NULL or invalid" );
    }
    this->setCommand( srcPtr->getCommand() );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char ControlCommand::getDataStructureType() const {
    return ControlCommand::ID_CONTROLCOMMAND;
}

////////////////////////////////////////////////////////////////////////////////
std::string ControlCommand::toString() const {

    ostringstream stream;

    stream << "Begin Class = ControlCommand" << std::endl;
    stream << " Value of ControlCommand::ID_CONTROLCOMMAND = 14" << std::endl;
    stream << " Value of Command = " << this->getCommand() << std::endl;
    stream << BaseCommand::toString();
    stream << "End Class = ControlCommand" << std::endl;

    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
bool ControlCommand::equals( const DataStructure* value ) const {

    if( this == value ) {
        return true;
    }

    const ControlCommand* valuePtr = dynamic_cast<const ControlCommand*>( value );

    if( valuePtr == NULL || value == NULL ) {
        return false;
    }
    if( this->getCommand() != valuePtr->getCommand() ) {
        return false;
    }
    if( !BaseCommand::equals( value ) ) {
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
commands::Command* ControlCommand::visit( activemq::state::CommandVisitor* visitor ) 
    throw( exceptions::ActiveMQException ) {

    return visitor->processControlCommand( this );
}

////////////////////////////////////////////////////////////////////////////////
const std::string& ControlCommand::getCommand() const {
    return command;
}

////////////////////////////////////////////////////////////////////////////////
std::string& ControlCommand::getCommand() {
    return command;
}

////////////////////////////////////////////////////////////////////////////////
void ControlCommand::setCommand( const std::string& command ) {
    this->command = command;
}

