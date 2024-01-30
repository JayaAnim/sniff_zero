#include <stdio.h>
#include <pcap/pcap.h>
#include <arpa/inet.h>
#include "packet_parser.h"
#include "interface_opts.h"
#include "sniffer_config.h"
#include "sniffer.h"
#include <unistd.h>

int main(int argc, char** argv) {

    char* if_name = retr_if();
    
    pcap_t* handle = init_handle(if_name);

    u_int8_t config_code = config_handle(handle);

    int status_code = activate_handle(handle);

    int code = sniff_pkts_noloop(handle);

    free(if_name);
    //End program
    pcap_close(handle);

    
    return 0;

}
