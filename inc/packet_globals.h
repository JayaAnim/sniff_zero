#ifndef PACKET_GLOBALS_H
#define PACKET_GLOBALS_H
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>
#include <arpa/inet.h>
#include <string.h>

struct packet;

//For displaying packet information
typedef void (*disp_pkt_func)(struct packet*);

//For displaying packet information
typedef void (*free_pkt_func)(struct packet*);

typedef struct packet {
    struct pcap_pkthdr pcap_hdr;
    void* spcl_hdr;
    void* norm_hdr;
    void* pkt_data;
    disp_pkt_func disp;
    free_pkt_func free;
} packet_t;

//Return 0 for no error, 1 for error
typedef int (*parse_pkt_func)(const u_char*, bpf_u_int32, packet_t*);



#endif
