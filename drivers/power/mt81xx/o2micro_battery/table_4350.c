/*****************************************************************************
* Copyright(c) O2Micro, 2014. All rights reserved.
*
* O2Micro battery gauge driver
* File: table.c
*
* $Source: /data/code/CVS
* $Revision: 4.00.01 $
*
* This program is free software and can be edistributed and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation.
*
* This Source Code Reference Design for O2MICRO Battery Gauge access (\u201cReference Design\u201d) 
* is sole for the use of PRODUCT INTEGRATION REFERENCE ONLY, and contains confidential 
* and privileged information of O2Micro International Limited. O2Micro shall have no 
* liability to any PARTY FOR THE RELIABILITY, SERVICEABILITY FOR THE RESULT OF PRODUCT 
* INTEGRATION, or results from: (i) any modification or attempted modification of the 
* Reference Design by any party, or (ii) the combination, operation or use of the 
* Reference Design with non-O2Micro Reference Design.
*
* Battery Manufacture: NOVEO
* Battery Model: U1005
* Absolute Max Capacity(mAhr): 4326
* Limited Charge Voltage(mV): 4350
* Cutoff Discharge Voltage(mV): 3200
* Equipment: "JY1-1","JY1-1","JY1-1","JY1-3","JY1-3","JY1-8","JY1-8","JY1-8","JY1-1","JY1-1","JY1-1","JY1-1","JY1-1","JY1-1","JY1-1","JY1-1","JY1-3","JY1-3","JY1-3","JY1-3","JY1-3","JY1-5","JY1-3","JY1-3","JY2-1","JY2-1","JY2-1","JY2-1","JY2-1","JY2-1","JY2-1","JY2-7","JY2-7","JY2-7","JY2-7","JY2-7","JY2-7","JY2-7","JY1-6","JY1-6","JY1-6","JY1-6","JY2-7","JY2-7","JY2-7"
* Tester: "SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ","SZ"
* Battery ID: "U1005_1","U1005_1","U1005_1","U1005_1","U1005_1","U1005_1","U1005_1","U1005_1","U1005_2","U1005_2","U1005_2","U1005_2","U1005_2","U1005_2","U1005_2","U1005_2","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3"
* Version = V00.9F.00
* Date = 2018.6.6
* Comment = 
*           
*****************************************************************************/

#include <linux/kernel.h>
#include "table.h" 

/*****************************************************************************
* Global variables section - Exported
* add declaration of global variables that will be exported here
* e.g.
*	int8_t foo;
****************************************************************************/
const char * table_version = "V00.9F.00-2018.6.6-U1005";

const char *battery_id[BATTERY_ID_NUM] = {"U1005_1","U1005_1","U1005_1","U1005_1","U1005_1","U1005_1","U1005_1","U1005_1","U1005_2","U1005_2","U1005_2","U1005_2","U1005_2","U1005_2","U1005_2","U1005_2","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3","U1005_3"};

one_latitude_data_t ocv_data[OCV_DATA_NUM] = {{3198, 0},{3353, 2},{3490, 3},{3496, 5},{3503, 6},{3512, 8},{3523, 9},{3542, 11},{3559, 13},{3576, 14},{3592, 16},{3607, 17},{3622, 19},{3640, 20},{3661, 22},{3683, 23},{3709, 25},{3734, 27},{3755, 28},{3768, 30},{3774, 31},{3775, 33},{3776, 34},{3776, 36},{3777, 38},{3777, 39},{3777, 41},{3777, 42},{3779, 44},{3781, 45},{3786, 47},{3791, 48},{3798, 50},{3807, 52},{3817, 53},{3828, 55},{3843, 56},{3859, 58},{3875, 59},{3890, 61},{3903, 63},{3916, 64},{3929, 66},{3943, 67},{3957, 69},{3971, 70},{3983, 72},{3992, 73},{4010, 75},{4031, 77},{4052, 78},{4067, 80},{4081, 81},{4099, 83},{4117, 84},{4135, 86},{4153, 88},{4172, 89},{4191, 91},{4210, 92},{4231, 94},{4252, 95},{4275, 97},{4303, 98},{4339, 100}};

//real current to soc 
one_latitude_data_t	charge_data[CHARGE_DATA_NUM] = {{80, 10000},{82, 9998},{84, 9996},{86, 9994},{88, 9991},{90, 9989},{92, 9986},{94, 9984},{96, 9982},{98, 9980},{100, 9978},{105, 9971},{110, 9966},{115, 9961},{120, 9955},{125, 9949},{130, 9943},{135, 9937},{140, 9932},{145, 9926},{150, 9921},{155, 9915},{160, 9910},{165, 9905},{170, 9899},{175, 9893},{180, 9888},{185, 9883},{190, 9877},{195, 9872},{200, 9866},{210, 9856},{220, 9845},{230, 9835},{240, 9824},{250, 9813},{260, 9802},{270, 9792},{280, 9781},{290, 9771},{300, 9760},{310, 9750},{320, 9739},{330, 9729},{340, 9718},{350, 9708},{360, 9697},{370, 9686},{380, 9676},{390, 9665},{400, 9655},{425, 9629},{450, 9603},{475, 9576},{500, 9550},{525, 9524},{550, 9499},{575, 9473},{600, 9448},{625, 9422},{650, 9397},{675, 9372},{700, 9348},{725, 9323},{800, 9260}};

//RC table X Axis value, in mV format
int32_t	XAxisElement[XAxis] = {3200, 3220, 3260, 3280, 3300, 3320, 3340, 3360, 3380, 3400, 3420, 3440, 3460, 3480, 3500, 3520, 3536, 3547, 3558, 3573, 3588, 3599, 3611, 3630, 3652, 3667, 3682, 3704, 3717, 3730, 3740, 3744, 3746, 3748, 3750, 3753, 3760, 3770, 3783, 3801, 3809, 3822, 3836, 3845, 3858, 3867, 3881, 3889, 3898, 3912, 3935, 3944, 3955, 3966, 3977, 3990, 4010, 4030, 4038, 4053, 4065, 4082, 4094, 4106, 4124, 4142, 4154, 4166, 4185, 4205, 4219, 4234, 4258, 4276, 4286, 4310, 4338};

//RC table Y Axis value, in mA format
int32_t	YAxisElement[YAxis] = {200, 500, 800, 1000, 1500, 2000, 3000};

// RC table Z Axis value, in 10*'C format
int32_t	ZAxisElement[ZAxis] = {-99, 0, 100, 200, 300, 400};

// contents of RC table, its unit is 10000C, 1C = DesignCapacity
int32_t	RCtable[YAxis*ZAxis][XAxis]={


//temp = -10.0 ^C 
{1373, 1433, 1571, 1652, 1737, 1834, 1943, 2064, 2197, 2337, 2491, 2657, 2836, 3026, 3231, 3449, 3639, 3777, 3924, 4134, 4361, 4531, 4728, 5041, 5391, 5611, 5821, 6114, 6272, 6433, 6553, 6605, 6625, 6647, 6671, 6707, 6791, 6913, 7062, 7273, 7365, 7501, 7641, 7733, 7840, 7917, 8036, 8103, 8176, 8291, 8499, 8585, 8690, 8795, 8901, 9016, 9198, 9369, 9431, 9545, 9631, 9743, 9811, 9868, 9932, 9970, 9986, 9995, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{3415, 3610, 4051, 4275, 4508, 4745, 4992, 5236, 5488, 5729, 5971, 6194, 6423, 6643, 6858, 7081, 7240, 7362, 7476, 7632, 7774, 7885, 8008, 8190, 8400, 8545, 8679, 8888, 9000, 9124, 9210, 9242, 9259, 9274, 9290, 9313, 9368, 9443, 9532, 9647, 9690, 9751, 9807, 9837, 9875, 9895, 9923, 9935, 9948, 9965, 9983, 9988, 9993, 9995, 9997, 9998, 9999, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{4550, 4774, 5253, 5492, 5725, 5961, 6185, 6401, 6622, 6833, 7041, 7240, 7435, 7631, 7823, 8007, 8166, 8263, 8363, 8505, 8648, 8745, 8854, 9040, 9220, 9345, 9452, 9590, 9658, 9716, 9758, 9771, 9780, 9787, 9793, 9802, 9824, 9852, 9883, 9918, 9929, 9949, 9964, 9972, 9981, 9986, 9993, 9994, 9997, 9997, 9998, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{5366, 5601, 6061, 6284, 6510, 6726, 6932, 7132, 7331, 7523, 7703, 7888, 8090, 8281, 8455, 8632, 8773, 8858, 8957, 9105, 9225, 9305, 9393, 9518, 9634, 9698, 9753, 9820, 9851, 9880, 9899, 9906, 9909, 9912, 9916, 9921, 9932, 9944, 9960, 9975, 9980, 9988, 9993, 9996, 9998, 9999, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{7320, 7510, 7934, 8110, 8296, 8520, 8741, 8943, 9137, 9320, 9461, 9574, 9664, 9736, 9790, 9840, 9873, 9889, 9909, 9927, 9944, 9957, 9969, 9980, 9990, 9993, 9994, 9997, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{8815, 9487, 9759, 9814, 9854, 9887, 9920, 9939, 9961, 9973, 9984, 9988, 9994, 9997, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{9882, 9909, 9953, 9969, 9974, 9989, 9991, 9994, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},

//temp = 0.0 ^C 
{910, 942, 1020, 1067, 1119, 1181, 1253, 1338, 1439, 1557, 1692, 1840, 2001, 2167, 2342, 2518, 2666, 2760, 2863, 3005, 3150, 3259, 3379, 3600, 3909, 4157, 4471, 5021, 5317, 5563, 5727, 5790, 5821, 5851, 5884, 5926, 6028, 6168, 6341, 6566, 6664, 6816, 6984, 7088, 7248, 7357, 7504, 7580, 7663, 7779, 7951, 8014, 8089, 8170, 8254, 8363, 8558, 8742, 8819, 8939, 9041, 9187, 9290, 9390, 9532, 9663, 9742, 9809, 9900, 9966, 9990, 9999, 10000, 10000, 10000, 10000, 10000},
{2039, 2109, 2274, 2366, 2472, 2591, 2719, 2863, 3023, 3191, 3381, 3579, 3799, 4032, 4276, 4544, 4773, 4931, 5097, 5331, 5561, 5734, 5913, 6185, 6473, 6659, 6833, 7080, 7220, 7360, 7460, 7503, 7524, 7540, 7568, 7593, 7663, 7765, 7894, 8057, 8127, 8233, 8344, 8412, 8508, 8573, 8675, 8730, 8795, 8889, 9017, 9055, 9097, 9136, 9170, 9212, 9277, 9348, 9378, 9433, 9481, 9554, 9608, 9665, 9751, 9840, 9893, 9940, 9987, 9999, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{2884, 3013, 3306, 3474, 3649, 3845, 4049, 4280, 4518, 4764, 5018, 5277, 5547, 5803, 6064, 6308, 6500, 6627, 6750, 6915, 7078, 7193, 7316, 7504, 7710, 7850, 7983, 8166, 8273, 8377, 8451, 8483, 8498, 8514, 8528, 8553, 8605, 8680, 8772, 8891, 8945, 9026, 9105, 9149, 9203, 9238, 9282, 9307, 9336, 9378, 9447, 9475, 9508, 9544, 9582, 9626, 9695, 9771, 9801, 9855, 9900, 9950, 9975, 9989, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{2918, 3081, 3448, 3654, 3893, 4083, 4324, 4582, 4832, 5093, 5362, 5615, 5871, 6123, 6358, 6597, 6765, 6885, 7004, 7166, 7322, 7438, 7559, 7746, 7955, 8101, 8240, 8447, 8570, 8681, 8770, 8806, 8821, 8837, 8861, 8887, 8956, 9049, 9163, 9318, 9382, 9487, 9584, 9644, 9720, 9766, 9825, 9855, 9883, 9918, 9956, 9970, 9980, 9989, 9993, 9997, 9998, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{4707, 4953, 5458, 5709, 5954, 6201, 6431, 6658, 6881, 7099, 7297, 7488, 7687, 7872, 8049, 8229, 8368, 8457, 8551, 8675, 8793, 8883, 8973, 9112, 9259, 9348, 9431, 9540, 9590, 9633, 9660, 9670, 9676, 9683, 9686, 9694, 9708, 9732, 9760, 9794, 9807, 9831, 9856, 9869, 9890, 9903, 9927, 9939, 9950, 9968, 9987, 9993, 9996, 9998, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{6138, 6356, 6812, 7023, 7219, 7407, 7590, 7776, 7961, 8143, 8322, 8485, 8649, 8817, 8974, 9120, 9234, 9301, 9374, 9465, 9541, 9593, 9641, 9712, 9772, 9808, 9843, 9881, 9898, 9916, 9929, 9934, 9937, 9940, 9943, 9945, 9953, 9959, 9974, 9983, 9989, 9994, 9996, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{8103, 8275, 8627, 8801, 8964, 9138, 9296, 9439, 9550, 9636, 9707, 9760, 9806, 9844, 9880, 9905, 9924, 9935, 9948, 9958, 9971, 9980, 9988, 9989, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},

//temp = 10.0 ^C 
{845, 869, 925, 960, 999, 1047, 1102, 1170, 1254, 1358, 1487, 1632, 1783, 1934, 2092, 2255, 2388, 2475, 2567, 2689, 2806, 2897, 2996, 3163, 3373, 3540, 3741, 4158, 4524, 4987, 5282, 5372, 5419, 5457, 5493, 5549, 5670, 5830, 6011, 6239, 6337, 6480, 6630, 6724, 6854, 6944, 7085, 7171, 7278, 7456, 7683, 7758, 7838, 7915, 7981, 8063, 8185, 8352, 8443, 8579, 8679, 8811, 8909, 9001, 9142, 9279, 9368, 9457, 9586, 9710, 9788, 9862, 9949, 9987, 9999, 10000, 10000},
{1367, 1414, 1529, 1600, 1675, 1771, 1870, 1979, 2104, 2240, 2379, 2531, 2683, 2849, 3019, 3191, 3345, 3454, 3574, 3740, 3925, 4074, 4261, 4578, 5018, 5324, 5592, 5937, 6112, 6283, 6403, 6451, 6479, 6500, 6523, 6559, 6638, 6751, 6896, 7089, 7171, 7313, 7475, 7572, 7707, 7792, 7907, 7968, 8033, 8122, 8262, 8325, 8396, 8488, 8591, 8701, 8866, 9016, 9078, 9191, 9277, 9396, 9475, 9552, 9663, 9755, 9811, 9855, 9911, 9961, 9984, 9996, 10000, 10000, 10000, 10000, 10000},
{1776, 1851, 2020, 2125, 2225, 2342, 2473, 2603, 2761, 2920, 3090, 3265, 3474, 3679, 3902, 4154, 4373, 4523, 4689, 4925, 5173, 5359, 5541, 5832, 6122, 6308, 6480, 6727, 6874, 7012, 7115, 7161, 7174, 7193, 7221, 7244, 7322, 7437, 7583, 7767, 7838, 7933, 8036, 8104, 8190, 8255, 8346, 8396, 8462, 8579, 8771, 8842, 8931, 9014, 9096, 9188, 9326, 9459, 9510, 9604, 9672, 9760, 9810, 9857, 9905, 9947, 9968, 9984, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{2036, 2123, 2328, 2445, 2562, 2697, 2850, 3002, 3178, 3355, 3557, 3767, 3988, 4249, 4510, 4802, 5030, 5198, 5366, 5590, 5792, 5942, 6095, 6329, 6576, 6748, 6908, 7140, 7263, 7409, 7502, 7549, 7569, 7577, 7607, 7639, 7704, 7789, 7908, 8048, 8103, 8194, 8292, 8359, 8447, 8509, 8616, 8692, 8770, 8876, 9058, 9112, 9198, 9276, 9344, 9438, 9558, 9664, 9712, 9783, 9836, 9894, 9926, 9940, 9976, 9996, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{2853, 2988, 3272, 3458, 3656, 3848, 4060, 4282, 4513, 4777, 5024, 5274, 5535, 5782, 6040, 6267, 6451, 6564, 6695, 6848, 6985, 7105, 7219, 7419, 7620, 7754, 7876, 8064, 8155, 8251, 8333, 8362, 8368, 8390, 8397, 8414, 8461, 8541, 8642, 8775, 8830, 8925, 9031, 9101, 9182, 9255, 9354, 9400, 9460, 9530, 9655, 9707, 9752, 9804, 9840, 9878, 9928, 9952, 9962, 9986, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{3837, 4007, 4443, 4642, 4878, 5108, 5333, 5585, 5814, 6046, 6262, 6483, 6688, 6871, 7088, 7259, 7420, 7502, 7610, 7739, 7869, 7961, 8046, 8206, 8350, 8471, 8570, 8744, 8829, 8913, 8994, 9018, 9042, 9053, 9078, 9083, 9137, 9196, 9288, 9407, 9459, 9536, 9613, 9667, 9709, 9772, 9821, 9846, 9871, 9913, 9947, 9960, 9973, 9980, 9988, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{5866, 6096, 6495, 6682, 6878, 7041, 7249, 7420, 7561, 7745, 7892, 8046, 8201, 8358, 8520, 8644, 8762, 8838, 8914, 9042, 9132, 9212, 9286, 9393, 9530, 9637, 9681, 9785, 9819, 9862, 9876, 9894, 9898, 9902, 9906, 9915, 9927, 9938, 9960, 9975, 9981, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},

//temp = 20.0 ^C 
{448, 467, 511, 535, 561, 590, 622, 659, 705, 769, 867, 1015, 1216, 1415, 1575, 1746, 1884, 1980, 2080, 2223, 2354, 2444, 2534, 2670, 2813, 2911, 3013, 3192, 3338, 3599, 4045, 4407, 4652, 4789, 4882, 4980, 5160, 5371, 5590, 5833, 5929, 6069, 6217, 6310, 6448, 6544, 6692, 6778, 6877, 7023, 7309, 7441, 7549, 7648, 7733, 7823, 7954, 8097, 8179, 8344, 8446, 8584, 8683, 8779, 8921, 9064, 9157, 9250, 9391, 9532, 9625, 9719, 9848, 9925, 9960, 10000, 10000},
{602, 626, 683, 719, 763, 818, 891, 988, 1110, 1264, 1429, 1586, 1748, 1914, 2092, 2269, 2405, 2496, 2585, 2698, 2809, 2890, 2982, 3140, 3372, 3603, 3975, 4931, 5247, 5491, 5653, 5713, 5746, 5773, 5805, 5845, 5943, 6075, 6237, 6441, 6527, 6663, 6809, 6900, 7031, 7122, 7289, 7397, 7499, 7625, 7799, 7857, 7925, 7997, 8073, 8190, 8389, 8555, 8617, 8737, 8830, 8963, 9057, 9149, 9286, 9419, 9503, 9585, 9703, 9814, 9881, 9936, 9991, 10000, 10000, 10000, 10000},
{790, 828, 930, 996, 1077, 1179, 1304, 1443, 1599, 1760, 1924, 2089, 2263, 2433, 2597, 2759, 2883, 2973, 3061, 3202, 3353, 3489, 3670, 4085, 4809, 5194, 5466, 5814, 5993, 6165, 6288, 6338, 6364, 6384, 6408, 6441, 6524, 6637, 6778, 6966, 7049, 7186, 7356, 7464, 7591, 7664, 7767, 7824, 7883, 7970, 8133, 8215, 8325, 8423, 8512, 8615, 8769, 8926, 8988, 9100, 9193, 9320, 9408, 9489, 9606, 9719, 9786, 9845, 9919, 9970, 9990, 10000, 10000, 10000, 10000, 10000, 10000},
{941, 993, 1133, 1226, 1332, 1459, 1601, 1761, 1926, 2094, 2262, 2430, 2593, 2757, 2922, 3092, 3241, 3350, 3481, 3691, 3964, 4221, 4573, 5087, 5498, 5731, 5941, 6233, 6389, 6536, 6652, 6695, 6718, 6739, 6764, 6793, 6869, 6977, 7117, 7321, 7418, 7554, 7677, 7743, 7834, 7895, 7982, 8034, 8099, 8216, 8431, 8504, 8588, 8675, 8761, 8862, 9013, 9166, 9226, 9333, 9418, 9533, 9611, 9686, 9783, 9871, 9915, 9945, 9982, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{1430, 1530, 1775, 1920, 2075, 2240, 2407, 2574, 2744, 2916, 3094, 3275, 3490, 3744, 4056, 4463, 4840, 5073, 5279, 5540, 5752, 5907, 6063, 6296, 6550, 6723, 6886, 7125, 7267, 7412, 7520, 7558, 7577, 7594, 7616, 7640, 7703, 7780, 7872, 7994, 8045, 8138, 8251, 8330, 8448, 8522, 8634, 8697, 8770, 8873, 9046, 9113, 9192, 9272, 9351, 9442, 9573, 9691, 9732, 9808, 9857, 9913, 9941, 9966, 9987, 9997, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{2075, 2219, 2534, 2702, 2872, 3050, 3239, 3445, 3678, 3940, 4257, 4613, 4994, 5351, 5657, 5930, 6133, 6263, 6391, 6564, 6724, 6849, 6980, 7177, 7414, 7569, 7702, 7871, 7964, 8054, 8119, 8151, 8167, 8182, 8198, 8217, 8276, 8368, 8477, 8623, 8688, 8785, 8894, 8963, 9061, 9122, 9225, 9279, 9344, 9435, 9583, 9636, 9693, 9750, 9801, 9853, 9913, 9950, 9964, 9983, 9989, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{3684, 3913, 4469, 4787, 5107, 5409, 5689, 5941, 6191, 6412, 6636, 6845, 7047, 7254, 7450, 7630, 7767, 7849, 7935, 8048, 8154, 8239, 8333, 8491, 8670, 8788, 8904, 9071, 9163, 9250, 9320, 9345, 9357, 9374, 9385, 9403, 9451, 9513, 9588, 9691, 9730, 9782, 9833, 9859, 9895, 9915, 9937, 9948, 9961, 9977, 9991, 9994, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},

//temp = 30.0 ^C 
{0, 20, 65, 91, 117, 147, 179, 215, 255, 304, 372, 482, 662, 894, 1083, 1258, 1404, 1501, 1605, 1754, 1900, 2001, 2102, 2249, 2404, 2503, 2597, 2748, 2853, 3009, 3265, 3505, 3714, 3963, 4301, 4512, 4751, 4999, 5248, 5508, 5607, 5750, 5901, 6000, 6145, 6247, 6405, 6495, 6600, 6756, 7006, 7104, 7258, 7399, 7500, 7603, 7748, 7905, 7995, 8152, 8254, 8399, 8500, 8602, 8752, 8902, 9000, 9098, 9247, 9399, 9500, 9603, 9752, 9850, 9899, 9991, 10000},
{221, 244, 294, 322, 354, 392, 437, 496, 583, 708, 882, 1077, 1254, 1421, 1599, 1783, 1937, 2038, 2140, 2265, 2381, 2465, 2549, 2681, 2842, 2978, 3167, 3909, 4720, 5052, 5248, 5324, 5362, 5393, 5430, 5476, 5584, 5729, 5898, 6108, 6196, 6336, 6487, 6581, 6720, 6814, 6961, 7041, 7138, 7316, 7560, 7631, 7714, 7788, 7867, 7967, 8180, 8347, 8413, 8535, 8635, 8772, 8870, 8966, 9108, 9248, 9338, 9426, 9559, 9689, 9772, 9851, 9952, 9994, 10000, 10000, 10000},
{338, 364, 429, 471, 523, 594, 686, 811, 970, 1150, 1327, 1488, 1664, 1850, 2037, 2217, 2352, 2437, 2522, 2633, 2745, 2830, 2934, 3143, 3579, 4249, 4851, 5312, 5529, 5726, 5863, 5916, 5946, 5972, 5997, 6034, 6120, 6242, 6394, 6587, 6673, 6805, 6949, 7041, 7173, 7283, 7451, 7525, 7600, 7704, 7864, 7928, 8022, 8140, 8240, 8345, 8510, 8671, 8734, 8853, 8947, 9080, 9172, 9265, 9396, 9522, 9606, 9683, 9792, 9890, 9944, 9981, 10000, 10000, 10000, 10000, 10000},
{423, 456, 544, 607, 687, 791, 922, 1079, 1254, 1423, 1596, 1776, 1962, 2146, 2320, 2480, 2605, 2685, 2771, 2899, 3039, 3168, 3353, 3866, 4772, 5116, 5386, 5731, 5913, 6081, 6205, 6256, 6279, 6303, 6329, 6361, 6442, 6557, 6696, 6883, 6966, 7098, 7256, 7363, 7502, 7581, 7686, 7741, 7803, 7899, 8104, 8190, 8281, 8371, 8461, 8564, 8723, 8881, 8946, 9059, 9150, 9277, 9368, 9452, 9574, 9693, 9763, 9829, 9914, 9970, 9993, 10000, 10000, 10000, 10000, 10000, 10000},
{693, 767, 963, 1091, 1237, 1405, 1587, 1770, 1953, 2137, 2309, 2477, 2637, 2799, 2976, 3191, 3417, 3624, 3917, 4437, 4873, 5109, 5324, 5621, 5932, 6124, 6312, 6567, 6707, 6847, 6954, 6996, 7021, 7040, 7062, 7092, 7166, 7285, 7429, 7599, 7660, 7753, 7850, 7908, 8015, 8102, 8224, 8291, 8370, 8475, 8657, 8728, 8813, 8895, 8982, 9081, 9229, 9374, 9432, 9530, 9612, 9715, 9784, 9843, 9913, 9963, 9982, 9996, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{1130, 1256, 1580, 1762, 1949, 2134, 2308, 2478, 2646, 2812, 2996, 3201, 3466, 3838, 4387, 4929, 5229, 5410, 5581, 5794, 5992, 6128, 6274, 6502, 6743, 6911, 7063, 7304, 7444, 7567, 7649, 7680, 7696, 7711, 7724, 7748, 7800, 7869, 7967, 8117, 8189, 8300, 8412, 8485, 8589, 8656, 8761, 8823, 8894, 8998, 9168, 9235, 9315, 9393, 9467, 9555, 9677, 9790, 9829, 9891, 9927, 9962, 9982, 9990, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{2496, 2674, 3037, 3252, 3487, 3787, 4181, 4637, 5053, 5389, 5678, 5933, 6180, 6415, 6641, 6857, 7022, 7133, 7249, 7399, 7541, 7638, 7728, 7873, 8043, 8169, 8294, 8477, 8582, 8683, 8753, 8784, 8801, 8815, 8830, 8855, 8909, 8987, 9077, 9203, 9266, 9355, 9453, 9504, 9590, 9642, 9726, 9762, 9807, 9860, 9920, 9940, 9954, 9972, 9984, 9990, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},

//temp = 40.0 ^C 
{62, 82, 128, 153, 180, 209, 241, 275, 313, 355, 408, 500, 667, 907, 1121, 1294, 1444, 1541, 1644, 1796, 1947, 2049, 2152, 2301, 2458, 2556, 2649, 2794, 2898, 3054, 3333, 3632, 3877, 4190, 4450, 4587, 4812, 5061, 5301, 5553, 5647, 5786, 5943, 6042, 6193, 6298, 6459, 6549, 6654, 6808, 7061, 7154, 7269, 7410, 7542, 7652, 7801, 7971, 8064, 8198, 8300, 8446, 8545, 8644, 8793, 8938, 9033, 9126, 9269, 9416, 9515, 9614, 9760, 9855, 9904, 9993, 10000},
{149, 172, 223, 251, 282, 315, 353, 400, 467, 578, 737, 945, 1147, 1318, 1496, 1681, 1840, 1941, 2045, 2178, 2296, 2379, 2464, 2595, 2747, 2868, 3034, 3703, 4596, 4961, 5173, 5249, 5285, 5322, 5358, 5403, 5515, 5662, 5826, 6035, 6126, 6270, 6426, 6525, 6664, 6760, 6910, 6993, 7085, 7230, 7498, 7586, 7674, 7754, 7835, 7942, 8139, 8311, 8377, 8500, 8600, 8738, 8833, 8927, 9069, 9208, 9299, 9386, 9518, 9652, 9736, 9818, 9932, 9988, 10000, 10000, 10000},
{221, 247, 306, 340, 381, 435, 510, 621, 771, 955, 1153, 1322, 1499, 1683, 1874, 2063, 2201, 2291, 2375, 2488, 2593, 2671, 2762, 2939, 3278, 3854, 4639, 5159, 5393, 5603, 5745, 5801, 5830, 5853, 5881, 5919, 6005, 6127, 6280, 6477, 6563, 6702, 6851, 6942, 7073, 7162, 7305, 7397, 7501, 7629, 7798, 7863, 7963, 8072, 8167, 8275, 8441, 8605, 8667, 8786, 8881, 9015, 9106, 9197, 9328, 9460, 9543, 9620, 9737, 9845, 9910, 9963, 10000, 10000, 10000, 10000, 10000},
{274, 303, 373, 421, 484, 571, 691, 844, 1026, 1212, 1386, 1561, 1751, 1940, 2126, 2293, 2418, 2497, 2580, 2690, 2807, 2913, 3051, 3421, 4439, 4891, 5195, 5565, 5755, 5932, 6063, 6111, 6135, 6161, 6188, 6220, 6305, 6418, 6565, 6753, 6835, 6970, 7112, 7198, 7336, 7438, 7579, 7645, 7714, 7811, 8012, 8094, 8186, 8277, 8370, 8474, 8634, 8792, 8854, 8970, 9063, 9191, 9280, 9366, 9494, 9616, 9693, 9762, 9862, 9943, 9982, 10000, 10000, 10000, 10000, 10000, 10000},
{490, 548, 712, 826, 957, 1120, 1299, 1484, 1665, 1851, 2030, 2202, 2369, 2522, 2680, 2851, 3016, 3156, 3344, 3731, 4320, 4682, 4964, 5312, 5656, 5862, 6060, 6330, 6479, 6632, 6741, 6782, 6809, 6823, 6851, 6877, 6954, 7059, 7189, 7380, 7466, 7586, 7694, 7760, 7857, 7931, 8054, 8130, 8206, 8319, 8502, 8572, 8653, 8741, 8824, 8919, 9070, 9217, 9272, 9381, 9464, 9575, 9652, 9725, 9823, 9907, 9947, 9977, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{796, 906, 1190, 1365, 1545, 1739, 1923, 2106, 2279, 2441, 2601, 2761, 2948, 3191, 3553, 4163, 4673, 4924, 5142, 5388, 5614, 5768, 5930, 6170, 6431, 6604, 6768, 6997, 7131, 7262, 7363, 7409, 7431, 7448, 7472, 7500, 7566, 7653, 7753, 7887, 7958, 8071, 8188, 8267, 8363, 8438, 8542, 8607, 8678, 8783, 8955, 9018, 9097, 9181, 9257, 9347, 9483, 9616, 9664, 9751, 9816, 9889, 9931, 9962, 9990, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
{1940, 2129, 2476, 2640, 2813, 3004, 3244, 3569, 4025, 4564, 5004, 5345, 5633, 5903, 6151, 6387, 6558, 6677, 6795, 6948, 7099, 7205, 7321, 7503, 7697, 7817, 7933, 8120, 8229, 8330, 8407, 8443, 8458, 8474, 8489, 8513, 8572, 8643, 8745, 8878, 8941, 9033, 9132, 9198, 9287, 9348, 9441, 9490, 9555, 9639, 9765, 9807, 9852, 9891, 9921, 9954, 9980, 9997, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000},
};