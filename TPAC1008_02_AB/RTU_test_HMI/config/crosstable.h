/*Created by MectConfigurator v2.x
INT       <-> int16_t
UINT      <-> u_int16_t
DINT      <-> int32_t
UDINT     <-> u_int32_t
REAL      <-> float
BIT       <-> int
BYTE_BIT  <-> int
WORD_BIT  <-> int
DWORD_BIT <-> int
*/
#ifndef CROSSTABLE_H
#define CROSSTABLE_H
#ifdef __cplusplus
extern "C" {
#endif
#include <sys/types.h>
#include "cross_table_utility.h"
 
#define ID_Addr_node01 193
extern u_int16_t Addr_node01;
int doWrite_Addr_node01(u_int16_t value);
int addWrite_Addr_node01(u_int16_t value);
int getStatus_Addr_node01();
 
#define ID_Life_node01 194
extern u_int16_t Life_node01;
int doWrite_Life_node01(u_int16_t value);
int addWrite_Life_node01(u_int16_t value);
int getStatus_Life_node01();
 
#define ID_AnInCnf_1_node01 195
extern u_int16_t AnInCnf_1_node01;
int doWrite_AnInCnf_1_node01(u_int16_t value);
int addWrite_AnInCnf_1_node01(u_int16_t value);
int getStatus_AnInCnf_1_node01();
 
#define ID_AnInCnf_2_node01 196
extern u_int16_t AnInCnf_2_node01;
int doWrite_AnInCnf_2_node01(u_int16_t value);
int addWrite_AnInCnf_2_node01(u_int16_t value);
int getStatus_AnInCnf_2_node01();
 
#define ID_ValAi1_node01 197
extern int16_t ValAi1_node01;
int doWrite_ValAi1_node01(int16_t value);
int addWrite_ValAi1_node01(int16_t value);
int getStatus_ValAi1_node01();
 
#define ID_ValAi2_node01 198
extern int16_t ValAi2_node01;
int doWrite_ValAi2_node01(int16_t value);
int addWrite_ValAi2_node01(int16_t value);
int getStatus_ValAi2_node01();
 
#define ID_DigDir_1_node01 199
extern int DigDir_1_node01;
int doWrite_DigDir_1_node01(int value);
int addWrite_DigDir_1_node01(int value);
int getStatus_DigDir_1_node01();
 
#define ID_DigDir_2_node01 200
extern int DigDir_2_node01;
int doWrite_DigDir_2_node01(int value);
int addWrite_DigDir_2_node01(int value);
int getStatus_DigDir_2_node01();
 
#define ID_DigDir_3_node01 201
extern int DigDir_3_node01;
int doWrite_DigDir_3_node01(int value);
int addWrite_DigDir_3_node01(int value);
int getStatus_DigDir_3_node01();
 
#define ID_DigDir_4_node01 202
extern int DigDir_4_node01;
int doWrite_DigDir_4_node01(int value);
int addWrite_DigDir_4_node01(int value);
int getStatus_DigDir_4_node01();
 
#define ID_DigDir_5_node01 203
extern int DigDir_5_node01;
int doWrite_DigDir_5_node01(int value);
int addWrite_DigDir_5_node01(int value);
int getStatus_DigDir_5_node01();
 
#define ID_DigDir_6_node01 204
extern int DigDir_6_node01;
int doWrite_DigDir_6_node01(int value);
int addWrite_DigDir_6_node01(int value);
int getStatus_DigDir_6_node01();
 
#define ID_DigDir_7_node01 205
extern int DigDir_7_node01;
int doWrite_DigDir_7_node01(int value);
int addWrite_DigDir_7_node01(int value);
int getStatus_DigDir_7_node01();
 
#define ID_DigDir_8_node01 206
extern int DigDir_8_node01;
int doWrite_DigDir_8_node01(int value);
int addWrite_DigDir_8_node01(int value);
int getStatus_DigDir_8_node01();
 
#define ID_DigIn_2_node01 207
extern int DigIn_2_node01;
int doWrite_DigIn_2_node01(int value);
int addWrite_DigIn_2_node01(int value);
int getStatus_DigIn_2_node01();
 
#define ID_DigIn_3_node01 208
extern int DigIn_3_node01;
int doWrite_DigIn_3_node01(int value);
int addWrite_DigIn_3_node01(int value);
int getStatus_DigIn_3_node01();
 
#define ID_DigIn_6_node01 209
extern int DigIn_6_node01;
int doWrite_DigIn_6_node01(int value);
int addWrite_DigIn_6_node01(int value);
int getStatus_DigIn_6_node01();
 
#define ID_DigIn_7_node01 210
extern int DigIn_7_node01;
int doWrite_DigIn_7_node01(int value);
int addWrite_DigIn_7_node01(int value);
int getStatus_DigIn_7_node01();
 
#define ID_DigOut_1_node01 211
extern int DigOut_1_node01;
int doWrite_DigOut_1_node01(int value);
int addWrite_DigOut_1_node01(int value);
int getStatus_DigOut_1_node01();
 
#define ID_DigOut_4_node01 212
extern int DigOut_4_node01;
int doWrite_DigOut_4_node01(int value);
int addWrite_DigOut_4_node01(int value);
int getStatus_DigOut_4_node01();
 
#define ID_DigOut_5_node01 213
extern int DigOut_5_node01;
int doWrite_DigOut_5_node01(int value);
int addWrite_DigOut_5_node01(int value);
int getStatus_DigOut_5_node01();
 
#define ID_DigOut_8_node01 214
extern int DigOut_8_node01;
int doWrite_DigOut_8_node01(int value);
int addWrite_DigOut_8_node01(int value);
int getStatus_DigOut_8_node01();
 
#define ID_errors_can 215
extern u_int32_t errors_can;
int doWrite_errors_can(u_int32_t value);
int addWrite_errors_can(u_int32_t value);
int getStatus_errors_can();
 
#define ID_Addr_node02 216
extern u_int16_t Addr_node02;
int doWrite_Addr_node02(u_int16_t value);
int addWrite_Addr_node02(u_int16_t value);
int getStatus_Addr_node02();
 
#define ID_Life_node02 217
extern u_int16_t Life_node02;
int doWrite_Life_node02(u_int16_t value);
int addWrite_Life_node02(u_int16_t value);
int getStatus_Life_node02();
 
#define ID_AnInCnf_1_node02 218
extern u_int16_t AnInCnf_1_node02;
int doWrite_AnInCnf_1_node02(u_int16_t value);
int addWrite_AnInCnf_1_node02(u_int16_t value);
int getStatus_AnInCnf_1_node02();
 
#define ID_AnInCnf_2_node02 219
extern u_int16_t AnInCnf_2_node02;
int doWrite_AnInCnf_2_node02(u_int16_t value);
int addWrite_AnInCnf_2_node02(u_int16_t value);
int getStatus_AnInCnf_2_node02();
 
#define ID_ValAi1_node02 220
extern int16_t ValAi1_node02;
int doWrite_ValAi1_node02(int16_t value);
int addWrite_ValAi1_node02(int16_t value);
int getStatus_ValAi1_node02();
 
#define ID_ValAi2_node02 221
extern int16_t ValAi2_node02;
int doWrite_ValAi2_node02(int16_t value);
int addWrite_ValAi2_node02(int16_t value);
int getStatus_ValAi2_node02();
 
#define ID_DigDir_1_node02 222
extern int DigDir_1_node02;
int doWrite_DigDir_1_node02(int value);
int addWrite_DigDir_1_node02(int value);
int getStatus_DigDir_1_node02();
 
#define ID_DigDir_2_node02 223
extern int DigDir_2_node02;
int doWrite_DigDir_2_node02(int value);
int addWrite_DigDir_2_node02(int value);
int getStatus_DigDir_2_node02();
 
#define ID_DigDir_3_node02 224
extern int DigDir_3_node02;
int doWrite_DigDir_3_node02(int value);
int addWrite_DigDir_3_node02(int value);
int getStatus_DigDir_3_node02();
 
#define ID_DigDir_4_node02 225
extern int DigDir_4_node02;
int doWrite_DigDir_4_node02(int value);
int addWrite_DigDir_4_node02(int value);
int getStatus_DigDir_4_node02();
 
#define ID_DigDir_5_node02 226
extern int DigDir_5_node02;
int doWrite_DigDir_5_node02(int value);
int addWrite_DigDir_5_node02(int value);
int getStatus_DigDir_5_node02();
 
#define ID_DigDir_6_node02 227
extern int DigDir_6_node02;
int doWrite_DigDir_6_node02(int value);
int addWrite_DigDir_6_node02(int value);
int getStatus_DigDir_6_node02();
 
#define ID_DigDir_7_node02 228
extern int DigDir_7_node02;
int doWrite_DigDir_7_node02(int value);
int addWrite_DigDir_7_node02(int value);
int getStatus_DigDir_7_node02();
 
#define ID_DigDir_8_node02 229
extern int DigDir_8_node02;
int doWrite_DigDir_8_node02(int value);
int addWrite_DigDir_8_node02(int value);
int getStatus_DigDir_8_node02();
 
#define ID_DigIn_2_node02 230
extern int DigIn_2_node02;
int doWrite_DigIn_2_node02(int value);
int addWrite_DigIn_2_node02(int value);
int getStatus_DigIn_2_node02();
 
#define ID_DigIn_3_node02 231
extern int DigIn_3_node02;
int doWrite_DigIn_3_node02(int value);
int addWrite_DigIn_3_node02(int value);
int getStatus_DigIn_3_node02();
 
#define ID_DigIn_6_node02 232
extern int DigIn_6_node02;
int doWrite_DigIn_6_node02(int value);
int addWrite_DigIn_6_node02(int value);
int getStatus_DigIn_6_node02();
 
#define ID_DigIn_7_node02 233
extern int DigIn_7_node02;
int doWrite_DigIn_7_node02(int value);
int addWrite_DigIn_7_node02(int value);
int getStatus_DigIn_7_node02();
 
#define ID_DigOut_1_node02 234
extern int DigOut_1_node02;
int doWrite_DigOut_1_node02(int value);
int addWrite_DigOut_1_node02(int value);
int getStatus_DigOut_1_node02();
 
#define ID_DigOut_4_node02 235
extern int DigOut_4_node02;
int doWrite_DigOut_4_node02(int value);
int addWrite_DigOut_4_node02(int value);
int getStatus_DigOut_4_node02();
 
#define ID_DigOut_5_node02 236
extern int DigOut_5_node02;
int doWrite_DigOut_5_node02(int value);
int addWrite_DigOut_5_node02(int value);
int getStatus_DigOut_5_node02();
 
#define ID_DigOut_8_node02 237
extern int DigOut_8_node02;
int doWrite_DigOut_8_node02(int value);
int addWrite_DigOut_8_node02(int value);
int getStatus_DigOut_8_node02();
 
#define ID_errors_01 238
extern u_int32_t errors_01;
int doWrite_errors_01(u_int32_t value);
int addWrite_errors_01(u_int32_t value);
int getStatus_errors_01();
 
#define ID_Addr_node03 239
extern u_int16_t Addr_node03;
int doWrite_Addr_node03(u_int16_t value);
int addWrite_Addr_node03(u_int16_t value);
int getStatus_Addr_node03();
 
#define ID_Life_node03 240
extern u_int16_t Life_node03;
int doWrite_Life_node03(u_int16_t value);
int addWrite_Life_node03(u_int16_t value);
int getStatus_Life_node03();
 
#define ID_AnInCnf_1_node03 241
extern u_int16_t AnInCnf_1_node03;
int doWrite_AnInCnf_1_node03(u_int16_t value);
int addWrite_AnInCnf_1_node03(u_int16_t value);
int getStatus_AnInCnf_1_node03();
 
#define ID_AnInCnf_2_node03 242
extern u_int16_t AnInCnf_2_node03;
int doWrite_AnInCnf_2_node03(u_int16_t value);
int addWrite_AnInCnf_2_node03(u_int16_t value);
int getStatus_AnInCnf_2_node03();
 
#define ID_ValAi1_node03 243
extern int16_t ValAi1_node03;
int doWrite_ValAi1_node03(int16_t value);
int addWrite_ValAi1_node03(int16_t value);
int getStatus_ValAi1_node03();
 
#define ID_ValAi2_node03 244
extern int16_t ValAi2_node03;
int doWrite_ValAi2_node03(int16_t value);
int addWrite_ValAi2_node03(int16_t value);
int getStatus_ValAi2_node03();
 
#define ID_DigDir_1_node03 245
extern int DigDir_1_node03;
int doWrite_DigDir_1_node03(int value);
int addWrite_DigDir_1_node03(int value);
int getStatus_DigDir_1_node03();
 
#define ID_DigDir_2_node03 246
extern int DigDir_2_node03;
int doWrite_DigDir_2_node03(int value);
int addWrite_DigDir_2_node03(int value);
int getStatus_DigDir_2_node03();
 
#define ID_DigDir_3_node03 247
extern int DigDir_3_node03;
int doWrite_DigDir_3_node03(int value);
int addWrite_DigDir_3_node03(int value);
int getStatus_DigDir_3_node03();
 
#define ID_DigDir_4_node03 248
extern int DigDir_4_node03;
int doWrite_DigDir_4_node03(int value);
int addWrite_DigDir_4_node03(int value);
int getStatus_DigDir_4_node03();
 
#define ID_DigDir_5_node03 249
extern int DigDir_5_node03;
int doWrite_DigDir_5_node03(int value);
int addWrite_DigDir_5_node03(int value);
int getStatus_DigDir_5_node03();
 
#define ID_DigDir_6_node03 250
extern int DigDir_6_node03;
int doWrite_DigDir_6_node03(int value);
int addWrite_DigDir_6_node03(int value);
int getStatus_DigDir_6_node03();
 
#define ID_DigDir_7_node03 251
extern int DigDir_7_node03;
int doWrite_DigDir_7_node03(int value);
int addWrite_DigDir_7_node03(int value);
int getStatus_DigDir_7_node03();
 
#define ID_DigDir_8_node03 252
extern int DigDir_8_node03;
int doWrite_DigDir_8_node03(int value);
int addWrite_DigDir_8_node03(int value);
int getStatus_DigDir_8_node03();
 
#define ID_DigIn_2_node03 253
extern int DigIn_2_node03;
int doWrite_DigIn_2_node03(int value);
int addWrite_DigIn_2_node03(int value);
int getStatus_DigIn_2_node03();
 
#define ID_DigIn_3_node03 254
extern int DigIn_3_node03;
int doWrite_DigIn_3_node03(int value);
int addWrite_DigIn_3_node03(int value);
int getStatus_DigIn_3_node03();
 
#define ID_DigIn_6_node03 255
extern int DigIn_6_node03;
int doWrite_DigIn_6_node03(int value);
int addWrite_DigIn_6_node03(int value);
int getStatus_DigIn_6_node03();
 
#define ID_DigIn_7_node03 256
extern int DigIn_7_node03;
int doWrite_DigIn_7_node03(int value);
int addWrite_DigIn_7_node03(int value);
int getStatus_DigIn_7_node03();
 
#define ID_DigOut_1_node03 257
extern int DigOut_1_node03;
int doWrite_DigOut_1_node03(int value);
int addWrite_DigOut_1_node03(int value);
int getStatus_DigOut_1_node03();
 
#define ID_DigOut_4_node03 258
extern int DigOut_4_node03;
int doWrite_DigOut_4_node03(int value);
int addWrite_DigOut_4_node03(int value);
int getStatus_DigOut_4_node03();
 
#define ID_DigOut_5_node03 259
extern int DigOut_5_node03;
int doWrite_DigOut_5_node03(int value);
int addWrite_DigOut_5_node03(int value);
int getStatus_DigOut_5_node03();
 
#define ID_DigOut_8_node03 260
extern int DigOut_8_node03;
int doWrite_DigOut_8_node03(int value);
int addWrite_DigOut_8_node03(int value);
int getStatus_DigOut_8_node03();
 
#define ID_errors_02 261
extern u_int32_t errors_02;
int doWrite_errors_02(u_int32_t value);
int addWrite_errors_02(u_int32_t value);
int getStatus_errors_02();
 
#define ID_Addr_node04 262
extern u_int16_t Addr_node04;
int doWrite_Addr_node04(u_int16_t value);
int addWrite_Addr_node04(u_int16_t value);
int getStatus_Addr_node04();
 
#define ID_Life_node04 263
extern u_int16_t Life_node04;
int doWrite_Life_node04(u_int16_t value);
int addWrite_Life_node04(u_int16_t value);
int getStatus_Life_node04();
 
#define ID_AnInCnf_1_node04 264
extern u_int16_t AnInCnf_1_node04;
int doWrite_AnInCnf_1_node04(u_int16_t value);
int addWrite_AnInCnf_1_node04(u_int16_t value);
int getStatus_AnInCnf_1_node04();
 
#define ID_AnInCnf_2_node04 265
extern u_int16_t AnInCnf_2_node04;
int doWrite_AnInCnf_2_node04(u_int16_t value);
int addWrite_AnInCnf_2_node04(u_int16_t value);
int getStatus_AnInCnf_2_node04();
 
#define ID_ValAi1_node04 266
extern int16_t ValAi1_node04;
int doWrite_ValAi1_node04(int16_t value);
int addWrite_ValAi1_node04(int16_t value);
int getStatus_ValAi1_node04();
 
#define ID_ValAi2_node04 267
extern int16_t ValAi2_node04;
int doWrite_ValAi2_node04(int16_t value);
int addWrite_ValAi2_node04(int16_t value);
int getStatus_ValAi2_node04();
 
#define ID_DigDir_1_node04 268
extern int DigDir_1_node04;
int doWrite_DigDir_1_node04(int value);
int addWrite_DigDir_1_node04(int value);
int getStatus_DigDir_1_node04();
 
#define ID_DigDir_2_node04 269
extern int DigDir_2_node04;
int doWrite_DigDir_2_node04(int value);
int addWrite_DigDir_2_node04(int value);
int getStatus_DigDir_2_node04();
 
#define ID_DigDir_3_node04 270
extern int DigDir_3_node04;
int doWrite_DigDir_3_node04(int value);
int addWrite_DigDir_3_node04(int value);
int getStatus_DigDir_3_node04();
 
#define ID_DigDir_4_node04 271
extern int DigDir_4_node04;
int doWrite_DigDir_4_node04(int value);
int addWrite_DigDir_4_node04(int value);
int getStatus_DigDir_4_node04();
 
#define ID_DigDir_5_node04 272
extern int DigDir_5_node04;
int doWrite_DigDir_5_node04(int value);
int addWrite_DigDir_5_node04(int value);
int getStatus_DigDir_5_node04();
 
#define ID_DigDir_6_node04 273
extern int DigDir_6_node04;
int doWrite_DigDir_6_node04(int value);
int addWrite_DigDir_6_node04(int value);
int getStatus_DigDir_6_node04();
 
#define ID_DigDir_7_node04 274
extern int DigDir_7_node04;
int doWrite_DigDir_7_node04(int value);
int addWrite_DigDir_7_node04(int value);
int getStatus_DigDir_7_node04();
 
#define ID_DigDir_8_node04 275
extern int DigDir_8_node04;
int doWrite_DigDir_8_node04(int value);
int addWrite_DigDir_8_node04(int value);
int getStatus_DigDir_8_node04();
 
#define ID_DigIn_2_node04 276
extern int DigIn_2_node04;
int doWrite_DigIn_2_node04(int value);
int addWrite_DigIn_2_node04(int value);
int getStatus_DigIn_2_node04();
 
#define ID_DigIn_3_node04 277
extern int DigIn_3_node04;
int doWrite_DigIn_3_node04(int value);
int addWrite_DigIn_3_node04(int value);
int getStatus_DigIn_3_node04();
 
#define ID_DigIn_6_node04 278
extern int DigIn_6_node04;
int doWrite_DigIn_6_node04(int value);
int addWrite_DigIn_6_node04(int value);
int getStatus_DigIn_6_node04();
 
#define ID_DigIn_7_node04 279
extern int DigIn_7_node04;
int doWrite_DigIn_7_node04(int value);
int addWrite_DigIn_7_node04(int value);
int getStatus_DigIn_7_node04();
 
#define ID_DigOut_1_node04 280
extern int DigOut_1_node04;
int doWrite_DigOut_1_node04(int value);
int addWrite_DigOut_1_node04(int value);
int getStatus_DigOut_1_node04();
 
#define ID_DigOut_4_node04 281
extern int DigOut_4_node04;
int doWrite_DigOut_4_node04(int value);
int addWrite_DigOut_4_node04(int value);
int getStatus_DigOut_4_node04();
 
#define ID_DigOut_5_node04 282
extern int DigOut_5_node04;
int doWrite_DigOut_5_node04(int value);
int addWrite_DigOut_5_node04(int value);
int getStatus_DigOut_5_node04();
 
#define ID_DigOut_8_node04 283
extern int DigOut_8_node04;
int doWrite_DigOut_8_node04(int value);
int addWrite_DigOut_8_node04(int value);
int getStatus_DigOut_8_node04();
 
#define ID_errors_03 284
extern u_int32_t errors_03;
int doWrite_errors_03(u_int32_t value);
int addWrite_errors_03(u_int32_t value);
int getStatus_errors_03();
 
#define ID_Addr_node05 285
extern u_int16_t Addr_node05;
int doWrite_Addr_node05(u_int16_t value);
int addWrite_Addr_node05(u_int16_t value);
int getStatus_Addr_node05();
 
#define ID_Life_node05 286
extern u_int16_t Life_node05;
int doWrite_Life_node05(u_int16_t value);
int addWrite_Life_node05(u_int16_t value);
int getStatus_Life_node05();
 
#define ID_AnInCnf_1_node05 287
extern u_int16_t AnInCnf_1_node05;
int doWrite_AnInCnf_1_node05(u_int16_t value);
int addWrite_AnInCnf_1_node05(u_int16_t value);
int getStatus_AnInCnf_1_node05();
 
#define ID_AnInCnf_2_node05 288
extern u_int16_t AnInCnf_2_node05;
int doWrite_AnInCnf_2_node05(u_int16_t value);
int addWrite_AnInCnf_2_node05(u_int16_t value);
int getStatus_AnInCnf_2_node05();
 
#define ID_ValAi1_node05 289
extern int16_t ValAi1_node05;
int doWrite_ValAi1_node05(int16_t value);
int addWrite_ValAi1_node05(int16_t value);
int getStatus_ValAi1_node05();
 
#define ID_ValAi2_node05 290
extern int16_t ValAi2_node05;
int doWrite_ValAi2_node05(int16_t value);
int addWrite_ValAi2_node05(int16_t value);
int getStatus_ValAi2_node05();
 
#define ID_DigDir_1_node05 291
extern int DigDir_1_node05;
int doWrite_DigDir_1_node05(int value);
int addWrite_DigDir_1_node05(int value);
int getStatus_DigDir_1_node05();
 
#define ID_DigDir_2_node05 292
extern int DigDir_2_node05;
int doWrite_DigDir_2_node05(int value);
int addWrite_DigDir_2_node05(int value);
int getStatus_DigDir_2_node05();
 
#define ID_DigDir_3_node05 293
extern int DigDir_3_node05;
int doWrite_DigDir_3_node05(int value);
int addWrite_DigDir_3_node05(int value);
int getStatus_DigDir_3_node05();
 
#define ID_DigDir_4_node05 294
extern int DigDir_4_node05;
int doWrite_DigDir_4_node05(int value);
int addWrite_DigDir_4_node05(int value);
int getStatus_DigDir_4_node05();
 
#define ID_DigDir_5_node05 295
extern int DigDir_5_node05;
int doWrite_DigDir_5_node05(int value);
int addWrite_DigDir_5_node05(int value);
int getStatus_DigDir_5_node05();
 
#define ID_DigDir_6_node05 296
extern int DigDir_6_node05;
int doWrite_DigDir_6_node05(int value);
int addWrite_DigDir_6_node05(int value);
int getStatus_DigDir_6_node05();
 
#define ID_DigDir_7_node05 297
extern int DigDir_7_node05;
int doWrite_DigDir_7_node05(int value);
int addWrite_DigDir_7_node05(int value);
int getStatus_DigDir_7_node05();
 
#define ID_DigDir_8_node05 298
extern int DigDir_8_node05;
int doWrite_DigDir_8_node05(int value);
int addWrite_DigDir_8_node05(int value);
int getStatus_DigDir_8_node05();
 
#define ID_DigIn_2_node05 299
extern int DigIn_2_node05;
int doWrite_DigIn_2_node05(int value);
int addWrite_DigIn_2_node05(int value);
int getStatus_DigIn_2_node05();
 
#define ID_DigIn_3_node05 300
extern int DigIn_3_node05;
int doWrite_DigIn_3_node05(int value);
int addWrite_DigIn_3_node05(int value);
int getStatus_DigIn_3_node05();
 
#define ID_DigIn_6_node05 301
extern int DigIn_6_node05;
int doWrite_DigIn_6_node05(int value);
int addWrite_DigIn_6_node05(int value);
int getStatus_DigIn_6_node05();
 
#define ID_DigIn_7_node05 302
extern int DigIn_7_node05;
int doWrite_DigIn_7_node05(int value);
int addWrite_DigIn_7_node05(int value);
int getStatus_DigIn_7_node05();
 
#define ID_DigOut_1_node05 303
extern int DigOut_1_node05;
int doWrite_DigOut_1_node05(int value);
int addWrite_DigOut_1_node05(int value);
int getStatus_DigOut_1_node05();
 
#define ID_DigOut_4_node05 304
extern int DigOut_4_node05;
int doWrite_DigOut_4_node05(int value);
int addWrite_DigOut_4_node05(int value);
int getStatus_DigOut_4_node05();
 
#define ID_DigOut_5_node05 305
extern int DigOut_5_node05;
int doWrite_DigOut_5_node05(int value);
int addWrite_DigOut_5_node05(int value);
int getStatus_DigOut_5_node05();
 
#define ID_DigOut_8_node05 306
extern int DigOut_8_node05;
int doWrite_DigOut_8_node05(int value);
int addWrite_DigOut_8_node05(int value);
int getStatus_DigOut_8_node05();
 
#define ID_errors_04 307
extern u_int32_t errors_04;
int doWrite_errors_04(u_int32_t value);
int addWrite_errors_04(u_int32_t value);
int getStatus_errors_04();
 
#define ID_Addr_node06 308
extern u_int16_t Addr_node06;
int doWrite_Addr_node06(u_int16_t value);
int addWrite_Addr_node06(u_int16_t value);
int getStatus_Addr_node06();
 
#define ID_Life_node06 309
extern u_int16_t Life_node06;
int doWrite_Life_node06(u_int16_t value);
int addWrite_Life_node06(u_int16_t value);
int getStatus_Life_node06();
 
#define ID_AnInCnf_1_node06 310
extern u_int16_t AnInCnf_1_node06;
int doWrite_AnInCnf_1_node06(u_int16_t value);
int addWrite_AnInCnf_1_node06(u_int16_t value);
int getStatus_AnInCnf_1_node06();
 
#define ID_AnInCnf_2_node06 311
extern u_int16_t AnInCnf_2_node06;
int doWrite_AnInCnf_2_node06(u_int16_t value);
int addWrite_AnInCnf_2_node06(u_int16_t value);
int getStatus_AnInCnf_2_node06();
 
#define ID_ValAi1_node06 312
extern int16_t ValAi1_node06;
int doWrite_ValAi1_node06(int16_t value);
int addWrite_ValAi1_node06(int16_t value);
int getStatus_ValAi1_node06();
 
#define ID_ValAi2_node06 313
extern int16_t ValAi2_node06;
int doWrite_ValAi2_node06(int16_t value);
int addWrite_ValAi2_node06(int16_t value);
int getStatus_ValAi2_node06();
 
#define ID_DigDir_1_node06 314
extern int DigDir_1_node06;
int doWrite_DigDir_1_node06(int value);
int addWrite_DigDir_1_node06(int value);
int getStatus_DigDir_1_node06();
 
#define ID_DigDir_2_node06 315
extern int DigDir_2_node06;
int doWrite_DigDir_2_node06(int value);
int addWrite_DigDir_2_node06(int value);
int getStatus_DigDir_2_node06();
 
#define ID_DigDir_3_node06 316
extern int DigDir_3_node06;
int doWrite_DigDir_3_node06(int value);
int addWrite_DigDir_3_node06(int value);
int getStatus_DigDir_3_node06();
 
#define ID_DigDir_4_node06 317
extern int DigDir_4_node06;
int doWrite_DigDir_4_node06(int value);
int addWrite_DigDir_4_node06(int value);
int getStatus_DigDir_4_node06();
 
#define ID_DigDir_5_node06 318
extern int DigDir_5_node06;
int doWrite_DigDir_5_node06(int value);
int addWrite_DigDir_5_node06(int value);
int getStatus_DigDir_5_node06();
 
#define ID_DigDir_6_node06 319
extern int DigDir_6_node06;
int doWrite_DigDir_6_node06(int value);
int addWrite_DigDir_6_node06(int value);
int getStatus_DigDir_6_node06();
 
#define ID_DigDir_7_node06 320
extern int DigDir_7_node06;
int doWrite_DigDir_7_node06(int value);
int addWrite_DigDir_7_node06(int value);
int getStatus_DigDir_7_node06();
 
#define ID_DigDir_8_node06 321
extern int DigDir_8_node06;
int doWrite_DigDir_8_node06(int value);
int addWrite_DigDir_8_node06(int value);
int getStatus_DigDir_8_node06();
 
#define ID_DigIn_2_node06 322
extern int DigIn_2_node06;
int doWrite_DigIn_2_node06(int value);
int addWrite_DigIn_2_node06(int value);
int getStatus_DigIn_2_node06();
 
#define ID_DigIn_3_node06 323
extern int DigIn_3_node06;
int doWrite_DigIn_3_node06(int value);
int addWrite_DigIn_3_node06(int value);
int getStatus_DigIn_3_node06();
 
#define ID_DigIn_6_node06 324
extern int DigIn_6_node06;
int doWrite_DigIn_6_node06(int value);
int addWrite_DigIn_6_node06(int value);
int getStatus_DigIn_6_node06();
 
#define ID_DigIn_7_node06 325
extern int DigIn_7_node06;
int doWrite_DigIn_7_node06(int value);
int addWrite_DigIn_7_node06(int value);
int getStatus_DigIn_7_node06();
 
#define ID_DigOut_1_node06 326
extern int DigOut_1_node06;
int doWrite_DigOut_1_node06(int value);
int addWrite_DigOut_1_node06(int value);
int getStatus_DigOut_1_node06();
 
#define ID_DigOut_4_node06 327
extern int DigOut_4_node06;
int doWrite_DigOut_4_node06(int value);
int addWrite_DigOut_4_node06(int value);
int getStatus_DigOut_4_node06();
 
#define ID_DigOut_5_node06 328
extern int DigOut_5_node06;
int doWrite_DigOut_5_node06(int value);
int addWrite_DigOut_5_node06(int value);
int getStatus_DigOut_5_node06();
 
#define ID_DigOut_8_node06 329
extern int DigOut_8_node06;
int doWrite_DigOut_8_node06(int value);
int addWrite_DigOut_8_node06(int value);
int getStatus_DigOut_8_node06();
 
#define ID_errors_05 330
extern u_int32_t errors_05;
int doWrite_errors_05(u_int32_t value);
int addWrite_errors_05(u_int32_t value);
int getStatus_errors_05();
 
#define ID_Addr_node07 331
extern u_int16_t Addr_node07;
int doWrite_Addr_node07(u_int16_t value);
int addWrite_Addr_node07(u_int16_t value);
int getStatus_Addr_node07();
 
#define ID_Life_node07 332
extern u_int16_t Life_node07;
int doWrite_Life_node07(u_int16_t value);
int addWrite_Life_node07(u_int16_t value);
int getStatus_Life_node07();
 
#define ID_AnInCnf_1_node07 333
extern u_int16_t AnInCnf_1_node07;
int doWrite_AnInCnf_1_node07(u_int16_t value);
int addWrite_AnInCnf_1_node07(u_int16_t value);
int getStatus_AnInCnf_1_node07();
 
#define ID_AnInCnf_2_node07 334
extern u_int16_t AnInCnf_2_node07;
int doWrite_AnInCnf_2_node07(u_int16_t value);
int addWrite_AnInCnf_2_node07(u_int16_t value);
int getStatus_AnInCnf_2_node07();
 
#define ID_ValAi1_node07 335
extern int16_t ValAi1_node07;
int doWrite_ValAi1_node07(int16_t value);
int addWrite_ValAi1_node07(int16_t value);
int getStatus_ValAi1_node07();
 
#define ID_ValAi2_node07 336
extern int16_t ValAi2_node07;
int doWrite_ValAi2_node07(int16_t value);
int addWrite_ValAi2_node07(int16_t value);
int getStatus_ValAi2_node07();
 
#define ID_DigDir_1_node07 337
extern int DigDir_1_node07;
int doWrite_DigDir_1_node07(int value);
int addWrite_DigDir_1_node07(int value);
int getStatus_DigDir_1_node07();
 
#define ID_DigDir_2_node07 338
extern int DigDir_2_node07;
int doWrite_DigDir_2_node07(int value);
int addWrite_DigDir_2_node07(int value);
int getStatus_DigDir_2_node07();
 
#define ID_DigDir_3_node07 339
extern int DigDir_3_node07;
int doWrite_DigDir_3_node07(int value);
int addWrite_DigDir_3_node07(int value);
int getStatus_DigDir_3_node07();
 
#define ID_DigDir_4_node07 340
extern int DigDir_4_node07;
int doWrite_DigDir_4_node07(int value);
int addWrite_DigDir_4_node07(int value);
int getStatus_DigDir_4_node07();
 
#define ID_DigDir_5_node07 341
extern int DigDir_5_node07;
int doWrite_DigDir_5_node07(int value);
int addWrite_DigDir_5_node07(int value);
int getStatus_DigDir_5_node07();
 
#define ID_DigDir_6_node07 342
extern int DigDir_6_node07;
int doWrite_DigDir_6_node07(int value);
int addWrite_DigDir_6_node07(int value);
int getStatus_DigDir_6_node07();
 
#define ID_DigDir_7_node07 343
extern int DigDir_7_node07;
int doWrite_DigDir_7_node07(int value);
int addWrite_DigDir_7_node07(int value);
int getStatus_DigDir_7_node07();
 
#define ID_DigDir_8_node07 344
extern int DigDir_8_node07;
int doWrite_DigDir_8_node07(int value);
int addWrite_DigDir_8_node07(int value);
int getStatus_DigDir_8_node07();
 
#define ID_DigIn_2_node07 345
extern int DigIn_2_node07;
int doWrite_DigIn_2_node07(int value);
int addWrite_DigIn_2_node07(int value);
int getStatus_DigIn_2_node07();
 
#define ID_DigIn_3_node07 346
extern int DigIn_3_node07;
int doWrite_DigIn_3_node07(int value);
int addWrite_DigIn_3_node07(int value);
int getStatus_DigIn_3_node07();
 
#define ID_DigIn_6_node07 347
extern int DigIn_6_node07;
int doWrite_DigIn_6_node07(int value);
int addWrite_DigIn_6_node07(int value);
int getStatus_DigIn_6_node07();
 
#define ID_DigIn_7_node07 348
extern int DigIn_7_node07;
int doWrite_DigIn_7_node07(int value);
int addWrite_DigIn_7_node07(int value);
int getStatus_DigIn_7_node07();
 
#define ID_DigOut_1_node07 349
extern int DigOut_1_node07;
int doWrite_DigOut_1_node07(int value);
int addWrite_DigOut_1_node07(int value);
int getStatus_DigOut_1_node07();
 
#define ID_DigOut_4_node07 350
extern int DigOut_4_node07;
int doWrite_DigOut_4_node07(int value);
int addWrite_DigOut_4_node07(int value);
int getStatus_DigOut_4_node07();
 
#define ID_DigOut_5_node07 351
extern int DigOut_5_node07;
int doWrite_DigOut_5_node07(int value);
int addWrite_DigOut_5_node07(int value);
int getStatus_DigOut_5_node07();
 
#define ID_DigOut_8_node07 352
extern int DigOut_8_node07;
int doWrite_DigOut_8_node07(int value);
int addWrite_DigOut_8_node07(int value);
int getStatus_DigOut_8_node07();
 
#define ID_errors_06 353
extern u_int32_t errors_06;
int doWrite_errors_06(u_int32_t value);
int addWrite_errors_06(u_int32_t value);
int getStatus_errors_06();
 
#define ID_Addr_node08 354
extern u_int16_t Addr_node08;
int doWrite_Addr_node08(u_int16_t value);
int addWrite_Addr_node08(u_int16_t value);
int getStatus_Addr_node08();
 
#define ID_Life_node08 355
extern u_int16_t Life_node08;
int doWrite_Life_node08(u_int16_t value);
int addWrite_Life_node08(u_int16_t value);
int getStatus_Life_node08();
 
#define ID_AnInCnf_1_node08 356
extern u_int16_t AnInCnf_1_node08;
int doWrite_AnInCnf_1_node08(u_int16_t value);
int addWrite_AnInCnf_1_node08(u_int16_t value);
int getStatus_AnInCnf_1_node08();
 
#define ID_AnInCnf_2_node08 357
extern u_int16_t AnInCnf_2_node08;
int doWrite_AnInCnf_2_node08(u_int16_t value);
int addWrite_AnInCnf_2_node08(u_int16_t value);
int getStatus_AnInCnf_2_node08();
 
#define ID_ValAi1_node08 358
extern int16_t ValAi1_node08;
int doWrite_ValAi1_node08(int16_t value);
int addWrite_ValAi1_node08(int16_t value);
int getStatus_ValAi1_node08();
 
#define ID_ValAi2_node08 359
extern int16_t ValAi2_node08;
int doWrite_ValAi2_node08(int16_t value);
int addWrite_ValAi2_node08(int16_t value);
int getStatus_ValAi2_node08();
 
#define ID_DigDir_1_node08 360
extern int DigDir_1_node08;
int doWrite_DigDir_1_node08(int value);
int addWrite_DigDir_1_node08(int value);
int getStatus_DigDir_1_node08();
 
#define ID_DigDir_2_node08 361
extern int DigDir_2_node08;
int doWrite_DigDir_2_node08(int value);
int addWrite_DigDir_2_node08(int value);
int getStatus_DigDir_2_node08();
 
#define ID_DigDir_3_node08 362
extern int DigDir_3_node08;
int doWrite_DigDir_3_node08(int value);
int addWrite_DigDir_3_node08(int value);
int getStatus_DigDir_3_node08();
 
#define ID_DigDir_4_node08 363
extern int DigDir_4_node08;
int doWrite_DigDir_4_node08(int value);
int addWrite_DigDir_4_node08(int value);
int getStatus_DigDir_4_node08();
 
#define ID_DigDir_5_node08 364
extern int DigDir_5_node08;
int doWrite_DigDir_5_node08(int value);
int addWrite_DigDir_5_node08(int value);
int getStatus_DigDir_5_node08();
 
#define ID_DigDir_6_node08 365
extern int DigDir_6_node08;
int doWrite_DigDir_6_node08(int value);
int addWrite_DigDir_6_node08(int value);
int getStatus_DigDir_6_node08();
 
#define ID_DigDir_7_node08 366
extern int DigDir_7_node08;
int doWrite_DigDir_7_node08(int value);
int addWrite_DigDir_7_node08(int value);
int getStatus_DigDir_7_node08();
 
#define ID_DigDir_8_node08 367
extern int DigDir_8_node08;
int doWrite_DigDir_8_node08(int value);
int addWrite_DigDir_8_node08(int value);
int getStatus_DigDir_8_node08();
 
#define ID_DigIn_2_node08 368
extern int DigIn_2_node08;
int doWrite_DigIn_2_node08(int value);
int addWrite_DigIn_2_node08(int value);
int getStatus_DigIn_2_node08();
 
#define ID_DigIn_3_node08 369
extern int DigIn_3_node08;
int doWrite_DigIn_3_node08(int value);
int addWrite_DigIn_3_node08(int value);
int getStatus_DigIn_3_node08();
 
#define ID_DigIn_6_node08 370
extern int DigIn_6_node08;
int doWrite_DigIn_6_node08(int value);
int addWrite_DigIn_6_node08(int value);
int getStatus_DigIn_6_node08();
 
#define ID_DigIn_7_node08 371
extern int DigIn_7_node08;
int doWrite_DigIn_7_node08(int value);
int addWrite_DigIn_7_node08(int value);
int getStatus_DigIn_7_node08();
 
#define ID_DigOut_1_node08 372
extern int DigOut_1_node08;
int doWrite_DigOut_1_node08(int value);
int addWrite_DigOut_1_node08(int value);
int getStatus_DigOut_1_node08();
 
#define ID_DigOut_4_node08 373
extern int DigOut_4_node08;
int doWrite_DigOut_4_node08(int value);
int addWrite_DigOut_4_node08(int value);
int getStatus_DigOut_4_node08();
 
#define ID_DigOut_5_node08 374
extern int DigOut_5_node08;
int doWrite_DigOut_5_node08(int value);
int addWrite_DigOut_5_node08(int value);
int getStatus_DigOut_5_node08();
 
#define ID_DigOut_8_node08 375
extern int DigOut_8_node08;
int doWrite_DigOut_8_node08(int value);
int addWrite_DigOut_8_node08(int value);
int getStatus_DigOut_8_node08();
 
#define ID_errors_07 376
extern u_int32_t errors_07;
int doWrite_errors_07(u_int32_t value);
int addWrite_errors_07(u_int32_t value);
int getStatus_errors_07();
 
#define ID_Addr_node09 377
extern u_int16_t Addr_node09;
int doWrite_Addr_node09(u_int16_t value);
int addWrite_Addr_node09(u_int16_t value);
int getStatus_Addr_node09();
 
#define ID_Life_node09 378
extern u_int16_t Life_node09;
int doWrite_Life_node09(u_int16_t value);
int addWrite_Life_node09(u_int16_t value);
int getStatus_Life_node09();
 
#define ID_AnInCnf_1_node09 379
extern u_int16_t AnInCnf_1_node09;
int doWrite_AnInCnf_1_node09(u_int16_t value);
int addWrite_AnInCnf_1_node09(u_int16_t value);
int getStatus_AnInCnf_1_node09();
 
#define ID_AnInCnf_2_node09 380
extern u_int16_t AnInCnf_2_node09;
int doWrite_AnInCnf_2_node09(u_int16_t value);
int addWrite_AnInCnf_2_node09(u_int16_t value);
int getStatus_AnInCnf_2_node09();
 
#define ID_ValAi1_node09 381
extern int16_t ValAi1_node09;
int doWrite_ValAi1_node09(int16_t value);
int addWrite_ValAi1_node09(int16_t value);
int getStatus_ValAi1_node09();
 
#define ID_ValAi2_node09 382
extern int16_t ValAi2_node09;
int doWrite_ValAi2_node09(int16_t value);
int addWrite_ValAi2_node09(int16_t value);
int getStatus_ValAi2_node09();
 
#define ID_DigDir_1_node09 383
extern int DigDir_1_node09;
int doWrite_DigDir_1_node09(int value);
int addWrite_DigDir_1_node09(int value);
int getStatus_DigDir_1_node09();
 
#define ID_DigDir_2_node09 384
extern int DigDir_2_node09;
int doWrite_DigDir_2_node09(int value);
int addWrite_DigDir_2_node09(int value);
int getStatus_DigDir_2_node09();
 
#define ID_DigDir_3_node09 385
extern int DigDir_3_node09;
int doWrite_DigDir_3_node09(int value);
int addWrite_DigDir_3_node09(int value);
int getStatus_DigDir_3_node09();
 
#define ID_DigDir_4_node09 386
extern int DigDir_4_node09;
int doWrite_DigDir_4_node09(int value);
int addWrite_DigDir_4_node09(int value);
int getStatus_DigDir_4_node09();
 
#define ID_DigDir_5_node09 387
extern int DigDir_5_node09;
int doWrite_DigDir_5_node09(int value);
int addWrite_DigDir_5_node09(int value);
int getStatus_DigDir_5_node09();
 
#define ID_DigDir_6_node09 388
extern int DigDir_6_node09;
int doWrite_DigDir_6_node09(int value);
int addWrite_DigDir_6_node09(int value);
int getStatus_DigDir_6_node09();
 
#define ID_DigDir_7_node09 389
extern int DigDir_7_node09;
int doWrite_DigDir_7_node09(int value);
int addWrite_DigDir_7_node09(int value);
int getStatus_DigDir_7_node09();
 
#define ID_DigDir_8_node09 390
extern int DigDir_8_node09;
int doWrite_DigDir_8_node09(int value);
int addWrite_DigDir_8_node09(int value);
int getStatus_DigDir_8_node09();
 
#define ID_DigIn_2_node09 391
extern int DigIn_2_node09;
int doWrite_DigIn_2_node09(int value);
int addWrite_DigIn_2_node09(int value);
int getStatus_DigIn_2_node09();
 
#define ID_DigIn_3_node09 392
extern int DigIn_3_node09;
int doWrite_DigIn_3_node09(int value);
int addWrite_DigIn_3_node09(int value);
int getStatus_DigIn_3_node09();
 
#define ID_DigIn_6_node09 393
extern int DigIn_6_node09;
int doWrite_DigIn_6_node09(int value);
int addWrite_DigIn_6_node09(int value);
int getStatus_DigIn_6_node09();
 
#define ID_DigIn_7_node09 394
extern int DigIn_7_node09;
int doWrite_DigIn_7_node09(int value);
int addWrite_DigIn_7_node09(int value);
int getStatus_DigIn_7_node09();
 
#define ID_DigOut_1_node09 395
extern int DigOut_1_node09;
int doWrite_DigOut_1_node09(int value);
int addWrite_DigOut_1_node09(int value);
int getStatus_DigOut_1_node09();
 
#define ID_DigOut_4_node09 396
extern int DigOut_4_node09;
int doWrite_DigOut_4_node09(int value);
int addWrite_DigOut_4_node09(int value);
int getStatus_DigOut_4_node09();
 
#define ID_DigOut_5_node09 397
extern int DigOut_5_node09;
int doWrite_DigOut_5_node09(int value);
int addWrite_DigOut_5_node09(int value);
int getStatus_DigOut_5_node09();
 
#define ID_DigOut_8_node09 398
extern int DigOut_8_node09;
int doWrite_DigOut_8_node09(int value);
int addWrite_DigOut_8_node09(int value);
int getStatus_DigOut_8_node09();
 
#define ID_errors_08 399
extern u_int32_t errors_08;
int doWrite_errors_08(u_int32_t value);
int addWrite_errors_08(u_int32_t value);
int getStatus_errors_08();
 
#define ID_Addr_node10 400
extern u_int16_t Addr_node10;
int doWrite_Addr_node10(u_int16_t value);
int addWrite_Addr_node10(u_int16_t value);
int getStatus_Addr_node10();
 
#define ID_Life_node10 401
extern u_int16_t Life_node10;
int doWrite_Life_node10(u_int16_t value);
int addWrite_Life_node10(u_int16_t value);
int getStatus_Life_node10();
 
#define ID_AnInCnf_1_node10 402
extern u_int16_t AnInCnf_1_node10;
int doWrite_AnInCnf_1_node10(u_int16_t value);
int addWrite_AnInCnf_1_node10(u_int16_t value);
int getStatus_AnInCnf_1_node10();
 
#define ID_AnInCnf_2_node10 403
extern u_int16_t AnInCnf_2_node10;
int doWrite_AnInCnf_2_node10(u_int16_t value);
int addWrite_AnInCnf_2_node10(u_int16_t value);
int getStatus_AnInCnf_2_node10();
 
#define ID_ValAi1_node10 404
extern int16_t ValAi1_node10;
int doWrite_ValAi1_node10(int16_t value);
int addWrite_ValAi1_node10(int16_t value);
int getStatus_ValAi1_node10();
 
#define ID_ValAi2_node10 405
extern int16_t ValAi2_node10;
int doWrite_ValAi2_node10(int16_t value);
int addWrite_ValAi2_node10(int16_t value);
int getStatus_ValAi2_node10();
 
#define ID_DigDir_1_node10 406
extern int DigDir_1_node10;
int doWrite_DigDir_1_node10(int value);
int addWrite_DigDir_1_node10(int value);
int getStatus_DigDir_1_node10();
 
#define ID_DigDir_2_node10 407
extern int DigDir_2_node10;
int doWrite_DigDir_2_node10(int value);
int addWrite_DigDir_2_node10(int value);
int getStatus_DigDir_2_node10();
 
#define ID_DigDir_3_node10 408
extern int DigDir_3_node10;
int doWrite_DigDir_3_node10(int value);
int addWrite_DigDir_3_node10(int value);
int getStatus_DigDir_3_node10();
 
#define ID_DigDir_4_node10 409
extern int DigDir_4_node10;
int doWrite_DigDir_4_node10(int value);
int addWrite_DigDir_4_node10(int value);
int getStatus_DigDir_4_node10();
 
#define ID_DigDir_5_node10 410
extern int DigDir_5_node10;
int doWrite_DigDir_5_node10(int value);
int addWrite_DigDir_5_node10(int value);
int getStatus_DigDir_5_node10();
 
#define ID_DigDir_6_node10 411
extern int DigDir_6_node10;
int doWrite_DigDir_6_node10(int value);
int addWrite_DigDir_6_node10(int value);
int getStatus_DigDir_6_node10();
 
#define ID_DigDir_7_node10 412
extern int DigDir_7_node10;
int doWrite_DigDir_7_node10(int value);
int addWrite_DigDir_7_node10(int value);
int getStatus_DigDir_7_node10();
 
#define ID_DigDir_8_node10 413
extern int DigDir_8_node10;
int doWrite_DigDir_8_node10(int value);
int addWrite_DigDir_8_node10(int value);
int getStatus_DigDir_8_node10();
 
#define ID_DigIn_2_node10 414
extern int DigIn_2_node10;
int doWrite_DigIn_2_node10(int value);
int addWrite_DigIn_2_node10(int value);
int getStatus_DigIn_2_node10();
 
#define ID_DigIn_3_node10 415
extern int DigIn_3_node10;
int doWrite_DigIn_3_node10(int value);
int addWrite_DigIn_3_node10(int value);
int getStatus_DigIn_3_node10();
 
#define ID_DigIn_6_node10 416
extern int DigIn_6_node10;
int doWrite_DigIn_6_node10(int value);
int addWrite_DigIn_6_node10(int value);
int getStatus_DigIn_6_node10();
 
#define ID_DigIn_7_node10 417
extern int DigIn_7_node10;
int doWrite_DigIn_7_node10(int value);
int addWrite_DigIn_7_node10(int value);
int getStatus_DigIn_7_node10();
 
#define ID_DigOut_1_node10 418
extern int DigOut_1_node10;
int doWrite_DigOut_1_node10(int value);
int addWrite_DigOut_1_node10(int value);
int getStatus_DigOut_1_node10();
 
#define ID_DigOut_4_node10 419
extern int DigOut_4_node10;
int doWrite_DigOut_4_node10(int value);
int addWrite_DigOut_4_node10(int value);
int getStatus_DigOut_4_node10();
 
#define ID_DigOut_5_node10 420
extern int DigOut_5_node10;
int doWrite_DigOut_5_node10(int value);
int addWrite_DigOut_5_node10(int value);
int getStatus_DigOut_5_node10();
 
#define ID_DigOut_8_node10 421
extern int DigOut_8_node10;
int doWrite_DigOut_8_node10(int value);
int addWrite_DigOut_8_node10(int value);
int getStatus_DigOut_8_node10();
 
#define ID_errors_09 422
extern u_int32_t errors_09;
int doWrite_errors_09(u_int32_t value);
int addWrite_errors_09(u_int32_t value);
int getStatus_errors_09();
 
#define ID_Addr_node11 423
extern u_int16_t Addr_node11;
int doWrite_Addr_node11(u_int16_t value);
int addWrite_Addr_node11(u_int16_t value);
int getStatus_Addr_node11();
 
#define ID_Life_node11 424
extern u_int16_t Life_node11;
int doWrite_Life_node11(u_int16_t value);
int addWrite_Life_node11(u_int16_t value);
int getStatus_Life_node11();
 
#define ID_AnInCnf_1_node11 425
extern u_int16_t AnInCnf_1_node11;
int doWrite_AnInCnf_1_node11(u_int16_t value);
int addWrite_AnInCnf_1_node11(u_int16_t value);
int getStatus_AnInCnf_1_node11();
 
#define ID_AnInCnf_2_node11 426
extern u_int16_t AnInCnf_2_node11;
int doWrite_AnInCnf_2_node11(u_int16_t value);
int addWrite_AnInCnf_2_node11(u_int16_t value);
int getStatus_AnInCnf_2_node11();
 
#define ID_ValAi1_node11 427
extern int16_t ValAi1_node11;
int doWrite_ValAi1_node11(int16_t value);
int addWrite_ValAi1_node11(int16_t value);
int getStatus_ValAi1_node11();
 
#define ID_ValAi2_node11 428
extern int16_t ValAi2_node11;
int doWrite_ValAi2_node11(int16_t value);
int addWrite_ValAi2_node11(int16_t value);
int getStatus_ValAi2_node11();
 
#define ID_DigDir_1_node11 429
extern int DigDir_1_node11;
int doWrite_DigDir_1_node11(int value);
int addWrite_DigDir_1_node11(int value);
int getStatus_DigDir_1_node11();
 
#define ID_DigDir_2_node11 430
extern int DigDir_2_node11;
int doWrite_DigDir_2_node11(int value);
int addWrite_DigDir_2_node11(int value);
int getStatus_DigDir_2_node11();
 
#define ID_DigDir_3_node11 431
extern int DigDir_3_node11;
int doWrite_DigDir_3_node11(int value);
int addWrite_DigDir_3_node11(int value);
int getStatus_DigDir_3_node11();
 
#define ID_DigDir_4_node11 432
extern int DigDir_4_node11;
int doWrite_DigDir_4_node11(int value);
int addWrite_DigDir_4_node11(int value);
int getStatus_DigDir_4_node11();
 
#define ID_DigDir_5_node11 433
extern int DigDir_5_node11;
int doWrite_DigDir_5_node11(int value);
int addWrite_DigDir_5_node11(int value);
int getStatus_DigDir_5_node11();
 
#define ID_DigDir_6_node11 434
extern int DigDir_6_node11;
int doWrite_DigDir_6_node11(int value);
int addWrite_DigDir_6_node11(int value);
int getStatus_DigDir_6_node11();
 
#define ID_DigDir_7_node11 435
extern int DigDir_7_node11;
int doWrite_DigDir_7_node11(int value);
int addWrite_DigDir_7_node11(int value);
int getStatus_DigDir_7_node11();
 
#define ID_DigDir_8_node11 436
extern int DigDir_8_node11;
int doWrite_DigDir_8_node11(int value);
int addWrite_DigDir_8_node11(int value);
int getStatus_DigDir_8_node11();
 
#define ID_DigIn_2_node11 437
extern int DigIn_2_node11;
int doWrite_DigIn_2_node11(int value);
int addWrite_DigIn_2_node11(int value);
int getStatus_DigIn_2_node11();
 
#define ID_DigIn_3_node11 438
extern int DigIn_3_node11;
int doWrite_DigIn_3_node11(int value);
int addWrite_DigIn_3_node11(int value);
int getStatus_DigIn_3_node11();
 
#define ID_DigIn_6_node11 439
extern int DigIn_6_node11;
int doWrite_DigIn_6_node11(int value);
int addWrite_DigIn_6_node11(int value);
int getStatus_DigIn_6_node11();
 
#define ID_DigIn_7_node11 440
extern int DigIn_7_node11;
int doWrite_DigIn_7_node11(int value);
int addWrite_DigIn_7_node11(int value);
int getStatus_DigIn_7_node11();
 
#define ID_DigOut_1_node11 441
extern int DigOut_1_node11;
int doWrite_DigOut_1_node11(int value);
int addWrite_DigOut_1_node11(int value);
int getStatus_DigOut_1_node11();
 
#define ID_DigOut_4_node11 442
extern int DigOut_4_node11;
int doWrite_DigOut_4_node11(int value);
int addWrite_DigOut_4_node11(int value);
int getStatus_DigOut_4_node11();
 
#define ID_DigOut_5_node11 443
extern int DigOut_5_node11;
int doWrite_DigOut_5_node11(int value);
int addWrite_DigOut_5_node11(int value);
int getStatus_DigOut_5_node11();
 
#define ID_DigOut_8_node11 444
extern int DigOut_8_node11;
int doWrite_DigOut_8_node11(int value);
int addWrite_DigOut_8_node11(int value);
int getStatus_DigOut_8_node11();
 
#define ID_errors_10 445
extern u_int32_t errors_10;
int doWrite_errors_10(u_int32_t value);
int addWrite_errors_10(u_int32_t value);
int getStatus_errors_10();
 
#define ID_Addr_node12 446
extern u_int16_t Addr_node12;
int doWrite_Addr_node12(u_int16_t value);
int addWrite_Addr_node12(u_int16_t value);
int getStatus_Addr_node12();
 
#define ID_Life_node12 447
extern u_int16_t Life_node12;
int doWrite_Life_node12(u_int16_t value);
int addWrite_Life_node12(u_int16_t value);
int getStatus_Life_node12();
 
#define ID_AnInCnf_1_node12 448
extern u_int16_t AnInCnf_1_node12;
int doWrite_AnInCnf_1_node12(u_int16_t value);
int addWrite_AnInCnf_1_node12(u_int16_t value);
int getStatus_AnInCnf_1_node12();
 
#define ID_AnInCnf_2_node12 449
extern u_int16_t AnInCnf_2_node12;
int doWrite_AnInCnf_2_node12(u_int16_t value);
int addWrite_AnInCnf_2_node12(u_int16_t value);
int getStatus_AnInCnf_2_node12();
 
#define ID_ValAi1_node12 450
extern int16_t ValAi1_node12;
int doWrite_ValAi1_node12(int16_t value);
int addWrite_ValAi1_node12(int16_t value);
int getStatus_ValAi1_node12();
 
#define ID_ValAi2_node12 451
extern int16_t ValAi2_node12;
int doWrite_ValAi2_node12(int16_t value);
int addWrite_ValAi2_node12(int16_t value);
int getStatus_ValAi2_node12();
 
#define ID_DigDir_1_node12 452
extern int DigDir_1_node12;
int doWrite_DigDir_1_node12(int value);
int addWrite_DigDir_1_node12(int value);
int getStatus_DigDir_1_node12();
 
#define ID_DigDir_2_node12 453
extern int DigDir_2_node12;
int doWrite_DigDir_2_node12(int value);
int addWrite_DigDir_2_node12(int value);
int getStatus_DigDir_2_node12();
 
#define ID_DigDir_3_node12 454
extern int DigDir_3_node12;
int doWrite_DigDir_3_node12(int value);
int addWrite_DigDir_3_node12(int value);
int getStatus_DigDir_3_node12();
 
#define ID_DigDir_4_node12 455
extern int DigDir_4_node12;
int doWrite_DigDir_4_node12(int value);
int addWrite_DigDir_4_node12(int value);
int getStatus_DigDir_4_node12();
 
#define ID_DigDir_5_node12 456
extern int DigDir_5_node12;
int doWrite_DigDir_5_node12(int value);
int addWrite_DigDir_5_node12(int value);
int getStatus_DigDir_5_node12();
 
#define ID_DigDir_6_node12 457
extern int DigDir_6_node12;
int doWrite_DigDir_6_node12(int value);
int addWrite_DigDir_6_node12(int value);
int getStatus_DigDir_6_node12();
 
#define ID_DigDir_7_node12 458
extern int DigDir_7_node12;
int doWrite_DigDir_7_node12(int value);
int addWrite_DigDir_7_node12(int value);
int getStatus_DigDir_7_node12();
 
#define ID_DigDir_8_node12 459
extern int DigDir_8_node12;
int doWrite_DigDir_8_node12(int value);
int addWrite_DigDir_8_node12(int value);
int getStatus_DigDir_8_node12();
 
#define ID_DigIn_2_node12 460
extern int DigIn_2_node12;
int doWrite_DigIn_2_node12(int value);
int addWrite_DigIn_2_node12(int value);
int getStatus_DigIn_2_node12();
 
#define ID_DigIn_3_node12 461
extern int DigIn_3_node12;
int doWrite_DigIn_3_node12(int value);
int addWrite_DigIn_3_node12(int value);
int getStatus_DigIn_3_node12();
 
#define ID_DigIn_6_node12 462
extern int DigIn_6_node12;
int doWrite_DigIn_6_node12(int value);
int addWrite_DigIn_6_node12(int value);
int getStatus_DigIn_6_node12();
 
#define ID_DigIn_7_node12 463
extern int DigIn_7_node12;
int doWrite_DigIn_7_node12(int value);
int addWrite_DigIn_7_node12(int value);
int getStatus_DigIn_7_node12();
 
#define ID_DigOut_1_node12 464
extern int DigOut_1_node12;
int doWrite_DigOut_1_node12(int value);
int addWrite_DigOut_1_node12(int value);
int getStatus_DigOut_1_node12();
 
#define ID_DigOut_4_node12 465
extern int DigOut_4_node12;
int doWrite_DigOut_4_node12(int value);
int addWrite_DigOut_4_node12(int value);
int getStatus_DigOut_4_node12();
 
#define ID_DigOut_5_node12 466
extern int DigOut_5_node12;
int doWrite_DigOut_5_node12(int value);
int addWrite_DigOut_5_node12(int value);
int getStatus_DigOut_5_node12();
 
#define ID_DigOut_8_node12 467
extern int DigOut_8_node12;
int doWrite_DigOut_8_node12(int value);
int addWrite_DigOut_8_node12(int value);
int getStatus_DigOut_8_node12();
 
#define ID_errors_11 468
extern u_int32_t errors_11;
int doWrite_errors_11(u_int32_t value);
int addWrite_errors_11(u_int32_t value);
int getStatus_errors_11();
 
#define ID_Addr_node13 469
extern u_int16_t Addr_node13;
int doWrite_Addr_node13(u_int16_t value);
int addWrite_Addr_node13(u_int16_t value);
int getStatus_Addr_node13();
 
#define ID_Life_node13 470
extern u_int16_t Life_node13;
int doWrite_Life_node13(u_int16_t value);
int addWrite_Life_node13(u_int16_t value);
int getStatus_Life_node13();
 
#define ID_AnInCnf_1_node13 471
extern u_int16_t AnInCnf_1_node13;
int doWrite_AnInCnf_1_node13(u_int16_t value);
int addWrite_AnInCnf_1_node13(u_int16_t value);
int getStatus_AnInCnf_1_node13();
 
#define ID_AnInCnf_2_node13 472
extern u_int16_t AnInCnf_2_node13;
int doWrite_AnInCnf_2_node13(u_int16_t value);
int addWrite_AnInCnf_2_node13(u_int16_t value);
int getStatus_AnInCnf_2_node13();
 
#define ID_ValAi1_node13 473
extern int16_t ValAi1_node13;
int doWrite_ValAi1_node13(int16_t value);
int addWrite_ValAi1_node13(int16_t value);
int getStatus_ValAi1_node13();
 
#define ID_ValAi2_node13 474
extern int16_t ValAi2_node13;
int doWrite_ValAi2_node13(int16_t value);
int addWrite_ValAi2_node13(int16_t value);
int getStatus_ValAi2_node13();
 
#define ID_DigDir_1_node13 475
extern int DigDir_1_node13;
int doWrite_DigDir_1_node13(int value);
int addWrite_DigDir_1_node13(int value);
int getStatus_DigDir_1_node13();
 
#define ID_DigDir_2_node13 476
extern int DigDir_2_node13;
int doWrite_DigDir_2_node13(int value);
int addWrite_DigDir_2_node13(int value);
int getStatus_DigDir_2_node13();
 
#define ID_DigDir_3_node13 477
extern int DigDir_3_node13;
int doWrite_DigDir_3_node13(int value);
int addWrite_DigDir_3_node13(int value);
int getStatus_DigDir_3_node13();
 
#define ID_DigDir_4_node13 478
extern int DigDir_4_node13;
int doWrite_DigDir_4_node13(int value);
int addWrite_DigDir_4_node13(int value);
int getStatus_DigDir_4_node13();
 
#define ID_DigDir_5_node13 479
extern int DigDir_5_node13;
int doWrite_DigDir_5_node13(int value);
int addWrite_DigDir_5_node13(int value);
int getStatus_DigDir_5_node13();
 
#define ID_DigDir_6_node13 480
extern int DigDir_6_node13;
int doWrite_DigDir_6_node13(int value);
int addWrite_DigDir_6_node13(int value);
int getStatus_DigDir_6_node13();
 
#define ID_DigDir_7_node13 481
extern int DigDir_7_node13;
int doWrite_DigDir_7_node13(int value);
int addWrite_DigDir_7_node13(int value);
int getStatus_DigDir_7_node13();
 
#define ID_DigDir_8_node13 482
extern int DigDir_8_node13;
int doWrite_DigDir_8_node13(int value);
int addWrite_DigDir_8_node13(int value);
int getStatus_DigDir_8_node13();
 
#define ID_DigIn_2_node13 483
extern int DigIn_2_node13;
int doWrite_DigIn_2_node13(int value);
int addWrite_DigIn_2_node13(int value);
int getStatus_DigIn_2_node13();
 
#define ID_DigIn_3_node13 484
extern int DigIn_3_node13;
int doWrite_DigIn_3_node13(int value);
int addWrite_DigIn_3_node13(int value);
int getStatus_DigIn_3_node13();
 
#define ID_DigIn_6_node13 485
extern int DigIn_6_node13;
int doWrite_DigIn_6_node13(int value);
int addWrite_DigIn_6_node13(int value);
int getStatus_DigIn_6_node13();
 
#define ID_DigIn_7_node13 486
extern int DigIn_7_node13;
int doWrite_DigIn_7_node13(int value);
int addWrite_DigIn_7_node13(int value);
int getStatus_DigIn_7_node13();
 
#define ID_DigOut_1_node13 487
extern int DigOut_1_node13;
int doWrite_DigOut_1_node13(int value);
int addWrite_DigOut_1_node13(int value);
int getStatus_DigOut_1_node13();
 
#define ID_DigOut_4_node13 488
extern int DigOut_4_node13;
int doWrite_DigOut_4_node13(int value);
int addWrite_DigOut_4_node13(int value);
int getStatus_DigOut_4_node13();
 
#define ID_DigOut_5_node13 489
extern int DigOut_5_node13;
int doWrite_DigOut_5_node13(int value);
int addWrite_DigOut_5_node13(int value);
int getStatus_DigOut_5_node13();
 
#define ID_DigOut_8_node13 490
extern int DigOut_8_node13;
int doWrite_DigOut_8_node13(int value);
int addWrite_DigOut_8_node13(int value);
int getStatus_DigOut_8_node13();
 
#define ID_errors_12 491
extern u_int32_t errors_12;
int doWrite_errors_12(u_int32_t value);
int addWrite_errors_12(u_int32_t value);
int getStatus_errors_12();
 
#define ID_Addr_node14 492
extern u_int16_t Addr_node14;
int doWrite_Addr_node14(u_int16_t value);
int addWrite_Addr_node14(u_int16_t value);
int getStatus_Addr_node14();
 
#define ID_Life_node14 493
extern u_int16_t Life_node14;
int doWrite_Life_node14(u_int16_t value);
int addWrite_Life_node14(u_int16_t value);
int getStatus_Life_node14();
 
#define ID_AnInCnf_1_node14 494
extern u_int16_t AnInCnf_1_node14;
int doWrite_AnInCnf_1_node14(u_int16_t value);
int addWrite_AnInCnf_1_node14(u_int16_t value);
int getStatus_AnInCnf_1_node14();
 
#define ID_AnInCnf_2_node14 495
extern u_int16_t AnInCnf_2_node14;
int doWrite_AnInCnf_2_node14(u_int16_t value);
int addWrite_AnInCnf_2_node14(u_int16_t value);
int getStatus_AnInCnf_2_node14();
 
#define ID_ValAi1_node14 496
extern int16_t ValAi1_node14;
int doWrite_ValAi1_node14(int16_t value);
int addWrite_ValAi1_node14(int16_t value);
int getStatus_ValAi1_node14();
 
#define ID_ValAi2_node14 497
extern int16_t ValAi2_node14;
int doWrite_ValAi2_node14(int16_t value);
int addWrite_ValAi2_node14(int16_t value);
int getStatus_ValAi2_node14();
 
#define ID_DigDir_1_node14 498
extern int DigDir_1_node14;
int doWrite_DigDir_1_node14(int value);
int addWrite_DigDir_1_node14(int value);
int getStatus_DigDir_1_node14();
 
#define ID_DigDir_2_node14 499
extern int DigDir_2_node14;
int doWrite_DigDir_2_node14(int value);
int addWrite_DigDir_2_node14(int value);
int getStatus_DigDir_2_node14();
 
#define ID_DigDir_3_node14 500
extern int DigDir_3_node14;
int doWrite_DigDir_3_node14(int value);
int addWrite_DigDir_3_node14(int value);
int getStatus_DigDir_3_node14();
 
#define ID_DigDir_4_node14 501
extern int DigDir_4_node14;
int doWrite_DigDir_4_node14(int value);
int addWrite_DigDir_4_node14(int value);
int getStatus_DigDir_4_node14();
 
#define ID_DigDir_5_node14 502
extern int DigDir_5_node14;
int doWrite_DigDir_5_node14(int value);
int addWrite_DigDir_5_node14(int value);
int getStatus_DigDir_5_node14();
 
#define ID_DigDir_6_node14 503
extern int DigDir_6_node14;
int doWrite_DigDir_6_node14(int value);
int addWrite_DigDir_6_node14(int value);
int getStatus_DigDir_6_node14();
 
#define ID_DigDir_7_node14 504
extern int DigDir_7_node14;
int doWrite_DigDir_7_node14(int value);
int addWrite_DigDir_7_node14(int value);
int getStatus_DigDir_7_node14();
 
#define ID_DigDir_8_node14 505
extern int DigDir_8_node14;
int doWrite_DigDir_8_node14(int value);
int addWrite_DigDir_8_node14(int value);
int getStatus_DigDir_8_node14();
 
#define ID_DigIn_2_node14 506
extern int DigIn_2_node14;
int doWrite_DigIn_2_node14(int value);
int addWrite_DigIn_2_node14(int value);
int getStatus_DigIn_2_node14();
 
#define ID_DigIn_3_node14 507
extern int DigIn_3_node14;
int doWrite_DigIn_3_node14(int value);
int addWrite_DigIn_3_node14(int value);
int getStatus_DigIn_3_node14();
 
#define ID_DigIn_6_node14 508
extern int DigIn_6_node14;
int doWrite_DigIn_6_node14(int value);
int addWrite_DigIn_6_node14(int value);
int getStatus_DigIn_6_node14();
 
#define ID_DigIn_7_node14 509
extern int DigIn_7_node14;
int doWrite_DigIn_7_node14(int value);
int addWrite_DigIn_7_node14(int value);
int getStatus_DigIn_7_node14();
 
#define ID_DigOut_1_node14 510
extern int DigOut_1_node14;
int doWrite_DigOut_1_node14(int value);
int addWrite_DigOut_1_node14(int value);
int getStatus_DigOut_1_node14();
 
#define ID_DigOut_4_node14 511
extern int DigOut_4_node14;
int doWrite_DigOut_4_node14(int value);
int addWrite_DigOut_4_node14(int value);
int getStatus_DigOut_4_node14();
 
#define ID_DigOut_5_node14 512
extern int DigOut_5_node14;
int doWrite_DigOut_5_node14(int value);
int addWrite_DigOut_5_node14(int value);
int getStatus_DigOut_5_node14();
 
#define ID_DigOut_8_node14 513
extern int DigOut_8_node14;
int doWrite_DigOut_8_node14(int value);
int addWrite_DigOut_8_node14(int value);
int getStatus_DigOut_8_node14();
 
#define ID_errors_13 514
extern u_int32_t errors_13;
int doWrite_errors_13(u_int32_t value);
int addWrite_errors_13(u_int32_t value);
int getStatus_errors_13();
 
#define ID_Addr_node15 515
extern u_int16_t Addr_node15;
int doWrite_Addr_node15(u_int16_t value);
int addWrite_Addr_node15(u_int16_t value);
int getStatus_Addr_node15();
 
#define ID_Life_node15 516
extern u_int16_t Life_node15;
int doWrite_Life_node15(u_int16_t value);
int addWrite_Life_node15(u_int16_t value);
int getStatus_Life_node15();
 
#define ID_AnInCnf_1_node15 517
extern u_int16_t AnInCnf_1_node15;
int doWrite_AnInCnf_1_node15(u_int16_t value);
int addWrite_AnInCnf_1_node15(u_int16_t value);
int getStatus_AnInCnf_1_node15();
 
#define ID_AnInCnf_2_node15 518
extern u_int16_t AnInCnf_2_node15;
int doWrite_AnInCnf_2_node15(u_int16_t value);
int addWrite_AnInCnf_2_node15(u_int16_t value);
int getStatus_AnInCnf_2_node15();
 
#define ID_ValAi1_node15 519
extern int16_t ValAi1_node15;
int doWrite_ValAi1_node15(int16_t value);
int addWrite_ValAi1_node15(int16_t value);
int getStatus_ValAi1_node15();
 
#define ID_ValAi2_node15 520
extern int16_t ValAi2_node15;
int doWrite_ValAi2_node15(int16_t value);
int addWrite_ValAi2_node15(int16_t value);
int getStatus_ValAi2_node15();
 
#define ID_DigDir_1_node15 521
extern int DigDir_1_node15;
int doWrite_DigDir_1_node15(int value);
int addWrite_DigDir_1_node15(int value);
int getStatus_DigDir_1_node15();
 
#define ID_DigDir_2_node15 522
extern int DigDir_2_node15;
int doWrite_DigDir_2_node15(int value);
int addWrite_DigDir_2_node15(int value);
int getStatus_DigDir_2_node15();
 
#define ID_DigDir_3_node15 523
extern int DigDir_3_node15;
int doWrite_DigDir_3_node15(int value);
int addWrite_DigDir_3_node15(int value);
int getStatus_DigDir_3_node15();
 
#define ID_DigDir_4_node15 524
extern int DigDir_4_node15;
int doWrite_DigDir_4_node15(int value);
int addWrite_DigDir_4_node15(int value);
int getStatus_DigDir_4_node15();
 
#define ID_DigDir_5_node15 525
extern int DigDir_5_node15;
int doWrite_DigDir_5_node15(int value);
int addWrite_DigDir_5_node15(int value);
int getStatus_DigDir_5_node15();
 
#define ID_DigDir_6_node15 526
extern int DigDir_6_node15;
int doWrite_DigDir_6_node15(int value);
int addWrite_DigDir_6_node15(int value);
int getStatus_DigDir_6_node15();
 
#define ID_DigDir_7_node15 527
extern int DigDir_7_node15;
int doWrite_DigDir_7_node15(int value);
int addWrite_DigDir_7_node15(int value);
int getStatus_DigDir_7_node15();
 
#define ID_DigDir_8_node15 528
extern int DigDir_8_node15;
int doWrite_DigDir_8_node15(int value);
int addWrite_DigDir_8_node15(int value);
int getStatus_DigDir_8_node15();
 
#define ID_DigIn_2_node15 529
extern int DigIn_2_node15;
int doWrite_DigIn_2_node15(int value);
int addWrite_DigIn_2_node15(int value);
int getStatus_DigIn_2_node15();
 
#define ID_DigIn_3_node15 530
extern int DigIn_3_node15;
int doWrite_DigIn_3_node15(int value);
int addWrite_DigIn_3_node15(int value);
int getStatus_DigIn_3_node15();
 
#define ID_DigIn_6_node15 531
extern int DigIn_6_node15;
int doWrite_DigIn_6_node15(int value);
int addWrite_DigIn_6_node15(int value);
int getStatus_DigIn_6_node15();
 
#define ID_DigIn_7_node15 532
extern int DigIn_7_node15;
int doWrite_DigIn_7_node15(int value);
int addWrite_DigIn_7_node15(int value);
int getStatus_DigIn_7_node15();
 
#define ID_DigOut_1_node15 533
extern int DigOut_1_node15;
int doWrite_DigOut_1_node15(int value);
int addWrite_DigOut_1_node15(int value);
int getStatus_DigOut_1_node15();
 
#define ID_DigOut_4_node15 534
extern int DigOut_4_node15;
int doWrite_DigOut_4_node15(int value);
int addWrite_DigOut_4_node15(int value);
int getStatus_DigOut_4_node15();
 
#define ID_DigOut_5_node15 535
extern int DigOut_5_node15;
int doWrite_DigOut_5_node15(int value);
int addWrite_DigOut_5_node15(int value);
int getStatus_DigOut_5_node15();
 
#define ID_DigOut_8_node15 536
extern int DigOut_8_node15;
int doWrite_DigOut_8_node15(int value);
int addWrite_DigOut_8_node15(int value);
int getStatus_DigOut_8_node15();
 
#define ID_errors_14 537
extern u_int32_t errors_14;
int doWrite_errors_14(u_int32_t value);
int addWrite_errors_14(u_int32_t value);
int getStatus_errors_14();
 
#define ID_Addr_node16 538
extern u_int16_t Addr_node16;
int doWrite_Addr_node16(u_int16_t value);
int addWrite_Addr_node16(u_int16_t value);
int getStatus_Addr_node16();
 
#define ID_Life_node16 539
extern u_int16_t Life_node16;
int doWrite_Life_node16(u_int16_t value);
int addWrite_Life_node16(u_int16_t value);
int getStatus_Life_node16();
 
#define ID_AnInCnf_1_node16 540
extern u_int16_t AnInCnf_1_node16;
int doWrite_AnInCnf_1_node16(u_int16_t value);
int addWrite_AnInCnf_1_node16(u_int16_t value);
int getStatus_AnInCnf_1_node16();
 
#define ID_AnInCnf_2_node16 541
extern u_int16_t AnInCnf_2_node16;
int doWrite_AnInCnf_2_node16(u_int16_t value);
int addWrite_AnInCnf_2_node16(u_int16_t value);
int getStatus_AnInCnf_2_node16();
 
#define ID_ValAi1_node16 542
extern int16_t ValAi1_node16;
int doWrite_ValAi1_node16(int16_t value);
int addWrite_ValAi1_node16(int16_t value);
int getStatus_ValAi1_node16();
 
#define ID_ValAi2_node16 543
extern int16_t ValAi2_node16;
int doWrite_ValAi2_node16(int16_t value);
int addWrite_ValAi2_node16(int16_t value);
int getStatus_ValAi2_node16();
 
#define ID_DigDir_1_node16 544
extern int DigDir_1_node16;
int doWrite_DigDir_1_node16(int value);
int addWrite_DigDir_1_node16(int value);
int getStatus_DigDir_1_node16();
 
#define ID_DigDir_2_node16 545
extern int DigDir_2_node16;
int doWrite_DigDir_2_node16(int value);
int addWrite_DigDir_2_node16(int value);
int getStatus_DigDir_2_node16();
 
#define ID_DigDir_3_node16 546
extern int DigDir_3_node16;
int doWrite_DigDir_3_node16(int value);
int addWrite_DigDir_3_node16(int value);
int getStatus_DigDir_3_node16();
 
#define ID_DigDir_4_node16 547
extern int DigDir_4_node16;
int doWrite_DigDir_4_node16(int value);
int addWrite_DigDir_4_node16(int value);
int getStatus_DigDir_4_node16();
 
#define ID_DigDir_5_node16 548
extern int DigDir_5_node16;
int doWrite_DigDir_5_node16(int value);
int addWrite_DigDir_5_node16(int value);
int getStatus_DigDir_5_node16();
 
#define ID_DigDir_6_node16 549
extern int DigDir_6_node16;
int doWrite_DigDir_6_node16(int value);
int addWrite_DigDir_6_node16(int value);
int getStatus_DigDir_6_node16();
 
#define ID_DigDir_7_node16 550
extern int DigDir_7_node16;
int doWrite_DigDir_7_node16(int value);
int addWrite_DigDir_7_node16(int value);
int getStatus_DigDir_7_node16();
 
#define ID_DigDir_8_node16 551
extern int DigDir_8_node16;
int doWrite_DigDir_8_node16(int value);
int addWrite_DigDir_8_node16(int value);
int getStatus_DigDir_8_node16();
 
#define ID_DigIn_2_node16 552
extern int DigIn_2_node16;
int doWrite_DigIn_2_node16(int value);
int addWrite_DigIn_2_node16(int value);
int getStatus_DigIn_2_node16();
 
#define ID_DigIn_3_node16 553
extern int DigIn_3_node16;
int doWrite_DigIn_3_node16(int value);
int addWrite_DigIn_3_node16(int value);
int getStatus_DigIn_3_node16();
 
#define ID_DigIn_6_node16 554
extern int DigIn_6_node16;
int doWrite_DigIn_6_node16(int value);
int addWrite_DigIn_6_node16(int value);
int getStatus_DigIn_6_node16();
 
#define ID_DigIn_7_node16 555
extern int DigIn_7_node16;
int doWrite_DigIn_7_node16(int value);
int addWrite_DigIn_7_node16(int value);
int getStatus_DigIn_7_node16();
 
#define ID_DigOut_1_node16 556
extern int DigOut_1_node16;
int doWrite_DigOut_1_node16(int value);
int addWrite_DigOut_1_node16(int value);
int getStatus_DigOut_1_node16();
 
#define ID_DigOut_4_node16 557
extern int DigOut_4_node16;
int doWrite_DigOut_4_node16(int value);
int addWrite_DigOut_4_node16(int value);
int getStatus_DigOut_4_node16();
 
#define ID_DigOut_5_node16 558
extern int DigOut_5_node16;
int doWrite_DigOut_5_node16(int value);
int addWrite_DigOut_5_node16(int value);
int getStatus_DigOut_5_node16();
 
#define ID_DigOut_8_node16 559
extern int DigOut_8_node16;
int doWrite_DigOut_8_node16(int value);
int addWrite_DigOut_8_node16(int value);
int getStatus_DigOut_8_node16();
 
#define ID_errors_15 560
extern u_int32_t errors_15;
int doWrite_errors_15(u_int32_t value);
int addWrite_errors_15(u_int32_t value);
int getStatus_errors_15();
 
#define ID_Addr_node17 561
extern u_int16_t Addr_node17;
int doWrite_Addr_node17(u_int16_t value);
int addWrite_Addr_node17(u_int16_t value);
int getStatus_Addr_node17();
 
#define ID_Life_node17 562
extern u_int16_t Life_node17;
int doWrite_Life_node17(u_int16_t value);
int addWrite_Life_node17(u_int16_t value);
int getStatus_Life_node17();
 
#define ID_AnInCnf_1_node17 563
extern u_int16_t AnInCnf_1_node17;
int doWrite_AnInCnf_1_node17(u_int16_t value);
int addWrite_AnInCnf_1_node17(u_int16_t value);
int getStatus_AnInCnf_1_node17();
 
#define ID_AnInCnf_2_node17 564
extern u_int16_t AnInCnf_2_node17;
int doWrite_AnInCnf_2_node17(u_int16_t value);
int addWrite_AnInCnf_2_node17(u_int16_t value);
int getStatus_AnInCnf_2_node17();
 
#define ID_ValAi1_node17 565
extern int16_t ValAi1_node17;
int doWrite_ValAi1_node17(int16_t value);
int addWrite_ValAi1_node17(int16_t value);
int getStatus_ValAi1_node17();
 
#define ID_ValAi2_node17 566
extern int16_t ValAi2_node17;
int doWrite_ValAi2_node17(int16_t value);
int addWrite_ValAi2_node17(int16_t value);
int getStatus_ValAi2_node17();
 
#define ID_DigDir_1_node17 567
extern int DigDir_1_node17;
int doWrite_DigDir_1_node17(int value);
int addWrite_DigDir_1_node17(int value);
int getStatus_DigDir_1_node17();
 
#define ID_DigDir_2_node17 568
extern int DigDir_2_node17;
int doWrite_DigDir_2_node17(int value);
int addWrite_DigDir_2_node17(int value);
int getStatus_DigDir_2_node17();
 
#define ID_DigDir_3_node17 569
extern int DigDir_3_node17;
int doWrite_DigDir_3_node17(int value);
int addWrite_DigDir_3_node17(int value);
int getStatus_DigDir_3_node17();
 
#define ID_DigDir_4_node17 570
extern int DigDir_4_node17;
int doWrite_DigDir_4_node17(int value);
int addWrite_DigDir_4_node17(int value);
int getStatus_DigDir_4_node17();
 
#define ID_DigDir_5_node17 571
extern int DigDir_5_node17;
int doWrite_DigDir_5_node17(int value);
int addWrite_DigDir_5_node17(int value);
int getStatus_DigDir_5_node17();
 
#define ID_DigDir_6_node17 572
extern int DigDir_6_node17;
int doWrite_DigDir_6_node17(int value);
int addWrite_DigDir_6_node17(int value);
int getStatus_DigDir_6_node17();
 
#define ID_DigDir_7_node17 573
extern int DigDir_7_node17;
int doWrite_DigDir_7_node17(int value);
int addWrite_DigDir_7_node17(int value);
int getStatus_DigDir_7_node17();
 
#define ID_DigDir_8_node17 574
extern int DigDir_8_node17;
int doWrite_DigDir_8_node17(int value);
int addWrite_DigDir_8_node17(int value);
int getStatus_DigDir_8_node17();
 
#define ID_DigIn_2_node17 575
extern int DigIn_2_node17;
int doWrite_DigIn_2_node17(int value);
int addWrite_DigIn_2_node17(int value);
int getStatus_DigIn_2_node17();
 
#define ID_DigIn_3_node17 576
extern int DigIn_3_node17;
int doWrite_DigIn_3_node17(int value);
int addWrite_DigIn_3_node17(int value);
int getStatus_DigIn_3_node17();
 
#define ID_DigIn_6_node17 577
extern int DigIn_6_node17;
int doWrite_DigIn_6_node17(int value);
int addWrite_DigIn_6_node17(int value);
int getStatus_DigIn_6_node17();
 
#define ID_DigIn_7_node17 578
extern int DigIn_7_node17;
int doWrite_DigIn_7_node17(int value);
int addWrite_DigIn_7_node17(int value);
int getStatus_DigIn_7_node17();
 
#define ID_DigOut_1_node17 579
extern int DigOut_1_node17;
int doWrite_DigOut_1_node17(int value);
int addWrite_DigOut_1_node17(int value);
int getStatus_DigOut_1_node17();
 
#define ID_DigOut_4_node17 580
extern int DigOut_4_node17;
int doWrite_DigOut_4_node17(int value);
int addWrite_DigOut_4_node17(int value);
int getStatus_DigOut_4_node17();
 
#define ID_DigOut_5_node17 581
extern int DigOut_5_node17;
int doWrite_DigOut_5_node17(int value);
int addWrite_DigOut_5_node17(int value);
int getStatus_DigOut_5_node17();
 
#define ID_DigOut_8_node17 582
extern int DigOut_8_node17;
int doWrite_DigOut_8_node17(int value);
int addWrite_DigOut_8_node17(int value);
int getStatus_DigOut_8_node17();
 
#define ID_errors_16 583
extern u_int32_t errors_16;
int doWrite_errors_16(u_int32_t value);
int addWrite_errors_16(u_int32_t value);
int getStatus_errors_16();
 
#define ID_Addr_node18 584
extern u_int16_t Addr_node18;
int doWrite_Addr_node18(u_int16_t value);
int addWrite_Addr_node18(u_int16_t value);
int getStatus_Addr_node18();
 
#define ID_Life_node18 585
extern u_int16_t Life_node18;
int doWrite_Life_node18(u_int16_t value);
int addWrite_Life_node18(u_int16_t value);
int getStatus_Life_node18();
 
#define ID_AnInCnf_1_node18 586
extern u_int16_t AnInCnf_1_node18;
int doWrite_AnInCnf_1_node18(u_int16_t value);
int addWrite_AnInCnf_1_node18(u_int16_t value);
int getStatus_AnInCnf_1_node18();
 
#define ID_AnInCnf_2_node18 587
extern u_int16_t AnInCnf_2_node18;
int doWrite_AnInCnf_2_node18(u_int16_t value);
int addWrite_AnInCnf_2_node18(u_int16_t value);
int getStatus_AnInCnf_2_node18();
 
#define ID_ValAi1_node18 588
extern int16_t ValAi1_node18;
int doWrite_ValAi1_node18(int16_t value);
int addWrite_ValAi1_node18(int16_t value);
int getStatus_ValAi1_node18();
 
#define ID_ValAi2_node18 589
extern int16_t ValAi2_node18;
int doWrite_ValAi2_node18(int16_t value);
int addWrite_ValAi2_node18(int16_t value);
int getStatus_ValAi2_node18();
 
#define ID_DigDir_1_node18 590
extern int DigDir_1_node18;
int doWrite_DigDir_1_node18(int value);
int addWrite_DigDir_1_node18(int value);
int getStatus_DigDir_1_node18();
 
#define ID_DigDir_2_node18 591
extern int DigDir_2_node18;
int doWrite_DigDir_2_node18(int value);
int addWrite_DigDir_2_node18(int value);
int getStatus_DigDir_2_node18();
 
#define ID_DigDir_3_node18 592
extern int DigDir_3_node18;
int doWrite_DigDir_3_node18(int value);
int addWrite_DigDir_3_node18(int value);
int getStatus_DigDir_3_node18();
 
#define ID_DigDir_4_node18 593
extern int DigDir_4_node18;
int doWrite_DigDir_4_node18(int value);
int addWrite_DigDir_4_node18(int value);
int getStatus_DigDir_4_node18();
 
#define ID_DigDir_5_node18 594
extern int DigDir_5_node18;
int doWrite_DigDir_5_node18(int value);
int addWrite_DigDir_5_node18(int value);
int getStatus_DigDir_5_node18();
 
#define ID_DigDir_6_node18 595
extern int DigDir_6_node18;
int doWrite_DigDir_6_node18(int value);
int addWrite_DigDir_6_node18(int value);
int getStatus_DigDir_6_node18();
 
#define ID_DigDir_7_node18 596
extern int DigDir_7_node18;
int doWrite_DigDir_7_node18(int value);
int addWrite_DigDir_7_node18(int value);
int getStatus_DigDir_7_node18();
 
#define ID_DigDir_8_node18 597
extern int DigDir_8_node18;
int doWrite_DigDir_8_node18(int value);
int addWrite_DigDir_8_node18(int value);
int getStatus_DigDir_8_node18();
 
#define ID_DigIn_2_node18 598
extern int DigIn_2_node18;
int doWrite_DigIn_2_node18(int value);
int addWrite_DigIn_2_node18(int value);
int getStatus_DigIn_2_node18();
 
#define ID_DigIn_3_node18 599
extern int DigIn_3_node18;
int doWrite_DigIn_3_node18(int value);
int addWrite_DigIn_3_node18(int value);
int getStatus_DigIn_3_node18();
 
#define ID_DigIn_6_node18 600
extern int DigIn_6_node18;
int doWrite_DigIn_6_node18(int value);
int addWrite_DigIn_6_node18(int value);
int getStatus_DigIn_6_node18();
 
#define ID_DigIn_7_node18 601
extern int DigIn_7_node18;
int doWrite_DigIn_7_node18(int value);
int addWrite_DigIn_7_node18(int value);
int getStatus_DigIn_7_node18();
 
#define ID_DigOut_1_node18 602
extern int DigOut_1_node18;
int doWrite_DigOut_1_node18(int value);
int addWrite_DigOut_1_node18(int value);
int getStatus_DigOut_1_node18();
 
#define ID_DigOut_4_node18 603
extern int DigOut_4_node18;
int doWrite_DigOut_4_node18(int value);
int addWrite_DigOut_4_node18(int value);
int getStatus_DigOut_4_node18();
 
#define ID_DigOut_5_node18 604
extern int DigOut_5_node18;
int doWrite_DigOut_5_node18(int value);
int addWrite_DigOut_5_node18(int value);
int getStatus_DigOut_5_node18();
 
#define ID_DigOut_8_node18 605
extern int DigOut_8_node18;
int doWrite_DigOut_8_node18(int value);
int addWrite_DigOut_8_node18(int value);
int getStatus_DigOut_8_node18();
 
#define ID_errors_17 606
extern u_int32_t errors_17;
int doWrite_errors_17(u_int32_t value);
int addWrite_errors_17(u_int32_t value);
int getStatus_errors_17();
 
#define ID_Addr_node19 607
extern u_int16_t Addr_node19;
int doWrite_Addr_node19(u_int16_t value);
int addWrite_Addr_node19(u_int16_t value);
int getStatus_Addr_node19();
 
#define ID_Life_node19 608
extern u_int16_t Life_node19;
int doWrite_Life_node19(u_int16_t value);
int addWrite_Life_node19(u_int16_t value);
int getStatus_Life_node19();
 
#define ID_AnInCnf_1_node19 609
extern u_int16_t AnInCnf_1_node19;
int doWrite_AnInCnf_1_node19(u_int16_t value);
int addWrite_AnInCnf_1_node19(u_int16_t value);
int getStatus_AnInCnf_1_node19();
 
#define ID_AnInCnf_2_node19 610
extern u_int16_t AnInCnf_2_node19;
int doWrite_AnInCnf_2_node19(u_int16_t value);
int addWrite_AnInCnf_2_node19(u_int16_t value);
int getStatus_AnInCnf_2_node19();
 
#define ID_ValAi1_node19 611
extern int16_t ValAi1_node19;
int doWrite_ValAi1_node19(int16_t value);
int addWrite_ValAi1_node19(int16_t value);
int getStatus_ValAi1_node19();
 
#define ID_ValAi2_node19 612
extern int16_t ValAi2_node19;
int doWrite_ValAi2_node19(int16_t value);
int addWrite_ValAi2_node19(int16_t value);
int getStatus_ValAi2_node19();
 
#define ID_DigDir_1_node19 613
extern int DigDir_1_node19;
int doWrite_DigDir_1_node19(int value);
int addWrite_DigDir_1_node19(int value);
int getStatus_DigDir_1_node19();
 
#define ID_DigDir_2_node19 614
extern int DigDir_2_node19;
int doWrite_DigDir_2_node19(int value);
int addWrite_DigDir_2_node19(int value);
int getStatus_DigDir_2_node19();
 
#define ID_DigDir_3_node19 615
extern int DigDir_3_node19;
int doWrite_DigDir_3_node19(int value);
int addWrite_DigDir_3_node19(int value);
int getStatus_DigDir_3_node19();
 
#define ID_DigDir_4_node19 616
extern int DigDir_4_node19;
int doWrite_DigDir_4_node19(int value);
int addWrite_DigDir_4_node19(int value);
int getStatus_DigDir_4_node19();
 
#define ID_DigDir_5_node19 617
extern int DigDir_5_node19;
int doWrite_DigDir_5_node19(int value);
int addWrite_DigDir_5_node19(int value);
int getStatus_DigDir_5_node19();
 
#define ID_DigDir_6_node19 618
extern int DigDir_6_node19;
int doWrite_DigDir_6_node19(int value);
int addWrite_DigDir_6_node19(int value);
int getStatus_DigDir_6_node19();
 
#define ID_DigDir_7_node19 619
extern int DigDir_7_node19;
int doWrite_DigDir_7_node19(int value);
int addWrite_DigDir_7_node19(int value);
int getStatus_DigDir_7_node19();
 
#define ID_DigDir_8_node19 620
extern int DigDir_8_node19;
int doWrite_DigDir_8_node19(int value);
int addWrite_DigDir_8_node19(int value);
int getStatus_DigDir_8_node19();
 
#define ID_DigIn_2_node19 621
extern int DigIn_2_node19;
int doWrite_DigIn_2_node19(int value);
int addWrite_DigIn_2_node19(int value);
int getStatus_DigIn_2_node19();
 
#define ID_DigIn_3_node19 622
extern int DigIn_3_node19;
int doWrite_DigIn_3_node19(int value);
int addWrite_DigIn_3_node19(int value);
int getStatus_DigIn_3_node19();
 
#define ID_DigIn_6_node19 623
extern int DigIn_6_node19;
int doWrite_DigIn_6_node19(int value);
int addWrite_DigIn_6_node19(int value);
int getStatus_DigIn_6_node19();
 
#define ID_DigIn_7_node19 624
extern int DigIn_7_node19;
int doWrite_DigIn_7_node19(int value);
int addWrite_DigIn_7_node19(int value);
int getStatus_DigIn_7_node19();
 
#define ID_DigOut_1_node19 625
extern int DigOut_1_node19;
int doWrite_DigOut_1_node19(int value);
int addWrite_DigOut_1_node19(int value);
int getStatus_DigOut_1_node19();
 
#define ID_DigOut_4_node19 626
extern int DigOut_4_node19;
int doWrite_DigOut_4_node19(int value);
int addWrite_DigOut_4_node19(int value);
int getStatus_DigOut_4_node19();
 
#define ID_DigOut_5_node19 627
extern int DigOut_5_node19;
int doWrite_DigOut_5_node19(int value);
int addWrite_DigOut_5_node19(int value);
int getStatus_DigOut_5_node19();
 
#define ID_DigOut_8_node19 628
extern int DigOut_8_node19;
int doWrite_DigOut_8_node19(int value);
int addWrite_DigOut_8_node19(int value);
int getStatus_DigOut_8_node19();
 
#define ID_errors_18 629
extern u_int32_t errors_18;
int doWrite_errors_18(u_int32_t value);
int addWrite_errors_18(u_int32_t value);
int getStatus_errors_18();
 
#define ID_Addr_node20 630
extern u_int16_t Addr_node20;
int doWrite_Addr_node20(u_int16_t value);
int addWrite_Addr_node20(u_int16_t value);
int getStatus_Addr_node20();
 
#define ID_Life_node20 631
extern u_int16_t Life_node20;
int doWrite_Life_node20(u_int16_t value);
int addWrite_Life_node20(u_int16_t value);
int getStatus_Life_node20();
 
#define ID_AnInCnf_1_node20 632
extern u_int16_t AnInCnf_1_node20;
int doWrite_AnInCnf_1_node20(u_int16_t value);
int addWrite_AnInCnf_1_node20(u_int16_t value);
int getStatus_AnInCnf_1_node20();
 
#define ID_AnInCnf_2_node20 633
extern u_int16_t AnInCnf_2_node20;
int doWrite_AnInCnf_2_node20(u_int16_t value);
int addWrite_AnInCnf_2_node20(u_int16_t value);
int getStatus_AnInCnf_2_node20();
 
#define ID_ValAi1_node20 634
extern int16_t ValAi1_node20;
int doWrite_ValAi1_node20(int16_t value);
int addWrite_ValAi1_node20(int16_t value);
int getStatus_ValAi1_node20();
 
#define ID_ValAi2_node20 635
extern int16_t ValAi2_node20;
int doWrite_ValAi2_node20(int16_t value);
int addWrite_ValAi2_node20(int16_t value);
int getStatus_ValAi2_node20();
 
#define ID_DigDir_1_node20 636
extern int DigDir_1_node20;
int doWrite_DigDir_1_node20(int value);
int addWrite_DigDir_1_node20(int value);
int getStatus_DigDir_1_node20();
 
#define ID_DigDir_2_node20 637
extern int DigDir_2_node20;
int doWrite_DigDir_2_node20(int value);
int addWrite_DigDir_2_node20(int value);
int getStatus_DigDir_2_node20();
 
#define ID_DigDir_3_node20 638
extern int DigDir_3_node20;
int doWrite_DigDir_3_node20(int value);
int addWrite_DigDir_3_node20(int value);
int getStatus_DigDir_3_node20();
 
#define ID_DigDir_4_node20 639
extern int DigDir_4_node20;
int doWrite_DigDir_4_node20(int value);
int addWrite_DigDir_4_node20(int value);
int getStatus_DigDir_4_node20();
 
#define ID_DigDir_5_node20 640
extern int DigDir_5_node20;
int doWrite_DigDir_5_node20(int value);
int addWrite_DigDir_5_node20(int value);
int getStatus_DigDir_5_node20();
 
#define ID_DigDir_6_node20 641
extern int DigDir_6_node20;
int doWrite_DigDir_6_node20(int value);
int addWrite_DigDir_6_node20(int value);
int getStatus_DigDir_6_node20();
 
#define ID_DigDir_7_node20 642
extern int DigDir_7_node20;
int doWrite_DigDir_7_node20(int value);
int addWrite_DigDir_7_node20(int value);
int getStatus_DigDir_7_node20();
 
#define ID_DigDir_8_node20 643
extern int DigDir_8_node20;
int doWrite_DigDir_8_node20(int value);
int addWrite_DigDir_8_node20(int value);
int getStatus_DigDir_8_node20();
 
#define ID_DigIn_2_node20 644
extern int DigIn_2_node20;
int doWrite_DigIn_2_node20(int value);
int addWrite_DigIn_2_node20(int value);
int getStatus_DigIn_2_node20();
 
#define ID_DigIn_3_node20 645
extern int DigIn_3_node20;
int doWrite_DigIn_3_node20(int value);
int addWrite_DigIn_3_node20(int value);
int getStatus_DigIn_3_node20();
 
#define ID_DigIn_6_node20 646
extern int DigIn_6_node20;
int doWrite_DigIn_6_node20(int value);
int addWrite_DigIn_6_node20(int value);
int getStatus_DigIn_6_node20();
 
#define ID_DigIn_7_node20 647
extern int DigIn_7_node20;
int doWrite_DigIn_7_node20(int value);
int addWrite_DigIn_7_node20(int value);
int getStatus_DigIn_7_node20();
 
#define ID_DigOut_1_node20 648
extern int DigOut_1_node20;
int doWrite_DigOut_1_node20(int value);
int addWrite_DigOut_1_node20(int value);
int getStatus_DigOut_1_node20();
 
#define ID_DigOut_4_node20 649
extern int DigOut_4_node20;
int doWrite_DigOut_4_node20(int value);
int addWrite_DigOut_4_node20(int value);
int getStatus_DigOut_4_node20();
 
#define ID_DigOut_5_node20 650
extern int DigOut_5_node20;
int doWrite_DigOut_5_node20(int value);
int addWrite_DigOut_5_node20(int value);
int getStatus_DigOut_5_node20();
 
#define ID_DigOut_8_node20 651
extern int DigOut_8_node20;
int doWrite_DigOut_8_node20(int value);
int addWrite_DigOut_8_node20(int value);
int getStatus_DigOut_8_node20();
 
#define ID_errors_19 652
extern u_int32_t errors_19;
int doWrite_errors_19(u_int32_t value);
int addWrite_errors_19(u_int32_t value);
int getStatus_errors_19();
 
#define ID_Addr_node21 653
extern u_int16_t Addr_node21;
int doWrite_Addr_node21(u_int16_t value);
int addWrite_Addr_node21(u_int16_t value);
int getStatus_Addr_node21();
 
#define ID_Life_node21 654
extern u_int16_t Life_node21;
int doWrite_Life_node21(u_int16_t value);
int addWrite_Life_node21(u_int16_t value);
int getStatus_Life_node21();
 
#define ID_AnInCnf_1_node21 655
extern u_int16_t AnInCnf_1_node21;
int doWrite_AnInCnf_1_node21(u_int16_t value);
int addWrite_AnInCnf_1_node21(u_int16_t value);
int getStatus_AnInCnf_1_node21();
 
#define ID_AnInCnf_2_node21 656
extern u_int16_t AnInCnf_2_node21;
int doWrite_AnInCnf_2_node21(u_int16_t value);
int addWrite_AnInCnf_2_node21(u_int16_t value);
int getStatus_AnInCnf_2_node21();
 
#define ID_ValAi1_node21 657
extern int16_t ValAi1_node21;
int doWrite_ValAi1_node21(int16_t value);
int addWrite_ValAi1_node21(int16_t value);
int getStatus_ValAi1_node21();
 
#define ID_ValAi2_node21 658
extern int16_t ValAi2_node21;
int doWrite_ValAi2_node21(int16_t value);
int addWrite_ValAi2_node21(int16_t value);
int getStatus_ValAi2_node21();
 
#define ID_DigDir_1_node21 659
extern int DigDir_1_node21;
int doWrite_DigDir_1_node21(int value);
int addWrite_DigDir_1_node21(int value);
int getStatus_DigDir_1_node21();
 
#define ID_DigDir_2_node21 660
extern int DigDir_2_node21;
int doWrite_DigDir_2_node21(int value);
int addWrite_DigDir_2_node21(int value);
int getStatus_DigDir_2_node21();
 
#define ID_DigDir_3_node21 661
extern int DigDir_3_node21;
int doWrite_DigDir_3_node21(int value);
int addWrite_DigDir_3_node21(int value);
int getStatus_DigDir_3_node21();
 
#define ID_DigDir_4_node21 662
extern int DigDir_4_node21;
int doWrite_DigDir_4_node21(int value);
int addWrite_DigDir_4_node21(int value);
int getStatus_DigDir_4_node21();
 
#define ID_DigDir_5_node21 663
extern int DigDir_5_node21;
int doWrite_DigDir_5_node21(int value);
int addWrite_DigDir_5_node21(int value);
int getStatus_DigDir_5_node21();
 
#define ID_DigDir_6_node21 664
extern int DigDir_6_node21;
int doWrite_DigDir_6_node21(int value);
int addWrite_DigDir_6_node21(int value);
int getStatus_DigDir_6_node21();
 
#define ID_DigDir_7_node21 665
extern int DigDir_7_node21;
int doWrite_DigDir_7_node21(int value);
int addWrite_DigDir_7_node21(int value);
int getStatus_DigDir_7_node21();
 
#define ID_DigDir_8_node21 666
extern int DigDir_8_node21;
int doWrite_DigDir_8_node21(int value);
int addWrite_DigDir_8_node21(int value);
int getStatus_DigDir_8_node21();
 
#define ID_DigIn_2_node21 667
extern int DigIn_2_node21;
int doWrite_DigIn_2_node21(int value);
int addWrite_DigIn_2_node21(int value);
int getStatus_DigIn_2_node21();
 
#define ID_DigIn_3_node21 668
extern int DigIn_3_node21;
int doWrite_DigIn_3_node21(int value);
int addWrite_DigIn_3_node21(int value);
int getStatus_DigIn_3_node21();
 
#define ID_DigIn_6_node21 669
extern int DigIn_6_node21;
int doWrite_DigIn_6_node21(int value);
int addWrite_DigIn_6_node21(int value);
int getStatus_DigIn_6_node21();
 
#define ID_DigIn_7_node21 670
extern int DigIn_7_node21;
int doWrite_DigIn_7_node21(int value);
int addWrite_DigIn_7_node21(int value);
int getStatus_DigIn_7_node21();
 
#define ID_DigOut_1_node21 671
extern int DigOut_1_node21;
int doWrite_DigOut_1_node21(int value);
int addWrite_DigOut_1_node21(int value);
int getStatus_DigOut_1_node21();
 
#define ID_DigOut_4_node21 672
extern int DigOut_4_node21;
int doWrite_DigOut_4_node21(int value);
int addWrite_DigOut_4_node21(int value);
int getStatus_DigOut_4_node21();
 
#define ID_DigOut_5_node21 673
extern int DigOut_5_node21;
int doWrite_DigOut_5_node21(int value);
int addWrite_DigOut_5_node21(int value);
int getStatus_DigOut_5_node21();
 
#define ID_DigOut_8_node21 674
extern int DigOut_8_node21;
int doWrite_DigOut_8_node21(int value);
int addWrite_DigOut_8_node21(int value);
int getStatus_DigOut_8_node21();
 
#define ID_errors_20 675
extern u_int32_t errors_20;
int doWrite_errors_20(u_int32_t value);
int addWrite_errors_20(u_int32_t value);
int getStatus_errors_20();
 
#define ID_Addr_node22 676
extern u_int16_t Addr_node22;
int doWrite_Addr_node22(u_int16_t value);
int addWrite_Addr_node22(u_int16_t value);
int getStatus_Addr_node22();
 
#define ID_Life_node22 677
extern u_int16_t Life_node22;
int doWrite_Life_node22(u_int16_t value);
int addWrite_Life_node22(u_int16_t value);
int getStatus_Life_node22();
 
#define ID_AnInCnf_1_node22 678
extern u_int16_t AnInCnf_1_node22;
int doWrite_AnInCnf_1_node22(u_int16_t value);
int addWrite_AnInCnf_1_node22(u_int16_t value);
int getStatus_AnInCnf_1_node22();
 
#define ID_AnInCnf_2_node22 679
extern u_int16_t AnInCnf_2_node22;
int doWrite_AnInCnf_2_node22(u_int16_t value);
int addWrite_AnInCnf_2_node22(u_int16_t value);
int getStatus_AnInCnf_2_node22();
 
#define ID_ValAi1_node22 680
extern int16_t ValAi1_node22;
int doWrite_ValAi1_node22(int16_t value);
int addWrite_ValAi1_node22(int16_t value);
int getStatus_ValAi1_node22();
 
#define ID_ValAi2_node22 681
extern int16_t ValAi2_node22;
int doWrite_ValAi2_node22(int16_t value);
int addWrite_ValAi2_node22(int16_t value);
int getStatus_ValAi2_node22();
 
#define ID_DigDir_1_node22 682
extern int DigDir_1_node22;
int doWrite_DigDir_1_node22(int value);
int addWrite_DigDir_1_node22(int value);
int getStatus_DigDir_1_node22();
 
#define ID_DigDir_2_node22 683
extern int DigDir_2_node22;
int doWrite_DigDir_2_node22(int value);
int addWrite_DigDir_2_node22(int value);
int getStatus_DigDir_2_node22();
 
#define ID_DigDir_3_node22 684
extern int DigDir_3_node22;
int doWrite_DigDir_3_node22(int value);
int addWrite_DigDir_3_node22(int value);
int getStatus_DigDir_3_node22();
 
#define ID_DigDir_4_node22 685
extern int DigDir_4_node22;
int doWrite_DigDir_4_node22(int value);
int addWrite_DigDir_4_node22(int value);
int getStatus_DigDir_4_node22();
 
#define ID_DigDir_5_node22 686
extern int DigDir_5_node22;
int doWrite_DigDir_5_node22(int value);
int addWrite_DigDir_5_node22(int value);
int getStatus_DigDir_5_node22();
 
#define ID_DigDir_6_node22 687
extern int DigDir_6_node22;
int doWrite_DigDir_6_node22(int value);
int addWrite_DigDir_6_node22(int value);
int getStatus_DigDir_6_node22();
 
#define ID_DigDir_7_node22 688
extern int DigDir_7_node22;
int doWrite_DigDir_7_node22(int value);
int addWrite_DigDir_7_node22(int value);
int getStatus_DigDir_7_node22();
 
#define ID_DigDir_8_node22 689
extern int DigDir_8_node22;
int doWrite_DigDir_8_node22(int value);
int addWrite_DigDir_8_node22(int value);
int getStatus_DigDir_8_node22();
 
#define ID_DigIn_2_node22 690
extern int DigIn_2_node22;
int doWrite_DigIn_2_node22(int value);
int addWrite_DigIn_2_node22(int value);
int getStatus_DigIn_2_node22();
 
#define ID_DigIn_3_node22 691
extern int DigIn_3_node22;
int doWrite_DigIn_3_node22(int value);
int addWrite_DigIn_3_node22(int value);
int getStatus_DigIn_3_node22();
 
#define ID_DigIn_6_node22 692
extern int DigIn_6_node22;
int doWrite_DigIn_6_node22(int value);
int addWrite_DigIn_6_node22(int value);
int getStatus_DigIn_6_node22();
 
#define ID_DigIn_7_node22 693
extern int DigIn_7_node22;
int doWrite_DigIn_7_node22(int value);
int addWrite_DigIn_7_node22(int value);
int getStatus_DigIn_7_node22();
 
#define ID_DigOut_1_node22 694
extern int DigOut_1_node22;
int doWrite_DigOut_1_node22(int value);
int addWrite_DigOut_1_node22(int value);
int getStatus_DigOut_1_node22();
 
#define ID_DigOut_4_node22 695
extern int DigOut_4_node22;
int doWrite_DigOut_4_node22(int value);
int addWrite_DigOut_4_node22(int value);
int getStatus_DigOut_4_node22();
 
#define ID_DigOut_5_node22 696
extern int DigOut_5_node22;
int doWrite_DigOut_5_node22(int value);
int addWrite_DigOut_5_node22(int value);
int getStatus_DigOut_5_node22();
 
#define ID_DigOut_8_node22 697
extern int DigOut_8_node22;
int doWrite_DigOut_8_node22(int value);
int addWrite_DigOut_8_node22(int value);
int getStatus_DigOut_8_node22();
 
#define ID_errors_21 698
extern u_int32_t errors_21;
int doWrite_errors_21(u_int32_t value);
int addWrite_errors_21(u_int32_t value);
int getStatus_errors_21();
 
#define ID_errors_22 699
extern u_int32_t errors_22;
int doWrite_errors_22(u_int32_t value);
int addWrite_errors_22(u_int32_t value);
int getStatus_errors_22();
 
#define ID_Addr_node23 700
extern u_int16_t Addr_node23;
int doWrite_Addr_node23(u_int16_t value);
int addWrite_Addr_node23(u_int16_t value);
int getStatus_Addr_node23();
 
#define ID_Life_node23 701
extern u_int16_t Life_node23;
int doWrite_Life_node23(u_int16_t value);
int addWrite_Life_node23(u_int16_t value);
int getStatus_Life_node23();
 
#define ID_AnInCnf_1_node23 702
extern u_int16_t AnInCnf_1_node23;
int doWrite_AnInCnf_1_node23(u_int16_t value);
int addWrite_AnInCnf_1_node23(u_int16_t value);
int getStatus_AnInCnf_1_node23();
 
#define ID_AnInCnf_2_node23 703
extern u_int16_t AnInCnf_2_node23;
int doWrite_AnInCnf_2_node23(u_int16_t value);
int addWrite_AnInCnf_2_node23(u_int16_t value);
int getStatus_AnInCnf_2_node23();
 
#define ID_ValAi1_node23 704
extern int16_t ValAi1_node23;
int doWrite_ValAi1_node23(int16_t value);
int addWrite_ValAi1_node23(int16_t value);
int getStatus_ValAi1_node23();
 
#define ID_ValAi2_node23 705
extern int16_t ValAi2_node23;
int doWrite_ValAi2_node23(int16_t value);
int addWrite_ValAi2_node23(int16_t value);
int getStatus_ValAi2_node23();
 
#define ID_DigDir_1_node23 706
extern int DigDir_1_node23;
int doWrite_DigDir_1_node23(int value);
int addWrite_DigDir_1_node23(int value);
int getStatus_DigDir_1_node23();
 
#define ID_DigDir_2_node23 707
extern int DigDir_2_node23;
int doWrite_DigDir_2_node23(int value);
int addWrite_DigDir_2_node23(int value);
int getStatus_DigDir_2_node23();
 
#define ID_DigDir_3_node23 708
extern int DigDir_3_node23;
int doWrite_DigDir_3_node23(int value);
int addWrite_DigDir_3_node23(int value);
int getStatus_DigDir_3_node23();
 
#define ID_DigDir_4_node23 709
extern int DigDir_4_node23;
int doWrite_DigDir_4_node23(int value);
int addWrite_DigDir_4_node23(int value);
int getStatus_DigDir_4_node23();
 
#define ID_DigDir_5_node23 710
extern int DigDir_5_node23;
int doWrite_DigDir_5_node23(int value);
int addWrite_DigDir_5_node23(int value);
int getStatus_DigDir_5_node23();
 
#define ID_DigDir_6_node23 711
extern int DigDir_6_node23;
int doWrite_DigDir_6_node23(int value);
int addWrite_DigDir_6_node23(int value);
int getStatus_DigDir_6_node23();
 
#define ID_DigDir_7_node23 712
extern int DigDir_7_node23;
int doWrite_DigDir_7_node23(int value);
int addWrite_DigDir_7_node23(int value);
int getStatus_DigDir_7_node23();
 
#define ID_DigDir_8_node23 713
extern int DigDir_8_node23;
int doWrite_DigDir_8_node23(int value);
int addWrite_DigDir_8_node23(int value);
int getStatus_DigDir_8_node23();
 
#define ID_DigIn_2_node23 714
extern int DigIn_2_node23;
int doWrite_DigIn_2_node23(int value);
int addWrite_DigIn_2_node23(int value);
int getStatus_DigIn_2_node23();
 
#define ID_DigIn_3_node23 715
extern int DigIn_3_node23;
int doWrite_DigIn_3_node23(int value);
int addWrite_DigIn_3_node23(int value);
int getStatus_DigIn_3_node23();
 
#define ID_DigIn_6_node23 716
extern int DigIn_6_node23;
int doWrite_DigIn_6_node23(int value);
int addWrite_DigIn_6_node23(int value);
int getStatus_DigIn_6_node23();
 
#define ID_DigIn_7_node23 717
extern int DigIn_7_node23;
int doWrite_DigIn_7_node23(int value);
int addWrite_DigIn_7_node23(int value);
int getStatus_DigIn_7_node23();
 
#define ID_DigOut_1_node23 718
extern int DigOut_1_node23;
int doWrite_DigOut_1_node23(int value);
int addWrite_DigOut_1_node23(int value);
int getStatus_DigOut_1_node23();
 
#define ID_DigOut_4_node23 719
extern int DigOut_4_node23;
int doWrite_DigOut_4_node23(int value);
int addWrite_DigOut_4_node23(int value);
int getStatus_DigOut_4_node23();
 
#define ID_DigOut_5_node23 720
extern int DigOut_5_node23;
int doWrite_DigOut_5_node23(int value);
int addWrite_DigOut_5_node23(int value);
int getStatus_DigOut_5_node23();
 
#define ID_DigOut_8_node23 721
extern int DigOut_8_node23;
int doWrite_DigOut_8_node23(int value);
int addWrite_DigOut_8_node23(int value);
int getStatus_DigOut_8_node23();
 
#define ID_errors_23 722
extern u_int32_t errors_23;
int doWrite_errors_23(u_int32_t value);
int addWrite_errors_23(u_int32_t value);
int getStatus_errors_23();
 
#define ID_Addr_node24 723
extern u_int16_t Addr_node24;
int doWrite_Addr_node24(u_int16_t value);
int addWrite_Addr_node24(u_int16_t value);
int getStatus_Addr_node24();
 
#define ID_Life_node24 724
extern u_int16_t Life_node24;
int doWrite_Life_node24(u_int16_t value);
int addWrite_Life_node24(u_int16_t value);
int getStatus_Life_node24();
 
#define ID_AnInCnf_1_node24 725
extern u_int16_t AnInCnf_1_node24;
int doWrite_AnInCnf_1_node24(u_int16_t value);
int addWrite_AnInCnf_1_node24(u_int16_t value);
int getStatus_AnInCnf_1_node24();
 
#define ID_AnInCnf_2_node24 726
extern u_int16_t AnInCnf_2_node24;
int doWrite_AnInCnf_2_node24(u_int16_t value);
int addWrite_AnInCnf_2_node24(u_int16_t value);
int getStatus_AnInCnf_2_node24();
 
#define ID_ValAi1_node24 727
extern int16_t ValAi1_node24;
int doWrite_ValAi1_node24(int16_t value);
int addWrite_ValAi1_node24(int16_t value);
int getStatus_ValAi1_node24();
 
#define ID_ValAi2_node24 728
extern int16_t ValAi2_node24;
int doWrite_ValAi2_node24(int16_t value);
int addWrite_ValAi2_node24(int16_t value);
int getStatus_ValAi2_node24();
 
#define ID_DigDir_1_node24 729
extern int DigDir_1_node24;
int doWrite_DigDir_1_node24(int value);
int addWrite_DigDir_1_node24(int value);
int getStatus_DigDir_1_node24();
 
#define ID_DigDir_2_node24 730
extern int DigDir_2_node24;
int doWrite_DigDir_2_node24(int value);
int addWrite_DigDir_2_node24(int value);
int getStatus_DigDir_2_node24();
 
#define ID_DigDir_3_node24 731
extern int DigDir_3_node24;
int doWrite_DigDir_3_node24(int value);
int addWrite_DigDir_3_node24(int value);
int getStatus_DigDir_3_node24();
 
#define ID_DigDir_4_node24 732
extern int DigDir_4_node24;
int doWrite_DigDir_4_node24(int value);
int addWrite_DigDir_4_node24(int value);
int getStatus_DigDir_4_node24();
 
#define ID_DigDir_5_node24 733
extern int DigDir_5_node24;
int doWrite_DigDir_5_node24(int value);
int addWrite_DigDir_5_node24(int value);
int getStatus_DigDir_5_node24();
 
#define ID_DigDir_6_node24 734
extern int DigDir_6_node24;
int doWrite_DigDir_6_node24(int value);
int addWrite_DigDir_6_node24(int value);
int getStatus_DigDir_6_node24();
 
#define ID_DigDir_7_node24 735
extern int DigDir_7_node24;
int doWrite_DigDir_7_node24(int value);
int addWrite_DigDir_7_node24(int value);
int getStatus_DigDir_7_node24();
 
#define ID_DigDir_8_node24 736
extern int DigDir_8_node24;
int doWrite_DigDir_8_node24(int value);
int addWrite_DigDir_8_node24(int value);
int getStatus_DigDir_8_node24();
 
#define ID_DigIn_2_node24 737
extern int DigIn_2_node24;
int doWrite_DigIn_2_node24(int value);
int addWrite_DigIn_2_node24(int value);
int getStatus_DigIn_2_node24();
 
#define ID_DigIn_3_node24 738
extern int DigIn_3_node24;
int doWrite_DigIn_3_node24(int value);
int addWrite_DigIn_3_node24(int value);
int getStatus_DigIn_3_node24();
 
#define ID_DigIn_6_node24 739
extern int DigIn_6_node24;
int doWrite_DigIn_6_node24(int value);
int addWrite_DigIn_6_node24(int value);
int getStatus_DigIn_6_node24();
 
#define ID_DigIn_7_node24 740
extern int DigIn_7_node24;
int doWrite_DigIn_7_node24(int value);
int addWrite_DigIn_7_node24(int value);
int getStatus_DigIn_7_node24();
 
#define ID_DigOut_1_node24 741
extern int DigOut_1_node24;
int doWrite_DigOut_1_node24(int value);
int addWrite_DigOut_1_node24(int value);
int getStatus_DigOut_1_node24();
 
#define ID_DigOut_4_node24 742
extern int DigOut_4_node24;
int doWrite_DigOut_4_node24(int value);
int addWrite_DigOut_4_node24(int value);
int getStatus_DigOut_4_node24();
 
#define ID_DigOut_5_node24 743
extern int DigOut_5_node24;
int doWrite_DigOut_5_node24(int value);
int addWrite_DigOut_5_node24(int value);
int getStatus_DigOut_5_node24();
 
#define ID_DigOut_8_node24 744
extern int DigOut_8_node24;
int doWrite_DigOut_8_node24(int value);
int addWrite_DigOut_8_node24(int value);
int getStatus_DigOut_8_node24();
 
#define ID_errors_24 745
extern u_int32_t errors_24;
int doWrite_errors_24(u_int32_t value);
int addWrite_errors_24(u_int32_t value);
int getStatus_errors_24();
 
#define ID_latency_01_ms 746
extern u_int16_t latency_01_ms;
int doWrite_latency_01_ms(u_int16_t value);
int addWrite_latency_01_ms(u_int16_t value);
int getStatus_latency_01_ms();
 
#define ID_latency_02_ms 747
extern u_int16_t latency_02_ms;
int doWrite_latency_02_ms(u_int16_t value);
int addWrite_latency_02_ms(u_int16_t value);
int getStatus_latency_02_ms();
 
#define ID_latency_03_ms 748
extern u_int16_t latency_03_ms;
int doWrite_latency_03_ms(u_int16_t value);
int addWrite_latency_03_ms(u_int16_t value);
int getStatus_latency_03_ms();
 
#define ID_latency_04_ms 749
extern u_int16_t latency_04_ms;
int doWrite_latency_04_ms(u_int16_t value);
int addWrite_latency_04_ms(u_int16_t value);
int getStatus_latency_04_ms();
 
#define ID_latency_05_ms 750
extern u_int16_t latency_05_ms;
int doWrite_latency_05_ms(u_int16_t value);
int addWrite_latency_05_ms(u_int16_t value);
int getStatus_latency_05_ms();
 
#define ID_latency_06_ms 751
extern u_int16_t latency_06_ms;
int doWrite_latency_06_ms(u_int16_t value);
int addWrite_latency_06_ms(u_int16_t value);
int getStatus_latency_06_ms();
 
#define ID_latency_07_ms 752
extern u_int16_t latency_07_ms;
int doWrite_latency_07_ms(u_int16_t value);
int addWrite_latency_07_ms(u_int16_t value);
int getStatus_latency_07_ms();
 
#define ID_latency_08_ms 753
extern u_int16_t latency_08_ms;
int doWrite_latency_08_ms(u_int16_t value);
int addWrite_latency_08_ms(u_int16_t value);
int getStatus_latency_08_ms();
 
#define ID_latency_09_ms 754
extern u_int16_t latency_09_ms;
int doWrite_latency_09_ms(u_int16_t value);
int addWrite_latency_09_ms(u_int16_t value);
int getStatus_latency_09_ms();
 
#define ID_latency_10_ms 755
extern u_int16_t latency_10_ms;
int doWrite_latency_10_ms(u_int16_t value);
int addWrite_latency_10_ms(u_int16_t value);
int getStatus_latency_10_ms();
 
#define ID_latency_11_ms 756
extern u_int16_t latency_11_ms;
int doWrite_latency_11_ms(u_int16_t value);
int addWrite_latency_11_ms(u_int16_t value);
int getStatus_latency_11_ms();
 
#define ID_latency_12_ms 757
extern u_int16_t latency_12_ms;
int doWrite_latency_12_ms(u_int16_t value);
int addWrite_latency_12_ms(u_int16_t value);
int getStatus_latency_12_ms();
 
#define ID_latency_13_ms 758
extern u_int16_t latency_13_ms;
int doWrite_latency_13_ms(u_int16_t value);
int addWrite_latency_13_ms(u_int16_t value);
int getStatus_latency_13_ms();
 
#define ID_latency_14_ms 759
extern u_int16_t latency_14_ms;
int doWrite_latency_14_ms(u_int16_t value);
int addWrite_latency_14_ms(u_int16_t value);
int getStatus_latency_14_ms();
 
#define ID_latency_15_ms 760
extern u_int16_t latency_15_ms;
int doWrite_latency_15_ms(u_int16_t value);
int addWrite_latency_15_ms(u_int16_t value);
int getStatus_latency_15_ms();
 
#define ID_latency_16_ms 761
extern u_int16_t latency_16_ms;
int doWrite_latency_16_ms(u_int16_t value);
int addWrite_latency_16_ms(u_int16_t value);
int getStatus_latency_16_ms();
 
#define ID_latency_17_ms 762
extern u_int16_t latency_17_ms;
int doWrite_latency_17_ms(u_int16_t value);
int addWrite_latency_17_ms(u_int16_t value);
int getStatus_latency_17_ms();
 
#define ID_latency_18_ms 763
extern u_int16_t latency_18_ms;
int doWrite_latency_18_ms(u_int16_t value);
int addWrite_latency_18_ms(u_int16_t value);
int getStatus_latency_18_ms();
 
#define ID_latency_19_ms 764
extern u_int16_t latency_19_ms;
int doWrite_latency_19_ms(u_int16_t value);
int addWrite_latency_19_ms(u_int16_t value);
int getStatus_latency_19_ms();
 
#define ID_latency_20_ms 765
extern u_int16_t latency_20_ms;
int doWrite_latency_20_ms(u_int16_t value);
int addWrite_latency_20_ms(u_int16_t value);
int getStatus_latency_20_ms();
 
#define ID_latency_21_ms 766
extern u_int16_t latency_21_ms;
int doWrite_latency_21_ms(u_int16_t value);
int addWrite_latency_21_ms(u_int16_t value);
int getStatus_latency_21_ms();
 
#define ID_latency_22_ms 767
extern u_int16_t latency_22_ms;
int doWrite_latency_22_ms(u_int16_t value);
int addWrite_latency_22_ms(u_int16_t value);
int getStatus_latency_22_ms();
 
#define ID_latency_23_ms 768
extern u_int16_t latency_23_ms;
int doWrite_latency_23_ms(u_int16_t value);
int addWrite_latency_23_ms(u_int16_t value);
int getStatus_latency_23_ms();
 
#define ID_latency_24_ms 769
extern u_int16_t latency_24_ms;
int doWrite_latency_24_ms(u_int16_t value);
int addWrite_latency_24_ms(u_int16_t value);
int getStatus_latency_24_ms();
 
#define ID_min_latency_01_m 770
extern u_int16_t min_latency_01_m;
int doWrite_min_latency_01_m(u_int16_t value);
int addWrite_min_latency_01_m(u_int16_t value);
int getStatus_min_latency_01_m();
 
#define ID_min_latency_02_m 771
extern u_int16_t min_latency_02_m;
int doWrite_min_latency_02_m(u_int16_t value);
int addWrite_min_latency_02_m(u_int16_t value);
int getStatus_min_latency_02_m();
 
#define ID_min_latency_03_m 772
extern u_int16_t min_latency_03_m;
int doWrite_min_latency_03_m(u_int16_t value);
int addWrite_min_latency_03_m(u_int16_t value);
int getStatus_min_latency_03_m();
 
#define ID_min_latency_04_m 773
extern u_int16_t min_latency_04_m;
int doWrite_min_latency_04_m(u_int16_t value);
int addWrite_min_latency_04_m(u_int16_t value);
int getStatus_min_latency_04_m();
 
#define ID_min_latency_05_m 774
extern u_int16_t min_latency_05_m;
int doWrite_min_latency_05_m(u_int16_t value);
int addWrite_min_latency_05_m(u_int16_t value);
int getStatus_min_latency_05_m();
 
#define ID_min_latency_06_m 775
extern u_int16_t min_latency_06_m;
int doWrite_min_latency_06_m(u_int16_t value);
int addWrite_min_latency_06_m(u_int16_t value);
int getStatus_min_latency_06_m();
 
#define ID_min_latency_07_m 776
extern u_int16_t min_latency_07_m;
int doWrite_min_latency_07_m(u_int16_t value);
int addWrite_min_latency_07_m(u_int16_t value);
int getStatus_min_latency_07_m();
 
#define ID_min_latency_08_m 777
extern u_int16_t min_latency_08_m;
int doWrite_min_latency_08_m(u_int16_t value);
int addWrite_min_latency_08_m(u_int16_t value);
int getStatus_min_latency_08_m();
 
#define ID_min_latency_09_m 778
extern u_int16_t min_latency_09_m;
int doWrite_min_latency_09_m(u_int16_t value);
int addWrite_min_latency_09_m(u_int16_t value);
int getStatus_min_latency_09_m();
 
#define ID_min_latency_10_m 779
extern u_int16_t min_latency_10_m;
int doWrite_min_latency_10_m(u_int16_t value);
int addWrite_min_latency_10_m(u_int16_t value);
int getStatus_min_latency_10_m();
 
#define ID_min_latency_11_m 780
extern u_int16_t min_latency_11_m;
int doWrite_min_latency_11_m(u_int16_t value);
int addWrite_min_latency_11_m(u_int16_t value);
int getStatus_min_latency_11_m();
 
#define ID_min_latency_12_m 781
extern u_int16_t min_latency_12_m;
int doWrite_min_latency_12_m(u_int16_t value);
int addWrite_min_latency_12_m(u_int16_t value);
int getStatus_min_latency_12_m();
 
#define ID_min_latency_13_m 782
extern u_int16_t min_latency_13_m;
int doWrite_min_latency_13_m(u_int16_t value);
int addWrite_min_latency_13_m(u_int16_t value);
int getStatus_min_latency_13_m();
 
#define ID_min_latency_14_m 783
extern u_int16_t min_latency_14_m;
int doWrite_min_latency_14_m(u_int16_t value);
int addWrite_min_latency_14_m(u_int16_t value);
int getStatus_min_latency_14_m();
 
#define ID_min_latency_15_m 784
extern u_int16_t min_latency_15_m;
int doWrite_min_latency_15_m(u_int16_t value);
int addWrite_min_latency_15_m(u_int16_t value);
int getStatus_min_latency_15_m();
 
#define ID_min_latency_16_m 785
extern u_int16_t min_latency_16_m;
int doWrite_min_latency_16_m(u_int16_t value);
int addWrite_min_latency_16_m(u_int16_t value);
int getStatus_min_latency_16_m();
 
#define ID_min_latency_17_m 786
extern u_int16_t min_latency_17_m;
int doWrite_min_latency_17_m(u_int16_t value);
int addWrite_min_latency_17_m(u_int16_t value);
int getStatus_min_latency_17_m();
 
#define ID_min_latency_18_m 787
extern u_int16_t min_latency_18_m;
int doWrite_min_latency_18_m(u_int16_t value);
int addWrite_min_latency_18_m(u_int16_t value);
int getStatus_min_latency_18_m();
 
#define ID_min_latency_19_m 788
extern u_int16_t min_latency_19_m;
int doWrite_min_latency_19_m(u_int16_t value);
int addWrite_min_latency_19_m(u_int16_t value);
int getStatus_min_latency_19_m();
 
#define ID_min_latency_20_m 789
extern u_int16_t min_latency_20_m;
int doWrite_min_latency_20_m(u_int16_t value);
int addWrite_min_latency_20_m(u_int16_t value);
int getStatus_min_latency_20_m();
 
#define ID_min_latency_21_m 790
extern u_int16_t min_latency_21_m;
int doWrite_min_latency_21_m(u_int16_t value);
int addWrite_min_latency_21_m(u_int16_t value);
int getStatus_min_latency_21_m();
 
#define ID_min_latency_22_m 791
extern u_int16_t min_latency_22_m;
int doWrite_min_latency_22_m(u_int16_t value);
int addWrite_min_latency_22_m(u_int16_t value);
int getStatus_min_latency_22_m();
 
#define ID_min_latency_23_m 792
extern u_int16_t min_latency_23_m;
int doWrite_min_latency_23_m(u_int16_t value);
int addWrite_min_latency_23_m(u_int16_t value);
int getStatus_min_latency_23_m();
 
#define ID_min_latency_24_m 793
extern u_int16_t min_latency_24_m;
int doWrite_min_latency_24_m(u_int16_t value);
int addWrite_min_latency_24_m(u_int16_t value);
int getStatus_min_latency_24_m();
 
#define ID_max_latency_01_m 794
extern u_int16_t max_latency_01_m;
int doWrite_max_latency_01_m(u_int16_t value);
int addWrite_max_latency_01_m(u_int16_t value);
int getStatus_max_latency_01_m();
 
#define ID_max_latency_02_m 795
extern u_int16_t max_latency_02_m;
int doWrite_max_latency_02_m(u_int16_t value);
int addWrite_max_latency_02_m(u_int16_t value);
int getStatus_max_latency_02_m();
 
#define ID_max_latency_03_m 796
extern u_int16_t max_latency_03_m;
int doWrite_max_latency_03_m(u_int16_t value);
int addWrite_max_latency_03_m(u_int16_t value);
int getStatus_max_latency_03_m();
 
#define ID_max_latency_04_m 797
extern u_int16_t max_latency_04_m;
int doWrite_max_latency_04_m(u_int16_t value);
int addWrite_max_latency_04_m(u_int16_t value);
int getStatus_max_latency_04_m();
 
#define ID_max_latency_05_m 798
extern u_int16_t max_latency_05_m;
int doWrite_max_latency_05_m(u_int16_t value);
int addWrite_max_latency_05_m(u_int16_t value);
int getStatus_max_latency_05_m();
 
#define ID_max_latency_06_m 799
extern u_int16_t max_latency_06_m;
int doWrite_max_latency_06_m(u_int16_t value);
int addWrite_max_latency_06_m(u_int16_t value);
int getStatus_max_latency_06_m();
 
#define ID_max_latency_07_m 800
extern u_int16_t max_latency_07_m;
int doWrite_max_latency_07_m(u_int16_t value);
int addWrite_max_latency_07_m(u_int16_t value);
int getStatus_max_latency_07_m();
 
#define ID_max_latency_08_m 801
extern u_int16_t max_latency_08_m;
int doWrite_max_latency_08_m(u_int16_t value);
int addWrite_max_latency_08_m(u_int16_t value);
int getStatus_max_latency_08_m();
 
#define ID_max_latency_09_m 802
extern u_int16_t max_latency_09_m;
int doWrite_max_latency_09_m(u_int16_t value);
int addWrite_max_latency_09_m(u_int16_t value);
int getStatus_max_latency_09_m();
 
#define ID_max_latency_10_m 803
extern u_int16_t max_latency_10_m;
int doWrite_max_latency_10_m(u_int16_t value);
int addWrite_max_latency_10_m(u_int16_t value);
int getStatus_max_latency_10_m();
 
#define ID_max_latency_11_m 804
extern u_int16_t max_latency_11_m;
int doWrite_max_latency_11_m(u_int16_t value);
int addWrite_max_latency_11_m(u_int16_t value);
int getStatus_max_latency_11_m();
 
#define ID_max_latency_12_m 805
extern u_int16_t max_latency_12_m;
int doWrite_max_latency_12_m(u_int16_t value);
int addWrite_max_latency_12_m(u_int16_t value);
int getStatus_max_latency_12_m();
 
#define ID_max_latency_13_m 806
extern u_int16_t max_latency_13_m;
int doWrite_max_latency_13_m(u_int16_t value);
int addWrite_max_latency_13_m(u_int16_t value);
int getStatus_max_latency_13_m();
 
#define ID_max_latency_14_m 807
extern u_int16_t max_latency_14_m;
int doWrite_max_latency_14_m(u_int16_t value);
int addWrite_max_latency_14_m(u_int16_t value);
int getStatus_max_latency_14_m();
 
#define ID_max_latency_15_m 808
extern u_int16_t max_latency_15_m;
int doWrite_max_latency_15_m(u_int16_t value);
int addWrite_max_latency_15_m(u_int16_t value);
int getStatus_max_latency_15_m();
 
#define ID_max_latency_16_m 809
extern u_int16_t max_latency_16_m;
int doWrite_max_latency_16_m(u_int16_t value);
int addWrite_max_latency_16_m(u_int16_t value);
int getStatus_max_latency_16_m();
 
#define ID_max_latency_17_m 810
extern u_int16_t max_latency_17_m;
int doWrite_max_latency_17_m(u_int16_t value);
int addWrite_max_latency_17_m(u_int16_t value);
int getStatus_max_latency_17_m();
 
#define ID_max_latency_18_m 811
extern u_int16_t max_latency_18_m;
int doWrite_max_latency_18_m(u_int16_t value);
int addWrite_max_latency_18_m(u_int16_t value);
int getStatus_max_latency_18_m();
 
#define ID_max_latency_19_m 812
extern u_int16_t max_latency_19_m;
int doWrite_max_latency_19_m(u_int16_t value);
int addWrite_max_latency_19_m(u_int16_t value);
int getStatus_max_latency_19_m();
 
#define ID_max_latency_20_m 813
extern u_int16_t max_latency_20_m;
int doWrite_max_latency_20_m(u_int16_t value);
int addWrite_max_latency_20_m(u_int16_t value);
int getStatus_max_latency_20_m();
 
#define ID_max_latency_21_m 814
extern u_int16_t max_latency_21_m;
int doWrite_max_latency_21_m(u_int16_t value);
int addWrite_max_latency_21_m(u_int16_t value);
int getStatus_max_latency_21_m();
 
#define ID_max_latency_22_m 815
extern u_int16_t max_latency_22_m;
int doWrite_max_latency_22_m(u_int16_t value);
int addWrite_max_latency_22_m(u_int16_t value);
int getStatus_max_latency_22_m();
 
#define ID_max_latency_23_m 816
extern u_int16_t max_latency_23_m;
int doWrite_max_latency_23_m(u_int16_t value);
int addWrite_max_latency_23_m(u_int16_t value);
int getStatus_max_latency_23_m();
 
#define ID_max_latency_24_m 817
extern u_int16_t max_latency_24_m;
int doWrite_max_latency_24_m(u_int16_t value);
int addWrite_max_latency_24_m(u_int16_t value);
int getStatus_max_latency_24_m();
 
#define ID_RTU0_TYPE_PORT 5000
extern u_int32_t RTU0_TYPE_PORT;
int doWrite_RTU0_TYPE_PORT(u_int32_t value);
int addWrite_RTU0_TYPE_PORT(u_int32_t value);
int getStatus_RTU0_TYPE_PORT();
 
#define ID_RTU0_BAUDRATE 5001
extern u_int32_t RTU0_BAUDRATE;
int doWrite_RTU0_BAUDRATE(u_int32_t value);
int addWrite_RTU0_BAUDRATE(u_int32_t value);
int getStatus_RTU0_BAUDRATE();
 
#define ID_RTU0_STATUS 5002
extern u_int32_t RTU0_STATUS;
int doWrite_RTU0_STATUS(u_int32_t value);
int addWrite_RTU0_STATUS(u_int32_t value);
int getStatus_RTU0_STATUS();
 
#define ID_RTU0_READS 5003
extern u_int32_t RTU0_READS;
int doWrite_RTU0_READS(u_int32_t value);
int addWrite_RTU0_READS(u_int32_t value);
int getStatus_RTU0_READS();
 
#define ID_RTU0_WRITES 5004
extern u_int32_t RTU0_WRITES;
int doWrite_RTU0_WRITES(u_int32_t value);
int addWrite_RTU0_WRITES(u_int32_t value);
int getStatus_RTU0_WRITES();
 
#define ID_RTU0_TIMEOUTS 5005
extern u_int32_t RTU0_TIMEOUTS;
int doWrite_RTU0_TIMEOUTS(u_int32_t value);
int addWrite_RTU0_TIMEOUTS(u_int32_t value);
int getStatus_RTU0_TIMEOUTS();
 
#define ID_RTU0_COMM_ERRORS 5006
extern u_int32_t RTU0_COMM_ERRORS;
int doWrite_RTU0_COMM_ERRORS(u_int32_t value);
int addWrite_RTU0_COMM_ERRORS(u_int32_t value);
int getStatus_RTU0_COMM_ERRORS();
 
#define ID_RTU0_LAST_ERROR 5007
extern u_int32_t RTU0_LAST_ERROR;
int doWrite_RTU0_LAST_ERROR(u_int32_t value);
int addWrite_RTU0_LAST_ERROR(u_int32_t value);
int getStatus_RTU0_LAST_ERROR();
 
#define ID_RTU0_WRITE_QUEUE 5008
extern u_int32_t RTU0_WRITE_QUEUE;
int doWrite_RTU0_WRITE_QUEUE(u_int32_t value);
int addWrite_RTU0_WRITE_QUEUE(u_int32_t value);
int getStatus_RTU0_WRITE_QUEUE();
 
#define ID_RTU0_READ_QUEUE 5009
extern u_int32_t RTU0_READ_QUEUE;
int doWrite_RTU0_READ_QUEUE(u_int32_t value);
int addWrite_RTU0_READ_QUEUE(u_int32_t value);
int getStatus_RTU0_READ_QUEUE();
 
#define ID_RTU1_TYPE_PORT 5010
extern u_int32_t RTU1_TYPE_PORT;
int doWrite_RTU1_TYPE_PORT(u_int32_t value);
int addWrite_RTU1_TYPE_PORT(u_int32_t value);
int getStatus_RTU1_TYPE_PORT();
 
#define ID_RTU1_BAUDRATE 5011
extern u_int32_t RTU1_BAUDRATE;
int doWrite_RTU1_BAUDRATE(u_int32_t value);
int addWrite_RTU1_BAUDRATE(u_int32_t value);
int getStatus_RTU1_BAUDRATE();
 
#define ID_RTU1_STATUS 5012
extern u_int32_t RTU1_STATUS;
int doWrite_RTU1_STATUS(u_int32_t value);
int addWrite_RTU1_STATUS(u_int32_t value);
int getStatus_RTU1_STATUS();
 
#define ID_RTU1_READS 5013
extern u_int32_t RTU1_READS;
int doWrite_RTU1_READS(u_int32_t value);
int addWrite_RTU1_READS(u_int32_t value);
int getStatus_RTU1_READS();
 
#define ID_RTU1_WRITES 5014
extern u_int32_t RTU1_WRITES;
int doWrite_RTU1_WRITES(u_int32_t value);
int addWrite_RTU1_WRITES(u_int32_t value);
int getStatus_RTU1_WRITES();
 
#define ID_RTU1_TIMEOUTS 5015
extern u_int32_t RTU1_TIMEOUTS;
int doWrite_RTU1_TIMEOUTS(u_int32_t value);
int addWrite_RTU1_TIMEOUTS(u_int32_t value);
int getStatus_RTU1_TIMEOUTS();
 
#define ID_RTU1_COMM_ERRORS 5016
extern u_int32_t RTU1_COMM_ERRORS;
int doWrite_RTU1_COMM_ERRORS(u_int32_t value);
int addWrite_RTU1_COMM_ERRORS(u_int32_t value);
int getStatus_RTU1_COMM_ERRORS();
 
#define ID_RTU1_LAST_ERROR 5017
extern u_int32_t RTU1_LAST_ERROR;
int doWrite_RTU1_LAST_ERROR(u_int32_t value);
int addWrite_RTU1_LAST_ERROR(u_int32_t value);
int getStatus_RTU1_LAST_ERROR();
 
#define ID_RTU1_WRITE_QUEUE 5018
extern u_int32_t RTU1_WRITE_QUEUE;
int doWrite_RTU1_WRITE_QUEUE(u_int32_t value);
int addWrite_RTU1_WRITE_QUEUE(u_int32_t value);
int getStatus_RTU1_WRITE_QUEUE();
 
#define ID_RTU1_READ_QUEUE 5019
extern u_int32_t RTU1_READ_QUEUE;
int doWrite_RTU1_READ_QUEUE(u_int32_t value);
int addWrite_RTU1_READ_QUEUE(u_int32_t value);
int getStatus_RTU1_READ_QUEUE();
 
#define ID_RTU3_TYPE_PORT 5020
extern u_int32_t RTU3_TYPE_PORT;
int doWrite_RTU3_TYPE_PORT(u_int32_t value);
int addWrite_RTU3_TYPE_PORT(u_int32_t value);
int getStatus_RTU3_TYPE_PORT();
 
#define ID_RTU3_BAUDRATE 5021
extern u_int32_t RTU3_BAUDRATE;
int doWrite_RTU3_BAUDRATE(u_int32_t value);
int addWrite_RTU3_BAUDRATE(u_int32_t value);
int getStatus_RTU3_BAUDRATE();
 
#define ID_RTU3_STATUS 5022
extern u_int32_t RTU3_STATUS;
int doWrite_RTU3_STATUS(u_int32_t value);
int addWrite_RTU3_STATUS(u_int32_t value);
int getStatus_RTU3_STATUS();
 
#define ID_RTU3_READS 5023
extern u_int32_t RTU3_READS;
int doWrite_RTU3_READS(u_int32_t value);
int addWrite_RTU3_READS(u_int32_t value);
int getStatus_RTU3_READS();
 
#define ID_RTU3_WRITES 5024
extern u_int32_t RTU3_WRITES;
int doWrite_RTU3_WRITES(u_int32_t value);
int addWrite_RTU3_WRITES(u_int32_t value);
int getStatus_RTU3_WRITES();
 
#define ID_RTU3_TIMEOUTS 5025
extern u_int32_t RTU3_TIMEOUTS;
int doWrite_RTU3_TIMEOUTS(u_int32_t value);
int addWrite_RTU3_TIMEOUTS(u_int32_t value);
int getStatus_RTU3_TIMEOUTS();
 
#define ID_RTU3_COMM_ERRORS 5026
extern u_int32_t RTU3_COMM_ERRORS;
int doWrite_RTU3_COMM_ERRORS(u_int32_t value);
int addWrite_RTU3_COMM_ERRORS(u_int32_t value);
int getStatus_RTU3_COMM_ERRORS();
 
#define ID_RTU3_LAST_ERROR 5027
extern u_int32_t RTU3_LAST_ERROR;
int doWrite_RTU3_LAST_ERROR(u_int32_t value);
int addWrite_RTU3_LAST_ERROR(u_int32_t value);
int getStatus_RTU3_LAST_ERROR();
 
#define ID_RTU3_WRITE_QUEUE 5028
extern u_int32_t RTU3_WRITE_QUEUE;
int doWrite_RTU3_WRITE_QUEUE(u_int32_t value);
int addWrite_RTU3_WRITE_QUEUE(u_int32_t value);
int getStatus_RTU3_WRITE_QUEUE();
 
#define ID_RTU3_READ_QUEUE 5029
extern u_int32_t RTU3_READ_QUEUE;
int doWrite_RTU3_READ_QUEUE(u_int32_t value);
int addWrite_RTU3_READ_QUEUE(u_int32_t value);
int getStatus_RTU3_READ_QUEUE();
 
#define ID_CAN0_TYPE_PORT 5030
extern u_int32_t CAN0_TYPE_PORT;
int doWrite_CAN0_TYPE_PORT(u_int32_t value);
int addWrite_CAN0_TYPE_PORT(u_int32_t value);
int getStatus_CAN0_TYPE_PORT();
 
#define ID_CAN0_BAUDRATE 5031
extern u_int32_t CAN0_BAUDRATE;
int doWrite_CAN0_BAUDRATE(u_int32_t value);
int addWrite_CAN0_BAUDRATE(u_int32_t value);
int getStatus_CAN0_BAUDRATE();
 
#define ID_CAN0_STATUS 5032
extern u_int32_t CAN0_STATUS;
int doWrite_CAN0_STATUS(u_int32_t value);
int addWrite_CAN0_STATUS(u_int32_t value);
int getStatus_CAN0_STATUS();
 
#define ID_CAN0_READS 5033
extern u_int32_t CAN0_READS;
int doWrite_CAN0_READS(u_int32_t value);
int addWrite_CAN0_READS(u_int32_t value);
int getStatus_CAN0_READS();
 
#define ID_CAN0_WRITES 5034
extern u_int32_t CAN0_WRITES;
int doWrite_CAN0_WRITES(u_int32_t value);
int addWrite_CAN0_WRITES(u_int32_t value);
int getStatus_CAN0_WRITES();
 
#define ID_CAN0_TIMEOUTS 5035
extern u_int32_t CAN0_TIMEOUTS;
int doWrite_CAN0_TIMEOUTS(u_int32_t value);
int addWrite_CAN0_TIMEOUTS(u_int32_t value);
int getStatus_CAN0_TIMEOUTS();
 
#define ID_CAN0_COMM_ERRORS 5036
extern u_int32_t CAN0_COMM_ERRORS;
int doWrite_CAN0_COMM_ERRORS(u_int32_t value);
int addWrite_CAN0_COMM_ERRORS(u_int32_t value);
int getStatus_CAN0_COMM_ERRORS();
 
#define ID_CAN0_LAST_ERROR 5037
extern u_int32_t CAN0_LAST_ERROR;
int doWrite_CAN0_LAST_ERROR(u_int32_t value);
int addWrite_CAN0_LAST_ERROR(u_int32_t value);
int getStatus_CAN0_LAST_ERROR();
 
#define ID_CAN0_WRITE_QUEUE 5038
extern u_int32_t CAN0_WRITE_QUEUE;
int doWrite_CAN0_WRITE_QUEUE(u_int32_t value);
int addWrite_CAN0_WRITE_QUEUE(u_int32_t value);
int getStatus_CAN0_WRITE_QUEUE();
 
#define ID_CAN0_READ_QUEUE 5039
extern u_int32_t CAN0_READ_QUEUE;
int doWrite_CAN0_READ_QUEUE(u_int32_t value);
int addWrite_CAN0_READ_QUEUE(u_int32_t value);
int getStatus_CAN0_READ_QUEUE();
 
#define ID_CAN1_TYPE_PORT 5040
extern u_int32_t CAN1_TYPE_PORT;
int doWrite_CAN1_TYPE_PORT(u_int32_t value);
int addWrite_CAN1_TYPE_PORT(u_int32_t value);
int getStatus_CAN1_TYPE_PORT();
 
#define ID_CAN1_BAUDRATE 5041
extern u_int32_t CAN1_BAUDRATE;
int doWrite_CAN1_BAUDRATE(u_int32_t value);
int addWrite_CAN1_BAUDRATE(u_int32_t value);
int getStatus_CAN1_BAUDRATE();
 
#define ID_CAN1_STATUS 5042
extern u_int32_t CAN1_STATUS;
int doWrite_CAN1_STATUS(u_int32_t value);
int addWrite_CAN1_STATUS(u_int32_t value);
int getStatus_CAN1_STATUS();
 
#define ID_CAN1_READS 5043
extern u_int32_t CAN1_READS;
int doWrite_CAN1_READS(u_int32_t value);
int addWrite_CAN1_READS(u_int32_t value);
int getStatus_CAN1_READS();
 
#define ID_CAN1_WRITES 5044
extern u_int32_t CAN1_WRITES;
int doWrite_CAN1_WRITES(u_int32_t value);
int addWrite_CAN1_WRITES(u_int32_t value);
int getStatus_CAN1_WRITES();
 
#define ID_CAN1_TIMEOUTS 5045
extern u_int32_t CAN1_TIMEOUTS;
int doWrite_CAN1_TIMEOUTS(u_int32_t value);
int addWrite_CAN1_TIMEOUTS(u_int32_t value);
int getStatus_CAN1_TIMEOUTS();
 
#define ID_CAN1_COMM_ERRORS 5046
extern u_int32_t CAN1_COMM_ERRORS;
int doWrite_CAN1_COMM_ERRORS(u_int32_t value);
int addWrite_CAN1_COMM_ERRORS(u_int32_t value);
int getStatus_CAN1_COMM_ERRORS();
 
#define ID_CAN1_LAST_ERROR 5047
extern u_int32_t CAN1_LAST_ERROR;
int doWrite_CAN1_LAST_ERROR(u_int32_t value);
int addWrite_CAN1_LAST_ERROR(u_int32_t value);
int getStatus_CAN1_LAST_ERROR();
 
#define ID_CAN1_WRITE_QUEUE 5048
extern u_int32_t CAN1_WRITE_QUEUE;
int doWrite_CAN1_WRITE_QUEUE(u_int32_t value);
int addWrite_CAN1_WRITE_QUEUE(u_int32_t value);
int getStatus_CAN1_WRITE_QUEUE();
 
#define ID_CAN1_READ_QUEUE 5049
extern u_int32_t CAN1_READ_QUEUE;
int doWrite_CAN1_READ_QUEUE(u_int32_t value);
int addWrite_CAN1_READ_QUEUE(u_int32_t value);
int getStatus_CAN1_READ_QUEUE();
 
#define ID_TCPS_TYPE_PORT 5050
extern u_int32_t TCPS_TYPE_PORT;
int doWrite_TCPS_TYPE_PORT(u_int32_t value);
int addWrite_TCPS_TYPE_PORT(u_int32_t value);
int getStatus_TCPS_TYPE_PORT();
 
#define ID_TCPS_IP_ADDRESS 5051
extern u_int32_t TCPS_IP_ADDRESS;
int doWrite_TCPS_IP_ADDRESS(u_int32_t value);
int addWrite_TCPS_IP_ADDRESS(u_int32_t value);
int getStatus_TCPS_IP_ADDRESS();
 
#define ID_TCPS_STATUS 5052
extern u_int32_t TCPS_STATUS;
int doWrite_TCPS_STATUS(u_int32_t value);
int addWrite_TCPS_STATUS(u_int32_t value);
int getStatus_TCPS_STATUS();
 
#define ID_TCPS_READS 5053
extern u_int32_t TCPS_READS;
int doWrite_TCPS_READS(u_int32_t value);
int addWrite_TCPS_READS(u_int32_t value);
int getStatus_TCPS_READS();
 
#define ID_TCPS_WRITES 5054
extern u_int32_t TCPS_WRITES;
int doWrite_TCPS_WRITES(u_int32_t value);
int addWrite_TCPS_WRITES(u_int32_t value);
int getStatus_TCPS_WRITES();
 
#define ID_TCPS_TIMEOUTS 5055
extern u_int32_t TCPS_TIMEOUTS;
int doWrite_TCPS_TIMEOUTS(u_int32_t value);
int addWrite_TCPS_TIMEOUTS(u_int32_t value);
int getStatus_TCPS_TIMEOUTS();
 
#define ID_TCPS_COMM_ERRORS 5056
extern u_int32_t TCPS_COMM_ERRORS;
int doWrite_TCPS_COMM_ERRORS(u_int32_t value);
int addWrite_TCPS_COMM_ERRORS(u_int32_t value);
int getStatus_TCPS_COMM_ERRORS();
 
#define ID_TCPS_LAST_ERROR 5057
extern u_int32_t TCPS_LAST_ERROR;
int doWrite_TCPS_LAST_ERROR(u_int32_t value);
int addWrite_TCPS_LAST_ERROR(u_int32_t value);
int getStatus_TCPS_LAST_ERROR();
 
#define ID_TCPS_WRITE_QUEUE 5058
extern u_int32_t TCPS_WRITE_QUEUE;
int doWrite_TCPS_WRITE_QUEUE(u_int32_t value);
int addWrite_TCPS_WRITE_QUEUE(u_int32_t value);
int getStatus_TCPS_WRITE_QUEUE();
 
#define ID_TCPS_READ_QUEUE 5059
extern u_int32_t TCPS_READ_QUEUE;
int doWrite_TCPS_READ_QUEUE(u_int32_t value);
int addWrite_TCPS_READ_QUEUE(u_int32_t value);
int getStatus_TCPS_READ_QUEUE();
 
#define ID_TCP0_TYPE_PORT 5060
extern u_int32_t TCP0_TYPE_PORT;
int doWrite_TCP0_TYPE_PORT(u_int32_t value);
int addWrite_TCP0_TYPE_PORT(u_int32_t value);
int getStatus_TCP0_TYPE_PORT();
 
#define ID_TCP0_IP_ADDRESS 5061
extern u_int32_t TCP0_IP_ADDRESS;
int doWrite_TCP0_IP_ADDRESS(u_int32_t value);
int addWrite_TCP0_IP_ADDRESS(u_int32_t value);
int getStatus_TCP0_IP_ADDRESS();
 
#define ID_TCP0_STATUS 5062
extern u_int32_t TCP0_STATUS;
int doWrite_TCP0_STATUS(u_int32_t value);
int addWrite_TCP0_STATUS(u_int32_t value);
int getStatus_TCP0_STATUS();
 
#define ID_TCP0_READS 5063
extern u_int32_t TCP0_READS;
int doWrite_TCP0_READS(u_int32_t value);
int addWrite_TCP0_READS(u_int32_t value);
int getStatus_TCP0_READS();
 
#define ID_TCP0_WRITES 5064
extern u_int32_t TCP0_WRITES;
int doWrite_TCP0_WRITES(u_int32_t value);
int addWrite_TCP0_WRITES(u_int32_t value);
int getStatus_TCP0_WRITES();
 
#define ID_TCP0_TIMEOUTS 5065
extern u_int32_t TCP0_TIMEOUTS;
int doWrite_TCP0_TIMEOUTS(u_int32_t value);
int addWrite_TCP0_TIMEOUTS(u_int32_t value);
int getStatus_TCP0_TIMEOUTS();
 
#define ID_TCP0_COMM_ERRORS 5066
extern u_int32_t TCP0_COMM_ERRORS;
int doWrite_TCP0_COMM_ERRORS(u_int32_t value);
int addWrite_TCP0_COMM_ERRORS(u_int32_t value);
int getStatus_TCP0_COMM_ERRORS();
 
#define ID_TCP0_LAST_ERROR 5067
extern u_int32_t TCP0_LAST_ERROR;
int doWrite_TCP0_LAST_ERROR(u_int32_t value);
int addWrite_TCP0_LAST_ERROR(u_int32_t value);
int getStatus_TCP0_LAST_ERROR();
 
#define ID_TCP0_WRITE_QUEUE 5068
extern u_int32_t TCP0_WRITE_QUEUE;
int doWrite_TCP0_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP0_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP0_WRITE_QUEUE();
 
#define ID_TCP0_READ_QUEUE 5069
extern u_int32_t TCP0_READ_QUEUE;
int doWrite_TCP0_READ_QUEUE(u_int32_t value);
int addWrite_TCP0_READ_QUEUE(u_int32_t value);
int getStatus_TCP0_READ_QUEUE();
 
#define ID_TCP1_TYPE_PORT 5070
extern u_int32_t TCP1_TYPE_PORT;
int doWrite_TCP1_TYPE_PORT(u_int32_t value);
int addWrite_TCP1_TYPE_PORT(u_int32_t value);
int getStatus_TCP1_TYPE_PORT();
 
#define ID_TCP1_IP_ADDRESS 5071
extern u_int32_t TCP1_IP_ADDRESS;
int doWrite_TCP1_IP_ADDRESS(u_int32_t value);
int addWrite_TCP1_IP_ADDRESS(u_int32_t value);
int getStatus_TCP1_IP_ADDRESS();
 
#define ID_TCP1_STATUS 5072
extern u_int32_t TCP1_STATUS;
int doWrite_TCP1_STATUS(u_int32_t value);
int addWrite_TCP1_STATUS(u_int32_t value);
int getStatus_TCP1_STATUS();
 
#define ID_TCP1_READS 5073
extern u_int32_t TCP1_READS;
int doWrite_TCP1_READS(u_int32_t value);
int addWrite_TCP1_READS(u_int32_t value);
int getStatus_TCP1_READS();
 
#define ID_TCP1_WRITES 5074
extern u_int32_t TCP1_WRITES;
int doWrite_TCP1_WRITES(u_int32_t value);
int addWrite_TCP1_WRITES(u_int32_t value);
int getStatus_TCP1_WRITES();
 
#define ID_TCP1_TIMEOUTS 5075
extern u_int32_t TCP1_TIMEOUTS;
int doWrite_TCP1_TIMEOUTS(u_int32_t value);
int addWrite_TCP1_TIMEOUTS(u_int32_t value);
int getStatus_TCP1_TIMEOUTS();
 
#define ID_TCP1_COMM_ERRORS 5076
extern u_int32_t TCP1_COMM_ERRORS;
int doWrite_TCP1_COMM_ERRORS(u_int32_t value);
int addWrite_TCP1_COMM_ERRORS(u_int32_t value);
int getStatus_TCP1_COMM_ERRORS();
 
#define ID_TCP1_LAST_ERROR 5077
extern u_int32_t TCP1_LAST_ERROR;
int doWrite_TCP1_LAST_ERROR(u_int32_t value);
int addWrite_TCP1_LAST_ERROR(u_int32_t value);
int getStatus_TCP1_LAST_ERROR();
 
#define ID_TCP1_WRITE_QUEUE 5078
extern u_int32_t TCP1_WRITE_QUEUE;
int doWrite_TCP1_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP1_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP1_WRITE_QUEUE();
 
#define ID_TCP1_READ_QUEUE 5079
extern u_int32_t TCP1_READ_QUEUE;
int doWrite_TCP1_READ_QUEUE(u_int32_t value);
int addWrite_TCP1_READ_QUEUE(u_int32_t value);
int getStatus_TCP1_READ_QUEUE();
 
#define ID_TCP2_TYPE_PORT 5080
extern u_int32_t TCP2_TYPE_PORT;
int doWrite_TCP2_TYPE_PORT(u_int32_t value);
int addWrite_TCP2_TYPE_PORT(u_int32_t value);
int getStatus_TCP2_TYPE_PORT();
 
#define ID_TCP2_IP_ADDRESS 5081
extern u_int32_t TCP2_IP_ADDRESS;
int doWrite_TCP2_IP_ADDRESS(u_int32_t value);
int addWrite_TCP2_IP_ADDRESS(u_int32_t value);
int getStatus_TCP2_IP_ADDRESS();
 
#define ID_TCP2_STATUS 5082
extern u_int32_t TCP2_STATUS;
int doWrite_TCP2_STATUS(u_int32_t value);
int addWrite_TCP2_STATUS(u_int32_t value);
int getStatus_TCP2_STATUS();
 
#define ID_TCP2_READS 5083
extern u_int32_t TCP2_READS;
int doWrite_TCP2_READS(u_int32_t value);
int addWrite_TCP2_READS(u_int32_t value);
int getStatus_TCP2_READS();
 
#define ID_TCP2_WRITES 5084
extern u_int32_t TCP2_WRITES;
int doWrite_TCP2_WRITES(u_int32_t value);
int addWrite_TCP2_WRITES(u_int32_t value);
int getStatus_TCP2_WRITES();
 
#define ID_TCP2_TIMEOUTS 5085
extern u_int32_t TCP2_TIMEOUTS;
int doWrite_TCP2_TIMEOUTS(u_int32_t value);
int addWrite_TCP2_TIMEOUTS(u_int32_t value);
int getStatus_TCP2_TIMEOUTS();
 
#define ID_TCP2_COMM_ERRORS 5086
extern u_int32_t TCP2_COMM_ERRORS;
int doWrite_TCP2_COMM_ERRORS(u_int32_t value);
int addWrite_TCP2_COMM_ERRORS(u_int32_t value);
int getStatus_TCP2_COMM_ERRORS();
 
#define ID_TCP2_LAST_ERROR 5087
extern u_int32_t TCP2_LAST_ERROR;
int doWrite_TCP2_LAST_ERROR(u_int32_t value);
int addWrite_TCP2_LAST_ERROR(u_int32_t value);
int getStatus_TCP2_LAST_ERROR();
 
#define ID_TCP2_WRITE_QUEUE 5088
extern u_int32_t TCP2_WRITE_QUEUE;
int doWrite_TCP2_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP2_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP2_WRITE_QUEUE();
 
#define ID_TCP2_READ_QUEUE 5089
extern u_int32_t TCP2_READ_QUEUE;
int doWrite_TCP2_READ_QUEUE(u_int32_t value);
int addWrite_TCP2_READ_QUEUE(u_int32_t value);
int getStatus_TCP2_READ_QUEUE();
 
#define ID_TCP3_TYPE_PORT 5090
extern u_int32_t TCP3_TYPE_PORT;
int doWrite_TCP3_TYPE_PORT(u_int32_t value);
int addWrite_TCP3_TYPE_PORT(u_int32_t value);
int getStatus_TCP3_TYPE_PORT();
 
#define ID_TCP3_IP_ADDRESS 5091
extern u_int32_t TCP3_IP_ADDRESS;
int doWrite_TCP3_IP_ADDRESS(u_int32_t value);
int addWrite_TCP3_IP_ADDRESS(u_int32_t value);
int getStatus_TCP3_IP_ADDRESS();
 
#define ID_TCP3_STATUS 5092
extern u_int32_t TCP3_STATUS;
int doWrite_TCP3_STATUS(u_int32_t value);
int addWrite_TCP3_STATUS(u_int32_t value);
int getStatus_TCP3_STATUS();
 
#define ID_TCP3_READS 5093
extern u_int32_t TCP3_READS;
int doWrite_TCP3_READS(u_int32_t value);
int addWrite_TCP3_READS(u_int32_t value);
int getStatus_TCP3_READS();
 
#define ID_TCP3_WRITES 5094
extern u_int32_t TCP3_WRITES;
int doWrite_TCP3_WRITES(u_int32_t value);
int addWrite_TCP3_WRITES(u_int32_t value);
int getStatus_TCP3_WRITES();
 
#define ID_TCP3_TIMEOUTS 5095
extern u_int32_t TCP3_TIMEOUTS;
int doWrite_TCP3_TIMEOUTS(u_int32_t value);
int addWrite_TCP3_TIMEOUTS(u_int32_t value);
int getStatus_TCP3_TIMEOUTS();
 
#define ID_TCP3_COMM_ERRORS 5096
extern u_int32_t TCP3_COMM_ERRORS;
int doWrite_TCP3_COMM_ERRORS(u_int32_t value);
int addWrite_TCP3_COMM_ERRORS(u_int32_t value);
int getStatus_TCP3_COMM_ERRORS();
 
#define ID_TCP3_LAST_ERROR 5097
extern u_int32_t TCP3_LAST_ERROR;
int doWrite_TCP3_LAST_ERROR(u_int32_t value);
int addWrite_TCP3_LAST_ERROR(u_int32_t value);
int getStatus_TCP3_LAST_ERROR();
 
#define ID_TCP3_WRITE_QUEUE 5098
extern u_int32_t TCP3_WRITE_QUEUE;
int doWrite_TCP3_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP3_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP3_WRITE_QUEUE();
 
#define ID_TCP3_READ_QUEUE 5099
extern u_int32_t TCP3_READ_QUEUE;
int doWrite_TCP3_READ_QUEUE(u_int32_t value);
int addWrite_TCP3_READ_QUEUE(u_int32_t value);
int getStatus_TCP3_READ_QUEUE();
 
#define ID_TCP4_TYPE_PORT 5100
extern u_int32_t TCP4_TYPE_PORT;
int doWrite_TCP4_TYPE_PORT(u_int32_t value);
int addWrite_TCP4_TYPE_PORT(u_int32_t value);
int getStatus_TCP4_TYPE_PORT();
 
#define ID_TCP4_IP_ADDRESS 5101
extern u_int32_t TCP4_IP_ADDRESS;
int doWrite_TCP4_IP_ADDRESS(u_int32_t value);
int addWrite_TCP4_IP_ADDRESS(u_int32_t value);
int getStatus_TCP4_IP_ADDRESS();
 
#define ID_TCP4_STATUS 5102
extern u_int32_t TCP4_STATUS;
int doWrite_TCP4_STATUS(u_int32_t value);
int addWrite_TCP4_STATUS(u_int32_t value);
int getStatus_TCP4_STATUS();
 
#define ID_TCP4_READS 5103
extern u_int32_t TCP4_READS;
int doWrite_TCP4_READS(u_int32_t value);
int addWrite_TCP4_READS(u_int32_t value);
int getStatus_TCP4_READS();
 
#define ID_TCP4_WRITES 5104
extern u_int32_t TCP4_WRITES;
int doWrite_TCP4_WRITES(u_int32_t value);
int addWrite_TCP4_WRITES(u_int32_t value);
int getStatus_TCP4_WRITES();
 
#define ID_TCP4_TIMEOUTS 5105
extern u_int32_t TCP4_TIMEOUTS;
int doWrite_TCP4_TIMEOUTS(u_int32_t value);
int addWrite_TCP4_TIMEOUTS(u_int32_t value);
int getStatus_TCP4_TIMEOUTS();
 
#define ID_TCP4_COMM_ERRORS 5106
extern u_int32_t TCP4_COMM_ERRORS;
int doWrite_TCP4_COMM_ERRORS(u_int32_t value);
int addWrite_TCP4_COMM_ERRORS(u_int32_t value);
int getStatus_TCP4_COMM_ERRORS();
 
#define ID_TCP4_LAST_ERROR 5107
extern u_int32_t TCP4_LAST_ERROR;
int doWrite_TCP4_LAST_ERROR(u_int32_t value);
int addWrite_TCP4_LAST_ERROR(u_int32_t value);
int getStatus_TCP4_LAST_ERROR();
 
#define ID_TCP4_WRITE_QUEUE 5108
extern u_int32_t TCP4_WRITE_QUEUE;
int doWrite_TCP4_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP4_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP4_WRITE_QUEUE();
 
#define ID_TCP4_READ_QUEUE 5109
extern u_int32_t TCP4_READ_QUEUE;
int doWrite_TCP4_READ_QUEUE(u_int32_t value);
int addWrite_TCP4_READ_QUEUE(u_int32_t value);
int getStatus_TCP4_READ_QUEUE();
 
#define ID_TCP5_TYPE_PORT 5110
extern u_int32_t TCP5_TYPE_PORT;
int doWrite_TCP5_TYPE_PORT(u_int32_t value);
int addWrite_TCP5_TYPE_PORT(u_int32_t value);
int getStatus_TCP5_TYPE_PORT();
 
#define ID_TCP5_IP_ADDRESS 5111
extern u_int32_t TCP5_IP_ADDRESS;
int doWrite_TCP5_IP_ADDRESS(u_int32_t value);
int addWrite_TCP5_IP_ADDRESS(u_int32_t value);
int getStatus_TCP5_IP_ADDRESS();
 
#define ID_TCP5_STATUS 5112
extern u_int32_t TCP5_STATUS;
int doWrite_TCP5_STATUS(u_int32_t value);
int addWrite_TCP5_STATUS(u_int32_t value);
int getStatus_TCP5_STATUS();
 
#define ID_TCP5_READS 5113
extern u_int32_t TCP5_READS;
int doWrite_TCP5_READS(u_int32_t value);
int addWrite_TCP5_READS(u_int32_t value);
int getStatus_TCP5_READS();
 
#define ID_TCP5_WRITES 5114
extern u_int32_t TCP5_WRITES;
int doWrite_TCP5_WRITES(u_int32_t value);
int addWrite_TCP5_WRITES(u_int32_t value);
int getStatus_TCP5_WRITES();
 
#define ID_TCP5_TIMEOUTS 5115
extern u_int32_t TCP5_TIMEOUTS;
int doWrite_TCP5_TIMEOUTS(u_int32_t value);
int addWrite_TCP5_TIMEOUTS(u_int32_t value);
int getStatus_TCP5_TIMEOUTS();
 
#define ID_TCP5_COMM_ERRORS 5116
extern u_int32_t TCP5_COMM_ERRORS;
int doWrite_TCP5_COMM_ERRORS(u_int32_t value);
int addWrite_TCP5_COMM_ERRORS(u_int32_t value);
int getStatus_TCP5_COMM_ERRORS();
 
#define ID_TCP5_LAST_ERROR 5117
extern u_int32_t TCP5_LAST_ERROR;
int doWrite_TCP5_LAST_ERROR(u_int32_t value);
int addWrite_TCP5_LAST_ERROR(u_int32_t value);
int getStatus_TCP5_LAST_ERROR();
 
#define ID_TCP5_WRITE_QUEUE 5118
extern u_int32_t TCP5_WRITE_QUEUE;
int doWrite_TCP5_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP5_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP5_WRITE_QUEUE();
 
#define ID_TCP5_READ_QUEUE 5119
extern u_int32_t TCP5_READ_QUEUE;
int doWrite_TCP5_READ_QUEUE(u_int32_t value);
int addWrite_TCP5_READ_QUEUE(u_int32_t value);
int getStatus_TCP5_READ_QUEUE();
 
#define ID_TCP6_TYPE_PORT 5120
extern u_int32_t TCP6_TYPE_PORT;
int doWrite_TCP6_TYPE_PORT(u_int32_t value);
int addWrite_TCP6_TYPE_PORT(u_int32_t value);
int getStatus_TCP6_TYPE_PORT();
 
#define ID_TCP6_IP_ADDRESS 5121
extern u_int32_t TCP6_IP_ADDRESS;
int doWrite_TCP6_IP_ADDRESS(u_int32_t value);
int addWrite_TCP6_IP_ADDRESS(u_int32_t value);
int getStatus_TCP6_IP_ADDRESS();
 
#define ID_TCP6_STATUS 5122
extern u_int32_t TCP6_STATUS;
int doWrite_TCP6_STATUS(u_int32_t value);
int addWrite_TCP6_STATUS(u_int32_t value);
int getStatus_TCP6_STATUS();
 
#define ID_TCP6_READS 5123
extern u_int32_t TCP6_READS;
int doWrite_TCP6_READS(u_int32_t value);
int addWrite_TCP6_READS(u_int32_t value);
int getStatus_TCP6_READS();
 
#define ID_TCP6_WRITES 5124
extern u_int32_t TCP6_WRITES;
int doWrite_TCP6_WRITES(u_int32_t value);
int addWrite_TCP6_WRITES(u_int32_t value);
int getStatus_TCP6_WRITES();
 
#define ID_TCP6_TIMEOUTS 5125
extern u_int32_t TCP6_TIMEOUTS;
int doWrite_TCP6_TIMEOUTS(u_int32_t value);
int addWrite_TCP6_TIMEOUTS(u_int32_t value);
int getStatus_TCP6_TIMEOUTS();
 
#define ID_TCP6_COMM_ERRORS 5126
extern u_int32_t TCP6_COMM_ERRORS;
int doWrite_TCP6_COMM_ERRORS(u_int32_t value);
int addWrite_TCP6_COMM_ERRORS(u_int32_t value);
int getStatus_TCP6_COMM_ERRORS();
 
#define ID_TCP6_LAST_ERROR 5127
extern u_int32_t TCP6_LAST_ERROR;
int doWrite_TCP6_LAST_ERROR(u_int32_t value);
int addWrite_TCP6_LAST_ERROR(u_int32_t value);
int getStatus_TCP6_LAST_ERROR();
 
#define ID_TCP6_WRITE_QUEUE 5128
extern u_int32_t TCP6_WRITE_QUEUE;
int doWrite_TCP6_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP6_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP6_WRITE_QUEUE();
 
#define ID_TCP6_READ_QUEUE 5129
extern u_int32_t TCP6_READ_QUEUE;
int doWrite_TCP6_READ_QUEUE(u_int32_t value);
int addWrite_TCP6_READ_QUEUE(u_int32_t value);
int getStatus_TCP6_READ_QUEUE();
 
#define ID_TCP7_TYPE_PORT 5130
extern u_int32_t TCP7_TYPE_PORT;
int doWrite_TCP7_TYPE_PORT(u_int32_t value);
int addWrite_TCP7_TYPE_PORT(u_int32_t value);
int getStatus_TCP7_TYPE_PORT();
 
#define ID_TCP7_IP_ADDRESS 5131
extern u_int32_t TCP7_IP_ADDRESS;
int doWrite_TCP7_IP_ADDRESS(u_int32_t value);
int addWrite_TCP7_IP_ADDRESS(u_int32_t value);
int getStatus_TCP7_IP_ADDRESS();
 
#define ID_TCP7_STATUS 5132
extern u_int32_t TCP7_STATUS;
int doWrite_TCP7_STATUS(u_int32_t value);
int addWrite_TCP7_STATUS(u_int32_t value);
int getStatus_TCP7_STATUS();
 
#define ID_TCP7_READS 5133
extern u_int32_t TCP7_READS;
int doWrite_TCP7_READS(u_int32_t value);
int addWrite_TCP7_READS(u_int32_t value);
int getStatus_TCP7_READS();
 
#define ID_TCP7_WRITES 5134
extern u_int32_t TCP7_WRITES;
int doWrite_TCP7_WRITES(u_int32_t value);
int addWrite_TCP7_WRITES(u_int32_t value);
int getStatus_TCP7_WRITES();
 
#define ID_TCP7_TIMEOUTS 5135
extern u_int32_t TCP7_TIMEOUTS;
int doWrite_TCP7_TIMEOUTS(u_int32_t value);
int addWrite_TCP7_TIMEOUTS(u_int32_t value);
int getStatus_TCP7_TIMEOUTS();
 
#define ID_TCP7_COMM_ERRORS 5136
extern u_int32_t TCP7_COMM_ERRORS;
int doWrite_TCP7_COMM_ERRORS(u_int32_t value);
int addWrite_TCP7_COMM_ERRORS(u_int32_t value);
int getStatus_TCP7_COMM_ERRORS();
 
#define ID_TCP7_LAST_ERROR 5137
extern u_int32_t TCP7_LAST_ERROR;
int doWrite_TCP7_LAST_ERROR(u_int32_t value);
int addWrite_TCP7_LAST_ERROR(u_int32_t value);
int getStatus_TCP7_LAST_ERROR();
 
#define ID_TCP7_WRITE_QUEUE 5138
extern u_int32_t TCP7_WRITE_QUEUE;
int doWrite_TCP7_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP7_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP7_WRITE_QUEUE();
 
#define ID_TCP7_READ_QUEUE 5139
extern u_int32_t TCP7_READ_QUEUE;
int doWrite_TCP7_READ_QUEUE(u_int32_t value);
int addWrite_TCP7_READ_QUEUE(u_int32_t value);
int getStatus_TCP7_READ_QUEUE();
 
#define ID_TCP8_TYPE_PORT 5140
extern u_int32_t TCP8_TYPE_PORT;
int doWrite_TCP8_TYPE_PORT(u_int32_t value);
int addWrite_TCP8_TYPE_PORT(u_int32_t value);
int getStatus_TCP8_TYPE_PORT();
 
#define ID_TCP8_IP_ADDRESS 5141
extern u_int32_t TCP8_IP_ADDRESS;
int doWrite_TCP8_IP_ADDRESS(u_int32_t value);
int addWrite_TCP8_IP_ADDRESS(u_int32_t value);
int getStatus_TCP8_IP_ADDRESS();
 
#define ID_TCP8_STATUS 5142
extern u_int32_t TCP8_STATUS;
int doWrite_TCP8_STATUS(u_int32_t value);
int addWrite_TCP8_STATUS(u_int32_t value);
int getStatus_TCP8_STATUS();
 
#define ID_TCP8_READS 5143
extern u_int32_t TCP8_READS;
int doWrite_TCP8_READS(u_int32_t value);
int addWrite_TCP8_READS(u_int32_t value);
int getStatus_TCP8_READS();
 
#define ID_TCP8_WRITES 5144
extern u_int32_t TCP8_WRITES;
int doWrite_TCP8_WRITES(u_int32_t value);
int addWrite_TCP8_WRITES(u_int32_t value);
int getStatus_TCP8_WRITES();
 
#define ID_TCP8_TIMEOUTS 5145
extern u_int32_t TCP8_TIMEOUTS;
int doWrite_TCP8_TIMEOUTS(u_int32_t value);
int addWrite_TCP8_TIMEOUTS(u_int32_t value);
int getStatus_TCP8_TIMEOUTS();
 
#define ID_TCP8_COMM_ERRORS 5146
extern u_int32_t TCP8_COMM_ERRORS;
int doWrite_TCP8_COMM_ERRORS(u_int32_t value);
int addWrite_TCP8_COMM_ERRORS(u_int32_t value);
int getStatus_TCP8_COMM_ERRORS();
 
#define ID_TCP8_LAST_ERROR 5147
extern u_int32_t TCP8_LAST_ERROR;
int doWrite_TCP8_LAST_ERROR(u_int32_t value);
int addWrite_TCP8_LAST_ERROR(u_int32_t value);
int getStatus_TCP8_LAST_ERROR();
 
#define ID_TCP8_WRITE_QUEUE 5148
extern u_int32_t TCP8_WRITE_QUEUE;
int doWrite_TCP8_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP8_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP8_WRITE_QUEUE();
 
#define ID_TCP8_READ_QUEUE 5149
extern u_int32_t TCP8_READ_QUEUE;
int doWrite_TCP8_READ_QUEUE(u_int32_t value);
int addWrite_TCP8_READ_QUEUE(u_int32_t value);
int getStatus_TCP8_READ_QUEUE();
 
#define ID_TCP9_TYPE_PORT 5150
extern u_int32_t TCP9_TYPE_PORT;
int doWrite_TCP9_TYPE_PORT(u_int32_t value);
int addWrite_TCP9_TYPE_PORT(u_int32_t value);
int getStatus_TCP9_TYPE_PORT();
 
#define ID_TCP9_IP_ADDRESS 5151
extern u_int32_t TCP9_IP_ADDRESS;
int doWrite_TCP9_IP_ADDRESS(u_int32_t value);
int addWrite_TCP9_IP_ADDRESS(u_int32_t value);
int getStatus_TCP9_IP_ADDRESS();
 
#define ID_TCP9_STATUS 5152
extern u_int32_t TCP9_STATUS;
int doWrite_TCP9_STATUS(u_int32_t value);
int addWrite_TCP9_STATUS(u_int32_t value);
int getStatus_TCP9_STATUS();
 
#define ID_TCP9_READS 5153
extern u_int32_t TCP9_READS;
int doWrite_TCP9_READS(u_int32_t value);
int addWrite_TCP9_READS(u_int32_t value);
int getStatus_TCP9_READS();
 
#define ID_TCP9_WRITES 5154
extern u_int32_t TCP9_WRITES;
int doWrite_TCP9_WRITES(u_int32_t value);
int addWrite_TCP9_WRITES(u_int32_t value);
int getStatus_TCP9_WRITES();
 
#define ID_TCP9_TIMEOUTS 5155
extern u_int32_t TCP9_TIMEOUTS;
int doWrite_TCP9_TIMEOUTS(u_int32_t value);
int addWrite_TCP9_TIMEOUTS(u_int32_t value);
int getStatus_TCP9_TIMEOUTS();
 
#define ID_TCP9_COMM_ERRORS 5156
extern u_int32_t TCP9_COMM_ERRORS;
int doWrite_TCP9_COMM_ERRORS(u_int32_t value);
int addWrite_TCP9_COMM_ERRORS(u_int32_t value);
int getStatus_TCP9_COMM_ERRORS();
 
#define ID_TCP9_LAST_ERROR 5157
extern u_int32_t TCP9_LAST_ERROR;
int doWrite_TCP9_LAST_ERROR(u_int32_t value);
int addWrite_TCP9_LAST_ERROR(u_int32_t value);
int getStatus_TCP9_LAST_ERROR();
 
#define ID_TCP9_WRITE_QUEUE 5158
extern u_int32_t TCP9_WRITE_QUEUE;
int doWrite_TCP9_WRITE_QUEUE(u_int32_t value);
int addWrite_TCP9_WRITE_QUEUE(u_int32_t value);
int getStatus_TCP9_WRITE_QUEUE();
 
#define ID_TCP9_READ_QUEUE 5159
extern u_int32_t TCP9_READ_QUEUE;
int doWrite_TCP9_READ_QUEUE(u_int32_t value);
int addWrite_TCP9_READ_QUEUE(u_int32_t value);
int getStatus_TCP9_READ_QUEUE();
 
#define ID_NODE_01_DEV_NODE 5172
extern u_int32_t NODE_01_DEV_NODE;
int doWrite_NODE_01_DEV_NODE(u_int32_t value);
int addWrite_NODE_01_DEV_NODE(u_int32_t value);
int getStatus_NODE_01_DEV_NODE();
 
#define ID_NODE_01_STATUS 5173
extern u_int32_t NODE_01_STATUS;
int doWrite_NODE_01_STATUS(u_int32_t value);
int addWrite_NODE_01_STATUS(u_int32_t value);
int getStatus_NODE_01_STATUS();
 
#define ID_NODE_02_DEV_NODE 5174
extern u_int32_t NODE_02_DEV_NODE;
int doWrite_NODE_02_DEV_NODE(u_int32_t value);
int addWrite_NODE_02_DEV_NODE(u_int32_t value);
int getStatus_NODE_02_DEV_NODE();
 
#define ID_NODE_02_STATUS 5175
extern u_int32_t NODE_02_STATUS;
int doWrite_NODE_02_STATUS(u_int32_t value);
int addWrite_NODE_02_STATUS(u_int32_t value);
int getStatus_NODE_02_STATUS();
 
#define ID_NODE_03_DEV_NODE 5176
extern u_int32_t NODE_03_DEV_NODE;
int doWrite_NODE_03_DEV_NODE(u_int32_t value);
int addWrite_NODE_03_DEV_NODE(u_int32_t value);
int getStatus_NODE_03_DEV_NODE();
 
#define ID_NODE_03_STATUS 5177
extern u_int32_t NODE_03_STATUS;
int doWrite_NODE_03_STATUS(u_int32_t value);
int addWrite_NODE_03_STATUS(u_int32_t value);
int getStatus_NODE_03_STATUS();
 
#define ID_NODE_04_DEV_NODE 5178
extern u_int32_t NODE_04_DEV_NODE;
int doWrite_NODE_04_DEV_NODE(u_int32_t value);
int addWrite_NODE_04_DEV_NODE(u_int32_t value);
int getStatus_NODE_04_DEV_NODE();
 
#define ID_NODE_04_STATUS 5179
extern u_int32_t NODE_04_STATUS;
int doWrite_NODE_04_STATUS(u_int32_t value);
int addWrite_NODE_04_STATUS(u_int32_t value);
int getStatus_NODE_04_STATUS();
 
#define ID_NODE_05_DEV_NODE 5180
extern u_int32_t NODE_05_DEV_NODE;
int doWrite_NODE_05_DEV_NODE(u_int32_t value);
int addWrite_NODE_05_DEV_NODE(u_int32_t value);
int getStatus_NODE_05_DEV_NODE();
 
#define ID_NODE_05_STATUS 5181
extern u_int32_t NODE_05_STATUS;
int doWrite_NODE_05_STATUS(u_int32_t value);
int addWrite_NODE_05_STATUS(u_int32_t value);
int getStatus_NODE_05_STATUS();
 
#define ID_NODE_06_DEV_NODE 5182
extern u_int32_t NODE_06_DEV_NODE;
int doWrite_NODE_06_DEV_NODE(u_int32_t value);
int addWrite_NODE_06_DEV_NODE(u_int32_t value);
int getStatus_NODE_06_DEV_NODE();
 
#define ID_NODE_06_STATUS 5183
extern u_int32_t NODE_06_STATUS;
int doWrite_NODE_06_STATUS(u_int32_t value);
int addWrite_NODE_06_STATUS(u_int32_t value);
int getStatus_NODE_06_STATUS();
 
#define ID_NODE_07_DEV_NODE 5184
extern u_int32_t NODE_07_DEV_NODE;
int doWrite_NODE_07_DEV_NODE(u_int32_t value);
int addWrite_NODE_07_DEV_NODE(u_int32_t value);
int getStatus_NODE_07_DEV_NODE();
 
#define ID_NODE_07_STATUS 5185
extern u_int32_t NODE_07_STATUS;
int doWrite_NODE_07_STATUS(u_int32_t value);
int addWrite_NODE_07_STATUS(u_int32_t value);
int getStatus_NODE_07_STATUS();
 
#define ID_NODE_08_DEV_NODE 5186
extern u_int32_t NODE_08_DEV_NODE;
int doWrite_NODE_08_DEV_NODE(u_int32_t value);
int addWrite_NODE_08_DEV_NODE(u_int32_t value);
int getStatus_NODE_08_DEV_NODE();
 
#define ID_NODE_08_STATUS 5187
extern u_int32_t NODE_08_STATUS;
int doWrite_NODE_08_STATUS(u_int32_t value);
int addWrite_NODE_08_STATUS(u_int32_t value);
int getStatus_NODE_08_STATUS();
 
#define ID_NODE_09_DEV_NODE 5188
extern u_int32_t NODE_09_DEV_NODE;
int doWrite_NODE_09_DEV_NODE(u_int32_t value);
int addWrite_NODE_09_DEV_NODE(u_int32_t value);
int getStatus_NODE_09_DEV_NODE();
 
#define ID_NODE_09_STATUS 5189
extern u_int32_t NODE_09_STATUS;
int doWrite_NODE_09_STATUS(u_int32_t value);
int addWrite_NODE_09_STATUS(u_int32_t value);
int getStatus_NODE_09_STATUS();
 
#define ID_NODE_10_DEV_NODE 5190
extern u_int32_t NODE_10_DEV_NODE;
int doWrite_NODE_10_DEV_NODE(u_int32_t value);
int addWrite_NODE_10_DEV_NODE(u_int32_t value);
int getStatus_NODE_10_DEV_NODE();
 
#define ID_NODE_10_STATUS 5191
extern u_int32_t NODE_10_STATUS;
int doWrite_NODE_10_STATUS(u_int32_t value);
int addWrite_NODE_10_STATUS(u_int32_t value);
int getStatus_NODE_10_STATUS();
 
#define ID_NODE_11_DEV_NODE 5192
extern u_int32_t NODE_11_DEV_NODE;
int doWrite_NODE_11_DEV_NODE(u_int32_t value);
int addWrite_NODE_11_DEV_NODE(u_int32_t value);
int getStatus_NODE_11_DEV_NODE();
 
#define ID_NODE_11_STATUS 5193
extern u_int32_t NODE_11_STATUS;
int doWrite_NODE_11_STATUS(u_int32_t value);
int addWrite_NODE_11_STATUS(u_int32_t value);
int getStatus_NODE_11_STATUS();
 
#define ID_NODE_12_DEV_NODE 5194
extern u_int32_t NODE_12_DEV_NODE;
int doWrite_NODE_12_DEV_NODE(u_int32_t value);
int addWrite_NODE_12_DEV_NODE(u_int32_t value);
int getStatus_NODE_12_DEV_NODE();
 
#define ID_NODE_12_STATUS 5195
extern u_int32_t NODE_12_STATUS;
int doWrite_NODE_12_STATUS(u_int32_t value);
int addWrite_NODE_12_STATUS(u_int32_t value);
int getStatus_NODE_12_STATUS();
 
#define ID_NODE_13_DEV_NODE 5196
extern u_int32_t NODE_13_DEV_NODE;
int doWrite_NODE_13_DEV_NODE(u_int32_t value);
int addWrite_NODE_13_DEV_NODE(u_int32_t value);
int getStatus_NODE_13_DEV_NODE();
 
#define ID_NODE_13_STATUS 5197
extern u_int32_t NODE_13_STATUS;
int doWrite_NODE_13_STATUS(u_int32_t value);
int addWrite_NODE_13_STATUS(u_int32_t value);
int getStatus_NODE_13_STATUS();
 
#define ID_NODE_14_DEV_NODE 5198
extern u_int32_t NODE_14_DEV_NODE;
int doWrite_NODE_14_DEV_NODE(u_int32_t value);
int addWrite_NODE_14_DEV_NODE(u_int32_t value);
int getStatus_NODE_14_DEV_NODE();
 
#define ID_NODE_14_STATUS 5199
extern u_int32_t NODE_14_STATUS;
int doWrite_NODE_14_STATUS(u_int32_t value);
int addWrite_NODE_14_STATUS(u_int32_t value);
int getStatus_NODE_14_STATUS();
 
#define ID_NODE_15_DEV_NODE 5200
extern u_int32_t NODE_15_DEV_NODE;
int doWrite_NODE_15_DEV_NODE(u_int32_t value);
int addWrite_NODE_15_DEV_NODE(u_int32_t value);
int getStatus_NODE_15_DEV_NODE();
 
#define ID_NODE_15_STATUS 5201
extern u_int32_t NODE_15_STATUS;
int doWrite_NODE_15_STATUS(u_int32_t value);
int addWrite_NODE_15_STATUS(u_int32_t value);
int getStatus_NODE_15_STATUS();
 
#define ID_NODE_16_DEV_NODE 5202
extern u_int32_t NODE_16_DEV_NODE;
int doWrite_NODE_16_DEV_NODE(u_int32_t value);
int addWrite_NODE_16_DEV_NODE(u_int32_t value);
int getStatus_NODE_16_DEV_NODE();
 
#define ID_NODE_16_STATUS 5203
extern u_int32_t NODE_16_STATUS;
int doWrite_NODE_16_STATUS(u_int32_t value);
int addWrite_NODE_16_STATUS(u_int32_t value);
int getStatus_NODE_16_STATUS();
 
#define ID_NODE_17_DEV_NODE 5204
extern u_int32_t NODE_17_DEV_NODE;
int doWrite_NODE_17_DEV_NODE(u_int32_t value);
int addWrite_NODE_17_DEV_NODE(u_int32_t value);
int getStatus_NODE_17_DEV_NODE();
 
#define ID_NODE_17_STATUS 5205
extern u_int32_t NODE_17_STATUS;
int doWrite_NODE_17_STATUS(u_int32_t value);
int addWrite_NODE_17_STATUS(u_int32_t value);
int getStatus_NODE_17_STATUS();
 
#define ID_NODE_18_DEV_NODE 5206
extern u_int32_t NODE_18_DEV_NODE;
int doWrite_NODE_18_DEV_NODE(u_int32_t value);
int addWrite_NODE_18_DEV_NODE(u_int32_t value);
int getStatus_NODE_18_DEV_NODE();
 
#define ID_NODE_18_STATUS 5207
extern u_int32_t NODE_18_STATUS;
int doWrite_NODE_18_STATUS(u_int32_t value);
int addWrite_NODE_18_STATUS(u_int32_t value);
int getStatus_NODE_18_STATUS();
 
#define ID_NODE_19_DEV_NODE 5208
extern u_int32_t NODE_19_DEV_NODE;
int doWrite_NODE_19_DEV_NODE(u_int32_t value);
int addWrite_NODE_19_DEV_NODE(u_int32_t value);
int getStatus_NODE_19_DEV_NODE();
 
#define ID_NODE_19_STATUS 5209
extern u_int32_t NODE_19_STATUS;
int doWrite_NODE_19_STATUS(u_int32_t value);
int addWrite_NODE_19_STATUS(u_int32_t value);
int getStatus_NODE_19_STATUS();
 
#define ID_NODE_20_DEV_NODE 5210
extern u_int32_t NODE_20_DEV_NODE;
int doWrite_NODE_20_DEV_NODE(u_int32_t value);
int addWrite_NODE_20_DEV_NODE(u_int32_t value);
int getStatus_NODE_20_DEV_NODE();
 
#define ID_NODE_20_STATUS 5211
extern u_int32_t NODE_20_STATUS;
int doWrite_NODE_20_STATUS(u_int32_t value);
int addWrite_NODE_20_STATUS(u_int32_t value);
int getStatus_NODE_20_STATUS();
 
#define ID_NODE_21_DEV_NODE 5212
extern u_int32_t NODE_21_DEV_NODE;
int doWrite_NODE_21_DEV_NODE(u_int32_t value);
int addWrite_NODE_21_DEV_NODE(u_int32_t value);
int getStatus_NODE_21_DEV_NODE();
 
#define ID_NODE_21_STATUS 5213
extern u_int32_t NODE_21_STATUS;
int doWrite_NODE_21_STATUS(u_int32_t value);
int addWrite_NODE_21_STATUS(u_int32_t value);
int getStatus_NODE_21_STATUS();
 
#define ID_NODE_22_DEV_NODE 5214
extern u_int32_t NODE_22_DEV_NODE;
int doWrite_NODE_22_DEV_NODE(u_int32_t value);
int addWrite_NODE_22_DEV_NODE(u_int32_t value);
int getStatus_NODE_22_DEV_NODE();
 
#define ID_NODE_22_STATUS 5215
extern u_int32_t NODE_22_STATUS;
int doWrite_NODE_22_STATUS(u_int32_t value);
int addWrite_NODE_22_STATUS(u_int32_t value);
int getStatus_NODE_22_STATUS();
 
#define ID_NODE_23_DEV_NODE 5216
extern u_int32_t NODE_23_DEV_NODE;
int doWrite_NODE_23_DEV_NODE(u_int32_t value);
int addWrite_NODE_23_DEV_NODE(u_int32_t value);
int getStatus_NODE_23_DEV_NODE();
 
#define ID_NODE_23_STATUS 5217
extern u_int32_t NODE_23_STATUS;
int doWrite_NODE_23_STATUS(u_int32_t value);
int addWrite_NODE_23_STATUS(u_int32_t value);
int getStatus_NODE_23_STATUS();
 
#define ID_NODE_24_DEV_NODE 5218
extern u_int32_t NODE_24_DEV_NODE;
int doWrite_NODE_24_DEV_NODE(u_int32_t value);
int addWrite_NODE_24_DEV_NODE(u_int32_t value);
int getStatus_NODE_24_DEV_NODE();
 
#define ID_NODE_24_STATUS 5219
extern u_int32_t NODE_24_STATUS;
int doWrite_NODE_24_STATUS(u_int32_t value);
int addWrite_NODE_24_STATUS(u_int32_t value);
int getStatus_NODE_24_STATUS();
 
#define ID_PLC_DigIn_1 5300
extern int PLC_DigIn_1;
int doWrite_PLC_DigIn_1(int value);
int addWrite_PLC_DigIn_1(int value);
int getStatus_PLC_DigIn_1();
 
#define ID_PLC_DigIn_2 5301
extern int PLC_DigIn_2;
int doWrite_PLC_DigIn_2(int value);
int addWrite_PLC_DigIn_2(int value);
int getStatus_PLC_DigIn_2();
 
#define ID_PLC_DigIn_3 5302
extern int PLC_DigIn_3;
int doWrite_PLC_DigIn_3(int value);
int addWrite_PLC_DigIn_3(int value);
int getStatus_PLC_DigIn_3();
 
#define ID_PLC_DigIn_4 5303
extern int PLC_DigIn_4;
int doWrite_PLC_DigIn_4(int value);
int addWrite_PLC_DigIn_4(int value);
int getStatus_PLC_DigIn_4();
 
#define ID_PLC_DigIn_5 5304
extern int PLC_DigIn_5;
int doWrite_PLC_DigIn_5(int value);
int addWrite_PLC_DigIn_5(int value);
int getStatus_PLC_DigIn_5();
 
#define ID_PLC_DigIn_6 5305
extern int PLC_DigIn_6;
int doWrite_PLC_DigIn_6(int value);
int addWrite_PLC_DigIn_6(int value);
int getStatus_PLC_DigIn_6();
 
#define ID_PLC_DigIn_7 5306
extern int PLC_DigIn_7;
int doWrite_PLC_DigIn_7(int value);
int addWrite_PLC_DigIn_7(int value);
int getStatus_PLC_DigIn_7();
 
#define ID_PLC_DigIn_8 5307
extern int PLC_DigIn_8;
int doWrite_PLC_DigIn_8(int value);
int addWrite_PLC_DigIn_8(int value);
int getStatus_PLC_DigIn_8();
 
#define ID_PLC_Reserved_1 5308
extern int PLC_Reserved_1;
int doWrite_PLC_Reserved_1(int value);
int addWrite_PLC_Reserved_1(int value);
int getStatus_PLC_Reserved_1();
 
#define ID_PLC_DigOut_1 5309
extern int PLC_DigOut_1;
int doWrite_PLC_DigOut_1(int value);
int addWrite_PLC_DigOut_1(int value);
int getStatus_PLC_DigOut_1();
 
#define ID_PLC_DigOut_2 5310
extern int PLC_DigOut_2;
int doWrite_PLC_DigOut_2(int value);
int addWrite_PLC_DigOut_2(int value);
int getStatus_PLC_DigOut_2();
 
#define ID_PLC_DigOut_3 5311
extern int PLC_DigOut_3;
int doWrite_PLC_DigOut_3(int value);
int addWrite_PLC_DigOut_3(int value);
int getStatus_PLC_DigOut_3();
 
#define ID_PLC_DigOut_4 5312
extern int PLC_DigOut_4;
int doWrite_PLC_DigOut_4(int value);
int addWrite_PLC_DigOut_4(int value);
int getStatus_PLC_DigOut_4();
 
#define ID_PLC_DigOut_5 5313
extern int PLC_DigOut_5;
int doWrite_PLC_DigOut_5(int value);
int addWrite_PLC_DigOut_5(int value);
int getStatus_PLC_DigOut_5();
 
#define ID_PLC_DigOut_6 5314
extern int PLC_DigOut_6;
int doWrite_PLC_DigOut_6(int value);
int addWrite_PLC_DigOut_6(int value);
int getStatus_PLC_DigOut_6();
 
#define ID_PLC_DigOut_7 5315
extern int PLC_DigOut_7;
int doWrite_PLC_DigOut_7(int value);
int addWrite_PLC_DigOut_7(int value);
int getStatus_PLC_DigOut_7();
 
#define ID_PLC_DigOut_8 5316
extern int PLC_DigOut_8;
int doWrite_PLC_DigOut_8(int value);
int addWrite_PLC_DigOut_8(int value);
int getStatus_PLC_DigOut_8();
 
#define ID_PLC_DigOut_9 5317
extern int PLC_DigOut_9;
int doWrite_PLC_DigOut_9(int value);
int addWrite_PLC_DigOut_9(int value);
int getStatus_PLC_DigOut_9();
 
#define ID_PLC_DigOut_10 5318
extern int PLC_DigOut_10;
int doWrite_PLC_DigOut_10(int value);
int addWrite_PLC_DigOut_10(int value);
int getStatus_PLC_DigOut_10();
 
#define ID_PLC_DigOut_11 5319
extern int PLC_DigOut_11;
int doWrite_PLC_DigOut_11(int value);
int addWrite_PLC_DigOut_11(int value);
int getStatus_PLC_DigOut_11();
 
#define ID_PLC_DigOut_12 5320
extern int PLC_DigOut_12;
int doWrite_PLC_DigOut_12(int value);
int addWrite_PLC_DigOut_12(int value);
int getStatus_PLC_DigOut_12();
 
#define ID_PLC_Hwconf 5321
extern u_int16_t PLC_Hwconf;
int doWrite_PLC_Hwconf(u_int16_t value);
int addWrite_PLC_Hwconf(u_int16_t value);
int getStatus_PLC_Hwconf();
 
#define ID_PLC_Revisione 5322
extern u_int16_t PLC_Revisione;
int doWrite_PLC_Revisione(u_int16_t value);
int addWrite_PLC_Revisione(u_int16_t value);
int getStatus_PLC_Revisione();
 
#define ID_PLC_StatusReg 5323
extern u_int16_t PLC_StatusReg;
int doWrite_PLC_StatusReg(u_int16_t value);
int addWrite_PLC_StatusReg(u_int16_t value);
int getStatus_PLC_StatusReg();
 
#define ID_PLC_Heartbeat 5324
extern u_int16_t PLC_Heartbeat;
int doWrite_PLC_Heartbeat(u_int16_t value);
int addWrite_PLC_Heartbeat(u_int16_t value);
int getStatus_PLC_Heartbeat();
 
#define ID_PLC_AnIn_1 5325
extern int16_t PLC_AnIn_1;
int doWrite_PLC_AnIn_1(int16_t value);
int addWrite_PLC_AnIn_1(int16_t value);
int getStatus_PLC_AnIn_1();
 
#define ID_PLC_AnIn_2 5326
extern int16_t PLC_AnIn_2;
int doWrite_PLC_AnIn_2(int16_t value);
int addWrite_PLC_AnIn_2(int16_t value);
int getStatus_PLC_AnIn_2();
 
#define ID_PLC_AnIn_3 5327
extern int16_t PLC_AnIn_3;
int doWrite_PLC_AnIn_3(int16_t value);
int addWrite_PLC_AnIn_3(int16_t value);
int getStatus_PLC_AnIn_3();
 
#define ID_PLC_AnIn_4 5328
extern int16_t PLC_AnIn_4;
int doWrite_PLC_AnIn_4(int16_t value);
int addWrite_PLC_AnIn_4(int16_t value);
int getStatus_PLC_AnIn_4();
 
#define ID_PLC_EncoderCo_Lo 5329
extern u_int16_t PLC_EncoderCo_Lo;
int doWrite_PLC_EncoderCo_Lo(u_int16_t value);
int addWrite_PLC_EncoderCo_Lo(u_int16_t value);
int getStatus_PLC_EncoderCo_Lo();
 
#define ID_PLC_EncoderCo_Hi 5330
extern u_int16_t PLC_EncoderCo_Hi;
int doWrite_PLC_EncoderCo_Hi(u_int16_t value);
int addWrite_PLC_EncoderCo_Hi(u_int16_t value);
int getStatus_PLC_EncoderCo_Hi();
 
#define ID_PLC_CaptureT1_Lo 5331
extern u_int16_t PLC_CaptureT1_Lo;
int doWrite_PLC_CaptureT1_Lo(u_int16_t value);
int addWrite_PLC_CaptureT1_Lo(u_int16_t value);
int getStatus_PLC_CaptureT1_Lo();
 
#define ID_PLC_CaptureT1_Hi 5332
extern u_int16_t PLC_CaptureT1_Hi;
int doWrite_PLC_CaptureT1_Hi(u_int16_t value);
int addWrite_PLC_CaptureT1_Hi(u_int16_t value);
int getStatus_PLC_CaptureT1_Hi();
 
#define ID_PLC_CaptureT2_Lo 5333
extern u_int16_t PLC_CaptureT2_Lo;
int doWrite_PLC_CaptureT2_Lo(u_int16_t value);
int addWrite_PLC_CaptureT2_Lo(u_int16_t value);
int getStatus_PLC_CaptureT2_Lo();
 
#define ID_PLC_CaptureT2_Hi 5334
extern u_int16_t PLC_CaptureT2_Hi;
int doWrite_PLC_CaptureT2_Hi(u_int16_t value);
int addWrite_PLC_CaptureT2_Hi(u_int16_t value);
int getStatus_PLC_CaptureT2_Hi();
 
#define ID_PLC_RPM 5335
extern u_int16_t PLC_RPM;
int doWrite_PLC_RPM(u_int16_t value);
int addWrite_PLC_RPM(u_int16_t value);
int getStatus_PLC_RPM();
 
#define ID_PLC_Tamb 5336
extern int16_t PLC_Tamb;
int doWrite_PLC_Tamb(int16_t value);
int addWrite_PLC_Tamb(int16_t value);
int getStatus_PLC_Tamb();
 
#define ID_PLC_EnableEnc 5337
extern u_int16_t PLC_EnableEnc;
int doWrite_PLC_EnableEnc(u_int16_t value);
int addWrite_PLC_EnableEnc(u_int16_t value);
int getStatus_PLC_EnableEnc();
 
#define ID_PLC_ResetCount 5338
extern u_int16_t PLC_ResetCount;
int doWrite_PLC_ResetCount(u_int16_t value);
int addWrite_PLC_ResetCount(u_int16_t value);
int getStatus_PLC_ResetCount();
 
#define ID_PLC_AnInConf_1 5339
extern u_int16_t PLC_AnInConf_1;
int doWrite_PLC_AnInConf_1(u_int16_t value);
int addWrite_PLC_AnInConf_1(u_int16_t value);
int getStatus_PLC_AnInConf_1();
 
#define ID_PLC_AnInConf_2 5340
extern u_int16_t PLC_AnInConf_2;
int doWrite_PLC_AnInConf_2(u_int16_t value);
int addWrite_PLC_AnInConf_2(u_int16_t value);
int getStatus_PLC_AnInConf_2();
 
#define ID_PLC_AnInConf_3 5341
extern u_int16_t PLC_AnInConf_3;
int doWrite_PLC_AnInConf_3(u_int16_t value);
int addWrite_PLC_AnInConf_3(u_int16_t value);
int getStatus_PLC_AnInConf_3();
 
#define ID_PLC_AnInConf_4 5342
extern u_int16_t PLC_AnInConf_4;
int doWrite_PLC_AnInConf_4(u_int16_t value);
int addWrite_PLC_AnInConf_4(u_int16_t value);
int getStatus_PLC_AnInConf_4();
 
#define ID_PLC_AnOutConf_1 5343
extern u_int16_t PLC_AnOutConf_1;
int doWrite_PLC_AnOutConf_1(u_int16_t value);
int addWrite_PLC_AnOutConf_1(u_int16_t value);
int getStatus_PLC_AnOutConf_1();
 
#define ID_PLC_AnOutConf_2 5344
extern u_int16_t PLC_AnOutConf_2;
int doWrite_PLC_AnOutConf_2(u_int16_t value);
int addWrite_PLC_AnOutConf_2(u_int16_t value);
int getStatus_PLC_AnOutConf_2();
 
#define ID_PLC_Reserved_2 5345
extern u_int16_t PLC_Reserved_2;
int doWrite_PLC_Reserved_2(u_int16_t value);
int addWrite_PLC_Reserved_2(u_int16_t value);
int getStatus_PLC_Reserved_2();
 
#define ID_PLC_Reserved_3 5346
extern u_int16_t PLC_Reserved_3;
int doWrite_PLC_Reserved_3(u_int16_t value);
int addWrite_PLC_Reserved_3(u_int16_t value);
int getStatus_PLC_Reserved_3();
 
#define ID_PLC_AnOut_1 5347
extern int16_t PLC_AnOut_1;
int doWrite_PLC_AnOut_1(int16_t value);
int addWrite_PLC_AnOut_1(int16_t value);
int getStatus_PLC_AnOut_1();
 
#define ID_PLC_AnOut_2 5348
extern int16_t PLC_AnOut_2;
int doWrite_PLC_AnOut_2(int16_t value);
int addWrite_PLC_AnOut_2(int16_t value);
int getStatus_PLC_AnOut_2();
 
#define ID_PLC_Reserved_4 5349
extern int16_t PLC_Reserved_4;
int doWrite_PLC_Reserved_4(int16_t value);
int addWrite_PLC_Reserved_4(int16_t value);
int getStatus_PLC_Reserved_4();
 
#define ID_PLC_Reserved_5 5350
extern int16_t PLC_Reserved_5;
int doWrite_PLC_Reserved_5(int16_t value);
int addWrite_PLC_Reserved_5(int16_t value);
int getStatus_PLC_Reserved_5();
 
#define ID_PLC_FiltAnIn_1 5351
extern u_int16_t PLC_FiltAnIn_1;
int doWrite_PLC_FiltAnIn_1(u_int16_t value);
int addWrite_PLC_FiltAnIn_1(u_int16_t value);
int getStatus_PLC_FiltAnIn_1();
 
#define ID_PLC_FiltAnIn_2 5352
extern u_int16_t PLC_FiltAnIn_2;
int doWrite_PLC_FiltAnIn_2(u_int16_t value);
int addWrite_PLC_FiltAnIn_2(u_int16_t value);
int getStatus_PLC_FiltAnIn_2();
 
#define ID_PLC_FiltAnIn_3 5353
extern u_int16_t PLC_FiltAnIn_3;
int doWrite_PLC_FiltAnIn_3(u_int16_t value);
int addWrite_PLC_FiltAnIn_3(u_int16_t value);
int getStatus_PLC_FiltAnIn_3();
 
#define ID_PLC_FiltAnIn_4 5354
extern u_int16_t PLC_FiltAnIn_4;
int doWrite_PLC_FiltAnIn_4(u_int16_t value);
int addWrite_PLC_FiltAnIn_4(u_int16_t value);
int getStatus_PLC_FiltAnIn_4();
 
#define ID_CH0_NETRUN 5357
extern int CH0_NETRUN;
int doWrite_CH0_NETRUN(int value);
int addWrite_CH0_NETRUN(int value);
int getStatus_CH0_NETRUN();
 
#define ID_CH0_NETGOOD 5358
extern int CH0_NETGOOD;
int doWrite_CH0_NETGOOD(int value);
int addWrite_CH0_NETGOOD(int value);
int getStatus_CH0_NETGOOD();
 
#define ID_CH0_NETERR 5359
extern u_int32_t CH0_NETERR;
int doWrite_CH0_NETERR(u_int32_t value);
int addWrite_CH0_NETERR(u_int32_t value);
int getStatus_CH0_NETERR();
 
#define ID_CH0_NETRST 5360
extern int CH0_NETRST;
int doWrite_CH0_NETRST(int value);
int addWrite_CH0_NETRST(int value);
int getStatus_CH0_NETRST();
 
#define ID_CH0_NETDIS 5361
extern int CH0_NETDIS;
int doWrite_CH0_NETDIS(int value);
int addWrite_CH0_NETDIS(int value);
int getStatus_CH0_NETDIS();
 
#define ID_CH0_01_NODERUN 5362
extern int CH0_01_NODERUN;
int doWrite_CH0_01_NODERUN(int value);
int addWrite_CH0_01_NODERUN(int value);
int getStatus_CH0_01_NODERUN();
 
#define ID_CH0_01_NODEGOOD 5363
extern int CH0_01_NODEGOOD;
int doWrite_CH0_01_NODEGOOD(int value);
int addWrite_CH0_01_NODEGOOD(int value);
int getStatus_CH0_01_NODEGOOD();
 
#define ID_CH0_01_NODEERR 5364
extern u_int32_t CH0_01_NODEERR;
int doWrite_CH0_01_NODEERR(u_int32_t value);
int addWrite_CH0_01_NODEERR(u_int32_t value);
int getStatus_CH0_01_NODEERR();
 
#define ID_CH0_01_NODERST 5365
extern int CH0_01_NODERST;
int doWrite_CH0_01_NODERST(int value);
int addWrite_CH0_01_NODERST(int value);
int getStatus_CH0_01_NODERST();
 
#define ID_CH0_01_NODEDIS 5366
extern int CH0_01_NODEDIS;
int doWrite_CH0_01_NODEDIS(int value);
int addWrite_CH0_01_NODEDIS(int value);
int getStatus_CH0_01_NODEDIS();
 
#define ID_PLC_time 5390
extern float PLC_time;
int doWrite_PLC_time(float value);
int addWrite_PLC_time(float value);
int getStatus_PLC_time();
 
#define ID_PLC_timeMin 5391
extern float PLC_timeMin;
int doWrite_PLC_timeMin(float value);
int addWrite_PLC_timeMin(float value);
int getStatus_PLC_timeMin();
 
#define ID_PLC_timeMax 5392
extern float PLC_timeMax;
int doWrite_PLC_timeMax(float value);
int addWrite_PLC_timeMax(float value);
int getStatus_PLC_timeMax();
 
#define ID_PLC_timeWin 5393
extern float PLC_timeWin;
int doWrite_PLC_timeWin(float value);
int addWrite_PLC_timeWin(float value);
int getStatus_PLC_timeWin();
 
#define ID_PLC_Version 5394
extern u_int16_t PLC_Version;
int doWrite_PLC_Version(u_int16_t value);
int addWrite_PLC_Version(u_int16_t value);
int getStatus_PLC_Version();
 
#define ID_PLC_EngineStatus 5395
extern u_int16_t PLC_EngineStatus;
int doWrite_PLC_EngineStatus(u_int16_t value);
int addWrite_PLC_EngineStatus(u_int16_t value);
int getStatus_PLC_EngineStatus();
 
#define ID_PLC_ResetValues 5396
extern int PLC_ResetValues;
int doWrite_PLC_ResetValues(int value);
int addWrite_PLC_ResetValues(int value);
int getStatus_PLC_ResetValues();
 
#define ID_PLC_buzzerOn 5397
extern int PLC_buzzerOn;
int doWrite_PLC_buzzerOn(int value);
int addWrite_PLC_buzzerOn(int value);
int getStatus_PLC_buzzerOn();
 
#ifdef __cplusplus
}
#endif
#endif
