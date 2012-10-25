#ifndef _TCP_RECEIVER_H_
#define _TCP_RECEIVER_H_

#include "libpaxos_priv.h"
#include "carray.h"
#include <event2/event.h>
#include <event2/bufferevent.h>

struct tcp_receiver
{
	bufferevent_data_cb callback;
	void* arg;
	struct evconnlistener* listener;
	struct carray* bevs;
};

struct tcp_receiver*
tcp_receiver_new(struct event_base* b, address* a, bufferevent_data_cb callback, void* arg);
void
tcp_receiver_write_all(struct tcp_receiver* r, const void* data, size_t size);

#endif