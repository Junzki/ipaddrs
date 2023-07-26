#include <ipaddrs.h>
#include <ctype.h>


int
ip4_aton(ip4cidr *addr, const char *a, int size) {
    char *ptr = (char *) a;

    unsigned int parts[IPADDR_VERSION_4_PARTS];
    int part_index = 0;

    unsigned int val = 0;

    if (! isdigit(*ptr)) {
        return -1;
    }

    for (; ptr < (a + size); ++ptr) {
        if (isascii(*ptr) && isdigit(*ptr)) {
            val = (val * 10) + (*ptr - '0');
            continue;
        }

        if (IPADDR_SEP_DOT != *ptr)
            return -1;

        parts[part_index] = val;
        part_index ++;
        val = 0;
    }

    val |= (parts[0] << 24) | (parts[1] << 16) | parts[2] << 8;
    addr->addr_type = IPADDR_VERSION_4;
    addr->address = val;
    addr->mask = 32;

    return 0;
}

int
ip4_host_range(host_range *range, const ip4cidr *addr) {
    if (32 == addr->mask)
        return -1;

    unsigned int mask = (1U << addr->mask) - 1;
    mask = mask << (32 - addr->mask);

    unsigned int host = addr->address & mask;

    range->addr_type = addr->addr_type;
    range->min = host;
    range->max = host | (0xFFFFFFFF - mask);

    return 0;
}
