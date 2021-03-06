/*
 * TelemetryMAVLink.h
 *
 *  Created on: 18.10.2015
 *      Author: cem
 */

#ifndef APPLICATION_INCLUDE_TELEMETRYMAVLINK_H_
#define APPLICATION_INCLUDE_TELEMETRYMAVLINK_H_

#include <USART.h>

#include "TelemetryAdapter.h"
#include "MAVLinkLayer.h"
#include "MAVLinkComm.h"

namespace App
{

class TelemetryMAVLink: public TelemetryAdapter<TelemetryProtocol::MAVLink>
{
private:
	MAVLinkComm mav;
	uint8_t m_run;
protected:
	void Init() override;
	void Run(void) override;
	void DeInit() override;
public:
	TelemetryMAVLink(HAL::USART& usart) :
			TelemetryAdapter(), mav(usart, MAVLINK_COMM_2), m_run(1)
	{
	}
};

} /* namespace Application*/

#endif /* APPLICATION_INCLUDE_TELEMETRYMAVLINK_H_ */
