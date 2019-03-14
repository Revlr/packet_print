#pragma once
#include<arpa/inet.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define LIBNET_LIL_ENDIAN   1
#pragma pack(push, 1)
#include <libnet/libnet-macros.h>
#include <libnet/libnet-headers.h>
#pragma pack(pop)
#include <netinet/in.h>

#define ETH_HDR_LEN   14

class Pkt {
private:
    uint8_t* pkt;
public:
    struct libnet_ethernet_hdr *ethhdr;
    struct libnet_ipv4_hdr *iphdr;
    struct libnet_tcp_hdr *tcphdr;

    Pkt(uint8_t* _pkt);
    ~Pkt();

    bool isIp();
    bool isTcp();

    void printMac(uint8_t* mac);
    void printIp(struct in_addr *ip);
    void printTcp(uint16_t tcp);
    void printTcpData();
};
