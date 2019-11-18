#pragma once
#include <ipn.hpp>

using namespace m2d;

class simple_response_t : public ipn::packable_message::abstract_message_t
{
public:
	std::string message;
	MSGPACK_DEFINE(message);

	simple_response_t() {}
	simple_response_t(std::string message)
	    : message(message)
	{
	}

	msgpack::sbuffer packed_data() const
	{
		msgpack::sbuffer packed;
		msgpack::pack(packed, *this);
		return packed;
	};

	void *data() const
	{
		return packed_data().data();
	}

	size_t size() const
	{
		return packed_data().size();
	}
};

class simple_request_t : public ipn::packable_message::abstract_message_t
{
public:
	std::string message;
	MSGPACK_DEFINE(message);
	simple_request_t() {}
	simple_request_t(std::string message)
	    : message(message)
	{
	}

	msgpack::sbuffer packed_data() const
	{
		msgpack::sbuffer packed;
		msgpack::pack(packed, *this);
		return packed;
	};

	void *data() const
	{
		return packed_data().data();
	}

	size_t size() const
	{
		return packed_data().size();
	}
};