#include "packet_parser.h"
#include "packet_globals.h"

int sniff_pkts_noloop(pcap_t* handle) {
    u_int32_t pkt_cntr = 0;

    //Initialize header and data structs for retrieving packets
    struct pcap_pkthdr* pkt_hdr;
    const u_char* pkt_data;
    
    //Retrieve relevant datalink name and id
    int dl = pcap_datalink(handle);
    const char* dl_name = pcap_datalink_val_to_name(dl);



    //Capture packets
    while (pcap_next_ex(handle, &pkt_hdr, &pkt_data)) {

        fprintf(stdout, "packet[%hd]===============================================================\n", pkt_cntr);
        //Initialize packet type for capturing
        packet_t* packet = (packet_t*)malloc(sizeof(packet_t)); 
    	packet->free = NULL;
    	packet->disp = NULL;

        if (parse_pcap_hdr(pkt_hdr, packet)) {
            fprintf(stdout, "[ERROR] could not parse pcap header\n");
        }
        else {
            disp_pcap_hdr(packet, dl_name);
        }

        parse_pkt_func func = get_pkt_parser(dl, dl_name);
        if (func == NULL) {
            fprintf(stdout, "[ERROR] linktype %s not supported\n", dl_name);
        }
        else {
            if (func(pkt_data, pkt_hdr->caplen, packet)) {
                fprintf(stdout, "[ERROR] could not properly parse packet\n");
            }
            else if (packet->disp != NULL) {
                packet->disp(packet);
            }
        }

        if (packet->free != NULL) {
                packet->free(packet);
        }
        free(packet);
        

        pkt_cntr++;
        if (pkt_cntr % 10 == 0) {
            char answer;
            printf("Do you want to continue capturing more packets? (y/n): ");
            scanf(" %c", &answer);
            if (answer != 'y' && answer != 'Y') {
                break;  // Exit the loop if the user doesn't want to continue
            }
        }
    }

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

void disp_pcap_hdr(packet_t* parsed_packet, const char* dl_name) {
    fprintf(stdout, "(datalink %s) (captured %u/%u) (time %ld.%06d)\n", dl_name, parsed_packet->pcap_hdr.caplen, parsed_packet->pcap_hdr.len, parsed_packet->pcap_hdr.ts.tv_sec, parsed_packet->pcap_hdr.ts.tv_usec);
}

int parse_pcap_hdr(struct pcap_pkthdr* hdr, packet_t* parsed_packet) {
    parsed_packet->pcap_hdr = *hdr;
    return 0;
}

parse_pkt_func get_pkt_parser(int dl_id, const char* dl_name) {
    parse_pkt_func func = NULL;    

    struct dl_cmd_if cmds[] = {
        { 1, parse_LINKTYPE_ETHERNET },
        { 127, parse_IEEE802_11_RADIOTAP },
        { 229, parse_LINKTYPE_IPV6 },
        { 228, parse_LINKTYPE_IPV4 },
    };

    for (int i = 0; i < sizeof(cmds) / sizeof(cmds[0]); ++i) {
        if (cmds[i].dl_id == dl_id) {
            func = cmds[i].cmd; 
        }
    }

    return func;
}

