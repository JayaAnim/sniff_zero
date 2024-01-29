/*LINKTYPE_IEEE802_11_AVS 	163 	DLT_IEEE802_11_RADIO_AVS 	AVS monitor mode information followed by an 802.11 header */
/*LINKTYPE_NULL 	0 	DLT_NULL 	BSD loopback encapsulation */
/*LINKTYPE_EXP_ETHERNET 	2 	DLT_EN3MB 	Experimental Ethernet (3Mb) */
/*LINKTYPE_AX25 	3 	DLT_AX25 	AX.25 packet, with nothing preceding it */
/*LINKTYPE_PRONET 	4 	DLT_PRONET 	Proteon ProNET Token Ring */
/*LINKTYPE_CHAOS 	5 	DLT_CHAOS 	Chaos */
/*LINKTYPE_IEEE802_5 	6 	DLT_IEEE802 	IEEE 802.5 Token Ring; the IEEE802, without _5, in the DLT_ name is historical */
/*LINKTYPE_ARCNET_BSD 	7 	DLT_ARCNET 	ARCNET Data Packets, as described by the ARCNET Trade Association standard ATA 878.1-1999, but without the Starting Delimiter, Information Length, or Frame Check Sequence fields, and with only the first ISU of the Destination Identifier. For most packet types, ARCNET Trade Association draft standard ATA 878.2 is also used. See also RFC 1051 and RFC 1201; for RFC 1051 frames, ATA 878.2 is not used */
/*LINKTYPE_SLIP 	8 	DLT_SLIP 	SLIP, encapsulated with a LINKTYPE_SLIP header */
/*LINKTYPE_PPP 	9 	DLT_PPP 	PPP, as per RFC 1661 and RFC 1662; if the first 2 bytes are 0xff and 0x03, it's PPP in HDLC-like framing, with the PPP header following those two bytes, otherwise it's PPP without framing, and the packet begins with the PPP header. The data in the frame is not octet-stuffed or bit-stuffed */
/*LINKTYPE_FDDI 	10 	DLT_FDDI 	FDDI, as specified by ANSI INCITS 239-1994 */
/*LT_REDBACK_SMARTEDGE 	Redback SmartEdge 400/800 */
/*LINKTYPE_PPP_HDLC 	50 	DLT_PPP_SERIAL 	PPP in HDLC-like framing, as per RFC 1662, or Cisco PPP with HDLC framing, as per section 4.3.1 of RFC 1547; the first byte will be 0xFF for PPP in HDLC-like framing, and will be 0x0F or 0x8F for Cisco PPP with HDLC framing. The data in the frame is not octet-stuffed or bit-stuffed */
/*LINKTYPE_PPP_ETHER 	51 	DLT_PPP_ETHER 	PPPoE; the packet begins with a PPPoE header, as per RFC 2516 */
/*LINKTYPE_SYMANTEC_FIREWALL 	99 	DLT_SYMANTEC_FIREWALL 	Symantec Enterprise (ex-Axent Raptor) firewall */
/*LINKTYPE_ATM_RFC1483 	100 	DLT_ATM_RFC1483 	RFC 1483 LLC/SNAP-encapsulated ATM; the packet begins with an ISO 8802-2 (formerly known as IEEE 802.2) LLC header */
/*LINKTYPE_RAW 	101 	DLT_RAW 	Raw IP; the packet begins with an IPv4 or IPv6 header, with the version field of the header indicating whether it's an IPv4 or IPv6 header */
/*LINKTYPE_C_HDLC 	104 	DLT_C_HDLC 	Cisco PPP with HDLC framing, as per section 4.3.1 of RFC 1547 */
/*LINKTYPE_IEEE802_11 	105 	DLT_IEEE802_11 	IEEE 802.11 wireless LAN */
/*LINKTYPE_ATM_CLIP 	106 	DLT_ATM_CLIP 	Linux Classical IP over ATM */
/*LINKTYPE_FRELAY 	107 	DLT_FRELAY 	Frame Relay LAPF frames, beginning with a ITU-T Recommendation Q.922 LAPF header starting with the address field, and without an FCS at the end of the frame */
/*LINKTYPE_LOOP 	108 	DLT_LOOP 	OpenBSD loopback encapsulation */
/*LINKTYPE_ENC 	109 	DLT_ENC 	Encapsulated packets for IPsec */
/*LINKTYPE_NETBSD_HDLC 	112 	DLT_HDLC 	Cisco HDLC */
/*LINKTYPE_LINUX_SLL 	113 	DLT_LINUX_SLL 	Linux "cooked" capture encapsulation */
/*LINKTYPE_LTALK 	114 	DLT_LTALK 	Apple LocalTalk; the packet begins with an AppleTalk LocalTalk Link Access Protocol header, as described in chapter 1 of Inside AppleTalk, Second Edition */
/*LINKTYPE_PFLOG 	117 	DLT_PFLOG 	OpenBSD pflog; the link-layer header contains a struct pfloghdr structure, as defined by the host on that the file was saved. (This differs from operating system to operating system and release to release; there is nothing in the file to indicate what the layout of that structure is */)
/*LINKTYPE_IEEE802_11_PRISM 	119 	DLT_PRISM_HEADER 	Prism monitor mode information followed by an 802.11 header */
/*LINKTYPE_IP_OVER_FC 	122 	DLT_IP_OVER_FC 	RFC 2625 IP-over-Fibre Channel, with the link-layer header being the Network_Header as described in that RFC */
/*LINKTYPE_SUNATM 	123 	DLT_SUNATM 	ATM traffic, encapsulated as per the scheme used by SunATM devices */
/*LINKTYPE_TZSP 	128 	DLT_TZSP 	Tazmen Sniffer Protocol (TZSP) is a generic encapsulation for any other link type, which includes a means to include meta-information with the packet, e.g. signal strength and channel for 802.11 packets */
/*LINKTYPE_ARCNET_LINUX 	129 	DLT_ARCNET_LINUX 	ARCNET Data Packets, as described by the ARCNET Trade Association standard ATA 878.1-1999, but without the Starting Delimiter, Information Length, or Frame Check Sequence fields, with only the first ISU of the Destination Identifier, and with an extra two-ISU offset field following the Destination Identifier. For most packet types, ARCNET Trade Association draft standard ATA 878.2 is also used; however, no exception frames are supplied, and reassembled frames, rather than fragments, are supplied. See also RFC 1051 and RFC 1201; for RFC 1051 frames, ATA 878.2 is not used */
/*LINKTYPE_JUNIPER_MLPPP 	130 	DLT_JUNIPER_MLPPP 	Juniper Networks private data link type */
/*LINKTYPE_JUNIPER_MLFR 	131 	DLT_JUNIPER_MLFR 	Juniper Networks private data link type */
/*LINKTYPE_JUNIPER_ES 	132 	DLT_JUNIPER_ES 	Juniper Networks private data link type */
/*LINKTYPE_JUNIPER_GGSN 	133 	DLT_JUNIPER_GGSN 	Juniper Networks private data link type */
/*LINKTYPE_JUNIPER_MFR 	134 	DLT_JUNIPER_MFR 	Juniper Networks private data link type */
/*LINKTYPE_JUNIPER_ATM2 	135 	DLT_JUNIPER_ATM2 	Juniper Networks private data link type */
/*LINKTYPE_JUNIPER_SERVICES 	136 	DLT_JUNIPER_SERVICES 	Juniper Networks private data link type */
/*LINKTYPE_JUNIPER_ATM1 	137 	DLT_JUNIPER_ATM1 	Juniper Networks private data link type */
/*LINKTYPE_APPLE_IP_OVER_IEEE1394 	138 	DLT_APPLE_IP_OVER_IEEE1394 	Apple IP-over-IEEE 1394 cooked header */
/*LINKTYPE_MTP2_WITH_PHDR 	139 	DLT_MTP2_WITH_PHDR 	Signaling System 7 Message Transfer Part Level 2, as specified by ITU-T Recommendation Q.703, preceded by a pseudo-header */
/*LINKTYPE_MTP2 	140 	DLT_MTP2 	Signaling System 7 Message Transfer Part Level 2, as specified by ITU-T Recommendation Q.703 */
/*LINKTYPE_MTP3 	141 	DLT_MTP3 	Signaling System 7 Message Transfer Part Level 3, as specified by ITU-T Recommendation Q.704, with no MTP2 header preceding the MTP3 packet */
/*LINKTYPE_SCCP 	142 	DLT_SCCP 	Signaling System 7 Signalling Connection Control Part, as specified by ITU-T Recommendation Q.711, ITU-T Recommendation Q.712, ITU-T Recommendation Q.713, and ITU-T Recommendation Q.714, with no MTP3 or MTP2 headers preceding the SCCP packet */
/*LINKTYPE_DOCSIS 	143 	DLT_DOCSIS 	DOCSIS MAC frames, as described by the DOCSIS 4.0 MAC and Upper Layer Protocols Interface Specification or earlier specifications for MAC frames */
/*LINKTYPE_LINUX_IRDA 	144 	DLT_LINUX_IRDA 	Linux-IrDA packets, with a LINKTYPE_LINUX_IRDA header, with the payload for IrDA frames beginning with by the IrLAP header as defined by the IrDA Link Access Protocol specification */
/*LINKTYPE_IBM_SP 	145 	DLT_IBM_SP 	IBM SP switch */
/*LINKTYPE_IBM_SN 	146 	DLT_IBM_SN 	IBM Next Federation switch */
/*LINKTYPE_USER0–LINKTYPE_USER15 	147–162 	DLT_USER0–DLT_USER15 	Reserved for private use; see above */
/*LINKTYPE_JUNIPER_MONITOR 	164 	DLT_JUNIPER_MONITOR 	Juniper Networks private data link type */
/*LINKTYPE_BACNET_MS_TP 	165 	DLT_BACNET_MS_TP 	BACnet MS/TP frames, as specified by section 9.3 MS/TP Frame Format of ANSI/ASHRAE Standard 135, BACnet® - A Data Communication Protocol for Building Automation and Control Networks, including the preamble and, if present, the Data CRC */
/*LINKTYPE_PPP_PPPD 	166 	DLT_PPP_PPPD 	PPP in HDLC-like encapsulation, like LINKTYPE_PPP_HDLC, but with the 0xff address byte replaced by a direction indication—0x00 for incoming and 0x01 for outgoing */
/*LINKTYPE_JUNIPER_PPPOE 	167 	DLT_JUNIPER_PPPOE 	Juniper Networks private data link type */
/*LINKTYPE_JUNIPER_PPPOE_ATM 	168 	DLT_JUNIPER_PPPOE_ATM 	Juniper Networks private data link type */
/*LINKTYPE_GPRS_LLC 	169 	DLT_GPRS_LLC 	General Packet Radio Service Logical Link Control, as defined by 3GPP TS 04.64 */
/*LINKTYPE_GPF_T 	170 	DLT_GPF_T 	Transparent-mapped generic framing procedure, as specified by ITU-T Recommendation G.7041/Y.1303 */
/*LINKTYPE_GPF_F 	171 	DLT_GPF_F 	Frame-mapped generic framing procedure, as specified by ITU-T Recommendation G.7041/Y.1303 */
/*LINKTYPE_GCOM_T1E1 	172 	DLT_GCOM_T1E1 	Gcom's T1/E1 line monitoring equipment */
/*LINKTYPE_GCOM_SERIAL 	173 	DLT_GCOM_SERIAL 	Gcom's T1/E1 line monitoring equipment */
/*LINKTYPE_JUNIPER_PIC_PEER 	174 	DLT_JUNIPER_PIC_PEER 	Juniper Networks private data link type */
/*LINKTYPE_ERF_ETH 	175 	DLT_ERF_ETH 	An ERF header followed by Ethernet */
/*LINKTYPE_ERF_POS 	176 	DLT_ERF_POS 	An ERF header followed by Packet-over-SONET */
/*LINKTYPE_LINUX_LAPD 	177 	DLT_LINUX_LAPD 	Link Access Procedures on the D Channel (LAPD) frames, as specified by ITU-T Recommendation Q.920 and ITU-T Recommendation Q.921, captured via vISDN, with a LINKTYPE_LINUX_LAPD header, followed by the Q.921 frame, starting with the address field */
/*LINKTYPE_JUNIPER_ETHER 	178 	DLT_JUNIPER_ETHER 	Juniper Networks private data link type. Ethernet frames prepended with meta-information */
/*LINKTYPE_JUNIPER_PPP 	179 	DLT_JUNIPER_PPP 	Juniper Networks private data link type. PPP frames prepended with meta-information */
/*LINKTYPE_JUNIPER_FRELAY 	180 	DLT_JUNIPER_FRELAY 	Juniper Networks private data link type. Frame Relay frames prepended with meta-information */
/*LINKTYPE_JUNIPER_CHDLC 	181 	DLT_JUNIPER_CHDLC 	Juniper Networks private data link type. C-HDLC frames prepended with meta-information */
/*LINKTYPE_MFR 	182 	DLT_MFR 	FRF.16.1 Multi-Link Frame Relay frames, beginning with an FRF.12 Interface fragmentation format fragmentation header */
/*LINKTYPE_JUNIPER_VP 	183 	DLT_JUNIPER_VP 	Juniper Networks private data link type */
/*LINKTYPE_A429 	184 	DLT_A429 	ARINC 429 frames. Every frame contains a 32-bit A429 word, in little-endian format */
/*LINKTYPE_A653_ICM 	185 	DLT_A653_ICM 	ARINC 653 interpartition communication messages. Please refer to the A653-1 standard for more information */
/*LINKTYPE_USB_FREEBSD 	186 	DLT_USB_FREEBSD 	USB with FreeBSD header */
/*LINKTYPE_BLUETOOTH_HCI_H4 	187 	DLT_BLUETOOTH_HCI_H4 	Bluetooth HCI UART transport layer; the frame contains an HCI packet indicator byte, as specified by the UART Transport Layer portion of the most recent Bluetooth Core specification, followed by an HCI packet of the specified packet type, as specified by the Host Controller Interface Functional Specification portion of the most recent Bluetooth Core Specification */
/*LINKTYPE_IEEE802_16_MAC_CPS 	188 	DLT_IEEE802_16_MAC_CPS 	IEEE 802.16 MAC Common Part Sublayer */
/*LINKTYPE_USB_LINUX 	189 	DLT_USB_LINUX 	USB packets, beginning with a Linux USB header, as specified by the struct usbmon_packet in the Documentation/usb/usbmon.txt file in the Linux source tree. Only the first 48 bytes of that header are present. All fields in the header are in host byte order. When performing a live capture, the host byte order is the byte order of the machine on that the packets are captured. When reading a pcap file, the byte order is the byte order for the file, as specified by the file's magic number; when reading a pcapng file, the byte order is the byte order for the section of the pcapng file, as specified by the Section Header Block */
/*LINKTYPE_CAN20B 	190 	DLT_CAN20B 	Controller Area Network (CAN) v. 2.0B */
/*LINKTYPE_IEEE802_15_4_LINUX 	191 	DLT_IEEE802_15_4_LINUX 	IEEE 802.15.4, with address fields padded, as is done by Linux drivers */
/*LINKTYPE_PPI 	192 	DLT_PPI 	Per-Packet Information information, as specified by the Per-Packet Information Header Specification, followed by a packet with the LINKTYPE_ value specified by the pph_dlt field of that header */
/*LINKTYPE_IEEE802_16_MAC_CPS_RADIO 	193 	DLT_IEEE802_16_MAC_CPS_RADIO 	IEEE 802.16 MAC Common Part Sublayer plus radiotap header */
/*LINKTYPE_JUNIPER_ISM 	194 	DLT_JUNIPER_ISM 	Juniper Networks private data link type */
/*LINKTYPE_IEEE802_15_4_WITHFCS 	195 	DLT_IEEE802_15_4_WITHFCS 	IEEE 802.15.4 Low-Rate Wireless Networks, with each packet having the FCS at the end of the frame */
/*LINKTYPE_SITA 	196 	DLT_SITA 	Various link-layer types, with a pseudo-header, for SITA */
/*LINKTYPE_ERF 	197 	DLT_ERF 	Various link-layer types, with a pseudo-header, for Endace DAG cards; encapsulates Endace ERF records */
/*LINKTYPE_RAIF1 	198 	DLT_RAIF1 	Special header prepended to Ethernet packets when capturing from a u10 Networks board */
/*LINKTYPE_IPMB_KONTRON 	199 	DLT_IPMB_KONTRON 	IPMB packet for IPMI, beginning with a 2-byte header, followed by the I2C slave address, followed by the netFn and LUN, etc…*/
/*LINKTYPE_JUNIPER_ST 	200 	DLT_JUNIPER_ST 	Juniper Networks private data link type */
/*LINKTYPE_BLUETOOTH_HCI_H4_WITH_PHDR 	201 	DLT_BLUETOOTH_HCI_H4_WITH_PHDR 	Bluetooth HCI UART transport layer; the frame contains a 4-byte direction field, in network byte order (big-endian), the low-order bit of which is set if the frame was sent from the host to the controller and clear if the frame was received by the host from the controller, followed by an HCI packet indicator byte, as specified by the UART Transport Layer portion of the most recent Bluetooth Core specification, followed by an HCI packet of the specified packet type, as specified by the Host Controller Interface Functional Specification portion of the most recent Bluetooth Core Specification */
/*LINKTYPE_AX25_KISS 	202 	DLT_AX25_KISS 	AX.25 packet, with a 1-byte KISS header containing a type indicator */
/*LINKTYPE_LAPD 	203 	DLT_LAPD 	Link Access Procedures on the D Channel (LAPD) frames, as specified by ITU-T Recommendation Q.920 and ITU-T Recommendation Q.921, starting with the address field, with no pseudo-header */
/*LINKTYPE_PPP_WITH_DIR 	204 	DLT_PPP_WITH_DIR 	PPP, as per RFC 1661 and RFC 1662, preceded with a one-byte pseudo-header with a zero value meaning "received by this host" and a non-zero value meaning "sent by this host"; if the first 2 bytes are 0xff and 0x03, it's PPP in HDLC-like framing, with the PPP header following those two bytes, otherwise it's PPP without framing, and the packet begins with the PPP header. The data in the frame is not octet-stuffed or bit-stuffed */
/*LINKTYPE_C_HDLC_WITH_DIR 	205 	DLT_C_HDLC_WITH_DIR 	Cisco PPP with HDLC framing, as per section 4.3.1 of RFC 1547, preceded with a one-byte pseudo-header with a zero value meaning "received by this host" and a non-zero value meaning "sent by this host" */
/*LINKTYPE_FRELAY_WITH_DIR 	206 	DLT_FRELAY_WITH_DIR 	Frame Relay LAPF frames, beginning with a one-byte pseudo-header with a zero value meaning "received by this host" (DCE->DTE) and a non-zero value meaning "sent by this host" (DTE->DCE), followed by an ITU-T Recommendation Q.922 LAPF header starting with the address field, and without an FCS at the end of the frame */
/*LINKTYPE_LAPB_WITH_DIR 	207 	DLT_LAPB_WITH_DIR 	Link Access Procedure, Balanced (LAPB), as specified by ITU-T Recommendation X.25, preceded with a one-byte pseudo-header with a zero value meaning "received by this host" (DCE->DTE) and a non-zero value meaning "sent by this host" (DTE->DCE) */
/*LINKTYPE_IPMB_LINUX 	209 	DLT_IPMB_LINUX 	IPMB over an I2C circuit, with a Linux-specific pseudo-header */
/*LINKTYPE_FLEXRAY 	210 	DLT_FLEXRAY 	FlexRay automotive bus frames or symbols, preceded by a pseudo-header */
/*LINKTYPE_MOST 	211 	DLT_MOST 	Media Oriented Systems Transport (MOST) bus for multimedia transport */
/*LINKTYPE_LIN 	212 	DLT_LIN 	Local Interconnect Network (LIN) automotive bus, preceded by a pseudo-header */
/*LINKTYPE_X2E_SERIAL 	213 	DLT_X2E_SERIAL 	X2E-private data link type used for serial line capture */
/*LINKTYPE_X2E_XORAYA 	214 	DLT_X2E_XORAYA 	X2E-private data link type used for the Xoraya data logger family */
/*LINKTYPE_IEEE802_15_4_NONASK_PHY 	215 	DLT_IEEE802_15_4_NONASK_PHY 	IEEE 802.15.4 Low-Rate Wireless Networks, with each packet having the FCS at the end of the frame, and with the PHY-level data for the O-QPSK, BPSK, GFSK, MSK, and RCC DSS BPSK PHYs (4 octets of 0 as preamble, one octet of SFD, one octet of frame length + reserved bit) preceding the MAC-layer data (starting with the frame control field) */
/*LINKTYPE_LINUX_EVDEV 	216 	DLT_LINUX_EVDEV 	Linux evdev events from /dev/input/eventN devices */
/*LINKTYPE_GSMTAP_UM 	217 	DLT_GSMTAP_UM 	GSM Um interface, preceded by a "gsmtap" header */
/*LINKTYPE_GSMTAP_ABIS 	218 	DLT_GSMTAP_ABIS 	GSM Abis interface, preceded by a "gsmtap" header */
/*LINKTYPE_MPLS 	219 	DLT_MPLS 	MPLS, with an MPLS label as the link-layer header */
/*LINKTYPE_USB_LINUX_MMAPPED 	220 	DLT_USB_LINUX_MMAPPED 	USB packets, beginning with a Linux USB header, as specified by the struct usbmon_packet in the Documentation/usb/usbmon.txt file in the Linux source tree. All 64 bytes of the header are present. All fields in the header are in host byte order. When performing a live capture, the host byte order is the byte order of the machine on that the packets are captured. When reading a pcap file, the byte order is the byte order for the file, as specified by the file's magic number; when reading a pcapng file, the byte order is the byte order for the section of the pcapng file, as specified by the Section Header Block. For isochronous transfers, the ndesc field specifies the number of isochronous descriptors that follow */
/*LINKTYPE_DECT 	221 	DLT_DECT 	DECT packets, with a pseudo-header */
/*LINKTYPE_AOS 	222 	DLT_AOS 	AOS Space Data Link Protocol */
/*LINKTYPE_WIHART 	223 	DLT_WIHART 	WirelessHART (Highway Addressable Remote Transducer) from the HART Communication Foundation (IEC/PAS 62591) */
/*LINKTYPE_FC_2 	224 	DLT_FC_2 	Fibre Channel FC-2 frames, beginning with a Frame_Header */
/*LINKTYPE_FC_2_WITH_FRAME_DELIMS 	225 	DLT_FC_2_WITH_FRAME_DELIMS 	Fibre Channel FC-2 frames, beginning an encoding of the SOF, followed by a Frame_Header, and ending with an encoding of the SOF. The encodings represent the frame delimiters as 4-byte sequences representing the corresponding ordered sets, with K28.5 represented as 0xBC, and the D symbols as the corresponding byte values; for example, SOFi2, which is K28.5 - D21.5 - D1.2 - D21.2, is represented as 0xBC 0xB5 0x55 0x55 */
/*LINKTYPE_IPNET 	226 	DLT_IPNET 	Solaris ipnet pseudo-header, followed by an IPv4 or IPv6 datagram */
/*LINKTYPE_CAN_SOCKETCAN 	227 	DLT_CAN_SOCKETCAN 	CAN (Controller Area Network) frames, with a pseudo-header followed by the frame payload */
/*LINKTYPE_IEEE802_15_4_NOFCS 	230 	DLT_IEEE802_15_4_NOFCS 	IEEE 802.15.4 Low-Rate Wireless Network, without the FCS at the end of the frame */
/*LINKTYPE_DBUS 	231 	DLT_DBUS 	Raw D-Bus messages, starting with the endianness flag, followed by the message type, etc., but without the authentication handshake before the message sequence */
/*LINKTYPE_JUNIPER_VS 	232 	DLT_JUNIPER_VS 	Juniper Networks private data link type */
/*LINKTYPE_JUNIPER_SRX_E2E 	233 	DLT_JUNIPER_SRX_E2E 	Juniper Networks private data link type */
/*LINKTYPE_JUNIPER_FIBRECHANNEL 	234 	DLT_JUNIPER_FIBRECHANNEL 	Juniper Networks private data link type */
/*LINKTYPE_DVB_CI 	235 	DLT_DVB_CI 	DVB-CI messages, with the message format specified by the PCAP format for DVB-CI specification */
/*LINKTYPE_MUX27010 	236 	DLT_MUX27010 	Variant of 3GPP TS 27.010 multiplexing protocol (similar to, but not the same as, 27.010) */
/*LINKTYPE_STANAG_5066_D_PDU 	237 	DLT_STANAG_5066_D_PDU 	D_PDUs as described by NATO standard STANAG 5066, starting with the synchronization sequence, and including both header and data CRCs. The current version of STANAG 5066 is backwards-compatible with the 1.0.2 version, although newer versions are classified */
/*LINKTYPE_JUNIPER_ATM_CEMIC 	238 	DLT_JUNIPER_ATM_CEMIC 	Juniper Networks private data link type */
/*LINKTYPE_NFLOG 	239 	DLT_NFLOG 	Linux netlink NETLINK NFLOG socket log messages */
/*LINKTYPE_NETANALYZER 	240 	DLT_NETANALYZER 	Pseudo-header for Hilscher Gesellschaft für Systemautomation mbH netANALYZER devices, followed by an Ethernet frame, beginning with the MAC header and ending with the FCS */
/*LINKTYPE_NETANALYZER_TRANSPARENT 	241 	DLT_NETANALYZER_TRANSPARENT 	Pseudo-header for Hilscher Gesellschaft für Systemautomation mbH netANALYZER devices, followed by an Ethernet frame, beginning with the preamble, SFD, and MAC header, and ending with the FCS */
/*LINKTYPE_IPOIB 	242 	DLT_IPOIB 	IP-over-InfiniBand, as specified by RFC 4391 section 6 */
/*LINKTYPE_MPEG_2_TS 	243 	DLT_MPEG_2_TS 	MPEG-2 Transport Stream transport packets, as specified by ISO 13818-1/ITU-T Recommendation H.222.0 (see table 2-2 of section 2.4.3.2 "Transport Stream packet layer") */
/*LINKTYPE_NG40 	244 	DLT_NG40 	Pseudo-header for ng4T GmbH's UMTS Iub/Iur-over-ATM and Iub/Iur-over-IP format as used by their ng40 protocol tester, followed by frames for the Frame Protocol as specified by 3GPP TS 25.427 for dedicated channels and 3GPP TS 25.435 for common/shared channels in the case of ATM AAL2 or UDP traffic, by SSCOP packets as specified by ITU-T Recommendation Q.2110 for ATM AAL5 traffic, and by NBAP packets for SCTP traffic */
/*LINKTYPE_NFC_LLCP 	245 	DLT_NFC_LLCP 	Pseudo-header for NFC LLCP packet captures, followed by frame data for the LLCP Protocol as specified by the Logical Link Control Protocol Technical Specification */
/*LINKTYPE_PFSYNC 	246 		Packet filter state syncing */
/*LINKTYPE_INFINIBAND 	247 	DLT_INFINIBAND 	Raw InfiniBand frames, starting with the Local Routing Header, as specified in Chapter 5 "Data packet format" of InfiniBand™ Architecture Specification Release 1.2.1 Volume 1 - General Specifications */
/*LINKTYPE_SCTP 	248 	DLT_SCTP 	SCTP packets, as defined by RFC 4960, with no lower-level protocols such as IPv4 or IPv6 */
/*LINKTYPE_USBPCAP 	249 	DLT_USBPCAP 	USB packets, beginning with a USBPcap header */
/*LINKTYPE_RTAC_SERIAL 	250 	DLT_RTAC_SERIAL 	Serial-line packet header for the Schweitzer Engineering Laboratories "RTAC" product, followed by a payload for one of a number of industrial control protocols */
/*LINKTYPE_BLUETOOTH_LE_LL 	251 	DLT_BLUETOOTH_LE_LL 	Bluetooth Low Energy air interface Link Layer packets, in the format described in section 2.1 "PACKET FORMAT" of volume 6 of the Bluetooth Specification Version 4.0 (see PDF page 2200), but without the Preamble */
/*LINKTYPE_WIRESHARK_UPPER_PDU 	252 	DLT_WIRESHARK_UPPER_PDU 	Upper-protocol layer PDU saves from Wireshark; the actual contents are determined by two tags, one or more of which is stored with each packet */
/*LINKTYPE_NETLINK 	253 	DLT_NETLINK 	Linux Netlink capture encapsulation */
/*LINKTYPE_BLUETOOTH_LINUX_MONITOR 	254 	DLT_BLUETOOTH_LINUX_MONITOR 	Bluetooth Linux Monitor encapsulation of traffic for the BlueZ stack */
/*LINKTYPE_BLUETOOTH_BREDR_BB 	255 	DLT_BLUETOOTH_BREDR_BB 	Bluetooth Basic Rate and Enhanced Data Rate baseband packets */
/*LINKTYPE_BLUETOOTH_LE_LL_WITH_PHDR 	256 	DLT_BLUETOOTH_LE_LL_WITH_PHDR 	Bluetooth Low Energy link-layer packets */
/*LINKTYPE_PROFIBUS_DL 	257 	DLT_PROFIBUS_DL 	PROFIBUS data link layer packets, as specified by IEC standard 61158-4-3, beginning with the start delimiter, ending with the end delimiter, and including all octets between them */
/*LINKTYPE_PKTAP 	258 	DLT_PKTAP 	Apple PKTAP capture encapsulation */
/*LINKTYPE_EPON 	259 	DLT_EPON 	Ethernet-over-passive-optical-network packets, starting with the last 6 octets of the modified preamble as specified by 65.1.3.2 "Transmit" in Clause 65 of Section 5 of IEEE 802.3, followed immediately by an Ethernet frame */
/*LINKTYPE_IPMI_HPM_2 	260 	DLT_IPMI_HPM_2 	IPMI trace packets, as specified by Table 3-20 "Trace Data Block Format" in the PICMG HPM.2 specification. The time stamps for packets in this format must match the time stamps in the Trace Data Blocks */
/*LINKTYPE_ZWAVE_R1_R2 	261 	DLT_ZWAVE_R1_R2 	Z-Wave RF profile R1 and R2 packets, as specified by ITU-T Recommendation G.9959, with some MAC layer fields moved */
/*LINKTYPE_ZWAVE_R3 	262 	DLT_ZWAVE_R3 	Z-Wave RF profile R3 packets, as specified by ITU-T Recommendation G.9959, with some MAC layer fields moved */
/*LINKTYPE_WATTSTOPPER_DLM 	263 	DLT_WATTSTOPPER_DLM 	Formats for WattStopper Digital Lighting Management (DLM) and Legrand Nitoo Open protocol common packet structure captures */
/*LINKTYPE_ISO_14443 	264 	DLT_ISO_14443 	Messages between ISO 14443 contactless smartcards (Proximity Integrated Circuit Card, PICC) and card readers (Proximity Coupling Device, PCD), with the message format specified by the PCAP format for ISO14443 specification */
/*LINKTYPE_RDS 	265 	DLT_RDS 	Radio data system (RDS) groups, as per IEC 62106, encapsulated in this form */
/*LINKTYPE_USB_DARWIN 	266 	DLT_USB_DARWIN 	USB packets, beginning with a Darwin (macOS, etc.) USB header */
/*LINKTYPE_OPENFLOW 	267 	DLT_OPENFLOW 	OpenFlow messages with an additional 12-octet header, as used in OpenBSD switch interface monitoring */
/*LINKTYPE_SDLC 	268 	DLT_SDLC 	SDLC packets, as specified by Chapter 1, "DLC Links", section "Synchronous Data Link Control (SDLC)" of Systems Network Architecture Formats, GA27-3136-20, without the flag fields, zero-bit insertion, or Frame Check Sequence field, containing SNA path information units (PIUs) as the payload */
/*LINKTYPE_TI_LLN_SNIFFER 	269 	DLT_TI_LLN_SNIFFER 	TI LLN sniffer frames */
/*LINKTYPE_LORATAP 	270 	DLT_LORATAP 	LoRaTap pseudo-header, followed by the payload, which is typically the PHYPayload from the LoRaWan specification */
/*LINKTYPE_VSOCK 	271 	DLT_VSOCK 	Protocol for communication between host and guest machines in VMware and KVM hypervisors */
/*LINKTYPE_NORDIC_BLE 	272 	DLT_NORDIC_BLE 	Messages to and from a Nordic Semiconductor nRF Sniffer for Bluetooth LE packets, beginning with a pseudo-header */
/*LINKTYPE_DOCSIS31_XRA31 	273 	DLT_DOCSIS31_XRA31 	DOCSIS packets and bursts, preceded by a pseudo-header giving metadata about the packet */
/*LINKTYPE_ETHERNET_MPACKET 	274 	DLT_ETHERNET_MPACKET 	mPackets, as specified by IEEE 802.3br Figure 99-4, starting with the preamble and always ending with a CRC field */
/*LINKTYPE_DISPLAYPORT_AUX 	275 	DLT_DISPLAYPORT_AUX 	DisplayPort AUX channel monitoring data as specified by VESA DisplayPort (DP) Standard preceded by a pseudo-header */
/*LINKTYPE_LINUX_SLL2 	276 	DLT_LINUX_SLL2 	Linux "cooked" capture encapsulation v2 */
/*LINKTYPE_SERCOS_MONITOR 	277 	DLT_SERCOS_MONITOR 	Sercos Monitor */
/*LINKTYPE_OPENVIZSLA 	278 	DLT_OPENVIZSLA 	Openvizsla FPGA-based USB sniffer */
/*LINKTYPE_EBHSCR 	279 	DLT_EBHSCR 	Elektrobit High Speed Capture and Replay (EBHSCR) format */
/*LINKTYPE_VPP_DISPATCH 	280 	DLT_VPP_DISPATCH 	Records in traces from the http://fd.io VPP graph dispatch tracer, in the the graph dispatcher trace format */
/*LINKTYPE_DSA_TAG_BRCM 	281 	DLT_DSA_TAG_BRCM 	Ethernet frames, with a switch tag inserted between the source address field and the type/length field in the Ethernet header */
/*LINKTYPE_DSA_TAG_BRCM_PREPEND 	282 	DLT_DSA_TAG_BRCM_PREPEND 	Ethernet frames, with a switch tag inserted before the destination address in the Ethernet header */
/*LINKTYPE_IEEE802_15_4_TAP 	283 	DLT_IEEE802_15_4_TAP 	IEEE 802.15.4 Low-Rate Wireless Networks, with a pseudo-header containing TLVs with metadata preceding the 802.15.4 header */
/*LINKTYPE_DSA_TAG_DSA 	284 	DLT_DSA_TAG_DSA 	Ethernet frames, with a switch tag inserted between the source address field and the type/length field in the Ethernet header */
/*LINKTYPE_DSA_TAG_EDSA 	285 	DLT_DSA_TAG_EDSA 	Ethernet frames, with a programmable Ethernet type switch tag inserted between the source address field and the type/length field in the Ethernet header */
/*LINKTYPE_ELEE 	286 	DLT_ELEE 	Payload of lawful intercept packets using the ELEE protocol. The packet begins with the ELEE header; it does not include any transport-layer or lower-layer headers for protocols used to transport ELEE packets */
/*LINKTYPE_Z_WAVE_SERIAL 	287 	DLT_Z_WAVE_SERIAL 	Serial frames transmitted between a host and a Z-Wave chip over an RS-232 or USB serial connection, as described in section 5 of the Z-Wave Serial API Host Application Programming Guide */
/*LINKTYPE_USB_2_0 	288 	DLT_USB_2_0 	USB 2.0, 1.1, or 1.0 packet, beginning with a PID, as described by Chapter 8 "Protocol Layer" of the the Universal Serial Bus Specification Revision 2.0. Deprecated in favor of speed specific USB 2.0, 1.1, or 1.0 linktypes */
/*LINKTYPE_ATSC_ALP 	289 	DLT_ATSC_ALP 	ATSC Link-Layer Protocol frames, as described in section 5 of the A/330 Link-Layer Protocol specification, found at the ATSC 3.0 standards page, beginning with a Base Header */
/*LINKTYPE_ETW 	290 	DLT_ETW 	Event Tracing for Windows messages, beginning with a pseudo-header */
/*LINKTYPE_NETANALYZER_NG 	291 	DLT_NETANALYZER_NG 	Reserved for Hilscher Gesellschaft fuer Systemautomation mbH netANALYZER NG hardware and software */
/*LINKTYPE_ZBOSS_NCP 	292 	DLT_ZBOSS_NCP 	Serial NCP (Network Co-Processor) protocol for Zigbee stack ZBOSS by DSR. ZBOSS NCP protocol, beginning with a header */
/*LINKTYPE_USB_2_0_LOW_SPEED 	293 	DLT_USB_2_0_LOW_SPEED 	Low-Speed USB 2.0, 1.1, or 1.0 packet, beginning with a PID, as described by Chapter 8 "Protocol Layer" of the the Universal Serial Bus Specification Revision 2.0 */
/*LINKTYPE_USB_2_0_FULL_SPEED 	294 	DLT_USB_2_0_FULL_SPEED 	Full-Speed USB 2.0, 1.1, or 1.0 packet, beginning with a PID, as described by Chapter 8 "Protocol Layer" of the the Universal Serial Bus Specification Revision 2.0 */
/*LINKTYPE_USB_2_0_HIGH_SPEED 	295 	DLT_USB_2_0_HIGH_SPEED 	High-Speed USB 2.0 packet, beginning with a PID, as described by Chapter 8 "Protocol Layer" of the the Universal Serial Bus Specification Revision 2.0 */
/*LINKTYPE_AUERSWALD_LOG 	296 	DLT_AUERSWALD_LOG 	Auerswald Logger Protocol, as described in this document */
/*LINKTYPE_ZWAVE_TAP 	297 	DLT_ZWAVE_TAP 	Z-Wave packets, as specified by ITU-T Recommendation G.9959, with a TAP meta-data header */
/*LINKTYPE_SILABS_DEBUG_CHANNEL 	298 	DLT_SILABS_DEBUG_CHANNEL 	Silicon Labs debug channel protocol, as described in the specification */
/*LINKTYPE_FIRA_UCI 	299 	DLT_FIRA_UCI 	Ultra-wideband (UWB) controller interface protocol (UCI) */
/*LINKTYPE_MDB 	300 	DLT_MDB 	MDB (Multi-Drop Bus) protocol between a vending machine controller and peripherals inside the vending machine, with the message format specified by the PCAP format for MDB specification */
/*LINKTYPE_DECT_NR 	301 	DLT_DECT_NR 	DECT-2020 New Radio (NR) MAC layer specified in ETSI TS 103 636-4. The Physical Header Field is always encoded using 80 bits (10 bytes). Broadcast transmissions using 40 bits (5 bytes) is padded with 40 zero bits (5 bytes). When padding is used the Receiver Identity value 0x0000 (reserved address) is used to detect broadcast transmissions */
