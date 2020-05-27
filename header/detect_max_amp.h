
//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i

/* complete the state machine. */

void Detect_Max_Amp()
{
    switch(detect_max_amp_state)
    {
        case DMAInit:
		max = amp;
		/*if (eq)*/ detect_max_amp_state = update_max;
//		else detect_max_amp_state = DMAInit;
            break;
	case update_max:
	    /*if (eq)*/ detect_max_amp_state = update_max;
//	    else detect_max_amp_state = DMAInit;
  		break;		
        default:
            break;
    }
    switch(detect_max_amp_state)
    {
        case DMAInit:
            break;
	case update_max:
	    if (max < amp) max = amp;
        default:
            break;
    }
}
