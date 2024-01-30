#include "ieee802_11.h"

//LINKTYPE_IEEE802_11_RADIOTAP 	127 	DLT_IEEE802_11_RADIO 	Radiotap link-layer information followed by an 802.11 header 
int _parse_IEEE802_11_RADIOTAP(sniffer_api_t* self, const u_char* data, struct pcap_pkthdr* hdr) {
    if (self->dl_id != 127) {
        fprintf(stderr, "[ERROR] attempted to call parse function of different linktype (%d)", self->dl_id);
        return 1;
    }
    // TODO: parse_hdr
    // TODO: parse_pkt
    _parse_IEEE802_11_RADIOTAP_hdr(self, data, hdr->caplen);
    return 0;

}

void _disp_IEEE802_11_RADIOTAP(sniffer_api_t* self) {
    if (self->dl_id != 127) {
        fprintf(stderr, "[ERROR] attempted to call display function of different linktype (%d)", self->dl_id);
        return;
    }
    fprintf(stdout, "(RADIOTAP VERSION %u) (RADIOTAP LENGTH %u)\n",((radiotap_hdr_t*)self->spcl_hdr)->it_version, ((radiotap_hdr_t*)self->spcl_hdr)->it_len); 
}

void _reset_IEEE802_11_RADIOTAP(sniffer_api_t* self) {
    ((radiotap_hdr_t*)self->spcl_hdr)->it_version = 0; 
    ((radiotap_hdr_t*)self->spcl_hdr)->it_pad = 0; 
    ((radiotap_hdr_t*)self->spcl_hdr)->it_len = 0; 
    ((radiotap_hdr_t*)self->spcl_hdr)->it_present = 0; 
}

int _set_IEEE802_11_RADIOTAP(sniffer_api_t* self) {
    if (self->dl_id != 127) {
        fprintf(stderr, "[ERROR] attempted to call set function of different linktype (%d)", self->dl_id);
        return 1;
    }
    // TODO: self->pkt_data
    // TODO: self->pkt_hdr
    self->spcl_hdr = (radiotap_hdr_t*)malloc(sizeof(radiotap_hdr_t));
    self->_disp_pkt = _disp_IEEE802_11_RADIOTAP;
    self->_parse_pkt = _parse_IEEE802_11_RADIOTAP;
    self->_reset_inst = _reset_IEEE802_11_RADIOTAP;
                                                                                                                                                                                                                                                  
    return 0;
}


void _prnt_binary_arr(const u_char* data, bpf_u_int32 caplen) {
    for (int i = 0; i < caplen; ++i) {
        for (int j = 0; j < 8; ++j) {
            u_int8_t byte = 128;
            u_int8_t msb = ( data[i] << j ) & byte;
            u_int8_t lsb = msb >> 7;
            printf("%u", lsb);
        }
        printf(" ");
    }
    printf("-------------------------------------------------------------------------------------------------------\n");
}
/* non-required functions */
int _parse_IEEE802_11_RADIOTAP_hdr(sniffer_api_t* self, const u_char* data, bpf_u_int32 caplen) {

    radiotap_hdr_t* other_example = (radiotap_hdr_t*) data;

    // TODO: finish
    //self->spcl_hdr = (radiotap_hdr_t*) data;
    ((radiotap_hdr_t*)self->spcl_hdr)->it_version |= data[0];

    ((radiotap_hdr_t*)self->spcl_hdr)->it_pad = 0;
    
    ((radiotap_hdr_t*)self->spcl_hdr)->it_len |= data[1];
    ((radiotap_hdr_t*)self->spcl_hdr)->it_len <<= 8;
    ((radiotap_hdr_t*)self->spcl_hdr)->it_len |= data[2];

    ((radiotap_hdr_t*)self->spcl_hdr)->it_present |= data[3];
    ((radiotap_hdr_t*)self->spcl_hdr)->it_present <<= 8;
    ((radiotap_hdr_t*)self->spcl_hdr)->it_present |= data[4];
    ((radiotap_hdr_t*)self->spcl_hdr)->it_present <<= 8;
    ((radiotap_hdr_t*)self->spcl_hdr)->it_present |= data[5];
    ((radiotap_hdr_t*)self->spcl_hdr)->it_present <<= 8;
    ((radiotap_hdr_t*)self->spcl_hdr)->it_present |= data[6];


    printf("-----------full packet example\n");
    _prnt_binary_arr(data, caplen);

    printf("----------\"other_example\" example\n");
    _prnt_binary_arr((const u_char*)other_example, 8); 

    printf("----------\"current example\" example\n");
    _prnt_binary_arr(self->spcl_hdr, 8);

    printf("----------\"other example\" size\n");
    printf("%ld\n", sizeof(*other_example));
    printf("----------\"current example\" size\n");
    printf("%ld\n", sizeof(*self->spcl_hdr));

    return 0;

}

int _parse_IEEE802_11_hdr(sniffer_api_t* self, const u_char* data, bpf_u_int32 caplen) {
    fprintf(stdout, "NOT YET COMPLETE\n");
    return 0;
}

int _parse_IEEE802_11_pkt(sniffer_api_t* self, const u_char* data, bpf_u_int32 caplen) {
    fprintf(stdout, "NOT YET COMPLETE\n");
    return 0;
}
