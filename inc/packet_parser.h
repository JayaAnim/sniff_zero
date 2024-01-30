#ifndef PACKET_PARSER_H
#define PACKET_PARSER_H
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>
#include <arpa/inet.h>
#include <string.h>
#include "sniffer.h"

//Returns 0 for no error, 1 for error
int sniff_pkts_noloop(pcap_t* handle);

void disp_dls(pcap_t* pcap_inst);


#endif
