/*	Author: <your name>
 *	Lab Section:
 *  Exam #2
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
#include "timer.h"

/* SM state declarations --- fill in as needed */
typedef enum ping_states { PInit, Pon, Poff
} ping_states;
typedef enum detect_eq_states { DEQInit, d_eq, wait_eq
} detect_eq_states;
typedef enum detect_max_amp_states { DMAInit, update_max
} detect_max_amp_states;
typedef enum detect_zc_states { DZCInit, first, second, third, out// e, ne, n, nw, w, sw, s, se, e_opp, ne_opp, n_op, nw_opp, w_opp, sw_opp, s_opp, se_opp, out
} detect_zc_states;
typedef enum transmit_states {TInit,                                        } transmit_states;

/* shared variables --- fill in as needed */

unsigned char A;
unsigned char dir;
unsigned char amp;
unsigned char ping;
unsigned char eq;
unsigned char zc;
unsigned char max;

/* state variables --- do not alter */
ping_states ping_state;
detect_eq_states detect_eq_state;
detect_max_amp_states detect_max_amp_state;
detect_zc_states detect_zc_state;
transmit_states transmit_state;

/* SM definitions --- complete each task as a SM in the appropriate file.
 * Alternatively, you can remove the #include statement and insert your
 *   SM implementation directly. 
 */
#include "ping.h"
#include "detect_eq.h"
#include "detect_max_amp.h"
#include "detect_zc.h"
#include "transmit.h"


/* main function --- do not alter */
int main(void) {
    /* DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
	
    A = ~PINA;
    dir = A & 0x07;
    amp = A >> 3;

    // Common period for all tasks set to 100ms
    TimerSet(100);
    TimerOn();

    // init state vars
    ping_state = PInit;
    detect_eq_state = DEQInit;
    detect_max_amp_state = DMAInit;
    detect_zc_state = DZCInit;
    transmit_state = TInit;

    while (1) {
        Ping();
        Detect_EQ();
        Detect_Max_Amp();
        Detect_ZC();
        Transmit();
        while (!TimerFlag) { }
        TimerFlag = 0;
    }
    return 1;
}
