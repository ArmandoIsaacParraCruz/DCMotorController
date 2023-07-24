#ifndef MyEncoder_H
#define MyEncoder_h
#include <Arduino.h>
#include "interrupt_pins.h"

// Use ICACHE_RAM_ATTR for ISRs to prevent ESP8266 resets
#if defined(ESP8266) || defined(ESP32)
#define ENCODER_ISR_ATTR ICACHE_RAM_ATTR
#else
#define ENCODER_ISR_ATTR
#endif

enum class EncoderMode{Velocity, Position};

typedef struct {
    EncoderMode encoderMode;
    volatile double position;
    volatile double velocity;
    volatile double pulseCounter;
} EncoderInfo;

class MyEncoder{
    public:
        MyEncoder(int8_t encoderPhaseA, int8_t encoderPhaseB);

    private:
    static EncoderInfo _encoderInfo[];
    #if defined(IRAM_ATTR)
	    static IRAM_ATTR void update(EncoderInfo &encoderInfo){
            Serial.println("Interruption ocurried");
             ++encoderInfo.pulseCounter;
        }
    #else
	    static void update(EncoderInfo &encoderInfo) {
            //Serial.println("Interruption ocurried");
            ++encoderInfo.pulseCounter;
        }
    #endif


    #ifdef CORE_INT0_PIN
        static ENCODER_ISR_ATTR void isr0(void) { update(_encoderInfo[0]); }
    #endif
    #ifdef CORE_INT1_PIN
        static ENCODER_ISR_ATTR void isr1(void) { update(_encoderInfo[1]); }
    #endif
    #ifdef CORE_INT2_PIN
        static ENCODER_ISR_ATTR void isr2(void) { update(_encoderInfo[2]); }
    #endif
    #ifdef CORE_INT3_PIN
        static ENCODER_ISR_ATTR void isr3(void) { update(_encoderInfo[3]); }
    #endif
    #ifdef CORE_INT4_PIN
        static ENCODER_ISR_ATTR void isr4(void) { update(_encoderInfo[4]); }
    #endif
    #ifdef CORE_INT5_PIN
        static ENCODER_ISR_ATTR void isr5(void) { update(_encoderInfo[5]); }
    #endif
    #ifdef CORE_INT6_PIN
        static ENCODER_ISR_ATTR void isr6(void) { update(_encoderInfo[6]); }
    #endif
    #ifdef CORE_INT7_PIN
        static ENCODER_ISR_ATTR void isr7(void) { update(_encoderInfo[7]); }
    #endif
    #ifdef CORE_INT8_PIN
        static ENCODER_ISR_ATTR void isr8(void) { update(_encoderInfo[8]); }
    #endif
    #ifdef CORE_INT9_PIN
        static ENCODER_ISR_ATTR void isr9(void) { update(__alloc_size2[9]); }
    #endif
    #ifdef CORE_INT10_PIN
        static ENCODER_ISR_ATTR void isr10(void) { update(_encoderInfo[10]); }
    #endif
    #ifdef CORE_INT11_PIN
        static ENCODER_ISR_ATTR void isr11(void) { update(_encoderInfo[11]); }
    #endif
    #ifdef CORE_INT12_PIN
        static ENCODER_ISR_ATTR void isr12(void) { update(_encoderInfo[12]); }
    #endif
    #ifdef CORE_INT13_PIN
        static ENCODER_ISR_ATTR void isr13(void) { update(_encoderInfo[13]); }
    #endif
    #ifdef CORE_INT14_PIN
        static ENCODER_ISR_ATTR void isr14(void) { update(_encoderInfo[14]); }
    #endif
    #ifdef CORE_INT15_PIN
        static ENCODER_ISR_ATTR void isr15(void) { update(_encoderInfo[15]); }
    #endif
    #ifdef CORE_INT16_PIN
        static ENCODER_ISR_ATTR void isr16(void) { update(_encoderInfo[16]); }
    #endif
    #ifdef CORE_INT17_PIN
        static ENCODER_ISR_ATTR void isr17(void) { update(_encoderInfo[17]); }
    #endif
    #ifdef CORE_INT18_PIN
        static ENCODER_ISR_ATTR void isr18(void) { update(_encoderInfo[18]); }
    #endif
    #ifdef CORE_INT19_PIN
        static ENCODER_ISR_ATTR void isr19(void) { update(_encoderInfo[19]); }
    #endif
    #ifdef CORE_INT20_PIN
        static ENCODER_ISR_ATTR void isr20(void) { update(_encoderInfo[20]); }
    #endif
    #ifdef CORE_INT21_PIN
        static ENCODER_ISR_ATTR void isr21(void) { update(_encoderInfo[21]); }
    #endif
    #ifdef CORE_INT22_PIN
        static ENCODER_ISR_ATTR void isr22(void) { update(_encoderInfo[22]); }
    #endif
    #ifdef CORE_INT23_PIN
        static ENCODER_ISR_ATTR void isr23(void) { update(_encoderInfo[23]); }
    #endif
    #ifdef CORE_INT24_PIN
        static ENCODER_ISR_ATTR void isr24(void) { update(_encoderInfo[24]); }
    #endif
    #ifdef CORE_INT25_PIN
        static ENCODER_ISR_ATTR void isr25(void) { update(_encoderInfo[25]); }
    #endif
    #ifdef CORE_INT26_PIN
        static ENCODER_ISR_ATTR void isr26(void) { update(_encoderInfo[26]); }
    #endif
    #ifdef CORE_INT27_PIN
        static ENCODER_ISR_ATTR void isr27(void) { update(_encoderInfo[27]); }
    #endif
    #ifdef CORE_INT28_PIN
        static ENCODER_ISR_ATTR void isr28(void) { update(_encoderInfo[28]); }
    #endif
    #ifdef CORE_INT29_PIN
        static ENCODER_ISR_ATTR void isr29(void) { update(_encoderInfo[29]); }
    #endif
    #ifdef CORE_INT30_PIN
        static ENCODER_ISR_ATTR void isr30(void) { update(_encoderInfo[30]); }
    #endif
    #ifdef CORE_INT31_PIN
        static ENCODER_ISR_ATTR void isr31(void) { update(_encoderInfo[31]); }
    #endif
    #ifdef CORE_INT32_PIN
        static ENCODER_ISR_ATTR void isr32(void) { update(_encoderInfo[32]); }
    #endif
    #ifdef CORE_INT33_PIN
        static ENCODER_ISR_ATTR void isr33(void) { update(_encoderInfo[33]); }
    #endif
    #ifdef CORE_INT34_PIN
        static ENCODER_ISR_ATTR void isr34(void) { update(_encoderInfo[34]); }
    #endif
    #ifdef CORE_INT35_PIN
        static ENCODER_ISR_ATTR void isr35(void) { update(_encoderInfo[35]); }
    #endif
    #ifdef CORE_INT36_PIN
        static ENCODER_ISR_ATTR void isr36(void) { update(_encoderInfo[36]); }
    #endif
    #ifdef CORE_INT37_PIN
        static ENCODER_ISR_ATTR void isr37(void) { update(_encoderInfo[37]); }
    #endif
    #ifdef CORE_INT38_PIN
        static ENCODER_ISR_ATTR void isr38(void) { update(_encoderInfo[38]); }
    #endif
    #ifdef CORE_INT39_PIN
        static ENCODER_ISR_ATTR void isr39(void) { update(_encoderInfo[39]); }
    #endif
    #ifdef CORE_INT40_PIN
        static ENCODER_ISR_ATTR void isr40(void) { update(_encoderInfo[40]); }
    #endif
    #ifdef CORE_INT41_PIN
        static ENCODER_ISR_ATTR void isr41(void) { update(_encoderInfo[41]); }
    #endif
    #ifdef CORE_INT42_PIN
        static ENCODER_ISR_ATTR void isr42(void) { update(_encoderInfo[42]); }
    #endif
    #ifdef CORE_INT43_PIN
        static ENCODER_ISR_ATTR void isr43(void) { update(_encoderInfo[43]); }
    #endif
    #ifdef CORE_INT44_PIN
        static ENCODER_ISR_ATTR void isr44(void) { update(_encoderInfo[44]); }
    #endif
    #ifdef CORE_INT45_PIN
        static ENCODER_ISR_ATTR void isr45(void) { update(_encoderInfo[45]); }
    #endif
    #ifdef CORE_INT46_PIN
        static ENCODER_ISR_ATTR void isr46(void) { update(_encoderInfo[46]); }
    #endif
    #ifdef CORE_INT47_PIN
        static ENCODER_ISR_ATTR void isr47(void) { update(_encoderInfo[47]); }
    #endif
    #ifdef CORE_INT48_PIN
        static ENCODER_ISR_ATTR void isr48(void) { update(_encoderInfo[48]); }
    #endif
    #ifdef CORE_INT49_PIN
        static ENCODER_ISR_ATTR void isr49(void) { update(_encoderInfo[49]); }
    #endif
    #ifdef CORE_INT50_PIN
        static ENCODER_ISR_ATTR void isr50(void) { update(_encoderInfo[50]); }
    #endif
    #ifdef CORE_INT51_PIN
        static ENCODER_ISR_ATTR void isr51(void) { update(_encoderInfo[51]); }
    #endif
    #ifdef CORE_INT52_PIN
        static ENCODER_ISR_ATTR void isr52(void) { update(_encoderInfo[52]); }
    #endif
    #ifdef CORE_INT53_PIN
        static ENCODER_ISR_ATTR void isr53(void) { update(_encoderInfo[53]); }
    #endif
    #ifdef CORE_INT54_PIN
        static ENCODER_ISR_ATTR void isr54(void) { update(_encoderInfo[54]); }
    #endif
    #ifdef CORE_INT55_PIN
        static ENCODER_ISR_ATTR void isr55(void) { update(_encoderInfo[55]); }
    #endif
    #ifdef CORE_INT56_PIN
        static ENCODER_ISR_ATTR void isr56(void) { update(_encoderInfo[56]); }
    #endif
    #ifdef CORE_INT57_PIN
        static ENCODER_ISR_ATTR void isr57(void) { update(_encoderInfo[57]); }
    #endif
    #ifdef CORE_INT58_PIN
        static ENCODER_ISR_ATTR void isr58(void) { update(_encoderInfo[58]); }
    #endif
    #ifdef CORE_INT59_PIN
        static ENCODER_ISR_ATTR void isr59(void) { update(_encoderInfo[59]); }
    #endif

    static uint8_t attach_interrupt(int8_t& pin, int8_t& interruptMode) {
        switch (pin) {
            #ifdef CORE_INT0_PIN
                    case CORE_INT0_PIN:
                        attachInterrupt(0, isr0, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT1_PIN
                    case CORE_INT1_PIN:
                        attachInterrupt(1, isr1, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT2_PIN
                    case CORE_INT2_PIN:
                        attachInterrupt(2, isr2, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT3_PIN
                    case CORE_INT3_PIN:
                        attachInterrupt(3, isr3, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT4_PIN
                    case CORE_INT4_PIN:
                        attachInterrupt(4, isr4, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT5_PIN
                    case CORE_INT5_PIN:
                        attachInterrupt(5, isr5, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT6_PIN
                    case CORE_INT6_PIN:
                        attachInterrupt(6, isr6, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT7_PIN
                    case CORE_INT7_PIN:
                        attachInterrupt(7, isr7, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT8_PIN
                    case CORE_INT8_PIN:
                        attachInterrupt(8, isr8, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT9_PIN
                    case CORE_INT9_PIN:
                        attachInterrupt(9, isr9, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT10_PIN
                    case CORE_INT10_PIN:
                        attachInterrupt(10, isr10, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT11_PIN
                    case CORE_INT11_PIN:
                        attachInterrupt(11, isr11, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT12_PIN
                    case CORE_INT12_PIN:
                        attachInterrupt(12, isr12, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT13_PIN
                    case CORE_INT13_PIN:
                        attachInterrupt(13, isr13, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT14_PIN
                    case CORE_INT14_PIN:
                        attachInterrupt(14, isr14, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT15_PIN
                    case CORE_INT15_PIN:
                        attachInterrupt(15, isr15, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT16_PIN
                    case CORE_INT16_PIN:
                        attachInterrupt(16, isr16, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT17_PIN
                    case CORE_INT17_PIN:
                        attachInterrupt(17, isr17, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT18_PIN
                    case CORE_INT18_PIN:
                        attachInterrupt(18, isr18, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT19_PIN
                    case CORE_INT19_PIN:
                        attachInterrupt(19, isr19, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT20_PIN
                    case CORE_INT20_PIN:
                        attachInterrupt(20, isr20, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT21_PIN
                    case CORE_INT21_PIN:
                        attachInterrupt(21, isr21, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT22_PIN
                    case CORE_INT22_PIN:
                        attachInterrupt(22, isr22, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT23_PIN
                    case CORE_INT23_PIN:
                        attachInterrupt(23, isr23, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT24_PIN
                    case CORE_INT24_PIN:
                        attachInterrupt(24, isr24, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT25_PIN
                    case CORE_INT25_PIN:
                        attachInterrupt(25, isr25, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT26_PIN
                    case CORE_INT26_PIN:
                        attachInterrupt(26, isr26, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT27_PIN
                    case CORE_INT27_PIN:
                        attachInterrupt(27, isr27, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT28_PIN
                    case CORE_INT28_PIN:
                        attachInterrupt(28, isr28, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT29_PIN
                    case CORE_INT29_PIN:
                        attachInterrupt(29, isr29, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT30_PIN
                    case CORE_INT30_PIN:
                        attachInterrupt(30, isr30, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT31_PIN
                    case CORE_INT31_PIN:
                        attachInterrupt(31, isr31, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT32_PIN
                    case CORE_INT32_PIN:
                        attachInterrupt(32, isr32, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT33_PIN
                    case CORE_INT33_PIN:
                        attachInterrupt(33, isr33, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT34_PIN
                    case CORE_INT34_PIN:
                        attachInterrupt(34, isr34, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT35_PIN
                    case CORE_INT35_PIN:
                        attachInterrupt(35, isr35, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT36_PIN
                    case CORE_INT36_PIN:
                        attachInterrupt(36, isr36, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT37_PIN
                    case CORE_INT37_PIN:
                        attachInterrupt(37, isr37, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT38_PIN
                    case CORE_INT38_PIN:
                        attachInterrupt(38, isr38, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT39_PIN
                    case CORE_INT39_PIN:
                        attachInterrupt(39, isr39, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT40_PIN
                    case CORE_INT40_PIN:
                        attachInterrupt(40, isr40, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT41_PIN
                    case CORE_INT41_PIN:
                        attachInterrupt(41, isr41, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT42_PIN
                    case CORE_INT42_PIN:
                        attachInterrupt(42, isr42, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT43_PIN
                    case CORE_INT43_PIN:
                        attachInterrupt(43, isr43, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT44_PIN
                    case CORE_INT44_PIN:
                        attachInterrupt(44, isr44, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT45_PIN
                    case CORE_INT45_PIN:
                        attachInterrupt(45, isr45, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT46_PIN
                    case CORE_INT46_PIN:
                        attachInterrupt(46, isr46, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT47_PIN
                    case CORE_INT47_PIN:
                        attachInterrupt(47, isr47, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT48_PIN
                    case CORE_INT48_PIN:
                        attachInterrupt(48, isr48, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT49_PIN
                    case CORE_INT49_PIN:
                        attachInterrupt(49, isr49, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT50_PIN
                    case CORE_INT50_PIN:
                        attachInterrupt(50, isr50, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT51_PIN
                    case CORE_INT51_PIN:
                        attachInterrupt(51, isr51, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT52_PIN
                    case CORE_INT52_PIN:
                        attachInterrupt(52, isr52, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT53_PIN
                    case CORE_INT53_PIN:
                        attachInterrupt(53, isr53, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT54_PIN
                    case CORE_INT54_PIN:
                        attachInterrupt(54, isr54, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT55_PIN
                    case CORE_INT55_PIN:
                        attachInterrupt(55, isr55, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT56_PIN
                    case CORE_INT56_PIN:
                        attachInterrupt(56, isr56, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT57_PIN
                    case CORE_INT57_PIN:
                        attachInterrupt(57, isr57, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT58_PIN
                    case CORE_INT58_PIN:
                        attachInterrupt(58, isr58, interruptMode);
                        break;
            #endif
            #ifdef CORE_INT59_PIN
                    case CORE_INT59_PIN:
                        attachInterrupt(59, isr59, interruptMode);
                        break;
            #endif
                    default:
                        return 0;
        }
        return 1;
    }



    

       
};

#endif 


