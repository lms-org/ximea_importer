#pragma once

//-------------------------------------------------------------------------------------------------------------------
// FPGA Register Address Space, common to all PCIe family devices
//-------------------------------------------------------------------------------------------------------------------

// PCIe block dedicated address 0-7 sub-section 
#define FPGA_PCIE_COMM_REG_TRANSPORT_CTRL           0
#define FPGA_PCIE_COMM_REG_INTERRUPT             	1
#define FPGA_PCIE_COMM_REG_PCIE_STATUS              2
#define FPGA_PCIE_COMM_REG_STREAM_BUFF_DELIVERED    3

// Device registers 8-63 
#define FPGA_PCIE_COMM_REG_TEMPERATURE              8
#define FPGA_PCIE_COMM_REG_USER_ID                  9
#define FPGA_PCIE_COMM_REG_SERIAL_NUMBER            10
#define FPGA_PCIE_COMM_REG_FW_REV                   11
#define FPGA_PCIE_COMM_REG_UNIQUE_ID_REG1           12
#define FPGA_PCIE_COMM_REG_UNIQUE_ID_REG2           13
#define FPGA_PCIE_COMM_REG_TIMESTAMP_REG1           14
#define FPGA_PCIE_COMM_REG_TIMESTAMP_REG2           15
#define FPGA_PCIE_COMM_REG_CLK_DAT                  16
#define FPGA_PCIE_COMM_REG_CLK_CFG                  17
#define FPGA_PCIE_COMM_REG_ACQ_FRAME_COUNT          18
#define FPGA_PCIE_COMM_REG_ACQ_FRAME_FIRED_REG1     19
#define FPGA_PCIE_COMM_REG_ACQ_FRAME_FIRED_REG2     20
#define FPGA_PCIE_COMM_REG_ACQ_FRAME_LOST           21
#define FPGA_PCIE_COMM_REG_ACQ_FRAME_UNDERRUN       22
#define FPGA_PCIE_COMM_REG_ACQ_CTRL                 23
#define FPGA_PCIE_COMM_REG_ACQ_NUM_FRAMES           24
#define FPGA_PCIE_COMM_REG_ACQ_NUM_BURST_FRAMES     25
#define FPGA_PCIE_COMM_REG_IO_SELECT                26
#define FPGA_PCIE_COMM_REG_IO_CONFIG                27
#define FPGA_PCIE_COMM_REG_IO_UART                  28
#define FPGA_PCIE_COMM_REG_USER_OUTPUT              29
#define FPGA_PCIE_COMM_REG_TRIG_CTRL                30
#define FPGA_PCIE_COMM_REG_FLASH_SPI_CMD            31
#define FPGA_PCIE_COMM_REG_FLASH_SPI_DAT            32
#define FPGA_PCIE_COMM_REG_FLASH_ADDR_EXT           95
#define FPGA_PCIE_COMM_REG_INT_DAT                  33
#define FPGA_PCIE_COMM_REG_INT_CFG                  34
#define FPGA_PCIE_COMM_REG_HEADER_CFG               35
#define FPGA_PCIE_COMM_REG_USER_METADATA_ADDR       36
#define FPGA_PCIE_COMM_REG_USER_METADATA_DAT        37
#define FPGA_PCIE_COMM_REG_DMA1_BUF_POOL_ADDRL      38
#define FPGA_PCIE_COMM_REG_DMA1_BUF_POOL_ADDRH      39
#define FPGA_PCIE_COMM_REG_DMA1_BUF_POOL_SIZE       40
#define FPGA_PCIE_COMM_REG_DMA1_BUF_POOL_CTRL       41
#define FPGA_PCIE_COMM_REG_IMAGE_CROP_SIZE_REG1     42
#define FPGA_PCIE_COMM_REG_IMAGE_CROP_SIZE_REG2     43
#define FPGA_PCIE_COMM_REG_PACKER_CFG               44
#define FPGA_PCIE_COMM_REG_STREAM_IMAGE_SIZE        45
#define FPGA_PCIE_COMM_REG_STREAM_IMAGE_CFG         46
#define FPGA_PCIE_COMM_REG_LUT_UPDATE               47
#define FPGA_PCIE_COMM_REG_LUT_CFG                  48
#define FPGA_PCIE_COMM_REG_COLCOR_BRAM_ADDR         49
#define FPGA_PCIE_COMM_REG_COLCOR_BRAM_DAT          50
#define FPGA_PCIE_COMM_REG_COLCOR_CFG               51
#define FPGA_PCIE_COMM_REG_SENSOR_SIM_CFG           52
#define FPGA_PCIE_COMM_REG_SENSOR_SIM_FRAME_SIZE    53
#define FPGA_PCIE_COMM_REG_SENSOR_SIM_EXP_TIME      54
#define FPGA_PCIE_COMM_REG_SENSOR_SIM_FOT_TIME      55
#define FPGA_PCIE_COMM_REG_DIG_GAIN_OFFSET_MULT     56
#define FPGA_PCIE_COMM_REG_DIG_GAIN_OFFSET_ADD      57
#define FPGA_PCIE_COMM_REG_BAD_PIXEL_DAT            58
#define FPGA_PCIE_COMM_REG_BAD_PIXEL_COUNTER        59
#define FPGA_PCIE_COMM_REG_BAD_PIXEL_ADDR           60
#define FPGA_PCIE_COMM_REG_ACQ_FRAME_RATE           61

//-------------------------------------------------------------------------------------------------------------------
// FPGA Register Read/Write Bit Offsets of individual variables
// Note: Registers that are not used for multiple variables - where all 32 bits belong to one variable (e.g. SERIAL_NUMBER == {serial_number[31:0]}) - are not specified
// Note: Register Address Map overview for Read/Write is available in Excel document
//-------------------------------------------------------------------------------------------------------------------

// FPGA_REG_TRANSPORT_CTRL_REG - WRITE Offsets
#define TRANSPORT_CTRL_WR_OFFSET_ABORT_DMA0     0
#define TRANSPORT_CTRL_WR_OFFSET_ABORT_DMA1     1

// FPGA_REG_DMA_CTRL_REG - READ Offsets
#define TRANSPORT_CTRL_RD_OFFSET_ABORT_DMA0     0
#define TRANSPORT_CTRL_RD_OFFSET_STATUS_DMA0    1
#define TRANSPORT_CTRL_RD_OFFSET_ABORT_DMA1     5
#define TRANSPORT_CTRL_RD_OFFSET_STATUS_DMA1    6
#define TRANSPORT_CTRL_RD_OFFSET_STATUS_IDLE    10  // Indicates idle state of the transport module

// FPGA_PCIE_COMM_REG_PCIE_STATUS - READ Offsets
#define PCIE_STATUS_RD_OFFSET_LINK_UP           0   // Indicates the physical layer link up status
#define PCIE_STATUS_RD_OFFSET_LINK_RATE         1   // 0: 2.5Gbps, 1: 5.0Gbps
#define PCIE_STATUS_RD_OFFSET_LINK_WIDTH        2   // 00: 1 lane, 01: 2 lane, 10: 4 lane, 11: 8 lane

// FPGA_REG_UNIQUE_ID_REG1 - WRITE Offsets
#define UNIQUE_ID_REG1_WR_OFFSET_RELOAD         0   // Forces sequence of re-loading Unique ID from DS2401/DS2411 IC through One-Wire communication

// FPGA_REG_CLK_DAT - WRITE Offsets
#define CLK_DAT_WR_OFFSET_DATA                  0
#define CLK_DAT_WR_OFFSET_DATA_MASK             16

// FPGA_REG_CLK_CFG - WRITE Offsets
#define CLK_CFG_WR_OFFSET_MMCM_RESET            0
#define CLK_CFG_WR_OFFSET_DRP_SET               1
#define CLK_CFG_WR_OFFSET_ADDRESS               2

// FPGA_REG_CLK_CFG - READ Offsets
#define CLK_DAT_RD_OFFSET_LOCKED                0   // Bit indicating that the MMCM Clock Generator is Locked
#define CLK_DAT_RD_OFFSET_BUSY                  1   // Bit indicating that the MMCM Clock Generator is Busy

// FPGA_REG_ACQ_CTRL - WRITE Offsets
#define	ACQ_CTRL_WR_OFFSET_EN                   0
#define	ACQ_CTRL_WR_OFFSET_EXP_MODE             1

// FPGA_REG_ACQ_CTRL - READ Offsets
#define	ACQ_CTRL_RD_OFFSET_EN                   0
#define	ACQ_CTRL_RD_OFFSET_EXP_MODE             1

// FPGA_REG_IO_SELECT - WRITE Offsets
#define	IO_SELECT_WR_OFFSET_LINE_SEL            0
#define	IO_SELECT_WR_OFFSET_TRIG_SEL            4
#define	IO_SELECT_WR_OFFSET_RXD_SEL             8
#define	IO_SELECT_WR_OFFSET_USER_OUT_SEL        12

// FPGA_REG_IO_SELECT - READ Offsets
#define	IO_SELECT_RD_OFFSET_LINE_SEL            0
#define	IO_SELECT_RD_OFFSET_TRIG_SEL            4
#define	IO_SELECT_RD_OFFSET_RXD_SEL             8
#define	IO_SELECT_RD_OFFSET_USER_OUT_SEL        12

// FPGA_REG_IO_CONFIG - WRITE Offsets
// Sets Invert, Mode and Source parameters of IO Line selected by IO_SELECT
#define	IO_CONFIG_WR_OFFSET_INVERTER            0
#define	IO_CONFIG_WR_OFFSET_MODE		        1
#define	IO_CONFIG_WR_OFFSET_SOURCE              2

// FPGA_REG_IO_CONFIG - READ Offsets: 32bit register [00000000 0ttttttt tttttttt tsssssmi]
// i = LineInverter IO_CONFIG_RD_OFFSET_INVERTER    (1 bit   = 0 invertor is off, =1 invertor is active)
// m = LineMode     IO_CONFIG_RD_OFFSET_MODE        (1 bit   = 1 line is output, =0 line is input)
// s = LineSource   IO_CONFIG_RD_OFFSET_SOURCE      (5 bits  = values see PcieFamLineSource)
// t = LineStatus   IO_CONFIG_RD_OFFSET_STATUS      (16 bits = digital status of 16 lines (not all may be physically present on device), bit index = PcieFamLineSelector)
#define	IO_CONFIG_RD_OFFSET_INVERTER            0
#define	IO_CONFIG_RD_OFFSET_MODE		        1
#define	IO_CONFIG_RD_OFFSET_SOURCE              2
#define	IO_CONFIG_RD_OFFSET_STATUS              7

// FPGA_REG_IO_UART - WRITE Offsets
#define	IO_UART_WR_OFFSET_START			        0
#define	IO_UART_WR_OFFSET_DAT			        1
#define	IO_UART_WR_OFFSET_BAUD		            9

// FPGA_REG_IO_UART - READ Offsets
#define	IO_UART_RD_OFFSET_READY 		        0
#define	IO_UART_RD_OFFSET_DAT			        1
#define	IO_UART_RD_OFFSET_BAUD		            9

// FPGA_REG_USER_OUTPUT - WRITE Offsets
#define USER_OUTPUT_WR_OFFSET_VALUE             0
#define USER_OUTPUT_WR_OFFSET_VALUE_MASK        16

// FPGA_REG_USER_OUTPUT - READ Offsets
#define USER_OUTPUT_RD_OFFSET_VALUE             0
#define USER_OUTPUT_RD_OFFSET_VALUE_MASK        16

// FPGA_REG_TRIG_CTRL - WRITE Offsets
#define	TRIG_CTRL_WR_OFFSET_SOURCE              0   	       
#define	TRIG_CTRL_WR_OFFSET_ACTIV   	        4
#define	TRIG_CTRL_WR_OFFSET_MODE   	            7
#define	TRIG_CTRL_WR_OFFSET_OVERLAP  	        8
#define	TRIG_CTRL_WR_OFFSET_SOFT   	            10

// FPGA_REG_TRIG_CTRL - READ Offsets
#define	TRIG_CTRL_RD_OFFSET_SOURCE              0   	       
#define	TRIG_CTRL_RD_OFFSET_ACTIV   	        4
#define	TRIG_CTRL_RD_OFFSET_MODE   	            7
#define	TRIG_CTRL_RD_OFFSET_OVERLAP  	        8

// FPGA_REG_FLASH_SPI_CMD - WRITE Offsets
#define FLASH_SPI_CMD_WR_OFFSET_ADDR	        0
#define FLASH_SPI_CMD_WR_OFFSET_CMD	            24

// FPGA_REG_FLASH_SPI_CMD - READ Offsets
#define FLASH_SPI_CMD_RD_OFFSET_BUSY	        0

// FPGA_PCIE_COMM_REG_FLASH_ADDR_EXT - WRITE Offsets
#define FLASH_SPI_EXT_WR_OFFSET_ADDR            0
#define FLASH_SPI_EXT_WR_OFFSET_BULK            8
#define FLASH_SPI_EXT_WR_OFFSET_RESET           28

// FPGA_PCIE_COMM_REG_FLASH_ADDR_EXT - READ Offsets
#define FLASH_SPI_EXT_RD_OFFSET_COUNT           0
#define FLASH_SPI_EXT_RD_OFFSET_VERSION         30


// FPGA_REG_INT_DAT - WRITE Offsets
#define INT_DAT_WR_OFFSET_EVENT_INT_ENABLED     0

// FPGA_REG_INT_DAT - READ Offsets
#define INT_DAT_RD_OFFSET_EVENT_INFO_BUFFER_ID          0
#define INT_DAT_RD_OFFSET_EVENT_INFO_BUFFER_ID_VALID    12
#define INT_DAT_RD_OFFSET_EVENT_SOURCE          		26

// FPGA_REG_INT_CFG - WRITE Offsets
#define INT_CFG_WR_OFFSET_EVENT_SELECTOR        0
#define INT_CFG_WR_OFFSET_EVENT_RST             6
#define INT_CFG_WR_OFFSET_INT_GLOBAL_ENABLE     7

// FPGA_REG_INT_CFG - READ Offsets
#define INT_CFG_RD_OFFSET_EVENT_INT_ENABLED     0
#define INT_CFG_RD_OFFSET_EVENT_SELECTOR        1
#define INT_CFG_RD_OFFSET_EVENT_COUNT           7
#define INT_CFG_RD_OFFSET_EVENT_OVERFLOW        17
#define INT_CFG_RD_OFFSET_INT_GLOBAL_ENABLE     18

// FPGA_REG_HEADER_CFG - WRITE Offsets
#define HEADER_CFG_OFFSET_SIZE                  0

// FPGA_REG_DMA1_BUF_POOL_CTRL - WRITE Offsets
#define DMA1_BUF_POOL_CTRL_WR_OFFSET_FRAME_NUM  0
#define DMA1_BUF_POOL_CTRL_WR_OFFSET_BUFFER_ID  14
#define DMA1_BUF_POOL_CTRL_WR_OFFSET_INT        26
#define DMA1_BUF_POOL_CTRL_WR_OFFSET_REQUEUE    27
#define DMA1_BUF_POOL_CTRL_WR_OFFSET_FLUSH      28
#define DMA1_BUF_POOL_CTRL_WR_OFFSET_ADD        29

// FPGA_REG_DMA1_BUF_POOL_CTRL - READ Offsets
#define DMA1_BUF_POOL_CTRL_RD_OFFSET_FULL       0
#define DMA1_BUF_POOL_CTRL_RD_OFFSET_FLUSH_BUSY 1
#define DMA1_BUF_POOL_CTRL_RD_OFFSET_ADD_BUSY   2

// FPGA_REG_IMAGE_CROP_SIZE_REG1 - WRITE Offset
#define IMAGE_CROP_SIZE_REG1_WR_OFFSET_START    0
#define IMAGE_CROP_SIZE_REG1_WR_OFFSET_STOP     16

// FPGA_REG_IMAGE_CROP_SIZE_REG2 - WRITE Offset
#define IMAGE_CROP_SIZE_REG1_WR_OFFSET_RECYCLE  0

// FPGA_REG_STREAM_IMAGE_CFG - WRITE Offset
#define STREAM_IMAGE_CFG_WR_OFFSET_ABORT        0
#define STREAM_IMAGE_CFG_WR_OFFSET_STOP         1

// FPGA_REG_STREAM_IMAGE_CFG - READ Offset
#define STREAM_IMAGE_CFG_RD_OFFSET_STOPPED      0

// FPGA_REG_LUT_UPDATE - WRITE Offset
#define LUT_UPDATE_WR_OFFSET_ADDR               0
#define LUT_UPDATE_WR_OFFSET_DAT                12

// FPGA_REG_LUT_CFG - WRITE Offset
#define LUT_CFG_WR_OFFSET_EN                    0

// FPGA_REG_COLCOR_CFG - WRITE Offset
#define COLCOR_CFG_WR_OFFSET_EN                 0
#define COLCOR_CFG_WR_OFFSET_RAND_EN            1
#define COLCOR_CFG_WR_OFFSET_ADDER_SHIFT        2
#define COLCOR_CFG_WR_OFFSET_ADDRES_RECYCLE     5

// FPGA_REG_COLCOR_BRAM_ADDR - WRITE Offset
#define COLCOR_BRAM_ADDR_WR_OFFSET_ADDRA        0
#define COLCOR_BRAM_ADDR_WR_OFFSET_SEL          11

// FPGA_REG_COLCOR_BRAM_DAT - WRITE Offset
#define COLCOR_BRAM_DAT_WR_OFFSET_ADD           0
#define COLCOR_BRAM_DAT_WR_OFFSET_SEL           11
#define COLCOR_BRAM_DAT_WR_OFFSET_MULT          12

// BAD Pixel List Offsets and Definitions
#define BAD_PIXEL_LIST_ADDR_MAX         2048

#define BAD_PIXEL_ADDR_OFFSET_ADDR      0
#define BAD_PIXEL_ADDR_OFFSET_COUNT     30
#define BAD_PIXEL_ADDR_OFFSET_WEA       31

#define BAD_PIXEL_COUNTER_OFFSET_COUNT  0
#define BAD_PIXEL_COUNTER_OFFSET_VALID  31

#define BAD_PIXEL_DAT_OFFSET_PIX0       0
#define BAD_PIXEL_DAT_OFFSET_PIX1       4
#define BAD_PIXEL_DAT_OFFSET_PIX2       8
#define BAD_PIXEL_DAT_OFFSET_PIX3       12
#define BAD_PIXEL_DAT_OFFSET_PIX4       16
#define BAD_PIXEL_DAT_OFFSET_PIX5       20
#define BAD_PIXEL_DAT_OFFSET_PIX6       24
#define BAD_PIXEL_DAT_OFFSET_PIX7       28

#define BAD_PIXEL_CORRECTION_NONE       8
#define BAD_PIXEL_CORRECTION_PIX0       0
#define BAD_PIXEL_CORRECTION_PIX1       1
#define BAD_PIXEL_CORRECTION_PIX2       2
#define BAD_PIXEL_CORRECTION_PIX3       3
#define BAD_PIXEL_CORRECTION_PIX4       4
#define BAD_PIXEL_CORRECTION_PIX5       5
#define BAD_PIXEL_CORRECTION_PIX6       6
#define BAD_PIXEL_CORRECTION_PIX7       7


//-------------------------------------------------------------------------------------------------------------------
// FPGA Register Variable Enumerators
//-------------------------------------------------------------------------------------------------------------------

// Column Correction Constants
// ColCor Reload Counter is specified in 8 pixel multiples
#define PCIE_COMMON_COLCOR_RELOAD_COUNT_MIN     1
#define PCIE_COMMON_COLCOR_RELOAD_COUNT_MAX     1536
// ColCor Column Selector is specified by individual pixel
#define PCIE_COMMON_COLCOR_COLUMN_MIN           0
#define PCIE_COMMON_COLCOR_COLUMN_MAX           (1536*8-1)

//-------------------------------------------------------------------------------------------------------------------
// IO Selector, Source, Mode, Inverter
//-------------------------------------------------------------------------------------------------------------------
typedef enum
{
	PCIE_COMM_LINE_MODE_INPUT             =0, // The selected physical line is used to Output an electrical signal.
	PCIE_COMM_LINE_MODE_OUTPUT            =1, // The selected physical line is used to Input an electrical signal.
} PcieCommonLineMode;

typedef enum
{
	PCIE_COMM_LINE_INVERTER_FALSE         =0, // The IO Line signal is not inverted.
	PCIE_COMM_LINE_INVERTER_TRUE          =1, // The IO Line signal is inverted.
} PcieCommonLineInverterMode;

// Line Source
typedef enum
{
	PCIE_COMM_LINE_SOURCE_OFF                = 0,  
	PCIE_COMM_LINE_SOURCE_ON                 = 1,  
	PCIE_COMM_LINE_SOURCE_BLINK              = 2,  
	PCIE_COMM_LINE_SOURCE_TXD                = 3,  
	PCIE_COMM_LINE_SOURCE_IMG_EXP            = 4,  
	PCIE_COMM_LINE_SOURCE_IMG_READ           = 5,  
	PCIE_COMM_LINE_SOURCE_IMG_BUSY           = 6,  
	PCIE_COMM_LINE_SOURCE_PCIE_SPEED         = 7,  
	PCIE_COMM_LINE_SOURCE_PCIE_LANE          = 8,  
	PCIE_COMM_LINE_SOURCE_RSV1               = 9,  
	PCIE_COMM_LINE_SOURCE_RSV2               = 10, 
	PCIE_COMM_LINE_SOURCE_RSV3               = 11, 
	PCIE_COMM_LINE_SOURCE_IO_STATUS_1        = 12, 
	PCIE_COMM_LINE_SOURCE_IO_STATUS_2        = 13, 
	PCIE_COMM_LINE_SOURCE_IO_STATUS_3        = 14, 
	PCIE_COMM_LINE_SOURCE_IO_STATUS_4        = 15, 
	PCIE_COMM_LINE_SOURCE_IO_STATUS_5        = 16, 
	PCIE_COMM_LINE_SOURCE_IO_STATUS_6        = 17, 
	PCIE_COMM_LINE_SOURCE_IO_STATUS_7        = 18, 
	PCIE_COMM_LINE_SOURCE_IO_STATUS_8        = 19, 
	PCIE_COMM_LINE_SOURCE_IO_STATUS_9        = 20, 
	PCIE_COMM_LINE_SOURCE_IO_STATUS_10       = 21, 
	PCIE_COMM_LINE_SOURCE_IO_STATUS_11       = 22, 
	PCIE_COMM_LINE_SOURCE_IO_STATUS_12       = 23, 
	PCIE_COMM_LINE_SOURCE_USER_OUTPUT1       = 24, 
	PCIE_COMM_LINE_SOURCE_USER_OUTPUT2       = 25, 
	PCIE_COMM_LINE_SOURCE_USER_OUTPUT3       = 26, 
	PCIE_COMM_LINE_SOURCE_USER_OUTPUT4       = 27, 
	PCIE_COMM_LINE_SOURCE_USER_OUTPUT5       = 28, 
	PCIE_COMM_LINE_SOURCE_USER_OUTPUT6       = 29, 
	PCIE_COMM_LINE_SOURCE_USER_OUTPUT7       = 30, 
	PCIE_COMM_LINE_SOURCE_USER_OUTPUT8       = 31, 
} PCIeCommonLineSource;

//-------------------------------------------------------------------------------------------------------------------
// Trigger Selector, Mode, Source, Activation, Overlap
//-------------------------------------------------------------------------------------------------------------------

// Trigger Selector - defines action to be done on the trigger event - TRIG_CTRL_WR_OFFSET_SOURCE
typedef enum
{
	PCIE_COMM_TRIG_SELECT_ACQ_START          = 0, // Acquisition will be started upon trigger event,
	PCIE_COMM_TRIG_SELECT_FRAME_START        = 1, // One Frame capture will be started upon trigger event,
	PCIE_COMM_TRIG_SELECT_FRAME_BURST_START  = 2, // Burst of Frames capture will be started upon trigger event,
	PCIE_COMM_TRIG_SELECT_EXP_ACTIVE         = 3, // Active Exposure time will be defined by the trigger event,
    PCIE_COMM_TRIG_SELECT_EXP_START          = 4, // Exposure of one Frame will be started upon trigger event,
} PCIeCommonTrigSelect;

typedef enum
{
    PCIE_COMM_TRIG_SOURCE_SOFT             =0, //
	PCIE_COMM_TRIG_SOURCE_LINE0            =1, //
	PCIE_COMM_TRIG_SOURCE_LINE1            =2, //
	PCIE_COMM_TRIG_SOURCE_LINE2            =3, //
	PCIE_COMM_TRIG_SOURCE_LINE3            =4, //
	PCIE_COMM_TRIG_SOURCE_LINE4            =5, //
	PCIE_COMM_TRIG_SOURCE_LINE5            =6, //
	PCIE_COMM_TRIG_SOURCE_LINE6            =7, //
	PCIE_COMM_TRIG_SOURCE_LINE7            =8, //
	PCIE_COMM_TRIG_SOURCE_LINE8            =9, //
	PCIE_COMM_TRIG_SOURCE_LINE9            =10,//
	PCIE_COMM_TRIG_SOURCE_LINE10           =11,//
	PCIE_COMM_TRIG_SOURCE_LINE11           =12,//
} PcieCommonTrigSource;

typedef enum
{
	PCIE_COMM_TRIG_ACTIV_RISING_EDGE       =0, //
	PCIE_COMM_TRIG_ACTIV_FALLING_EDGE      =1, //
	PCIE_COMM_TRIG_ACTIV_ANY_EDGE          =2, //
	PCIE_COMM_TRIG_ACTIV_LEVEL_HIGH        =3, //
	PCIE_COMM_TRIG_ACTIV_LEVEL_LOW         =4, //
} PcieCommonTrigActivation;

typedef enum
{
	PCIE_COMM_TRIG_OVERLAP_OFF             =0, //
	PCIE_COMM_TRIG_OVERLAP_READ            =1, //
	PCIE_COMM_TRIG_OVERLAP_PREVIOUS_FRAME  =2, //
} PcieCommonTrigOverlap;

// Trigger Mode
typedef enum
{
	PCIE_COMM_TRIG_MODE_OFF                  = 0, //
	PCIE_COMM_TRIG_MODE_ON                   = 1, //
} PCIeCommonTrigMode;

// Packer mode
typedef enum
{
    PCIE_COMM_PACK_MONO8        = 0,
    PCIE_COMM_PACK_MONO16       = 1,
    PCIE_COMM_PACK_MONO12       = 2,
    PCIE_COMM_PACK_MONO10       = 3,
    PCIE_COMM_PACK_MONO8P16     = 4,
    PCIE_COMM_PACK_MONO12MSB    = 5,
    PCIE_COMM_PACK_MONO10MSB    = 6,
    PCIE_COMM_PACK_MONO8P16MSB  = 7,
    PCIE_COMM_PACK_MONO10P      = 8,
    PCIE_COMM_PACK_MONO12P      = 9,
    PCIE_COMM_PACK_MONO9P       = 10,
    PCIE_COMM_PACK_MONO11P      = 11,
} PCIeCommonPackerMode;


// Interrupt Events Enumeration - INT_CFG_WR_OFFSET_EVENT_SELECTOR
typedef enum
{
	EVENT_ACQUISITION_TRANSFER_END      = 0, 
	EVENT_ACQUISITION_FRAME_LOST        = 1, 
	EVENT_LINE0_RISING_EDGE             = 32,
} PCIeCommonEventSelect;

// Exposure Mode Enumerator - ACQ_CTRL_RD_OFFSET_EXP_MODE; Note - identifiers are different than FGenTL_ITEM_ExposureMode (e.g. FGenTL_ITEM_ExposureModeEnum_Timed = 1)
typedef enum 
{
	ACQ_EXP_MODE_TIMED                  = 0,   // Timed exposure. The exposure duration is set using the ExposureTime feature
	ACQ_EXP_MODE_TRIG_WIDTH             = 1,   // Uses the width of the current Frame or Line trigger signal(s) to control the exposure duration.
} PCIeCommonAcquisitionExposureMode;

//-------------------------------------------------------------------------------------------------------------------
// Flash Transaction Commands (Write Enable, Sector Erase, Pape Program,...) - FLASH_SPI_CMD_WR_OFFSET_CMD
//-------------------------------------------------------------------------------------------------------------------
#define	SPI_FLASH_CMD_WREN	            0x06
#define	SPI_FLASH_CMD_SE	            0xD8
#define	SPI_FLASH_CMD_READ	            0x03
#define	SPI_FLASH_CMD_RDSR1	            0x05
#define	SPI_FLASH_CMD_PP	            0x02

