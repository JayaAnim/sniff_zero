<div style="border: 1px solid #ccc; padding: 10px; background-color: #f9f9f9;">
# Resource-Efficient Packet Sniffing with sniff_zero: Tailored for Small Systems and Portable to MacOS/Linux

sniff_zero is a technical project tailored for Flipper Zero devices, enabling real-time packet capture, decryption, and display. Leveraging advanced techniques such as bit manipulation and bitmaps, the tool decodes encrypted information within captured packets, providing users with detailed insights. This project serves as a robust foundation for users to integrate packet analysis functionality into their applications on Flipper Zero, offering a technical approach to packet processing and interpretation.
</div>

<div style="border: 1px solid #ccc; padding: 10px; background-color: #f9f9f9;">
## Program Structure and Initialization in sniff_zero

sniff_zero is built for a small system (256Kb memory), but can also be ported to MacOS and Linux. To ensure minimal resource usage rate it captures one packet at a time with a maximum capture of 10 packets, before user input.

Therefore, the program is based around three global variables  ```disp_pkt```, ```free_pkt```, and ```packet```. Each of these are initialized at the entrypoint via the ```init_globals``` function.

- _packet_ global variable containing pointers to structs with information on decrypted packet information
    - [ pcap_pkthdr struct ] _pcap_hdr_ pcap header which contains default pcap information on currently captured packet (i.e time captured etc)
    - [ custom struct pointer ] _spcl_hdr_ pointer to custom struct with decrypted information on any special (pcap based) headers prepended to packet
    - [ custom struct pointer ] _norm_hdr_ pointer to custom struct with decrypted information on normal (data link based) headers related to packet
    - [ custom struct pointer ] _pkt_data_ pointer to custom struct with decrypted information on packet data
- *disp_pkt* global function pointer which points to function capable of displaying currently captured packet
- *free_pkt* global function pointer which points to function capable of freeing memory from currently captured packet

Parsers how these global variables are used in conjunction with eachother. All parsers are of type ```parse_pkt_func```. Given a data link id, calling ```get_pkt_parser``` will return a function pointer to the function capable of parsing that packet.
Each parser will set what ever information it can decrypt into the ```packet``` variable then also set ```disp_pkt``` and ```free_pkt``` to functions capable of displaying and freeing that data.

This both prevents multiple system calls to create the same struct and also allows for extension of the application via consistancy. To make a custom packet reading loop, simply call the functions in order, for every packet in a buffer, savefile, or open loop

<small>The current packet sniff loop implementation is ```sniff_pkts_noloop```</small>
</div>

