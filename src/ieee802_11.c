#include "ieee802_11.h"

/*LINKTYPE_IEEE802_11_RADIOTAP 	127 	DLT_IEEE802_11_RADIO 	Radiotap link-layer information followed by an 802.11 header */
int parse_IEEE802_11_RADIOTAP(const u_char* data, bpf_u_int32 caplen, packet_t* parsed_packet) {
    fprintf(stdout, "parse called, I do nothing yet\n");
    parsed_packet->disp = disp_IEEE802_11_RADIOTAP;
    parsed_packet->free = free_IEEE802_11_RADIOTAP;
    return 0;
}

int parse_IEEE802_11_RADIOTAP_hdr(const u_char* data, bpf_u_int32 caplen, packet_t* parsed_packet) {
    fprintf(stdout, "parse hdr called, I do nothing yet\n");
    //parsed_packet->spcl_hdr = (radiotap_hdr_t*)malloc(sizeof(radiotap_hdr_t));
    //parsed_packet->spcl_hdr = (radiotap_hdr_t*) data;
    return 0;
}

int parse_IEEE802_11_hdr(const u_char* data, bpf_u_int32 caplen, packet_t* parsed_packet) {
    return 0;
}

int parse_IEEE802_11_pkt(const u_char* data, bpf_u_int32 caplen, packet_t* parsed_packet) {
    return 0;
}

void disp_IEEE802_11_RADIOTAP(packet_t* parsed_packet) {
    fprintf(stdout, "disp called, I do nothing yet\n");
    /*
    fprintf(stdout, "[Radiotap Header Info] (Version %u) (Header Length %u)\n",
        ((radiotap_hdr_t*)(parsed_packet->spcl_hdr))->it_version,
        ((radiotap_hdr_t*)(parsed_packet->spcl_hdr))->it_len);
    */
}

void free_IEEE802_11_RADIOTAP(packet_t* parsed_packet) {
    fprintf(stdout, "free called, I do nothing yet\n");
    //free(parsed_packet->spcl_hdr);
}

