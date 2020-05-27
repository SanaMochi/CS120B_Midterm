//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i

unsigned char i = 0x00;

/*complete the state machine*/

void Detect_EQ()
{
    switch(detect_eq_state)
    {
        case DEQInit:
            //init variable(s) here.
	    	i = 0x00;
            	if (!amp) detect_eq_state = DEQInit;
		else detect_eq_state = d_eq;
		break;
	case d_eq:
		if (amp) detect_eq_state = d_eq;
		else detect_eq_state = wait_eq;
	    break;
	case wait_eq:
		if (amp) detect_eq_state = d_eq;
		else if (!amp && i <= 10) detect_eq_state = wait_eq;
		else { detect_eq_state = DEQInit; i = 0x00;}
	  break; 
	default:
            detect_eq_state = DEQInit;
            break;
    }
    switch(detect_eq_state)
    {
        case DEQInit:
            break;
	case d_eq:
	    eq = 1;
	    break;
	case wait_eq:
	    i++;
	    break;
        default:
            break;
    }
}
