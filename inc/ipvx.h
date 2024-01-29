#ifndef IPVX_H
#define IPVX_H
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>
#include <arpa/inet.h>
#include <string.h>
#include "packet_globals.h"

/*LINKTYPE_IPV6 	229 	DLT_IPV6 	Raw IPv6; the packet begins with an IPv6 header */
int parse_LINKTYPE_IPV6(const u_char* data, bpf_u_int32 caplen);

/*LINKTYPE_IPV4 	228 	DLT_IPV4 	Raw IPv4; the packet begins with an IPv4 header */
int parse_LINKTYPE_IPV4(const u_char* data, bpf_u_int32 caplen);

#endif
