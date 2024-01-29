#ifndef SNIFFER_CONFIG_H
#define SNIFFER_CONFIG_H
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>
#include <arpa/inet.h>
#include <string.h>
#include "packet_globals.h"

/*
 * Helper functions for main to containerize error checking
 */

pcap_t* init_handle(char* if_name);

//Returns true if all configurations succeed
u_int8_t config_handle(pcap_t* handle);

int activate_handle(pcap_t* handle);

#endif
