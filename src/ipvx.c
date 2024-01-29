#include "ipvx.h"

/*LINKTYPE_IPV6 	229 	DLT_IPV6 	Raw IPv6; the packet begins with an IPv6 header */
int parse_LINKTYPE_IPV6(const u_char* data, bpf_u_int32 caplen, packet_t* parsed_packet) {
    fprintf(stdout, "datalink type not supported yet\t");
    return 1;
}

/*LINKTYPE_IPV4 	228 	DLT_IPV4 	Raw IPv4; the packet begins with an IPv4 header */
int parse_LINKTYPE_IPV4(const u_char* data, bpf_u_int32 caplen, packet_t* parsed_packet) {
    fprintf(stdout, "datalink type not supported yet\t");
    return 1;
}
