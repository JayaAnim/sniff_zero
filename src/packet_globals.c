#include "packet_globals.h"

packet_t packet;
disp_pkt_func disp_pkt;
disp_pkt_func free_pkt;


void init_globals() {
    packet.norm_hdr = NULL;
    packet.pkt_data = NULL;
    packet.spcl_hdr = NULL;
    disp_pkt = NULL;
    free_pkt = NULL;
}
