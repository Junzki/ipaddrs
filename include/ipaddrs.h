#ifndef IPADDRS_IPADDRS_H
#define IPADDRS_IPADDRS_H

void hello(void);

#define IPADDR_VERSION_4 32
#define IPADDR_VERSION_6 128
#define IPADDR_SEP_DOT '.'
#define IPADDR_SEP_COLON ':'

#define IPADDR_VERSION_4_PARTS 4


typedef struct ip4cidr {
    int addr_type;
    unsigned char mask;
    unsigned long address;
} ip4cidr;

typedef struct ip6cidr {
    int addr_type;
    unsigned char mask;
    unsigned long long address;
} ip6cidr;

typedef struct host_range {
    int addr_type;
    unsigned long long min;
    unsigned long long max;
} host_range;

int ip4_aton(ip4cidr *, const char *, int);
int ip4_host_range(host_range *, const ip4cidr *);


void *
stoaddr(const char *s, int size);

void *
legitimate_addr_s(void *, const char *, int);



#endif //IPADDRS_IPADDRS_H
