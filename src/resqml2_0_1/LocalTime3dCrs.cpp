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
#include "resqml2_0_1/LocalTime3dCrs.h"

#include <stdexcept>

using namespace std;
using namespace resqml2_0_1;
using namespace gsoap_resqml2_0_1;
using namespace epc;

const char* LocalTime3dCrs::XML_TAG = "LocalTime3dCrs";

void LocalTime3dCrs::init(soap* soapContext, const std::string & guid, const std::string & title,
			const double & originOrdinal1, const double & originOrdinal2, const double & originOrdinal3,
			const double & arealRotation,
			const gsoap_resqml2_0_1::eml20__LengthUom & projectedUom,
			const gsoap_resqml2_0_1::eml20__TimeUom & timeUom,
			const gsoap_resqml2_0_1::eml20__LengthUom & verticalUom, const bool & isUpOriented)
{
	if (soapContext == nullptr) {
		throw invalid_argument("The EPC document where the local CRS will be stored cannot be null.");
	}

	gsoapProxy2_0_1 = soap_new_resqml2__obj_USCORELocalTime3dCrs(soapContext, 1);
	_resqml2__LocalTime3dCrs* local3dCrs = static_cast<_resqml2__LocalTime3dCrs*>(gsoapProxy2_0_1);
	local3dCrs->ArealRotation = soap_new_eml20__PlaneAngleMeasure(gsoapProxy2_0_1->soap, 1);
	local3dCrs->ArealRotation->__item = arealRotation;
	local3dCrs->ArealRotation->uom = eml20__PlaneAngleUom__rad;
	local3dCrs->XOffset = originOrdinal1;
	local3dCrs->YOffset = originOrdinal2;
	local3dCrs->ZOffset = originOrdinal3;
	local3dCrs->ZIncreasingDownward = !isUpOriented;
	local3dCrs->ProjectedUom = projectedUom;
	local3dCrs->VerticalUom = verticalUom;
	local3dCrs->TimeUom = timeUom;

	initMandatoryMetadata();
	setMetadata(guid, title, "", -1, "", "", -1, "", "");
}

LocalTime3dCrs::LocalTime3dCrs(soap* soapContext, const std::string & guid, const std::string & title,
			const double & originOrdinal1, const double & originOrdinal2, const double & originOrdinal3,
			const double & arealRotation,
			const gsoap_resqml2_0_1::eml20__LengthUom & projectedUom, const unsigned long & projectedEpsgCode,
			const gsoap_resqml2_0_1::eml20__TimeUom & timeUom,
			const gsoap_resqml2_0_1::eml20__LengthUom & verticalUom, const unsigned int & verticalEpsgCode, const bool & isUpOriented)
{
	if (projectedEpsgCode == 0 || verticalEpsgCode == 0) {
		throw invalid_argument("An EPSG code cannot be set to 0.");
	}
	init(soapContext, guid, title, originOrdinal1, originOrdinal2, originOrdinal3, arealRotation, projectedUom, timeUom, verticalUom, isUpOriented);
	_resqml2__LocalTime3dCrs* local3dCrs = static_cast<_resqml2__LocalTime3dCrs*>(gsoapProxy2_0_1);

	// Projected CRS
	eml20__ProjectedCrsEpsgCode* projCrs = soap_new_eml20__ProjectedCrsEpsgCode(gsoapProxy2_0_1->soap, 1);
	local3dCrs->ProjectedCrs = projCrs;
	projCrs->EpsgCode = projectedEpsgCode;

	// Vertical CRS
	eml20__VerticalCrsEpsgCode* vertCrs = soap_new_eml20__VerticalCrsEpsgCode(gsoapProxy2_0_1->soap, 1);
	local3dCrs->VerticalCrs = vertCrs;
	vertCrs->EpsgCode = verticalEpsgCode;
}

LocalTime3dCrs::LocalTime3dCrs(soap* soapContext, const std::string & guid, const std::string & title,
			const double & originOrdinal1, const double & originOrdinal2, const double & originOrdinal3,
			const double & arealRotation,
			const gsoap_resqml2_0_1::eml20__LengthUom & projectedUom, const std::string & projectedUnknownReason,
			const gsoap_resqml2_0_1::eml20__TimeUom & timeUom,
			const gsoap_resqml2_0_1::eml20__LengthUom & verticalUom, const std::string & verticalUnknownReason, const bool & isUpOriented)
{
	init(soapContext, guid, title, originOrdinal1, originOrdinal2, originOrdinal3, arealRotation, projectedUom, timeUom, verticalUom, isUpOriented);
	_resqml2__LocalTime3dCrs* local3dCrs = static_cast<_resqml2__LocalTime3dCrs*>(gsoapProxy2_0_1);

	// Projected CRS
	eml20__ProjectedUnknownCrs* projCrs = soap_new_eml20__ProjectedUnknownCrs(gsoapProxy2_0_1->soap, 1);
	local3dCrs->ProjectedCrs = projCrs;
	projCrs->Unknown = projectedUnknownReason;

	// Vertical CRS
	eml20__VerticalUnknownCrs* vertCrs = soap_new_eml20__VerticalUnknownCrs(gsoapProxy2_0_1->soap, 1);
	local3dCrs->VerticalCrs = vertCrs;
	vertCrs->Unknown = verticalUnknownReason;
}

LocalTime3dCrs::LocalTime3dCrs(soap* soapContext, const std::string & guid, const std::string & title,
			const double & originOrdinal1, const double & originOrdinal2, const double & originOrdinal3,
			const double & arealRotation,
			const gsoap_resqml2_0_1::eml20__LengthUom & projectedUom, const unsigned long & projectedEpsgCode,
			const gsoap_resqml2_0_1::eml20__TimeUom & timeUom,
			const gsoap_resqml2_0_1::eml20__LengthUom & verticalUom, const std::string & verticalUnknownReason, const bool & isUpOriented)
{
	if (projectedEpsgCode == 0) {
		throw invalid_argument("An EPSG code cannot be set to 0.");
	}
	init(soapContext, guid, title, originOrdinal1, originOrdinal2, originOrdinal3, arealRotation, projectedUom, timeUom, verticalUom, isUpOriented);
	_resqml2__LocalTime3dCrs* local3dCrs = static_cast<_resqml2__LocalTime3dCrs*>(gsoapProxy2_0_1);

	// Projected CRS
	eml20__ProjectedCrsEpsgCode* projCrs = soap_new_eml20__ProjectedCrsEpsgCode(gsoapProxy2_0_1->soap, 1);
	local3dCrs->ProjectedCrs = projCrs;
	projCrs->EpsgCode = projectedEpsgCode;

	// Vertical CRS
	eml20__VerticalUnknownCrs* vertCrs = soap_new_eml20__VerticalUnknownCrs(gsoapProxy2_0_1->soap, 1);
	local3dCrs->VerticalCrs = vertCrs;
	vertCrs->Unknown = verticalUnknownReason;
}

LocalTime3dCrs::LocalTime3dCrs(soap* soapContext, const std::string & guid, const std::string & title,
			const double & originOrdinal1, const double & originOrdinal2, const double & originOrdinal3,
			const double & arealRotation,
			const gsoap_resqml2_0_1::eml20__LengthUom & projectedUom, const std::string & projectedUnknownReason,
			const gsoap_resqml2_0_1::eml20__TimeUom & timeUom,
			const gsoap_resqml2_0_1::eml20__LengthUom & verticalUom, const unsigned int & verticalEpsgCode, const bool & isUpOriented)
{
	if (verticalEpsgCode == 0) {
		throw invalid_argument("An EPSG code cannot be set to 0.");
	}
	init(soapContext, guid, title, originOrdinal1, originOrdinal2, originOrdinal3, arealRotation, projectedUom, timeUom, verticalUom, isUpOriented);
	_resqml2__LocalTime3dCrs* local3dCrs = static_cast<_resqml2__LocalTime3dCrs*>(gsoapProxy2_0_1);

	// Projected CRS
	eml20__ProjectedUnknownCrs* projCrs = soap_new_eml20__ProjectedUnknownCrs(gsoapProxy2_0_1->soap, 1);
	local3dCrs->ProjectedCrs = projCrs;
	projCrs->Unknown = projectedUnknownReason;

	// Vertical CRS
	eml20__VerticalCrsEpsgCode* vertCrs = soap_new_eml20__VerticalCrsEpsgCode(gsoapProxy2_0_1->soap, 1);
	local3dCrs->VerticalCrs = vertCrs;
	vertCrs->EpsgCode = verticalEpsgCode;
}

gsoap_resqml2_0_1::eml20__TimeUom LocalTime3dCrs::getUnit() const
{
	return static_cast<_resqml2__LocalTime3dCrs*>(gsoapProxy2_0_1)->TimeUom;
}

std::string LocalTime3dCrs::getUnitAsString() const
{
	return gsoap_resqml2_0_1::soap_eml20__TimeUom2s(gsoapProxy2_0_1->soap, static_cast<_resqml2__LocalTime3dCrs*>(gsoapProxy2_0_1)->TimeUom);
}

