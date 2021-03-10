#include <stdio.h>
#include <stdint.h>
#define HTONS(A) (((A) & 0xff00) >> 8) | (((A) & 0x00ff) << 8)

typedef struct {
    uint8_t ver_hdr;
    uint8_t tos;
    uint16_t totalLength;
    uint16_t id;
    uint16_t frag;
    uint8_t ttl;
    uint8_t protocol;
    uint16_t checkSum;
    uint8_t srcIp[4];
    uint8_t dstIp[4];
}Ipv4Hdr;

/*
IPv4报文内存中的样子和测试仪的顺序一致(网络字节序)
(gdb) x/20xb &firstFragPacket
0x61ff1c:       0x45    0x00    0x01    0xf4    0x00    0x0f    0x20    0x00
0x61ff24:       0xfe    0x01    0x90    0xf0    0x02    0x02    0x02    0x02
0x61ff2c:       0x03    0x03    0x03    0x03
*/

/*
解析IPV4报文和IPV6报文的checksum的算法：
校验和(checksum)算法，简单的说就是16位累加的反码运算
注意：uint32_t cksum的类型，这里是４个字节的，防止在累加的过程中，数据溢出(例如0xFF累加时就会内存溢出)
*/
uint32_t CheckSum(uint32_t cksum, void *pBuffer, uint32_t size)
{
    uint8_t num = 0;
    uint8_t *p = (uint8_t *)pBuffer;

    if(pBuffer == NULL || size == 0)
    {
        return cksum;
    }

    while(size>1)
    {
        // 2个字节累加,网络字节序要先变成主机字节序在进行累加
        cksum += ((uint16_t)p[num] << 8 & 0xff00) | ((uint16_t)p[num+1] & 0x00ff);
        size -= 2;
        num += 2;
    }

    if (size>0){
        // IPv4报文总长度为奇数,最后一个字节单独相加
        cksum += ((uint16_t)p[num] << 8 & 0xffff);
        num += 1;
    }

    while (cksum>>16)
    {
        // 累加完毕将结果中高16位再加到低16位上，重复这一过程直到高16位为全0
        cksum = (cksum & 0xffff) + (cksum>>16);
    }

    return cksum;
}

int main()
{
    Ipv4Hdr firstFragPacket = {
        .ver_hdr = 0x45,
        .tos = 0x00,
        .totalLength = 0xf401,
        .id = 0x0f00,
        .frag = 0x0020,
        .ttl = 0xfe,
        .protocol = 0x01,
        .checkSum = 0xf090,
        .srcIp = {0x02, 0x02, 0x02, 0x02},
        .dstIp = {0x03, 0x03, 0x03, 0x03}
    };
    Ipv4Hdr *pIpHeader = &firstFragPacket;
    printf("helloworld!\n");
    uint32_t ipHeadLen = (pIpHeader->ver_hdr & 0x0f) << 2;
    pIpHeader->checkSum = 0;
    printf("checkSum=0x%x\n", pIpHeader->checkSum);
    uint32_t sum = CheckSum(0, (void *)pIpHeader, ipHeadLen);
    printf("checkSum=0x%x\n", sum);
    pIpHeader->checkSum = HTONS((uint16_t)(~sum));
    printf("checkSum=0x%x\n", pIpHeader->checkSum);
    return 0;
}