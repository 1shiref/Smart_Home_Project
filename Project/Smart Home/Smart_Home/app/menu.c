
#include "menu.h"

void lED()
{
	LCD_Init();
	LCD_WriteString("1-room1 2-room2");
	LCD_GoTo(1, 0);
	LCD_WriteString("3-room3  4-more");
	uint8 x = GET_Input();
	_delay_ms(200);


	switch (x)
	{

	case('1'):
	{
		LCD_Init();
		LCD_WriteString("1-ON 2-OFF");

		/*while (x == 'm')
		{
			x = KeyPad_GetChar();
		}*/
		uint8 y=0;
		do
		{
			uint8 x = GET_Input();
					_delay_ms(200);
			switch (x)
					{
					case('1'):
					{
						LED1_TurnOn();
						LCD_Init();
						LCD_WriteString("done");
						LCD_Init();

						return;

					}
					case('2'):
					{
						LED1_TurnOff();
						LCD_Init();
						LCD_WriteString("done");
						LCD_Init();
						//leds();
						return;
					}
					default : y=-1;


		}

		}
		while(y=-1);
	}
	case('2'):
	{
		LCD_Init();
		LCD_WriteString("1-ON 2-OFF");
		uint8 y=0;
		do
		{
			uint8 x = GET_Input();
					_delay_ms(200);

					switch (x)
					{
					case('1'):
					{
						LED2_TurnOn();
						LCD_Init();
						LCD_WriteString("done");
						LCD_Init();

						return;
						break;
					}
					case('2'):
					{
						LED2_TurnOff();
						LCD_Init();
						LCD_WriteString("done");
						LCD_Init();

						return;
						break;
					}
					default : y=-1;
					}

		}while(y=-1);

	}
	case('3'):
	{
		LCD_Init();
		LCD_WriteString("1-ON 2-OFF");
		uint8 y=0;
		do
		{
			uint8 x = GET_Input();
			_delay_ms(200);
			while (x == 'm')
			{
				x = KeyPad_GetChar();
			}
			switch (x)
			{
			case('1'):
			{
				LED3_TurnOn();
				LCD_Init();
				LCD_WriteString("done");
				LCD_Init();
				return;
				break;
			}
			case('2'):
			{
				LED3_TurnOff();
				LCD_Init();
				LCD_WriteString("done");
				LCD_Init();
				//leds();
				return;
				break;
			}
			default : y=-1;
			}
		}while(y=-1);



	}
	case('4'):
	{
		LCD_Init();
		LCD_WriteString("1-room4 2-room5");
		LCD_GoTo(1, 0);
		LCD_WriteString("3-dimmer lamp");
		uint8 u=0;
		do
		{
			uint8 x = GET_Input();
			_delay_ms(200);
			switch (x)
			{
			case('1'):
			{
				LCD_Init();
				LCD_WriteString("1-ON 2-OFF");
				uint8 y=0;
				do
				{
					uint8 x = GET_Input();
					_delay_ms(200);
					switch (x)
					{

					case('1'):
					{
						LED4_TurnOn();
						LCD_Init();
						LCD_WriteString("done");
						LCD_Init();
						break;
						return;
					}
					case('2'):
					{
						LED4_TurnOff();
						LCD_Init();
						LCD_WriteString("done");
						LCD_Init();
						break;
						//leds();
						break; }
					default:y=-1;
					}
				}while(y=-1);




			}
			case('2'):
			{
				LCD_Init();
				LCD_WriteString("1-ON 2-OFF");
				uint8 y=0;
				do
				{
					uint8 x =GET_Input();
					_delay_ms(200);

					switch (x)
					{
					case('1'):
					{
						LED5_TurnOn();
						LCD_Init();
						LCD_WriteString("done");
						LCD_Init();
						//leds();
						return;
					}
					case('2'):
					{
						LED5_TurnOff();
						LCD_Init();
						LCD_WriteString("done");
						LCD_Init();
						//leds();
						return;
						break;
					}
					default:y=-1;
					}
				}while(y=-1);



			}
			case('3'):{

				LCD_Init();
				LCD_WriteString("1-50% 2-100%");
				uint8 y=0;
				do
				{
					uint8 x = GET_Input();
					_delay_ms(200);

					switch (x)
					{

					case('1'):
					{
						PWM2_init();
						PWM2_Set_OCR(1);
						LCD_Init();
						LCD_WriteString("done 50%");
						LCD_Init();
						break;
					}
					case('2'):
					{
						PWM2_init();
						PWM2_Set_OCR(255);
						LCD_Init();
						LCD_WriteString("done 100%");
						LCD_Init();
						break;
						break; }
					default:y=-1;

					}
				}while(y=-1);




			}


			}
		}while(u=-1);




	}
	default:{
									LCD_Init();
									LCD_WriteString("wrong input");
									_delay_ms(100);
									LCD_Init();
									lED();
								}
	}
}

void DOOR()
{
	LCD_Init();
	LCD_WriteString("1-open 2-close");
	uint8 x=GET_Input();
	_delay_ms(200);

	switch(x)
	{
	case('1'):ServoMotor_Set_Degree(2);break;
	case('2'):ServoMotor_Set_Degree(0);break;
	default:{
									LCD_Init();
									LCD_WriteString("wrong input");
									_delay_ms(100);
									LCD_Init();
									DOOR();
								}
	}

}

void TEMP()
{
	uint16 x= TEMP_Read();
	LCD_Init();
	LCD_WriteString("temperature= ");
	LCD_WriteInteger(x);
	LCD_GoTo(1, 0);
	LCD_WriteString("1-back");
	uint8 y=GET_Input();
	_delay_ms(200);
	switch(y){
			case('1'):{return;}
			default:{
					LCD_Init();
					LCD_WriteString("wrong input");
					_delay_ms(100);
					LCD_Init();
					TEMP();
										}
	}

}

void ADD_AND_REMOVE()
{
	LCD_Init();
				LCD_WriteString("5-add  6-remove");
				LCD_GoTo(1, 0);
				LCD_WriteString("7-restore 8-out");

				uint8 x=KeyPad_GetChar();
				while(x=='m')
				{
					x=KeyPad_GetChar();
				}
				switch(x){
							case('5'):{if(EEPROM_Read_Byte_From_Address(85)<=10){
								Add_New_user();
							}
							else
							{
								LCD_Init();
								LCD_WriteString("max");
							}



								Menu_For_Admin();}
							case('6'):{
								LCD_Init();
								LCD_WriteString("enter user:");
								uint8 u[user_limit];
								for(int i=0 ;i< user_limit ;)
								{
									uint8 letter =GET_Input();
									_delay_ms(200);
									//uint8 x = KeyPad_GetChar();
									if(letter!='m'){
									LCD_WriteChar(letter);
									u[i]=letter;
									i++;
									}
								}
								delete_user(u);
                                break;
							}
							case('7'):{
								Delete_ALL();
								main();
							}
							case('8'):{
								main();
							}
							default:{
								LCD_Init();
								LCD_WriteString("wrong input");
								_delay_ms(100);
								LCD_Init();
								ADD_AND_REMOVE();
							}

}
}

void Menu_For_Admin()
{
    LCD_Init();
	LCD_WriteString("1-led  2-AC");
	LCD_GoTo(1, 0);
	LCD_WriteString("3-door  4-more");
	uint8 x=GET_Input();
	_delay_ms(200);

	switch(x)
	{
	case('1'):{lED();Menu_For_Admin();} // @suppress("No break at end of case")
	case('2'):{TEMP();Menu_For_Admin();}
	case('3'):{DOOR();Menu_For_Admin();}
    case('4'):{ADD_AND_REMOVE();Menu_For_Admin();}
    default:{
    								LCD_Init();
    								LCD_WriteString("wrong input");
    								_delay_ms(100);
    								LCD_Init();
    								Menu_For_Admin();
    							}
    }
}

void Menu_For_User()
{

    LCD_Init();
	LCD_WriteString("1-led  2-AC");
	uint8 x=GET_Input();
	_delay_ms(200);
	while (x == 'm')
	{
		x = KeyPad_GetChar();
	}

	switch(x)
	{
	case('1'):{lED();Menu_For_User();} // @suppress("No break at end of case")
	case('2'):{TEMP();Menu_For_User();}
	default:{
									LCD_Init();
									LCD_WriteString("wrong input");
									_delay_ms(100);
									LCD_Init();
									Menu_For_User();
								}
	}
}


