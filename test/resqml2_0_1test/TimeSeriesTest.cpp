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
#include "TimeSeriesTest.h"
#include "../config.h"
#include "../catch.hpp"
#include "resqml2/TimeSeries.h"

using namespace std;
using namespace common;
using namespace resqml2_0_1test;
using namespace resqml2;

const char* TimeSeriesTest::defaultUuid = "0b8fc144-8e71-4f2a-a062-60c2d17fdc12";
const char* TimeSeriesTest::inputTile = "Time Series";

TimeSeriesTest::TimeSeriesTest(const string & epcDocPath)
	: AbstractResqmlDataObjectTest(epcDocPath, defaultUuid, inputTile) {
}

TimeSeriesTest::TimeSeriesTest(EpcDocument * epcDoc, bool init)
	: AbstractResqmlDataObjectTest(epcDoc, defaultUuid, inputTile) {
		if (init)
			this->initEpcDoc();
		else
			this->readEpcDoc();
}

void TimeSeriesTest::initEpcDocHandler() {
	TimeSeries* timeSeries = this->epcDoc->createTimeSeries(this->uuid, this->title);
	REQUIRE( timeSeries != nullptr );

	timeSeries->pushBackTimestamp(1378217895);
	timeSeries->pushBackTimestamp(1409753895);
	timeSeries->pushBackTimestamp(1441289895);
}

void TimeSeriesTest::readEpcDocHandler() {
	vector<TimeSeries*> timeSeriesSet = this->epcDoc->getTimeSeriesSet();
	REQUIRE(timeSeriesSet.size() == 1);

	// getting the TimeSeries
	TimeSeries* timeSeries = timeSeriesSet[0];

	// **********************
	// reading the TimeSeries

	// getTimestampIndex
	REQUIRE( timeSeries->getTimestampIndex(1378217895) == 0 );
	REQUIRE( timeSeries->getTimestampIndex(1409753895) == 1 );
	REQUIRE( timeSeries->getTimestampIndex(1441289895) == 2 );

	// getTimestampCount
	REQUIRE( timeSeries->getTimestampCount() == 3);

	// getTimestamp
	REQUIRE( timeSeries->getTimestamp(0) == 1378217895 );
	REQUIRE( timeSeries->getTimestamp(1) == 1409753895 );
	REQUIRE( timeSeries->getTimestamp(2) == 1441289895 );
}

