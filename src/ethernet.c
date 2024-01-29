#include "ethernet.h"

/*LINKTYPE_ETHERNET 	1 	DLT_EN10MB 	IEEE 802.3 Ethernet (10Mb, 100Mb, 1000Mb, and up); the 10MB in the DLT_ name is historical */
int parse_LINKTYPE_ETHERNET(const u_char* data, bpf_u_int32 caplen, packet_t* parsed_packet) { 
    fprintf(stdout, "datalink type not supported yet\t");
    return 1;
}
