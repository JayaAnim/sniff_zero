#include "ieee802_11.h"

/*LINKTYPE_IEEE802_11_RADIOTAP 	127 	DLT_IEEE802_11_RADIO 	Radiotap link-layer information followed by an 802.11 header */
int parse_IEEE802_11_RADIOTAP(const u_char* data, bpf_u_int32 caplen) {
    fprintf(stdout, "parse called, I do nothing yet\n");
    disp_pkt = disp_IEEE802_11_RADIOTAP;
    free_pkt = free_IEEE802_11_RADIOTAP;
    return 0;
}

int parse_IEEE802_11_RADIOTAP_hdr(const u_char* data, bpf_u_int32 caplen) {
    fprintf(stdout, "parse hdr called, I do nothing yet\n");
    //packet.spcl_hdr = (radiotap_hdr_t*)malloc(sizeof(radiotap_hdr_t));
    //packet.spcl_hdr = (radiotap_hdr_t*) data;
    return 0;
}

int parse_IEEE802_11_hdr(const u_char* data, bpf_u_int32 caplen) {
    return 0;
}

int parse_IEEE802_11_pkt(const u_char* data, bpf_u_int32 caplen) {
    return 0;
}

void disp_IEEE802_11_RADIOTAP() {
    fprintf(stdout, "disp called, I do nothing yet\n");
    /*
    fprintf(stdout, "[Radiotap Header Info] (Version %u) (Header Length %u)\n",
        ((radiotap_hdr_t*)(packet.spcl_hdr))->it_version,
        ((radiotap_hdr_t*)(packet.spcl_hdr))->it_len);
    */
}

void free_IEEE802_11_RADIOTAP() {
    fprintf(stdout, "free called, I do nothing yet\n");
    //free(packet.spcl_hdr);
}

