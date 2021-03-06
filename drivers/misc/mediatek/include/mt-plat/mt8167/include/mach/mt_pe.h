/*
 * Copyright (C) 2016 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */

#ifndef _CUST_PE_H_
#define _CUST_PE_H_

/* Pump Express support (fast charging) */
#ifdef CONFIG_MTK_PUMP_EXPRESS_PLUS_SUPPORT
#define TA_START_BATTERY_SOC	1
#define TA_STOP_BATTERY_SOC	95
#define TA_AC_9V_INPUT_CURRENT	CHARGE_CURRENT_1500_00_MA
#define TA_AC_7V_INPUT_CURRENT	CHARGE_CURRENT_1500_00_MA
#define TA_AC_CHARGING_CURRENT	CHARGE_CURRENT_2200_00_MA
#define TA_9V_SUPPORT

#undef V_CHARGER_MAX
#ifdef TA_9V_SUPPORT
#define V_CHARGER_MAX 10500				/*10.5 V*/
#else
#define V_CHARGER_MAX 7500				/*7.5 V*/
#endif
#endif

#endif /* _CUST_PE_H_ */
