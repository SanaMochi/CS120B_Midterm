
//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i

unsigned char L = 0x00;

/*complete the state machine*/

void Ping()
{
    switch(ping_state)
    {
        case PInit:
        	ping_state = Pon;
		ping = 0x00;
		L = 0x00;
		break;
	case Pon:
		ping_state = Poff;
		break;
	case Poff:
		if (L <= 0x09) ping_state = Poff;
		else { ping_state = Pon; L = 0x00;}
		break;
	default:
            ping_state = PInit;
            break;
    }
    switch(ping_state)
    {
        case PInit:
		ping = 0x00;
		L = 0x00;
            break;
	case Pon:
		ping = 0x01;
		break;
	case Poff:
		ping = 0x00;
		L++;
		break;
        default:
            break;
    }
}
