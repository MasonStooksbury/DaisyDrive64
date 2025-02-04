
#define DAISY_BASE_REGISTER 0x08040000
#define DAISY_MENU_INTERRUPT (1 << 3)
enum DAISY_FW_FUNCTION {
    GET_FW_VERSION,
    ENABLE_MENU_FUNCTIONS,
    DISABLE_MENU_FUNCTIONS,
    SD_CARD_READ_SECTOR,
    SD_CARD_WRITE_SECTOR,
    UPLOAD_ROM,
    UPLOAD_ROM_EX,
    SET_SAVE_TYPE,
};

#define DAISY_STATUS_BIT_ROM_LOADING 0x00010000
#define DAISY_STATUS_BIT_SD_BUSY     0x00020000
#define DAISY_STATUS_BIT_MENU_MODE   0x00040000
#define DAISY_STATUS_BIT_DMA_BUSY    0x00080000
#define DAISY_STATUS_BIT_DMA_TIMEOUT 0x00100000
#define DAISY_STATUS_BIT_SD_ERROR    0x00200000
#define DCFG_FIFO_TO_RAM 0
#define DCFG_RAM_TO_FIFO 1

enum DAISY_REGISTERS {
    REG_STATUS,
    REG_EXECUTE_FUNCTION,
    REG_FUNCTION_PARAMETER,
    REG_DMA_CFG,
    REG_DMA_LEN,
    REG_DMA_RAM_ADDR, // There are 512 bytes past this register to receive or send DMA.
    REG_DMA_DATA
};

#define SAVE_TYPE_OFF 0
#define SAVE_TYPE_SRAM 1
#define SAVE_TYPE_SRAM96 2
#define SAVE_TYPE_EEP4k 3
#define SAVE_TYPE_EEP16k 4
#define SAVE_TYPE_FLASH 5

extern uint32_t *MenuBase;

void InitMenuFunctions(void);
extern "C" ITCM_FUNCTION void EXTI3_IRQHandler(void);