#ifndef SNIFFER_H
#define SNIFFER_H
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>
#include <arpa/inet.h>
#include <string.h>
#include "sniffer_api.h"
#include "ieee802_11.h"
#include "ipvx.h"
#include "ethernet.h"

sniffer_api_t* init_sniffer(int dl_id);

_api_set_func _get_api_set_func(sniffer_api_t* api_inst, int dl_id);

void close_sniffer(sniffer_api_t* api_inst, int dl_id);

typedef struct _set_func_row {
    int dl_id;
    _api_set_func func;
} _set_func_row_t;


#endif
