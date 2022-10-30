

#ifndef APP_LOGIN_H_
#define APP_LOGIN_H_
#include "../STD_TYPES.h"
#include "../HALL/LCD.h"
#include <util/delay.h>

#define user_limit 4
#define pass_limit 4




void Add_New_user();
uint8 Check_User(uint8 name[],uint8 pass[]);
uint8 login();
void delete_user(uint8 arr[]);
uint8 Check_User_Exist(uint8 name[],uint8 pass[]);
void ADD_NEW_ADMIN();
void Delete_ALL();
uint8 GET_Input();



#endif /* APP_LOGIN_H_ */
