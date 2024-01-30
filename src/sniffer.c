#include "sniffer.h"
#include "ieee802_11.h"
#include "sniffer_api.h"
#include <pcap/pcap.h>

sniffer_api_t* init_sniffer(int dl_id) {
    struct pcap_pkthdr pcap_hdr;

    sniffer_api_t* api_inst = (sniffer_api_t*)malloc(sizeof(sniffer_api_t));
    api_inst->_map = 0;

    /* set sniffer handle metadata */
    api_inst->dl_id = dl_id;
    api_inst->dl_name = pcap_datalink_val_to_name(dl_id);
    api_inst->_map = api_inst->_map | SNIFFER_API_DL;        

    /* initialize everything to null/default values (in order) to allow for error checking if some values fail to initialize */
    api_inst->pcap_hdr.caplen = -1;
    api_inst->pcap_hdr.len = -1;
    api_inst->pcap_hdr.ts.tv_sec = -1;
    api_inst->pcap_hdr.ts.tv_usec = -1;
    api_inst->spcl_hdr = NULL;
    api_inst->pkt_hdr = NULL;
    api_inst->pkt_data = NULL;
    api_inst->parse_pkt = NULL;
    api_inst->disp_pkt = NULL;
    api_inst->_parse_pcap_hdr = NULL;
    api_inst->_parse_pkt = NULL;
    api_inst->_disp_pcap_hdr = NULL;
    api_inst->_disp_pkt = NULL;
    api_inst->_reset_inst = NULL;
    
    /* get set function to set structs and functions in api inst */
    /* sets spcl_hdr _disp_pkt _parse_pkt and _reset_inst */
    _api_set_func initializer = _get_api_set_func(api_inst, dl_id);

    /* set null for no set func */
    if (initializer == NULL) {
        fprintf(stderr, "[CRITICAL ERROR] failed to initialize sniffer, set function not found (possibly unsupported data link)\n");
    }
    else {
        api_inst->_map = api_inst->_map | SNIFFER_API_ACTIVATED;
        initializer(api_inst);
    }

    /* initialize user callable functions (standard for all link types) */
    api_inst->parse_pkt = parse_pkt_def;
    api_inst->disp_pkt = disp_pkt_def;

    /* initialize non user callable functions (standard for all link types) */
    api_inst->_parse_pcap_hdr = _parse_pcap_hdr_def;
    api_inst->_disp_pcap_hdr = _disp_pcap_hdr_def;

    return api_inst;
}

_api_set_func _get_api_set_func(sniffer_api_t* api_inst, int dl_id) {
    _api_set_func func = NULL;

    _set_func_row_t _set_func_table[] = {
        { 127, _set_IEEE802_11_RADIOTAP }
    };

    for (int i = 0; i < 1; ++i) {
        if (_set_func_table[i].dl_id == dl_id) {
            func = _set_func_table[i].func;
        }
    }

    return func;
}

void close_sniffer(sniffer_api_t* api_inst, int dl_id) {
    if (api_inst->_reset_inst == NULL) {
        fprintf(stderr, "[CRITICAL ERROR] initialized api inst does not have a reset func (possibly unsupported datalink or bad api inst)\n"); 
    }
    else {
        api_inst->_reset_inst(api_inst);
    }

    /* free structures */
    if (api_inst->spcl_hdr != NULL) {
        free(api_inst->spcl_hdr);
    }
    if (api_inst->pkt_hdr != NULL) {
        free(api_inst->pkt_hdr);
    }
    if(api_inst->pkt_data != NULL) {
        free(api_inst->pkt_data);
    }

    free(api_inst);
}
