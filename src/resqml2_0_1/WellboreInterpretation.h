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

#include "resqml2/AbstractFeatureInterpretation.h"

namespace resqml2_0_1
{
	class DLL_IMPORT_OR_EXPORT WellboreInterpretation : public resqml2::AbstractFeatureInterpretation
	{
	public:

		/**
		* Only to be used in partial transfer context
		*/
		WellboreInterpretation(gsoap_resqml2_0_1::eml20__DataObjectReference* partialObject) :
			resqml2::AbstractFeatureInterpretation(partialObject)
		{
		}

		/**
		* Creates an instance of this class in a gsoap context.
		* @param horizon	The feature the instance interprets.
		* @param guid		The guid to set to the fault. If empty then a new guid will be generated.
		* @param title		A title for the instance to create.
		* @param isDrilled	Indicate if the wellbore is interpreted wether as drilled or not.
		*/
		WellboreInterpretation(class WellboreFeature * WellboreFeature, const std::string & guid, const std::string & title, bool isDrilled);

		/**
		* Creates an instance of this class by wrapping a gsoap instance.
		*/
		WellboreInterpretation(gsoap_resqml2_0_1::_resqml2__WellboreInterpretation* fromGsoap) : resqml2::AbstractFeatureInterpretation(fromGsoap) {}

		/**
		* Destructor does nothing since the memory is managed by the gsoap context.
		*/
		~WellboreInterpretation() {}

		/**
		* Indicates if the wellbore has been interpreted as drilled or not.
		*/
		bool isDrilled() const;

		/**
		* Get all the trajectory representations of this interpretation
		*/
		std::vector<class WellboreTrajectoryRepresentation*> getWellboreTrajectoryRepresentationSet() const;

		static const char* XML_TAG;
		virtual std::string getXmlTag() const {return XML_TAG;}
	};
}

