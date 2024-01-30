#include "packet_parser.h"
#include "sniffer.h"

int sniff_pkts_noloop(pcap_t* handle) {
    u_int32_t pkt_cntr = 0;

    int dl = pcap_datalink(handle);

    //Initialize header and data structs for retrieving packets
    struct pcap_pkthdr* pkt_hdr;
    const u_char* pkt_data;

    sniffer_api_t* sniffer_handle = init_sniffer(dl);

    //Capture packets
    while (pcap_next_ex(handle, &pkt_hdr, &pkt_data)) {

        fprintf(stdout, "packet[%hd]===============================================================\n", pkt_cntr);
        sniffer_handle->parse_pkt(sniffer_handle, pkt_data, pkt_hdr);
        sniffer_handle->disp_pkt(sniffer_handle);

        pkt_cntr++;
        if (pkt_cntr % 30 == 0) {
            char answer;
            printf("Do you want to continue capturing more packets? (y/n): ");
            scanf(" %c", &answer);
            if (answer != 'y' && answer != 'Y') {
                break;  // Exit the loop if the user doesn't want to continue
            }
        }
    }

    close_sniffer(sniffer_handle, dl);

    return 0;
}

void disp_dls(pcap_t* pcap_inst) {
    int* dls;
    int num_dls = pcap_list_datalinks(pcap_inst, &dls);
    
    for (int i = 0; i < num_dls; ++i) {
        fprintf(stdout, "Datalink[%d]: %s\n", i, pcap_datalink_val_to_name(dls[i]));
    }

    pcap_free_datalinks(dls);
}
