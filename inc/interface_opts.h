#ifndef INTERFACE_OPTS_H
#define INTERFACE_OPTS_H
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>
#include <arpa/inet.h>
#include <string.h>
#include "sniffer_api.h"

//Displays interfaces to user and returns name of selection
char* retr_if();

//Displays addresses to user (helper func)
void disp_addr(pcap_addr_t* addr);

//Displays interfaces to user (helper func)
void disp_if(pcap_if_t* if_inst, int num);

//Converts address to string (helper func)
char* addr_to_str(struct sockaddr* addr);

//Returns selection of usr and validates selection (helper func)
u_int16_t slct_if(int num_if);

#endif
