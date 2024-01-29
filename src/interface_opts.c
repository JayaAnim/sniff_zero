#include "interface_opts.h"
#include <stdio.h>

char* retr_if() {

    char iface_errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t* interfaces;

    int search_code = pcap_findalldevs(&interfaces, iface_errbuf);

    //Failed to search
    if (search_code < 0) {
        fprintf(stderr, "pcap failed to search for devices\n");
        fprintf(stderr, "[ERROR]: %s\n", iface_errbuf);
        pcap_freealldevs(interfaces);
        exit(search_code);
    }

    //Searched with warning
    else if (search_code > 0) {
        fprintf(stderr, "pcap searched for devices with warning\n");
        fprintf(stderr, "[WARNING]: %s\n", iface_errbuf);
    }

    pcap_if_t* head = interfaces;
    int num_if = 0;
    while (head != NULL) {
        disp_if(head, num_if);             
        ++num_if;
        head = head->next;
    }

    if (num_if == 0) {
        fprintf(stderr, "no interfaces found, exiting");
        pcap_freealldevs(interfaces);
        exit(1);
    }

    //Prompt user to select if
    u_int16_t if_id = slct_if(num_if);
    fprintf(stdout, "id selected %d", if_id);

    //Retrieve if
    for (int i = 0; i < if_id; ++i) {
        interfaces = interfaces->next;
        if (interfaces == NULL) {
            fprintf(stderr, "attempted to access out of bounds interface, check bounds handling\n");
            pcap_freealldevs(interfaces);
            exit(1);
        }
    }
    char* if_name = strdup(interfaces->name);

    //Free array of interfaces
    pcap_freealldevs(interfaces);

    return if_name;
}

void disp_addr(pcap_addr_t* addr) {
    if (addr->addr->sa_family == AF_INET || addr->addr->sa_family == AF_INET6) {
        fprintf(stdout, "address---------------------------------------------\n");
        if (addr->addr != NULL) {
            char* s = addr_to_str(addr->addr);
            fprintf(stdout, "\t[addr] %s\n", s); 
            free(s);
        }
        if (addr->netmask != NULL) {
            char* s = addr_to_str(addr->netmask);
            fprintf(stdout, "\t[netmask] %s\n", s); 
            free(s);
        }
        if (addr->broadaddr != NULL) { 
            char* s = addr_to_str(addr->broadaddr);
            fprintf(stdout, "\t[broadcast addr] %s\n", s); 
            free(s);
        }
        if (addr->dstaddr != NULL) {
            char* s = addr_to_str(addr->dstaddr);
            fprintf(stdout, "\t[destination addr] %s\n", s); 
            free(s);
        }
    }
    fprintf(stdout, "\n");
}

void disp_if(pcap_if_t* if_inst, int num) {

    if (if_inst->flags & PCAP_IF_WIRELESS) {
        fprintf(stdout, "iface[%d]===============================================\n\n", num);
        if (if_inst->name != NULL) fprintf(stdout, "[name] %s\n", if_inst->name);
        if (if_inst->description != NULL) fprintf(stdout, "[description] %s\n", if_inst->description);

        pcap_addr_t* addresses = if_inst->addresses; 
        while (addresses != NULL) {
            disp_addr(addresses);
            addresses = addresses->next;
        }
    }
}

char* addr_to_str(struct sockaddr* addr) {
    if (addr->sa_family == AF_INET) {
        char* s = (char*)malloc(INET_ADDRSTRLEN);
        struct sockaddr_in* cnvrt_addr = (struct sockaddr_in*)addr;
        inet_ntop(AF_INET, &cnvrt_addr->sin_addr, s, INET_ADDRSTRLEN);
        return s;
    }
    else if (addr->sa_family == AF_INET6) {
        char* s = (char*)malloc(INET6_ADDRSTRLEN);
        struct sockaddr_in6* cnvrt_addr = (struct sockaddr_in6*)addr;
        inet_ntop(AF_INET6, &cnvrt_addr->sin6_addr, s, INET6_ADDRSTRLEN);
        return s;
    }
    else {
        return (char*)"addr not convertable";
    }
    return NULL;
}

u_int16_t slct_if(int num_if) {
    u_int16_t if_id;
    fprintf(stdout, "select valid interface number\n");

    while (1) {
        if (scanf("%hu", &if_id) == 1 && if_id >= 0 && if_id < num_if) {
            return if_id; 
        }
        else {
            fprintf(stdout, "invalid input, please select valid interface number\n");
        }
    }
}
