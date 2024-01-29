#ifndef PACKET_GLOBALS_H
#define PACKET_GLOBALS_H
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>
#include <arpa/inet.h>
#include <string.h>

struct packet;

//For displaying packet information
typedef void (*disp_pkt_func)();

//For displaying packet information
typedef void (*free_pkt_func)();

typedef struct packet {
    struct pcap_pkthdr pcap_hdr;
    void* spcl_hdr;
    void* norm_hdr;
    void* pkt_data;
} packet_t;

extern packet_t packet;
extern disp_pkt_func disp_pkt;
extern disp_pkt_func free_pkt;

//Return 0 for no error, 1 for error
typedef int (*parse_pkt_func)(const u_char*, bpf_u_int32);

void init_globals();

#endif
