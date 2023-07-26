#include <ipaddrs.h>
#include <string.h>
#include <assert.h>


int
test_ip4_aton() {
    char *addr = "127.0.0.1";
    size_t size = strlen(addr);

    ip4cidr ip;
    assert(0 <= ip4_aton(&ip, addr, size));
    assert(0x7F000001 == ip.address);

    return 0;
}

int test_ip4_host_range() {
    ip4cidr ip = {
            .address = 0xC0A80101,  // 192.168.1.1
            .mask = 16,
            .addr_type = IPADDR_VERSION_4
    };

    host_range range;
    assert(0 == ip4_host_range(&range, &ip));
    assert(0xC0A80000 == range.min);  // 192.168.0.0
    assert(0xC0A8FFFF == range.max);  // 192.168.255.255

    return 0;
}


int
main(void) {
    test_ip4_aton();
    test_ip4_host_range();
}
