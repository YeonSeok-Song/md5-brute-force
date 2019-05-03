#include <stdlib.h>
#include <string.h>
typedef unsigned int word32;
typedef unsigned int uint32;

typedef struct {
    uint32 h[4];
} MD5_Core_State;

struct MD5Context {
    MD5_Core_State core;
    unsigned char block[64];
    int blkused;
    uint32 lenhi, lenlo;
};

void MD5Init(struct MD5Context *context);
void MD5Update(struct MD5Context *context, unsigned char const *buf, unsigned len);
void MD5Final(unsigned char digest[16], struct MD5Context *context);
void MD5Simple(void const *p, unsigned len, unsigned char output[16]);
void MDPrint(unsigned char digest[16]);

