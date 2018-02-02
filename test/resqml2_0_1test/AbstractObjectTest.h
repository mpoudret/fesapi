/*-----------------------------------------------------------------------
Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the NOTICE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"; you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
-----------------------------------------------------------------------*/
#pragma once

#include "../AbstractTest.h"
#include <iostream>

namespace common {
	class EpcDocument;
}

namespace resqml2_0_1test {
	/**
	 * Base abstract class for testing a Resqml top level object.
	 */
	class AbstractObjectTest : public commontest::AbstractTest {
	public:
		/**
		 * Creation of a testing object from an EPC document path. At serialize() call,
		 * exising .epc file will be erased. 
		 * @param epcDocPath the path of the .epc file (including .epc extension)
		 * @param uuid the uuid of the Resqml top level object to test
		 * @param title the title of the Resqml top level object to test
		 */
		AbstractObjectTest(const std::string & epcDocPath, const std::string & uuid, const std::string & title);

		/**
		 * Creation of a testing object from an existing EPC document.
		 * Remark: no virtual method should be called in base class constructor (since at the base constructor call.
		 * it is not possible to decide which implemntation of virtual method run). Thus, no facilities is provided here to 
		 * directly call iniEpcDoc() or readEpcDoc() depending on the purpose of this testing object (created for initialization or reading purpose).
		 * Such iniEpcDoc() and readEpcDoc() calls should be made in child classes.
		 * @param epcDoc an existing EPC document
		 * @param uuid the uuid of the Resqml top level object to test
		 * @param title the title of the Resqml top level object to test
		 */
		AbstractObjectTest(common::EpcDocument * epcDoc, const std::string & uuid, const std::string & title);
		
		/**
		 * Implementation of AbstractTest::initEpcDoc(). It is checked that the Resqml object to create does not
		 * exists in the EPC document. This method calls initEpcDocHandler().
 		 */
		void initEpcDoc();

		/**
		 * Implementaiton of Abstract::readEpcDoc(). Consistant reading of both uuid and title of the top level Resqml
		 * object is checked. This method calls readEpcDocHandler().
		 */
		void readEpcDoc();
	protected:
		const std::string uuid;
		const std::string title;

		/** 
		 * As top level Resqml object initialization differs from one unit test to another, 
		 * it is virtual in this most general testing class.
		 */ 
		virtual void initEpcDocHandler() = 0;

		/** 
		 * As top level Resqml object reading differs from one unit test to another, 
		 * it is virtual in this most general testing class.
		 */
		virtual void readEpcDocHandler() = 0;
	};
}

