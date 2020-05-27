
//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i

unsigned char l_dir;

/*complete the state machine*/

void Detect_ZC()
{
    switch(detect_zc_state)
    {
        case DZCInit:
/*		l_dir = dir;
		detect_zc_state = first;
            break;

	case first:
		if (l_dir == dir) state = first;
		else state = second;
	    break;
	case second:
	    if (l_dir == 0x00 && dir == 0x04) || 
		(l_dir == 0x01 && dir == 0x05) ||
		(l_dir == 0x02 && dir == 0x06) ||
		(l_dir == 0x03 && dir == 0x07) ||
		(l_dir == 0x04 && dir == 0x00) ||
		(l_dir == 0x05 && dir == 0x01) ||
		(l_dir == 0x06 && dir == 0x02) ||
		(l_dir == 0x07 && dir == 0x03) {
			detect_zc_state = third;
		else detect_zc_state = first;

		break;
	case third:
		break;
	case out:
*/        default:
            detect_zc_state = DZCInit;
            break;
    }
    switch(detect_zc_state)
    {
        case DZCInit:
            break;
/*	case first:
	    break;
	case second:
	    break;
	case third:
	    break;
	case out:
	    zc = 1;
	    break;
  */      default:
            break;
    }
}
