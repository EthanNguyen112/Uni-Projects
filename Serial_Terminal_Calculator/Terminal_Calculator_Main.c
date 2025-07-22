 #include <DS89C4XX.h>

unsigned int power(int x, int n)
{
	if(n == 0) 
		return 1;
	else
		return x * power(x, n-1);
}

unsigned char receive(void)
{
	while(RI_0 == 0);
	RI_0 = 0;
	return SBUF0;
}

void transfer(unsigned char target)
{
	SBUF0 = target;
	while(TI_0 == 0);
	TI_0 = 0;
}

void transfer_str(unsigned char target[], unsigned int len)
{
	int i;
	for (i = 0; i < len ; i++)
		transfer(target[i]);
}

void transfer_dec(char isNeg, unsigned char target[], unsigned int len)
{
	int i;
	unsigned char isZero = 1;
	if (isNeg == 1)
		transfer('-');
	for (i = len-2; i >= 0; i--)
	{
		if (target[i] != 48)
			isZero = 0;
		if (!isZero)
			transfer(target[i]);
	}
	if ((i == -1) && (isZero == 1))
		transfer('0');
}

int dec_op(unsigned char op, int lhs, int rhs)
{
	if(op == '+')
		return lhs + rhs;
	else if(op == '-')
		return lhs - rhs;
	else if(op == '*')
		return lhs * rhs;
	else if(op == 47)
		return lhs/rhs;
	else if(op == '^')
		return power(lhs,rhs);
}

char dec2asc(unsigned char *digit, unsigned int len, int target)
{
	int i = 0;
	char isNeg = 0;
	if (target < 0)
	{
		isNeg = 1;
		target *= -1;
	}
	while(target)
	{
    digit[i++] = target % 10;
    target /= 10;
	}
	for (i = 0; i < len-1 ; i++)
		digit[i] += 48;
	return isNeg;
}

int asc2dec(char digit[], unsigned int len)
{
	int i;
	int result = 0;
	
	for (i = 0; i < len ; i++)
	{
		if ((i == (len-1)) && (digit [len-1] == '-'))
		{
			result *= -1;
			break;
		}
		result += (digit[i]-48) * power(10,i);
	}
	return result;
}

////////////binary/////////////////////
void transfer_bin(unsigned char target[], unsigned int len)
{
	int i;
	for (i = len-2; i >= 0; i--)
		transfer(target[i]);
}

void bin_op(unsigned char op, char lhs [], char rhs [], unsigned char *digit, unsigned int len)
{
	int i;
	char carry = 0;
	int num;
	if((op == '+')|| (op == '-'))
	{
		if (op == '-')
		{
			for (i = 0; i < len - 2; i++)
			{
				rhs[i] -= 48;
				rhs[i] = (rhs[i] == 1) ? 0 : 1;
			}
			carry = 1;
		}
		for (i = 0; i < len - 2; i++)
		{
			num = ((lhs[i]-48) + (rhs[i]-48) + carry);
			carry = 0;
			digit[i] = num%2;
			carry = num/2;
			if(i == (len-3))
				digit[i+1] = carry;
		}
	}
	else if(op == '&')
	{
		for (i = 0; i < len - 2; i++)
			digit[i] = (lhs[i]-48) & (rhs[i]-48);
	}
	else if(op == '|')
	{
		for (i = 0; i < len - 2; i++)
			digit[i] = (lhs[i]-48) | (rhs[i]-48);
	}
	
	for (i = 0; i < len-1 ; i++)
		digit[i] += 48;
}
///////////////////////////////////////

////////////hex/////////////////////
void transfer_hex(unsigned char target[], unsigned int len)
{
	int i;
	for (i = len-2; i >= 0; i--)
		transfer(target[i]);
}

void hex2value(unsigned char *digit, unsigned int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if(digit[i] >= 48 && digit[i] <= 57)
			digit[i] -= 48;
		else if (digit[i] == 'A')
			digit[i] = 10;
		else if (digit[i] == 'B')
			digit[i] = 11;
		else if (digit[i] == 'C')
			digit[i] = 12;
		else if (digit[i] == 'D')
			digit[i] = 13;
		else if (digit[i] == 'E')
			digit[i] = 14;
		else 
			digit[i] = 15;
	}
}

void value2hex(unsigned char *digit, unsigned int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if(digit[i] >= 0 && digit[i] <= 9)
			digit[i] += 48;
		else if (digit[i] == 10)
			digit[i] = 'A';
		else if (digit[i] == 11)
			digit[i] = 'B';
		else if (digit[i] == 12)
			digit[i] = 'C';
		else if (digit[i] == 13)
			digit[i] = 'D';
		else if (digit[i] == 14)
			digit[i] = 'E';
		else 
			digit[i] = 'F';
	}
}

void hex_op(unsigned char op, char lhs [], char rhs [], unsigned char *digit, unsigned int len)
{
	int i;
	char carry = 0;
	
	hex2value(lhs, 4);
	hex2value(rhs, 4);
	
	if(op == '+')
	{
		for (i = 0; i < len - 2; i++)
		{
			digit[i] = (lhs[i] + rhs[i] + carry)%16;
			carry = (lhs[i] + rhs[i] + carry)/16;
			if(i == (len-3))
				digit[i+1] = carry;
		}
	}
	else if(op == '-')
	{
		for (i = 0; i < len - 2; i++)
		{
			if(lhs[i] >= (rhs[i]+carry))
			{
				digit[i] = (lhs[i] - rhs[i] - carry)%16;
				carry = 0;
			}
			else
			{
				digit[i] = 16 + ((lhs[i] - rhs[i] - carry)%16);
				carry = 1;
			}
			if(i == (len-3))
				digit[i+1] = carry;
		}
	}
	value2hex(digit, 5);
	
}
///////////////////////////////////////

void timerone(void) interrupt 4
{
	int i;
	unsigned char byte = 0;
	unsigned char base = 0;
	char lhs_byte[4] = {0,0,0,0};
	char rhs_byte[4] = {0,0,0,0};
	int digit1 = 0;
	int digit2 = 0;
	int result = 0;
	unsigned char ascii[6] = {0,0,0,0,0,0};
	char isNeg = 0;
	
	transfer_str("\n\r> Choose base <",17);
	transfer_str("\n\r> 1 for Decimal",17);
	transfer_str("\n\r> 2 for Binary",16);
	transfer_str("\n\r> 3 for Hexadecimal",21);
	transfer_str("\n\r> ",4);
	base = receive();
	transfer(base);
	base -= 48;
	if((base) == 1)
		transfer_str("\n\r> Decimal <\n\r> ",17);
	else if((base) == 2)
		transfer_str("\n\r> Binary <\n\r> ",16);
	else if(base == 3)
		transfer_str("\n\r> Hexadecimal <\n\r> ",21);
	else
	{
		transfer_str("\n\r> Invalid selection! <\n\r> ",28);
		return;
	}
	
	lhs_byte[3] = receive();
	transfer(lhs_byte[3]);
	
	//read and write bit1
	lhs_byte[2] = receive();
	transfer(lhs_byte[2]);

	//read and write bit2
	lhs_byte[1] = receive();
	transfer(lhs_byte[1]);

	lhs_byte[0] = receive();
	transfer(lhs_byte[0]);

	for (i = 0; i < 4; i++)
	{
		if((base == 1) && lhs_byte[i] >= 48 && lhs_byte[i] <= 57);
		else if((base == 2) && lhs_byte[i] >= 48 && lhs_byte[i] <= 49);
		else if((base == 3) && ((lhs_byte[i] >= 48 && lhs_byte[i] <= 57) || (lhs_byte[i] >= 65 && lhs_byte[i] <= 70)));
		else
		{
			transfer_str("\n\r> Invalid input! <\n\r> ",24);
			return;
		}
	}
	
	// op
	byte = receive();
	transfer(byte);
	if((base == 1) && (byte == '+' || byte == '-' || byte == '*' || byte == '/' || byte == '^'));
	else if((base == 2) && (byte == '+' || byte == '-' || byte == '&' || byte == '|'));
	else if((base == 3) && (byte == '+' || byte == '-'));
	else
	{
		transfer_str("\n\r> Invalid operation! <\n\r> ",24);
		return;
	}

	rhs_byte[3] = receive();
	transfer(rhs_byte[3]);
	
	//byte 4
	rhs_byte[2] = receive();
	transfer(rhs_byte[2]);

	//byte 5
	rhs_byte[1] = receive();
	transfer(rhs_byte[1]);

	rhs_byte[0] = receive();
	transfer(rhs_byte[0]);
	
	for (i = 0; i < 4; i++)
	{
		if((base == 1) && rhs_byte[i] >= 48 && rhs_byte[i] <= 57);
		else if((base == 2) && rhs_byte[i] >= 48 && rhs_byte[i] <= 49);
		else if((base == 3) && ((rhs_byte[i] >= 48 && rhs_byte[i] <= 57) || (rhs_byte[i] >= 65 && rhs_byte[i] <= 70)));
		else
		{
			transfer_str("\n\r> Invalid input! <\n\r> ",24);
			return;
		}
	}
	
	transfer_str("\n\r= ",4);
	if (base == 1)
	{
		digit1 = asc2dec(lhs_byte, 4);
		digit2 = asc2dec(rhs_byte, 4);

		result = dec_op(byte, digit1, digit2);
		if (byte == '*' && (result/digit2) != digit1 )
		{
			transfer_str("\n\r> Result too large <",22);
			return;
		}
		isNeg = dec2asc(ascii, 6, result);
		transfer_dec(isNeg, ascii, 6);
	}
	else if (base == 2)
	{
		bin_op(byte, lhs_byte, rhs_byte, ascii, 6);
		if (byte == '+')
			transfer_bin(ascii, 6);
		else
			transfer_bin(ascii, 5);
	}
	else
	{
		hex_op(byte, lhs_byte, rhs_byte, ascii, 6);
		if (byte == '+')
			transfer_hex(ascii, 6);
		else
			transfer_hex(ascii, 5);
	}
	transfer_str("\n\r",2);
	transfer_str("\n\r> Press any key to continue...",32);
}


void main(void){
	
	IE = 0x90;
	TMOD = 0x20;
	TH1 = 0xFD;
	SCON0 = 0x50;
	TR1 = 1;
	
	while(1){}
}
