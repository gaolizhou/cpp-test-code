//
// Created by lizgao on 8/15/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <event2/event.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
namespace {
#define SVRADDR "127.0.0.1"
#define PORT 7890

static void buff_input_cb(struct bufferevent *bev, void *ctx) {

  printf("***in %s\n", __func__);

  printf("len=%d\n", evbuffer_get_length(bufferevent_get_input(bev)));

  return;
}

static void buff_ev_cb(struct bufferevent *bev, short events, void *ctx) {

  printf("in %s,  event=%#x\n", __func__, events);

  if (events & BEV_EVENT_CONNECTED) {
    printf("***BEV_EVENT_CONNECTED\n");
    struct evbuffer *ev_sync = evbuffer_new();
    char msg[64] = "I am from client";
    evbuffer_add(ev_sync, msg, strlen(msg));
    bufferevent_write_buffer(bev, ev_sync);
  } else if (events & BEV_EVENT_ERROR) {
    printf("***BEV_EVENT_ERROR\n");
  }
  return;
}

int bufferevent_client() {

  int sockfd;
  struct event_base *p_base;
  struct bufferevent *p_event;

  struct sockaddr_in addr;;

  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);

  if (inet_pton(AF_INET, SVRADDR, &addr.sin_addr) <= 0) {
    printf("inet_pton");
    exit(1);
  }

  if ((p_base = event_base_new()) == NULL) {
    printf("event_base_new ");
    return 1;
  }

  if ((p_event = bufferevent_socket_new(p_base, -1, BEV_OPT_CLOSE_ON_FREE)) == NULL) {
    printf("bufferevent_socket_new ");
    return 1;
  }

  if ((sockfd = bufferevent_socket_connect(p_event, (struct sockaddr *) &addr, sizeof(addr))) < 0) {
    printf("bufferevent_socket_connect ");
    return 1;
  }

  bufferevent_setcb(p_event, buff_input_cb, NULL, buff_ev_cb, p_base);
  bufferevent_enable(p_event, EV_READ);

  event_base_dispatch(p_base);

  return 0;
}

}
void bufferevent_client_test() {
  bufferevent_client();
}