#ifndef PACKET_PARSER_H
#define PACKET_PARSER_H
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>
#include <arpa/inet.h>
#include <string.h>
#include "packet_globals.h"
#include "ieee802_11.h"
#include "ipvx.h"
#include "ethernet.h"

//Returns 0 for no error, 1 for error
int sniff_pkts_noloop(pcap_t* handle);

void disp_dls(pcap_t* pcap_inst);

void disp_pcap_hdr(const char* dl_name);

int parse_pcap_hdr(struct pcap_pkthdr* hdr);

parse_pkt_func get_pkt_parser(int dl_id, const char* dl_name);

struct dl_cmd_if {
    int dl_id;
    parse_pkt_func cmd;
};


#endif
