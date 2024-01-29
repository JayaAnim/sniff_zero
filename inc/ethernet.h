#ifndef ETHERNET_H
#define ETHERNET_H
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>
#include <arpa/inet.h>
#include <string.h>
#include "packet_globals.h"

/*LINKTYPE_ETHERNET 	1 	DLT_EN10MB 	IEEE 802.3 Ethernet (10Mb, 100Mb, 1000Mb, and up); the 10MB in the DLT_ name is historical */
int parse_LINKTYPE_ETHERNET(const u_char* data, bpf_u_int32 caplen, packet_t* parsed_packet); 

#endif
