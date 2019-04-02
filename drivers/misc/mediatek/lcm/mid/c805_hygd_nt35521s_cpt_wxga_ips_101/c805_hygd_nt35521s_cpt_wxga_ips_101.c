#ifdef BUILD_LK
#include <platform/mt_gpio.h>
#include <platform/mt_i2c.h>
#include <platform/mt_pmic.h>
#include <string.h>
#else
#include <linux/string.h>
#include <linux/wait.h>
#include <linux/platform_device.h>
#include <linux/gpio.h>
#include <linux/pinctrl/consumer.h>
#include <linux/of_gpio.h>
#include <asm-generic/gpio.h>

#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/mm_types.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>

#ifdef CONFIG_OF
#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/regulator/consumer.h>
#include <linux/clk.h>
#endif
#endif
#include "lcm_drv.h"
#include <mt-plat/mt_gpio.h>
#include <mt-plat/upmu_common.h>
extern unsigned int GPIO_LCM_PWR;
extern unsigned int GPIO_LCM_RST;
extern unsigned int GPIO_LCM_VDD;
#define GPIO_LCM_EN GPIO_LCM_VDD




//---------------------------------------------------------------------------
//LocalConstants
//---------------------------------------------------------------------------

#define FRAME_WIDTH (800)
#define FRAME_HEIGHT (1280)
//---------------------------------------------------------------------------
//LocalVariables
//---------------------------------------------------------------------------

static LCM_UTIL_FUNCS lcm_util = {0};

#define SET_RESET_PIN(v)    (lcm_util.set_reset_pin((v)))

#define UDELAY(n) (lcm_util.udelay(n))
#define MDELAY(n) (lcm_util.mdelay(n))

//---------------------------------------------------------------------------
//LocalFunctions
//---------------------------------------------------------------------------
#define dsi_set_cmdq_V3(para_tbl,size,force_update) lcm_util.dsi_set_cmdq_V3(para_tbl,size,force_update)
#define dsi_set_cmdq_V2(cmd,count,ppara,force_update) lcm_util.dsi_set_cmdq_V2(cmd,count,ppara,force_update)
#define dsi_set_cmdq(pdata,queue_size,force_update) lcm_util.dsi_set_cmdq(pdata,queue_size,force_update)
#define wrtie_cmd(cmd) lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr,pdata,byte_nums) lcm_util.dsi_write_regs(addr,pdata,byte_nums)
#define read_reg lcm_util.dsi_read_reg()
#define read_reg_v2(cmd,buffer,buffer_size) lcm_util.dsi_dcs_read_lcm_reg_v2(cmd,buffer,buffer_size)

static void lcm_set_gpio_output(unsigned int GPIO, unsigned int output)
{
        gpio_direction_output(GPIO, output);
        gpio_set_value(GPIO, output);
}


// ---------------------------------------------------------------------------
//  LCM Driver Implementations
// ---------------------------------------------------------------------------


static void lcd_power_en(unsigned char enabled)
{

#ifdef BUILD_LK
		printf("%s(%d), LK \n", __func__, enabled?1:0);
#else
		printk("%s(%d), kernel", __func__, enabled?1:0);
#endif

	if (enabled)
	{
	    lcm_set_gpio_output(GPIO_LCM_EN, GPIO_OUT_ONE);
		lcm_set_gpio_output(GPIO_LCM_PWR, GPIO_OUT_ONE);		
	}
	else
	{	
		lcm_set_gpio_output(GPIO_LCM_EN, 0);
		lcm_set_gpio_output(GPIO_LCM_PWR, 0);   
	}

	
}

static void lcd_reset(unsigned char enabled)
{

#ifdef BUILD_LK
        printf("%s(%d), LK \n", __func__, enabled?1:0);
#else
        printk("%s(%d), kernel", __func__, enabled?1:0);
#endif

    if (enabled)
    {
        lcm_set_gpio_output(GPIO_LCM_RST, GPIO_OUT_ONE);
		
		pmic_config_interface(DIGLDO_CON29, 0x3, PMIC_RG_VGP2_VOSEL_MASK, PMIC_RG_VGP2_VOSEL_SHIFT);
		pmic_config_interface(DIGLDO_CON8, 0x1, PMIC_RG_VGP2_EN_MASK, PMIC_RG_VGP2_EN_SHIFT);	
    }
    else
    {   
        lcm_set_gpio_output(GPIO_LCM_RST, 0);
		
		pmic_config_interface(DIGLDO_CON29, 0x0, PMIC_RG_VGP2_VOSEL_MASK, PMIC_RG_VGP2_VOSEL_SHIFT);
		pmic_config_interface(DIGLDO_CON8, 0x0, PMIC_RG_VGP2_EN_MASK, PMIC_RG_VGP2_EN_SHIFT);	        
    }

    
}

static void init_lcm_registers(void)
{       

    unsigned int data_array[16];

data_array[0] = 0x00053902;
data_array[1] = 0x2555AAFF;
data_array[2] = 0x00000001;
dsi_set_cmdq(data_array, 3, 1);
MDELAY(1);

data_array[0] = 0x08FC1500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x00FC1500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x216F1500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x01F71500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x216F1500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x00F71500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x00053902;
data_array[1] = 0x2555AAFF;
data_array[2] = 0x00000000;
dsi_set_cmdq(data_array, 3, 1);
MDELAY(1);

data_array[0] = 0x00063902;
data_array[1] = 0x52AA55F0;
data_array[2] = 0x00000008;
dsi_set_cmdq(data_array, 3, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x000168B1;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x08B61500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x00043902;
data_array[1] = 0x080201B8;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x004444BB;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x000000BC;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00063902;
data_array[1] = 0x106802BD;
data_array[2] = 0x00000010;
dsi_set_cmdq(data_array, 3, 1);
MDELAY(1);

data_array[0] = 0x80C81500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x00063902;
data_array[1] = 0x52AA55F0;
data_array[2] = 0x00000108;
dsi_set_cmdq(data_array, 3, 1);
MDELAY(1);

data_array[0] = 0x0CC01500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x002929B3;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x001010B4;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x000505B5;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x003536B9;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x002525BA;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x000168BC;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x000168BD;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x3BBE1500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x00CA1500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x00063902;
data_array[1] = 0x52AA55F0;
data_array[2] = 0x00000208;
dsi_set_cmdq(data_array, 3, 1);
MDELAY(1);

data_array[0] = 0x01EE1500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x00113902;
data_array[1] = 0x000000B0;
data_array[2] = 0x0022000C;
data_array[3] = 0x00470035;
data_array[4] = 0x00850068;
data_array[5] = 0x000000B8;
dsi_set_cmdq(data_array, 6, 1);
MDELAY(1);

data_array[0] = 0x00113902;
data_array[1] = 0x01E300B1;
data_array[2] = 0x0167012B;
data_array[3] = 0x021502C5;
data_array[4] = 0x02600218;
data_array[5] = 0x000000AA;
dsi_set_cmdq(data_array, 6, 1);
MDELAY(1);

data_array[0] = 0x00113902;
data_array[1] = 0x03D902B2;
data_array[2] = 0x0340031B;
data_array[3] = 0x038D036D;
data_array[4] = 0x03CE03B4;
data_array[5] = 0x000000E5;
dsi_set_cmdq(data_array, 6, 1);
MDELAY(1);

data_array[0] = 0x00053902;
data_array[1] = 0x03FB03B3;
data_array[2] = 0x000000FF;
dsi_set_cmdq(data_array, 3, 1);
MDELAY(1);

data_array[0] = 0x00063902;
data_array[1] = 0x52AA55F0;
data_array[2] = 0x00000308;
dsi_set_cmdq(data_array, 3, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x000000B0;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x000000B1;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00063902;
data_array[1] = 0x170005B2;
data_array[2] = 0x00000000;
dsi_set_cmdq(data_array, 3, 1);
MDELAY(1);

data_array[0] = 0x00063902;
data_array[1] = 0x000005B6;
data_array[2] = 0x00000000;
dsi_set_cmdq(data_array, 3, 1);
MDELAY(1);

data_array[0] = 0x00063902;
data_array[1] = 0xA00053BA;
data_array[2] = 0x00000000;
dsi_set_cmdq(data_array, 3, 1);
MDELAY(1);

data_array[0] = 0x00063902;
data_array[1] = 0xA00053BB;
data_array[2] = 0x00000000;
dsi_set_cmdq(data_array, 3, 1);
MDELAY(1);

data_array[0] = 0x00053902;
data_array[1] = 0x000000C0;
data_array[2] = 0x00000000;
dsi_set_cmdq(data_array, 3, 1);
MDELAY(1);

data_array[0] = 0x00053902;
data_array[1] = 0x000000C1;
data_array[2] = 0x00000000;
dsi_set_cmdq(data_array, 3, 1);
MDELAY(1);

data_array[0] = 0x60C41500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0xC0C51500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x00063902;
data_array[1] = 0x52AA55F0;
data_array[2] = 0x00000508;
dsi_set_cmdq(data_array, 3, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x000617B0;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x000617B1;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x000617B2;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x000617B3;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x000617B4;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x000617B5;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x0CB81500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x00B91500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x00BA1500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x0ABB1500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x02BC1500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x00063902;
data_array[1] = 0x010103BD;
data_array[2] = 0x00000303;
dsi_set_cmdq(data_array, 3, 1);
MDELAY(1);

data_array[0] = 0x07C01500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0xA2C41500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x002003C8;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x002101C9;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00043902;
data_array[1] = 0x010000CC;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00043902;
data_array[1] = 0x010000CD;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00063902;
data_array[1] = 0xFC0400D1;
data_array[2] = 0x00001407;
dsi_set_cmdq(data_array, 3, 1);
MDELAY(1);

data_array[0] = 0x00063902;
data_array[1] = 0x000510D2;
data_array[2] = 0x00001603;
dsi_set_cmdq(data_array, 3, 1);
MDELAY(1);

data_array[0] = 0x06E51500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x06E61500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x06E71500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x06E81500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x06E91500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x06EA1500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x30ED1500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x00063902;
data_array[1] = 0x52AA55F0;
data_array[2] = 0x00000608;
dsi_set_cmdq(data_array, 3, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x001117B0;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x001016B1;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x001812B2;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x001913B3;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x003100B4;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x003431B5;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x002934B6;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x00332AB7;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x002D2EB8;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x003408B9;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x000834BA;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x002E2DBB;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x002A34BC;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x003429BD;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x003134BE;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x000031BF;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x001319C0;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x001218C1;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x001610C2;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x001711C3;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x003434E5;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x001812C4;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x001913C5;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x001117C6;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x001016C7;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x003108C8;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x003431C9;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x002934CA;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x00332ACB;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x002E2DCC;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x003400CD;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x000034CE;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x002D2ECF;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x002A34D0;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x003429D1;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x003134D2;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x000831D3;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x001610D4;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x001711D5;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x001319D6;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x001218D7;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00033902;
data_array[1] = 0x003434E6;
dsi_set_cmdq(data_array, 2, 1);
MDELAY(1);

data_array[0] = 0x00063902;
data_array[1] = 0x000000D8;
data_array[2] = 0x00000000;
dsi_set_cmdq(data_array, 3, 1);
MDELAY(1);

data_array[0] = 0x00063902;
data_array[1] = 0x000000D9;
data_array[2] = 0x00000000;
dsi_set_cmdq(data_array, 3, 1);
MDELAY(1);

data_array[0] = 0x00E71500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(1);

data_array[0] = 0x00110500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(120);

data_array[0] = 0x00290500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(20);



}


static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util)
{
    memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}

static void lcm_get_params(LCM_PARAMS *params)
{
    printk("=====wjh(lcm_get_params)=====\n");
    memset(params, 0, sizeof(LCM_PARAMS));

    params->type   = LCM_TYPE_DSI;

    params->width  = FRAME_WIDTH;
    params->height = FRAME_HEIGHT;

    params->dsi.mode    = BURST_VDO_MODE;
    params->dsi.LANE_NUM                = LCM_FOUR_LANE;

    params->dsi.data_format.format      = LCM_DSI_FORMAT_RGB888;

    params->dsi.PS=LCM_PACKED_PS_24BIT_RGB888;
    //params->dsi.word_count=800*3; 


	params->dsi.vertical_sync_active = 2;
	params->dsi.vertical_backporch =  10;
	params->dsi.vertical_frontporch = 12;
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 25;
	params->dsi.horizontal_backporch =	25; 
	params->dsi.horizontal_frontporch = 25;
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;


	params->dsi.PLL_CLOCK=200;

}


static void lcm_init(void)
{
   
 	lcd_reset(0);
	lcd_power_en(0);
	lcd_power_en(1);
	MDELAY(50);//Must > 5ms
	lcd_reset(1);
	MDELAY(10);//Must > 5ms
	lcd_reset(0);
	MDELAY(15);//Must > 5ms
	lcd_reset(1);
    MDELAY(100);
	init_lcm_registers();
}

static void lcm_suspend_jd9364(void)
{
    lcd_reset(0);
    MDELAY(10);
    lcd_power_en(0);
    MDELAY(20);
	printk("*****wjh(lcm_suspend)**********\n");
}

static void lcm_resume_jd9364(void)
{

	lcm_init();
}

static void lcm_suspend_power(void)
{
    MDELAY(10);
    lcd_reset(0);
    MDELAY(10);
    lcd_power_en(0);
    MDELAY(10);
}


static void lcm_init_power(void){
  printk("=====wjh(lcm_init_power)=====\n");
}

static void lcm_resume_power(void)
{
	lcm_init_power();	  
}
      
LCM_DRIVER c805_hygd_nt35521s_cpt_wxga_ips_101_lcm_drv= 
{
	.name			= "c805_hygd_nt35521s_cpt_wxga_ips_101",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params     = lcm_get_params,
	.init           = lcm_init,
	.suspend			=lcm_suspend_jd9364,
	.resume				=lcm_resume_jd9364,
	.suspend_power 	= lcm_suspend_power,
	.resume_power 		= lcm_resume_power,
	.init_power 		= lcm_init_power,
	
};