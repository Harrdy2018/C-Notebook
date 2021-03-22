#include <stdio.h>
#include <stdint.h>
#define BYTE_REVERT_2(x) ((((x)&0xff00) >> 8) | (((x)&0x00ff) << 8))

#ifndef NTOHS
#define NTOHS(x) BYTE_REVERT_2(x)
#endif

#ifndef HTONS
#define HTONS(x) BYTE_REVERT_2(x)
#endif

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
uint16_t CheckSum(void *pBuffer, uint32_t len)
{
    uint32_t cksum = 0;
    uint16_t *p = (uint16_t *)pBuffer;

    if(pBuffer == NULL || len == 0)
    {
        return (uint16_t)cksum;
    }

    while(len>1)
    {
        // 2个字节累加,网络字节序要先变成主机字节序在进行累加
        cksum += NTOHS(*p);
        p++;
        len -= 2;
    }

    if (len == 1){
        // IPv4报文总长度为奇数,最后一个字节单独相加
        cksum += NTOHS(*p) & 0xff00;
    }

    while (cksum>>16)
    {
        // 累加完毕将结果中高16位再加到低16位上，重复这一过程直到高16位为全0
        cksum = (cksum & 0xffff) + (cksum>>16);
    }

    return (uint16_t)(~cksum);
}


/*
将IP Header中每两个连续的字节当成一个16bit数，对所有的16bit数进行求和，在求和过程中，
任何溢出16bit数范围的求和结果都需要进行回卷——将溢出的高16bit和求和结果的低16bit相加；
对最终的求和结果按位取反，即可得到IP Header Checksum
IP Header Checksum的验证方法为：只需进行Checksum计算中的第二步，若最终结果为0xFFFF则说明IP Header无差错。

TCP/UDP的有效载荷（payload）会参与Checksum的计算；
TCP/UDP会额外将一个伪首部加入计算，伪首部包括：32bit的源/目的IP地址，8bit的补零，8bit的协议号，以及16bit的TCP/UDP报文长度（头+数据）
在计算过程中，TCP/UDP报文总字节数可能为奇数，最后剩余的单个字节直接和中间结果相加（相当于高8bit补0）
*/

/**
real packet:
0x0000:  0021 97aa 14f5 3822 d6bf 5100 0800 4500
0x0010:  003c 0000 4000 3e06 6ab6 9fe2 2716 0a18
0x0020:  00f6 0050 b469 e522 8dc4 8189 6718 a012
0x0030:  3890 32d5 0000 0204 05b4 0402 080a 3c62
0x0040:  232b 0091 9a24 0103 0306
IP报文总长度：60B (0x003c)
TCP报文总长度：40B (60B-20B)
IP Header checksum: 6ab6
TCP checksum: 32d5
 **/

//真实报文
uint8_t pkt[] = 
{
    0x00, 0x21, 0x97, 0xaa, 0x14, 0xf5, 0x38, 0x22, 
    0xd6, 0xbf, 0x51, 0x00, 0x08, 0x00, 0x45, 0x00,
    0x00, 0x3c, 0x00, 0x00, 0x40, 0x00, 0x3e, 0x06, 
    0x6a, 0xb6, 0x9f, 0xe2, 0x27, 0x16, 0x0a, 0x18,
    0x00, 0xf6, 0x00, 0x50, 0xb4, 0x69, 0xe5, 0x22, 
    0x8d, 0xc4, 0x81, 0x89, 0x67, 0x18, 0xa0, 0x12,
    0x38, 0x90, 0x32, 0xd5, 0x00, 0x00, 0x02, 0x04, 
    0x05, 0xb4, 0x04, 0x02, 0x08, 0x0a, 0x3c, 0x62,
    0x23, 0x2b, 0x00, 0x91, 0x9a, 0x24, 0x01, 0x03, 
    0x03, 0x06
};

//加入了伪首部的tcp报文
uint8_t pseudo_hdr_tcp[] = 
{
    //pseudo header
    0x9f, 0xe2, 0x27, 0x16, 0x0a, 0x18, 0x00, 0xf6,
    0x00, 0x06, 0x00, 0x28,
    //tcp
    0x00, 0x50, 0xb4, 0x69, 0xe5, 0x22, 0x8d, 0xc4, 
    0x81, 0x89, 0x67, 0x18, 0xa0, 0x12, 0x38, 0x90, 
    0x32, 0xd5, 0x00, 0x00, 0x02, 0x04, 0x05, 0xb4, 
    0x04, 0x02, 0x08, 0x0a, 0x3c, 0x62, 0x23, 0x2b, 
    0x00, 0x91, 0x9a, 0x24, 0x01, 0x03, 0x03, 0x06
};

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
    uint32_t sum = CheckSum((void *)pIpHeader, ipHeadLen);
    printf("pkt checkSum %x\n", sum);
    pIpHeader->checkSum = NTOHS(sum);
    printf("checkSum=0x%x\n", pIpHeader->checkSum);

    // test real pkt
     uint8_t *ip_hdr = (uint8_t*)&pkt[14];

    //checksum置0
    pkt[24] = 0;
    pkt[25] = 0;
    printf("pkt ip cksm %04x\n", CheckSum((void*)ip_hdr, 20));

    //checksum置0
    pseudo_hdr_tcp[28] = 0;
    pseudo_hdr_tcp[29] = 0;
    //12B伪首部+40Btcp报文
    printf("pkt tcp cksm %04x\n", CheckSum((void*)pseudo_hdr_tcp, 52));
    return 0;
}