#include "sniffer_api.h"

int parse_pkt_def(sniffer_api_t* self, const u_char* pkt, struct pcap_pkthdr* hdr) {
    /* Error check api is activated, dl ids match, and parse packet is defined */ 
    if (!!(self->_map & SNIFFER_API_ACTIVATED) == 0) {
        fprintf(stderr, "[ERROR] attempted to call sniffer api that has not been activated\n");
        return 1;
    }
    if (self->_parse_pkt == NULL) {
        fprintf(stderr, "[ERROR] attempted to call parser on sniffer api without parser specified (possibly unsupported data link type or bad instance)\n");
        return 1;
    }
    /* Check if sniffer api is allocated, if it is, free before continuing */
    if (!!(self->_map & SNIFFER_API_ALLOCATED)) {
        /* Error check that free instance func is defined */ 
        if (self->_reset_inst == NULL) {
            fprintf(stderr, "[ERROR] attempted to parse packet, when reset function is not defined (possibly unsupported data link type or bad instance)"); 
            return 1;
        }
        
        self->_reset_inst(self);
        self->_map = self->_map & ~SNIFFER_API_ALLOCATED;
    }

    /* Check if sniffer pcap header is allocated */
    if (!!(self->_map & SNIFFER_API_PCAP_HDR)) {
        self->pcap_hdr.ts.tv_sec = -1;
        self->pcap_hdr.ts.tv_usec = -1;
        self->pcap_hdr.caplen = -1;
        self->pcap_hdr.len = -1;
        self->_map = self->_map & ~SNIFFER_API_PCAP_HDR;
    }

    /* Error check that parse pcap header is defined then call */
    if (self->_parse_pcap_hdr == NULL) {
        fprintf(stderr, "[ERROR] attempted to parse pcap header, when parse function is not defined (possibly unsupported data link type or bad instance)\n"); 
        return 1;
    }

    if (self->_parse_pcap_hdr(self, pkt, hdr) == 1) {
        fprintf(stderr, "[WARNING] error occurred when attempting to parse pcap header (possibly invalid packet)\n"); 
    }
    else {
        self->_map = self->_map | SNIFFER_API_PCAP_HDR;
    }

    if (self->_parse_pkt(self, pkt, hdr) == 1) {
        fprintf(stderr, "[ERROR] error occurred when attempting to parse packet (possibly invalid packet or unsupported data link type)\n"); 
        return 1;
    }
    else {
        self->_map = self->_map | SNIFFER_API_ALLOCATED;
        return 0;
    }
}

void disp_pkt_def(sniffer_api_t* self) {
    /* Error check api is activated, dl ids match, packet is allocated and _disp_pkt is defined */ 
    if (!!(self->_map & SNIFFER_API_ACTIVATED) == 0) {
        fprintf(stderr, "[ERROR] attempted to call sniffer api that has not been activated\n");
        return;
    }
    if (self->_disp_pkt == NULL) {
        fprintf(stderr, "[ERROR] attempted to call display function on sniffer api without display function specified specified (possibly unsupported data link type or bad instance)\n");
        return;
    }
    if (!!(self->_map & SNIFFER_API_ALLOCATED) == 0) {
        fprintf(stderr, "[ERROR] attempted to display un-allocated packet\n"); 
        return;
    }

    if (!!(self->_map & SNIFFER_API_PCAP_HDR) == 0) {
        fprintf(stderr, "[WARNING] attempted to display un-allocated pcap header (internal error)\n"); 
    }
    else {
        _disp_pcap_hdr_def(self);
    }

    self->_disp_pkt(self);
}

int _parse_pcap_hdr_def(sniffer_api_t* self, const u_char* pkt, struct pcap_pkthdr* hdr) {
    /* Check if sniffer pcap header is allocated */
    if (!!(self->_map & SNIFFER_API_PCAP_HDR)) {
        fprintf(stderr, "[WARNING] parse pcap header called on already allocated pcap header (internal error)\n"); 
    }

    self->pcap_hdr = *hdr;
    self->_map = self->_map | SNIFFER_API_PCAP_HDR;

    return 0;
}

void _disp_pcap_hdr_def(sniffer_api_t* self) {
    if (!!(self->_map & SNIFFER_API_PCAP_HDR) == 0) {
        fprintf(stderr, "[ERROR] attempted to display un-allocated pcap header (internal error)\n"); 
        return;
    }

    fprintf(stdout, "(datalink %s) (captured %u/%u) (time %ld.%06d)\n", self->dl_name, self->pcap_hdr.caplen, self->pcap_hdr.len, self->pcap_hdr.ts.tv_sec, self->pcap_hdr.ts.tv_usec);
}
