#ifndef IEEE802_11_H
#define IEEE802_11_H
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>
#include <arpa/inet.h>
#include <string.h>
#include "sniffer_api.h"

struct ieee80211_radiotap_header {
    u_int8_t it_version; // Radiotap header version, should always be 0 
    u_int8_t it_pad; // Padding
    u_int16_t it_len; // Length of radiotap header
    u_int32_t it_present; // Radiotap bitmask for options
} __attribute__((__packed__)); // Packed to ensure packets match up

//typdef on different line to ensure __attribute__ is not ignored
typedef struct ieee80211_radiotap_header radiotap_hdr_t;

typedef struct ieee80211_radiotap_packet {
    radiotap_hdr_t hdr;
    u_int8_t num_it_present; // If bit 31 is set in original it_present, another it_present follows immediately after, this contains the number of it_presents found 
    u_int32_t* it_present_list; // List of it_present bitmaps, in order found
} radiotap_pkt_t;

//LINKTYPE_IEEE802_11_RADIOTAP 	127 	DLT_IEEE802_11_RADIO 	Radiotap link-layer information followed by an 802.11 header 
int _parse_IEEE802_11_RADIOTAP(sniffer_api_t* self, const u_char* data, struct pcap_pkthdr* hdr);

void _disp_IEEE802_11_RADIOTAP(sniffer_api_t* self);

void _reset_IEEE802_11_RADIOTAP(sniffer_api_t* self);

int _set_IEEE802_11_RADIOTAP(sniffer_api_t* self);

/* non-required functions */
int _parse_IEEE802_11_RADIOTAP_hdr(sniffer_api_t* self, const u_char* data, bpf_u_int32 caplen);

int _parse_IEEE802_11_hdr(sniffer_api_t* self, const u_char* data, bpf_u_int32 caplen);

int _parse_IEEE802_11_pkt(sniffer_api_t* self, const u_char* data, bpf_u_int32 caplen);

#endif
