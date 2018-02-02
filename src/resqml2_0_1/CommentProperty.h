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

#include "resqml2/AbstractValuesProperty.h"

namespace resqml2_0_1
{
	class DLL_IMPORT_OR_EXPORT CommentProperty : public resqml2::AbstractValuesProperty
	{
	public:

		/**
		* Only to be used in partial transfer context
		*/
		CommentProperty(gsoap_resqml2_0_1::eml20__DataObjectReference* partialObject) : resqml2::AbstractValuesProperty(partialObject) {}

		/**
		* Creates an instance of this class in a gsoap context.
		* @param rep						The representation which supports these property values.
		* @param guid						The guid to set to the property. If empty then a new guid will be generated.
		* @param title						A title for the instance to create.
		* @param dimension					The dimension of each value (scalar properties == 1).
		* @param attachmentKind				The topological orbit which support each value.
		* @param energisticsPropertyKind	The property kind of these property values which must be defined in the standard energistics property type dictionary.
		*/
		CommentProperty(resqml2::AbstractRepresentation * rep, const std::string & guid, const std::string & title,
			const unsigned int & dimension, const gsoap_resqml2_0_1::resqml2__IndexableElements & attachmentKind, const gsoap_resqml2_0_1::resqml2__ResqmlPropertyKind & energisticsPropertyKind);

		/**
		* Creates an instance of this class in a gsoap context.
		* @param rep						The representation which supports these property values.
		* @param guid						The guid to set to the property. If empty then a new guid will be generated.
		* @param title						A title for the instance to create.
		* @param dimension					The dimension of each value (scalar properties == 1).
		* @param attachmentKind				The topological orbit which support each value.
		* @param localPropKind				The property kind of these property values which must be defined in the EPC document as a local property kind.
		*/
		CommentProperty(resqml2::AbstractRepresentation * rep, const std::string & guid, const std::string & title,
			const unsigned int & dimension, const gsoap_resqml2_0_1::resqml2__IndexableElements & attachmentKind, resqml2::PropertyKind * localPropKind);

		/**
		* Creates an instance of this class by wrapping a gsoap instance.
		*/
		CommentProperty(gsoap_resqml2_0_1::_resqml2__CommentProperty* fromGsoap): AbstractValuesProperty(fromGsoap) {}

		/**
		* Destructor does nothing since the memory is managed by the gsoap context.
		*/
		~CommentProperty() {}

		static const char* XML_TAG;
		virtual std::string getXmlTag() const {return XML_TAG;}

		/**
		* Add an array of string values to the property values.
		* @param values					All the property values to set ordered according the topology of the representation it is based on.
		* @param proxy					The HDF proxy where to write the property values. It must be already opened for writing and won't be closed in this method.
		*/
		void pushBackStringHdf5ArrayOfValues(const std::vector<std::string> & values, common::AbstractHdfProxy* proxy);

		std::string pushBackRefToExistingDataset(common::AbstractHdfProxy* hdfProxy, const std::string & datasetName = "", const long & nullValue = (std::numeric_limits<long>::max)());

		/**
		* Get all the values of the instance which are supposed to be string ones.
		*/
		std::vector<std::string> getStringValuesOfPatch(const unsigned int & patchIndex);

		/**
		* Check if the associated local property kind is allowed for this property.
		*/
		bool validatePropertyKindAssociation(resqml2::PropertyKind* pk);

		/**
		* Check if the associated standard property kind is allowed for this property.
		*/
		bool validatePropertyKindAssociation(const gsoap_resqml2_0_1::resqml2__ResqmlPropertyKind & pk);

	};
}

