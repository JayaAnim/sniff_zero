#include "sniffer_config.h"

pcap_t* init_handle(char* if_name) {

    //Initialize pcap instnce
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle = pcap_create(if_name, errbuf);

    if (handle == NULL) {
        fprintf(stdout, "pcap failed to initialize\n");
        fprintf(stdout, "[ERROR]: %s", errbuf);
        pcap_close(handle);
        exit(1);
    }

    return handle;
}

u_int8_t config_handle(pcap_t* handle) {
    u_int8_t err = 0;

    //Set packet timeout to 1000ms
    pcap_set_timeout(handle, 100);

    //Set to promiscuous mode (capture all packets even unrecognized ones)
    if (pcap_set_promisc(handle, 1) == 0) {
        fprintf(stdout, "successfully set pcap to to promiscuous mode\n");
    }
    else {
        pcap_set_promisc(handle, 0);
        fprintf(stdout, "failed to set pcap to to promiscuous mode\n");
        err = 1;
    }

    //Allow all packets to be received even those from unassociated networks
    if (pcap_can_set_rfmon(handle)) {
        fprintf(stdout, "successfully set pcap to monitor mode\n");
        pcap_set_rfmon(handle, 1);
    }
    else {
        fprintf(stdout, "failed to set pcap to monitor mode\n");
        err = 1;
    }


    //Set snapshop length to 1024 to prevent packet loss on small systems (i.e flipper zero)
    if (pcap_set_snaplen(handle, 1024) == 0) {
        fprintf(stdout, "successfully set snap len to %d bytes\n", 1024);
    }
    else {
        fprintf(stdout, "failed to set to set snap len\n");
        err = 1;
    }
    
    return err;
}

int activate_handle(pcap_t* handle) {

    // Activate capture
    int status_code = pcap_activate(handle);

    if (status_code >= 0) {
        if (status_code == PCAP_WARNING) {
            fprintf(stdout, "activated, with warning: %s\n", pcap_geterr(handle));
        } else if (status_code != 0) {
            // warning
            fprintf(stdout, "activated, with warning: %s\n", pcap_statustostr(status_code));
        } else {
            // no warning
            fprintf(stdout, "activated successfully without warning\n");
        }
    } else {
        if (status_code == PCAP_ERROR) {
            fprintf(stdout, "failed to activate: %s\n", pcap_geterr(handle));
        } else {
            fprintf(stdout, "failed to activate: %s\n", pcap_statustostr(status_code));
        }
        exit(EXIT_FAILURE);
    }

    return status_code;
}
