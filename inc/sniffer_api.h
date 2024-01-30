#ifndef SNIFFER_API_H
#define SNIFFER_API_H
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>
#include <arpa/inet.h>

#define SNIFFER_API_ACTIVATED 0x01 /* checks if api inst has been initialized properly */
#define SNIFFER_API_ALLOCATED 0x02 /* checks if api inst has a parsed packet stored (returns false if packet has been reset or never allocated _*/
#define SNIFFER_API_DL 0x04 /* checks if datalink is specified */
#define SNIFFER_API_PCAP_HDR 0x08  /* checks if a parsed pcap header is stored */

/* declaration sniffer_api will be defined, enables func definitions */
struct sniffer_api;

/* func definitions for sniffer api */
typedef int (*api_callable_parse)(struct sniffer_api*, const u_char*, struct pcap_pkthdr*);
typedef int (*_api_intern_parse)(struct sniffer_api*, const u_char*, struct pcap_pkthdr*);
typedef void (*api_callable_disp)(struct sniffer_api*);
typedef void (*_api_intern_disp)(struct sniffer_api*); 
typedef void (*_api_intern_reset)(struct sniffer_api*); 
typedef int (*_api_set_func)(struct sniffer_api*);

typedef struct sniffer_api {
    /* bitmap for internal error checking */
    u_int16_t _map;

    /* api datalink information */
    int dl_id;
    const char* dl_name;

    /* parsed packet data */
    struct pcap_pkthdr pcap_hdr;
    void* spcl_hdr;
    void* pkt_hdr;
    void* pkt_data;

    /* general packet data which applies to all */
    //TODO

    /* function calls available to users */
    api_callable_parse parse_pkt; /* consistent across all api instances, defined here */
    api_callable_disp disp_pkt; /* consistent across all api instances, defined here */

    /* internal function calls */
    _api_intern_parse _parse_pcap_hdr; /* consistent across all api instances, defined here */
    _api_intern_parse _parse_pkt;
    _api_intern_disp _disp_pcap_hdr; /* consistent across all api instances, defined here */
    _api_intern_disp _disp_pkt;
    _api_intern_reset _reset_inst; /* this resets all data, and only frees datastructures inside spcl_hdr, pkt_hdr, and pkt_data. Therefore it is used for both resetting the instance or as a helper func to sniffer_close. */

} sniffer_api_t;

int parse_pkt_def(sniffer_api_t* self, const u_char* pkt, struct pcap_pkthdr* hdr);

void disp_pkt_def(sniffer_api_t* self);

int _parse_pcap_hdr_def(sniffer_api_t* self, const u_char* pkt, struct pcap_pkthdr* hdr);

void _disp_pcap_hdr_def(sniffer_api_t* self);

#endif
