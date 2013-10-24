#ifndef __RECEIVER_CHANNEL_H__
#define __RECEIVER_CHANNEL_H__

class ReceiverChannel
{
public:
	ReceiverChannel(char pin);
	ReceiverChannel(char pin, short pointOfReference);

	void initialize();

	void set_point_of_reference(short pointOfReference);
	void set_point_of_reference_as_current_signal();

	short get_raw_signal() const;
	short get_relative_signal() const;
	float get_relative_percent_change() const;

private:
	char _pin;
	short _pointOfReference;
};

#endif