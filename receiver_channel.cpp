#include "receiver_channel.h"

#include <Arduino.h>

ReceiverChannel::ReceiverChannel(char pin)
:_pin(pin), _pointOfReference(0)
{}

ReceiverChannel::ReceiverChannel(char pin, short pointOfReference)
:_pin(pin), _pointOfReference(pointOfReference)
{}

void ReceiverChannel::initialize()
{
	pinMode(_pin, INPUT);
}

void ReceiverChannel::set_point_of_reference(short pointOfReference)
{
	_pointOfReference = pointOfReference;
}

void ReceiverChannel::set_point_of_reference_as_current_signal()
{
	_pointOfReference = get_raw_signal();
}

short ReceiverChannel::get_raw_signal() const
{
	return pulseIn(5, HIGH, 25000);
}

short ReceiverChannel::get_relative_signal() const
{
	return get_raw_signal() - _pointOfReference;
}

float ReceiverChannel::get_relative_percent_change() const
{
	return get_relative_signal()/1000.0f;
}