#pragma once
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define LFRFID_T5577_BLOCK_COUNT 8

// T5577 block 0 definitions, thanks proxmark3!
#define LFRFID_T5577_POR_DELAY 0x00000001
#define LFRFID_T5577_ST_TERMINATOR 0x00000008
#define LFRFID_T5577_PWD 0x00000010
#define LFRFID_T5577_MAXBLOCK_SHIFT 5
#define LFRFID_T5577_AOR 0x00000200
#define LFRFID_T5577_PSKCF_RF_2 0
#define LFRFID_T5577_PSKCF_RF_4 0x00000400
#define LFRFID_T5577_PSKCF_RF_8 0x00000800
#define LFRFID_T5577_MODULATION_DIRECT 0
#define LFRFID_T5577_MODULATION_PSK1 0x00001000
#define LFRFID_T5577_MODULATION_PSK2 0x00002000
#define LFRFID_T5577_MODULATION_PSK3 0x00003000
#define LFRFID_T5577_MODULATION_FSK1 0x00004000
#define LFRFID_T5577_MODULATION_FSK2 0x00005000
#define LFRFID_T5577_MODULATION_FSK1a 0x00006000
#define LFRFID_T5577_MODULATION_FSK2a 0x00007000
#define LFRFID_T5577_MODULATION_MANCHESTER 0x00008000
#define LFRFID_T5577_MODULATION_BIPHASE 0x00010000
#define LFRFID_T5577_MODULATION_DIPHASE 0x00018000
#define LFRFID_T5577_X_MODE 0x00020000
#define LFRFID_T5577_BITRATE_RF_8 0
#define LFRFID_T5577_BITRATE_RF_16 0x00040000
#define LFRFID_T5577_BITRATE_RF_32 0x00080000
#define LFRFID_T5577_BITRATE_RF_40 0x000C0000
#define LFRFID_T5577_BITRATE_RF_50 0x00100000
#define LFRFID_T5577_BITRATE_RF_64 0x00140000
#define LFRFID_T5577_BITRATE_RF_100 0x00180000
#define LFRFID_T5577_BITRATE_RF_128 0x001C0000
#define LFRFID_T5577_TESTMODE_DISABLED 0x60000000

typedef struct {
    uint32_t block[LFRFID_T5577_BLOCK_COUNT];
    uint32_t blocks_to_write;
    uint8_t mask;
} LFRFIDT5577;

const uint32_t* t5577_get_default_passwords(uint8_t* len);

/**
 * @brief Write T5577 tag data to tag
 * 
 * @param data 
 */
void t5577_write(LFRFIDT5577* data);

void t5577_write_with_pass(LFRFIDT5577* data, uint32_t password);

void t5577_write_with_mask(LFRFIDT5577* data, uint8_t page, bool with_pass, uint32_t password);

void t5577_write_page_block_pass(
    uint8_t page,
    uint8_t block,
    bool lock_bit,
    uint32_t data,
    bool with_pass,
    uint32_t password /*, bool testmode*/);

void t5577_write_page_block_pass_with_start_and_stop(
    uint8_t page,
    uint8_t block,
    bool lock_bit,
    uint32_t data,
    bool with_pass,
    uint32_t password /*, bool testmode*/);

void t5577_write_page_block_simple_with_start_and_stop(
    uint8_t page,
    uint8_t block,
    bool lock_bit,
    uint32_t data /*, bool testmode*/);

#ifdef __cplusplus
}
#endif